#include <iostream>
#include "noVacio.h"
#include "elegirVaciar.h"
#include "liquido.h"
#include "eleccionMenu.h"
#include "puntuacion.h"
#define ROWS 6
#define COLUMNS 23

void tableroInicio(char table[ROWS][COLUMNS]) {
	char contraBarra = 92;
	char barra = 47;
	char comilla = 39;
	char num = 49;
	int Score = 0;
	for (int a = 0; a < ROWS; a++) {
		for (int b = 0; b < COLUMNS; b++) {
			table[a][b] = ' ';
		}
	}
#pragma region tablero
	//Tapa
	for (int b = 0; b < COLUMNS; b = b + 4) {
		table[0][b] = contraBarra;
	}
	for (int b = 2; b < COLUMNS; b = b + 4) {
		table[0][b] = barra;
	}
	//Cuerpo botella
	for (int a = 1; a < ROWS - 2; a++) {
		for (int b = 0; b < COLUMNS; b = b + 2) {
			table[a][b] = '|';
		}
	}
	//Parte final botella
	for (int a = 0; a < COLUMNS; a++) {
		table[4][a] = comilla;
	}
	for (int a = 3; a < COLUMNS; a = a + 4) {
		table[4][a] = ' ';
	}
	for (int a = 1; a < COLUMNS; a = a + 4) {
		table[5][a] = num;
		num++;
	}
#pragma endregion
	for (int a = 1; a < ROWS - 2; a++) {
		table[a][1] = 'X';
	}
	table[3][13] = 'O';
	table[2][13] = 'S';
	table[1][13] = 'S';
	table[3][5] = 'S';
	table[2][5] = 'S';
	table[3][21] = 'X';
	table[3][17] = 'O';
	table[2][17] = 'X';
}

void imprimirTablero(char table[ROWS][COLUMNS]) {
	for (int a = 0; a < ROWS; a++) {
		for (int b = 0; b < COLUMNS; b++) {
			std::cout << table[a][b];
		}
		std::cout << "\n";
	}
}

void guardarScore() {

}

void menu(char table[ROWS][COLUMNS], bool &partida, bool &salimos, int &turnos) {
	int eleccion = 0;
	std::cout << "------WATER COLOUR SORT-----\n";
	std::cout << "	1 - Nova partida\n";
	std::cout << "	2 - Scores\n";
	std::cout << "	3 - Sortir\n";
	std::cout << "	Decision: ";
	while (eleccion < 1 || eleccion >3) {
		std::cin >> eleccion;
	}
	switch (eleccion) {
	case 1:
		std::cout << "Generant nova partida\n";
		partida = true;
		salimos = false;
		turnos = 10;
		tableroInicio(table);
		break;
	case 2:
		std::cout << "Buscant i imiprimint en la pantalla la puntuacio\n";
		break;
	case 3:
		std::cout << "Sortint\n";
		partida = false;
		salimos = true;
		break;
	default:
		break;
	}
}

void main() {

	char table[ROWS][COLUMNS];
	int eleccion = 0;
	int eleccion2 = 0;
	int turnos = 10;
	int turnos2;
	bool completado = false;
	bool forzado = false;
	bool salimos = false;
	bool partida = false;
	while (!salimos) {
		menu(table, partida, salimos, turnos);
		if (partida) {

			while (turnos > 0) {
				completado = false;
				imprimirTablero(table);
				elegirMenu(eleccion, table, turnos, salimos, partida, turnos2);	//Elige la botella con liquido a vaciar
				if (partida) {
					elegirLlenar(eleccion2, eleccion, table);
					liquido(eleccion, eleccion2, table, completado);
					if (completado)turnos--;
				}
				else {
					std::cout << "Turnos restantes: " << turnos << "\n";
					forzado = true;
					puntuacio(table, turnos, turnos2, salimos, partida, forzado);
				}
			}
		}
	}
	std::cout << "Adeu!";
}