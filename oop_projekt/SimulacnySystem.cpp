#include "SimulacnySystem.h"
#include "VagonDruhejTriedy.h"
#include "VagonPrvejTriedy.h"
#include "RestauracnyVagon.h"
#include "VagonBusinessTriedy.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

SimulacnySystem::SimulacnySystem() {
    // random gen
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // test d·ta
    vytvorStanice();
    vytvorTrasy();
    vytvorVlaky();
}

SimulacnySystem::~SimulacnySystem() {
    
}

void SimulacnySystem::vytvorStanice() {
	// stanice pre lok·lnu trasu
    stanice.push_back(std::make_unique<Stanica>("Bratislava"));
    stanice.push_back(std::make_unique<Stanica>("Trnava"));
    stanice.push_back(std::make_unique<Stanica>("Leopoldov"));
    stanice.push_back(std::make_unique<Stanica>("Pieöùany"));
    stanice.push_back(std::make_unique<Stanica>("TrenËÌn"));
    stanice.push_back(std::make_unique<Stanica>("P˙chov"));
    stanice.push_back(std::make_unique<Stanica>("éilina"));
    stanice.push_back(std::make_unique<Stanica>("Vr˙tky"));
    stanice.push_back(std::make_unique<Stanica>("ätrba"));
    stanice.push_back(std::make_unique<Stanica>("Poprad"));
    stanice.push_back(std::make_unique<Stanica>("Spiösk· Nov· Ves"));
    stanice.push_back(std::make_unique<Stanica>("Koöice"));

	// stanice pre medzin·rdnu trasu
    stanice.push_back(std::make_unique<Stanica>("Praha"));
    stanice.push_back(std::make_unique<Stanica>("Brno"));
    stanice.push_back(std::make_unique<Stanica>("B¯eclav"));
    stanice.push_back(std::make_unique<Stanica>("K˙ty"));
    stanice.push_back(std::make_unique<Stanica>("Malacky"));
    stanice.push_back(std::make_unique<Stanica>("Bratislava"));
    stanice.push_back(std::make_unique<Stanica>("NovÈ Z·mky"));
    stanice.push_back(std::make_unique<Stanica>("ät˙rovo"));
    stanice.push_back(std::make_unique<Stanica>("Szob"));
    stanice.push_back(std::make_unique<Stanica>("V·c"));
    stanice.push_back(std::make_unique<Stanica>("Budapest"));
}

void SimulacnySystem::vytvorTrasy() {
    // pre-set lok·l
    auto trasaBratislavaKosice = std::make_unique<Trasa>("Bratislava - Koöice", false);

	// nahraj stanice do lok·lu
    for (int i = 0; i < 12; i++) {
        trasaBratislavaKosice->pridajStanicu(stanice[i].get());
    }

	// pre-set medzin·rodna
    auto trasaPrahaBudapest = std::make_unique<Trasa>("Praha - Budapest", true);

	// nahraj stanice do medzin·rodnej trasy
    for (int i = 12; i < 23; i++) {
        trasaPrahaBudapest->pridajStanicu(stanice[i].get());
    }

    // uloû traaù
    trasy.push_back(std::move(trasaBratislavaKosice));
    trasy.push_back(std::move(trasaPrahaBudapest));
}

void SimulacnySystem::vytvorVlaky() {
    // Os
    auto osobnyVlak = std::make_unique<OsobnyVlak>(101, trasy[0].get());
    osobnyVlak->pridajVagon(new VagonDruhejTriedy(80));
    osobnyVlak->pridajVagon(new VagonDruhejTriedy(80));
    // R
    auto rychlik = std::make_unique<Rychlik>(201, trasy[0].get());
    rychlik->pridajVagon(new VagonDruhejTriedy(80));
    rychlik->pridajVagon(new VagonDruhejTriedy(80));
    rychlik->pridajVagon(new VagonPrvejTriedy(60));
    // Ex
    auto expres = std::make_unique<Expres>(301, trasy[0].get());
    expres->pridajVagon(new VagonDruhejTriedy(80));
    expres->pridajVagon(new VagonDruhejTriedy(80));
    expres->pridajVagon(new VagonPrvejTriedy(60));
    expres->pridajVagon(new RestauracnyVagon(15));

    // IC
    auto interCity = std::make_unique<InterCity>(401, trasy[1].get());
    interCity->pridajVagon(new VagonDruhejTriedy(80));
    interCity->pridajVagon(new VagonDruhejTriedy(80));
    interCity->pridajVagon(new VagonPrvejTriedy(60));
    interCity->pridajVagon(new RestauracnyVagon(15));
    // EC
    auto euroCity = std::make_unique<EuroCity>(501, trasy[1].get());
    euroCity->pridajVagon(new VagonDruhejTriedy(80));
    euroCity->pridajVagon(new VagonDruhejTriedy(80));
    euroCity->pridajVagon(new VagonPrvejTriedy(60));
    euroCity->pridajVagon(new RestauracnyVagon(15));
    // rj
    auto railjet = std::make_unique<Railjet>(601, trasy[1].get());
    railjet->pridajVagon(new VagonDruhejTriedy(80));
    railjet->pridajVagon(new VagonDruhejTriedy(80));
    railjet->pridajVagon(new VagonPrvejTriedy(60));
    railjet->pridajVagon(new RestauracnyVagon(15));
    railjet->pridajVagon(new VagonBusinessTriedy(40));
    // SC
    auto superCity = std::make_unique<SuperCity>(701, trasy[1].get());
    superCity->pridajVagon(new VagonDruhejTriedy(80));
    superCity->pridajVagon(new VagonDruhejTriedy(80));
    superCity->pridajVagon(new VagonPrvejTriedy(60));
    superCity->pridajVagon(new RestauracnyVagon(15));

    // uloû
    vlaky.push_back(std::move(osobnyVlak));
    vlaky.push_back(std::move(rychlik));
    vlaky.push_back(std::move(expres));
    vlaky.push_back(std::move(interCity));
    vlaky.push_back(std::move(euroCity));
    vlaky.push_back(std::move(railjet));
    vlaky.push_back(std::move(superCity));
}

