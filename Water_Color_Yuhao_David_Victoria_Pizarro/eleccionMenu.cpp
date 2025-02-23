#include <iostream>
#include "elegirVaciar.h"
#include "puntuacion.h"

//El menú de pausa
void elegirMenu(int& eleccion, char table[ROWS][COLUMNS], int &turnos, bool & salimos, bool &partida, int &turnos2) {
	std::cout << "Elige entre:\n1 - Mover liquidos\n2 - Finalizar partida\n";
	int elejimaos = 0;

	while (elejimaos < 1 || elejimaos > 2) {
		std::cin >> elejimaos;
	}

	switch (elejimaos) {
	case 1:
		std::cout << "Movamos liquidos!\n";		//Movem líquids
		elegirVaciar(eleccion, table);
		break;
	case 2:
		std::cout << "Terminando partida y sacando puntuacion\n";	//Terminem forzosament la partida
		partida = false;
		turnos2 = turnos;
		turnos = 0;
		break;
	default:
		break;
	}
}