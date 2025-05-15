#include <iostream>
#include "SimulacnySystem.h"

int main() {
    std::locale::global(std::locale(""));
    // zapne simulátor
    SimulacnySystem simulacia;

    // zobrazí default state
    std::cout << "===== program štart =====\n" << std::endl;
    simulacia.zobrazStavVlakov();

    std::cout << "\n";
    simulacia.zobrazStaniceAVlaky();

    // simuluje 10 krokov
    simulacia.spustiSimulaciu(10);

	// nastaví meškanie pre IC 401
    std::cout << "===== meškania manuálne =====\n" << std::endl;
    simulacia.nastavMeskanie(401, 35);  // 30m < ; vlak sa odpáli

    // po simulácii
    std::cout << "===== program koniec =====\n" << std::endl;
    simulacia.zobrazStavVlakov();

    return 0;
}
