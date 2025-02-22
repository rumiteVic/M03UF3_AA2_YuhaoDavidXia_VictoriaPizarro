#include <iostream>
#include "noVacio.h"
#include "elegirVaciar.h"
#include "liquido.h"
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
	for (int a = 1; a < ROWS -2; a++) {
		for (int b = 0; b < COLUMNS; b = b +2) {
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
	table[2][13] = 'O';
	table[1][13] = 'S';
	table[3][5] = 'S';

}

void imprimirTablero(char table[ROWS][COLUMNS]) {
	for (int a = 0; a < ROWS; a++) {
		for (int b = 0; b < COLUMNS; b++) {
			std::cout << table[a][b];
		}
		std::cout << "\n";
	}
}


void main() {

	char table[ROWS][COLUMNS];
	int eleccion = 0;
	int eleccion2 = 0;
	int turnos = 10;
	while (turnos > 0) {
		tableroInicio(table);
		imprimirTablero(table);
		elegirVaciar(eleccion,  table);	//Elige la botella con liquido a vaciar
		elegirLlenar(eleccion2, eleccion, table);
		liquido(eleccion, eleccion2, table);
		turnos--;
		std::cout << "Turnos restantes: " << turnos << "\n";
	}
}