#include <iostream>
#include "SimulacnySystem.h"

int main() {
    std::locale::global(std::locale(""));
    // zapne simul�tor
    SimulacnySystem simulacia;

    // zobraz� default state
    std::cout << "===== program �tart =====\n" << std::endl;
    simulacia.zobrazStavVlakov();

    std::cout << "\n";
    simulacia.zobrazStaniceAVlaky();

    // simuluje 10 krokov
    simulacia.spustiSimulaciu(10);

	// nastav� me�kanie pre IC 401
    std::cout << "===== me�kania manu�lne =====\n" << std::endl;
    simulacia.nastavMeskanie(401, 35);  // 30m < ; vlak sa odp�li

    // po simul�cii
    std::cout << "===== program koniec =====\n" << std::endl;
    simulacia.zobrazStavVlakov();

    return 0;
}
