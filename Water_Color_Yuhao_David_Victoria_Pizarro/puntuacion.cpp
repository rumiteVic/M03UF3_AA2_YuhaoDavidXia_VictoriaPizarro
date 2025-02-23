#include <iostream>
#include "guardarPartida.h"
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

	for (int eleccion = 1; eleccion <= 6; eleccion++) {		//Comprobación de todas las botellas y de lo que tiene
		if (eleccion == 1) { columna = 1; }
		else if (eleccion == 2) { columna = 5; }
		else if (eleccion == 3) { columna = 9; }
		else if (eleccion == 4) { columna = 13; }
		else if (eleccion == 5) { columna = 17; }
		else if (eleccion == 6) { columna = 21; }

		for (int a = 1; a < ROWS - 2; a++) {	//Comprobamos el liquido que tiene (si es que tiene)
			if (table[a][columna] != ' ') {
				liq = table[a][columna];
				break;
			}
			else if (table[a][columna] == ' ') {	//Comprobamos si está completamente vacía la botella
				vacio++;
				liq = table[a][columna];
			}
		}
		if (vacio == 3) { voids = true; completa = true; }	//Si esta vacia no comprobamos nada más
		if (!voids) {
			for (int a = 1; a < ROWS - 2; a++) {	//Comprobamos si está llenada del todo la botella con el mismo liquido (3)
				if (table[a][columna] == liq) {
					canIgual++;
				}
			}
		}
		if (canIgual == 3) { completa = true; }		//Si está llena del todo dejamos de comprobar lo de abajo
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
		if (vacio == 3) {	//Esta vacio +50
			win++;
			score += 50;
		}
		else if (canIgual == 3) {	//Esta llena de lo mismo +30
			win++;
			score += 30;
		}
		else if (dif < 1) {			//Esta llena de lo mismo +30
			win++;
			score += 30;
		}
		vacio = 0;		//Reiniciamos esto para la siguiente botella
		canIgual = 0;
		voids = false;
		completa = false;
	}
	if (win == 6 || forzado) {	//Si hemos ganado o forzado a terminar, contamos la puntuacion final
		int turnPoints = 3;
		if(forzado)int cantidad = 3 * turnos2;	//si hemos forzado contamos los turnos restantes con turnos2 (turnos es 0 para acabar la partida)
		int cantidad = 3 * turnos;				//Si no hemos forzado contamos los turnos que tenga restantes
		score += cantidad;						//Les sumamos los puntos
		turnos2 = 0;
		turnos = 0;
		std::cout << "You won!!! Your score is: " << score << "----> Enter your name: ";
		std::cin >> name;	//Ponemos nombre
		guardarPartida(name, score);
	}
	win = 0;
}