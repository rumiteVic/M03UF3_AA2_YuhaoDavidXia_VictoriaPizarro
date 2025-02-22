#include <iostream>
#define ROWS 6
#define COLUMNS 23
void puntuacio(char table[ROWS][COLUMNS], int& turnos, int &turnos2, bool &salimos, bool &partida, bool &forzado) {
	int columna = 0;
	int vacio = 0;
	int canIgual = 0;
	std::string name;
	int dif = 0;
	bool completa = false;
	bool voids = false;
	int win = 0;
	char liq;
	int score = 0;

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
	if (win == 6 || forzado) {
		int turnPoints = 3;
		int cantidad = 3 * turnos2;
		score += cantidad;
		turnos2 = 0;
	}
	if ( partida || forzado) {
		std::cout << "You won!!! Your score is: " << score << "----> Enter your name: ";
		std::cin >> name;
	}
	win = 0;
}