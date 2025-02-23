#include <iostream>
#include "noVacio.h"
#define ROWS 6
#define COLUMNS 23

//Funció per buidar una ampolla
void elegirVaciar(int& eleccion, char table[ROWS][COLUMNS]) {
	eleccion = 0;
	std::cout << "Elige una botella con liquido\n";
	while (eleccion < 1 || eleccion > 6) {
		std::cin >> eleccion;
	}
	std::cout << "Has seleccionado la botella: " << eleccion << " \n";
	noVacio(eleccion, table);
}
//Funció per omplir una ampolla
void elegirLlenar(int& eleccion2, int& eleccion, char table[ROWS][COLUMNS]) {
	eleccion2 = 0;
	bool puedes = false;
	std::cout << "Elige una botella poco liquido o vacia\n";
	while (eleccion2 < 1 || eleccion2 > 6) {
		std::cin >> eleccion2;
	}
	std::cout << "Has seleccionado la botella: " << eleccion2 << " \n";
	comprobarLlena(eleccion2, eleccion, table);
}