void SimulacnySystem::spustiSimulaciu(int pocetKrokov) {
    std::cout << "===== krokovanie na " << pocetKrokov << " krokov =====\n" << std::endl;

    for (int krok = 1; krok <= pocetKrokov; krok++) {
        std::cout << "===== krok #" << krok << " =====\n" << std::endl;

        // nahodne meskanie
        for (auto& vlak : vlaky) {
            if (!vlak->getJeZruseny()) {
                int nahodneMeskanie = std::rand() % 5 - 1;  // -1 to 3 
                int noveMeskanie = std::max(0, vlak->getMeskanie() + nahodneMeskanie);
                vlak->setMeskanie(noveMeskanie);
            }
        }

        // pohyb vlaku
        for (auto& vlak : vlaky) {
            if (!vlak->getJeZruseny() && std::rand() % 2 == 0) {  // öanca na phyb
                vlak->posunNaDalsiuStanicu();
            }
        }

        zobrazStavVlakov();

        std::cout << "\n";
    }

    std::cout << "===== krokovanie na konci =====\n" << std::endl;
}

void SimulacnySystem::zobrazStavVlakov() const {
    std::cout << "stav vlake:" << std::endl;
    for (const auto& vlak : vlaky) {
        std::cout << *vlak.get();

        if (!vlak->getJeZruseny()) {
            // tip na meskanie u EC +
            if (vlak->getTypVlaku() == "EuroCity" ||
                vlak->getTypVlaku() == "railjet" ||
                vlak->getTypVlaku() == "SuperCity") {
                std::cout << ", odhadovanÈ meökanie na Ôalöej stanici: "
                    << vlak->getOdhadovaneMeskanieDalsiaStanica() << " min˙t";
            }

            if (vlak->maSaZastavitNaAktualnejStanici()) {
                std::cout << " (Zastavuje)";
            }
            else {
                std::cout << " (Nezastavuje)";
            }
        }

        std::cout << std::endl;
    }
}

void SimulacnySystem::zobrazStaniceAVlaky() const {
    std::cout << "list stanÌc:" << std::endl;

    for (const auto& stanica : stanice) {
        std::cout << *stanica.get() << std::endl;

        const auto& vlaky = stanica->getAktualneVlaky();
        if (vlaky.empty()) {
            std::cout << "  eöte ûiadne vlak" << std::endl;
        }
        else {
            for (const Vlak* vlak : vlaky) {
                std::cout << "  " << *vlak << std::endl;
            }
        }

        std::cout << std::endl;
    }
}

Vlak* SimulacnySystem::najdiVlak(int cisloVlaku) const {
    for (const auto& vlak : vlaky) {
        if (vlak->getCislo() == cisloVlaku) {
            return vlak.get();
        }
    }
    return nullptr;
}

void SimulacnySystem::pridajVlak(Vlak* vlak) {
    if (vlak) {
        vlaky.push_back(std::unique_ptr<Vlak>(vlak));
    }
}

bool SimulacnySystem::zrusVlak(int cisloVlaku) {
    Vlak* vlak = najdiVlak(cisloVlaku);
    if (vlak && !vlak->getJeZruseny()) {
        vlak->zrusVlak();
        return true;
    }
    return false;
}

bool SimulacnySystem::nastavMeskanie(int cisloVlaku, int meskanie) {
    Vlak* vlak = najdiVlak(cisloVlaku);
    if (vlak && !vlak->getJeZruseny()) {
        vlak->setMeskanie(meskanie);
        return true;
    }
    return false;
}

bool SimulacnySystem::posunVlakNaDalsiuStanicu(int cisloVlaku) {
    Vlak* vlak = najdiVlak(cisloVlaku);
    if (vlak && !vlak->getJeZruseny()) {
        vlak->posunNaDalsiuStanicu();
        return true;
    }
    return false;
}

bool SimulacnySystem::pridajVagonVlaku(int cisloVlaku, Vagon* vagon) {
    Vlak* vlak = najdiVlak(cisloVlaku);
    if (vlak && !vlak->getJeZruseny()) {
        return vlak->pridajVagon(vagon);
    }
    return false;
}
