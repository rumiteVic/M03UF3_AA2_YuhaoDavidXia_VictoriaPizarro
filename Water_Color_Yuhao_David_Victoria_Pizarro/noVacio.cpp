#include <iostream>
#include "elegirVaciar.h"
#define ROWS 6
#define COLUMNS 23
//Comprobar si tiene liquido la botella
void noVacio(int& eleccion, char table[ROWS][COLUMNS]) {
	int num = 0;
	int numLiq1 = 0;
	int numLiq2 = 0;
	int numLiq3 = 0;
	int numLiq4 = 0;
	int columna = 0;
	bool conLiquido = false;
	if (eleccion == 1) { columna = 1; }
	else if (eleccion == 2) { columna = 5; }
	else if (eleccion == 3) { columna = 9; }
	else if (eleccion == 4) { columna = 13; }
	else if (eleccion == 5) { columna = 17; }
	else if (eleccion == 6) { columna = 21; }

	for (int a = 1; a < ROWS - 2; a++) {
		if (table[a][columna] == ' ') {
			num++;
		}
		else if (table[a][columna] == 'X') {
			numLiq1++;
		}
		else if (table[a][columna] == 'O') {
			numLiq2++;
		}
		else if (table[a][columna] == '#') {
			numLiq3++;
		}
		else if (table[a][columna] == 'S') {
			numLiq4++;
		}
	}

	while (num == 3 || numLiq1 == 3 || numLiq2 == 3 || numLiq3 == 3 || numLiq4 == 3) {
		std::cout << "Esta vacia la botella o esta llena hasta arriba del mismo liquido\n";
		num = 0; numLiq1 = 0; numLiq2 = 0; numLiq3 = 0; numLiq4 = 0;
		elegirVaciar(eleccion, table);
	}
}
//Comprobar si está vacia la botella o parcialmente vacia
void comprobarLlena(int& eleccion2, int& eleccion, char table[ROWS][COLUMNS]) {
	while (eleccion == eleccion2) {
		std::cout << "No elijas la misma botella, ty\n";
		elegirLlenar(eleccion2, eleccion, table);
	}

	int num = 0;
	int nume = 0;

	int columna = 0;
	bool conLiquido = false;
	if (eleccion2 == 1) { columna = 1; }
	else if (eleccion2 == 2) { columna = 5; }
	else if (eleccion2 == 3) { columna = 9; }
	else if (eleccion2 == 4) { columna = 13; }
	else if (eleccion2 == 5) { columna = 17; }
	else if (eleccion2 == 6) { columna = 21; }

	for (int a = 1; a < ROWS - 2; a++) {
		if (table[a][columna] != ' ') {
			num++;
		}
	}
	while (num == 3) {
		std::cout << "Esta llena la botella\n";
		num = 0;
		elegirLlenar(eleccion2, eleccion, table);
	}
	num = 0;
}