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

void puntuacio(char table[ROWS][COLUMNS], int &score, int &turnos) {
	int columna = 0;
	int vacio = 0;
	int canIgual = 0;
	int dif = 0;
	bool completa = false;
	bool voids = false;
	int win = 0;
	char liq;

	for (int eleccion = 1; eleccion <= 6; eleccion++) {
		if (eleccion == 1) { columna = 1; }
		else if (eleccion == 2) { columna = 5; }
		else if (eleccion == 3) { columna = 9; }
		else if (eleccion == 4) { columna = 13; }
		else if (eleccion == 5) { columna = 17; }
		else if (eleccion == 6) { columna = 21; }

		for (int a = 1; a < ROWS - 2; a++) {
			if (table[a][columna] != ' ') {
				liq = table[a][columna];
				break;
			}
			else if (table[a][columna] == ' ') {
				vacio++;
				liq = table[a][columna];
			}
		}
		if (vacio == 3) { voids = true; completa = true; }
		if (!voids) {
			for (int a = 1; a < ROWS - 2; a++) {
				if (table[a][columna] == liq) {
					canIgual++;
				}
			}
		}
		if (canIgual == 3) { completa = true; }
		if (!completa) {
			for (int a = 1; a < ROWS - 2; a++) {
				if (table[a][columna] != ' ') {
					liq = table[a][columna];  // Asignamos el primer líquido encontrado
					break;
				}
			}
			for (int a = 1; a < ROWS - 2; a++) {
				if (table[a][columna] != ' ' && table[a][columna] != liq) {
					dif++;  // Solo cuenta si es un líquido diferente, evitando contar espacios vacíos
				}
			}
		}
		if (vacio == 3) {
			win++;
			score += 50;			
		}
		else if (canIgual == 3) {
			win++;
			score += 30;
		}
		else if (dif < 1) {
			win++;
			score += 30;
		}
		vacio = 0;
		canIgual = 0;
		voids = false;
		completa = false;
	}
	if (win != 6 && turnos != 0) {
		score = 0;
	}
	if (win == 6) {
		int turnPoints = 3;
		int cantidad = 3 * turnos;
		score += cantidad;
		turnos = 0;
	}
	std::cout << win << "\n";
	win = 0;
}

void main() {

	char table[ROWS][COLUMNS];
	int eleccion = 0;
	int eleccion2 = 0;
	int turnos = 10;
	bool completado = false;
	int score = 0;
	std::string name;
	tableroInicio(table);
	while (turnos > 0) {
		completado = false;
		imprimirTablero(table);
		elegirVaciar(eleccion, table);	//Elige la botella con liquido a vaciar
		elegirLlenar(eleccion2, eleccion, table);
		liquido(eleccion, eleccion2, table, completado);
		if (completado)turnos--;
		puntuacio(table, score, turnos);
		std::cout << "Turnos restantes: " << turnos << "\n";
	}
	std::cout << "You won!!! Your score is: " << score << "----> Enter your name: ";
	std::cin >> name;
}