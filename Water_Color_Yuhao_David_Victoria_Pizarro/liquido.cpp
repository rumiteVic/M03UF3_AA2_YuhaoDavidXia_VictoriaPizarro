#include <iostream>
#include "elegirVaciar.h"
#define ROWS 6
#define COLUMNS 23
void liquido(int &eleccion, int &eleccion2, char table[ROWS][COLUMNS], bool &completado) {
	int columna = 0;
	if (eleccion == 1) { columna = 1; }
	else if (eleccion == 2) { columna = 5; }
	else if (eleccion == 3) { columna = 9; }
	else if (eleccion == 4) { columna = 13; }
	else if (eleccion == 5) { columna = 17; }
	else if (eleccion == 6) { columna = 21; }

	int columna2 = 0;
	if (eleccion2 == 1) { columna2 = 1; }
	else if (eleccion2 == 2) { columna2 = 5; }
	else if (eleccion2 == 3) { columna2 = 9; }
	else if (eleccion2 == 4) { columna2 = 13; }
	else if (eleccion2 == 5) { columna2 = 17; }
	else if (eleccion2 == 6) { columna2 = 21; }

	int cantidadDar = 0;
	int cantidadRecibir = 0;
	bool poderVaciar = false;

	char liqDar;
	char liqRec;

	//Con eleccion 1 miramos la botella a vaciar
	//Miramos cual es su ultimo liquido y lo ponemos en un char (lo hacemos con un for y en cuanto tengamos el liquido le hacemos un break
	//Hacemos otro for pero esta vez contamos cuanto de ese liquido tiene (imposible tener 3)
	//Ultimo liquido
	for (int a = 1; a < ROWS - 2; a++) {
		if (table[a][columna] != ' ') {
			liqDar = table[a][columna];
			break;
		}
	}
	for (int a = 1; a < ROWS - 2; a++) {
		if (table[a][columna] == liqDar) {
			cantidadDar++;
		}
	}


	//Con eleccion 2 miramos cual es el ultimo liquido
	//Comprobamos si son el mismo liquido o no
	for (int a = 1; a < ROWS - 2; a++) {
		if (table[a][columna2] != ' ') {
			liqRec = table[a][columna2];
			break;
		}
		else if (table[3][columna2] == ' ') {
			liqRec = table[3][columna2];
		}
	}
	for (int a = 1; a < ROWS - 2; a++) {
		if (table[a][columna2] == ' ') {
			cantidadRecibir++;
		}
	}
	//Comprobamos si se puede o no vertir el liquido
	if (liqRec == ' ') {
		poderVaciar = true;
		completado = true;
	}
	else if (liqDar == liqRec) {
		poderVaciar = true;
		completado = true;
	}
	else if (!poderVaciar) {
		elegirLlenar(eleccion2, eleccion, table);
	}
	//std::cout << "liquido a dar " << liqDar << " cantidadDar " << cantidadDar << "\n";
	//std::cout << "ultimo liquido " << liqRec << " cantidadARecibir " << cantidadRecibir << "\n";

	if (cantidadRecibir < cantidadDar) {
		cantidadDar = cantidadRecibir;
	}
	std::cout << cantidadRecibir << "    " << cantidadDar;
	//Vaciamos botella
	for (int a = 1; a < cantidadDar; a++) {
		table[a][columna] = ' ';
	}
	//Llenamos botella
	for (int a = 1; a < cantidadRecibir; a++) {
		table[a][columna2] = liqDar;
	}
	//Miramos cuanto espacio hay desdel liquido hasta la ultima fila donde podemos poner el liquido
	//Miramos los espacios en blanco y los espacios que podemos dar, si espacios en blanco de recibir >= espacios a dar		== ta bien
	//Si espacios en blanco < espacios a dar entonces	espacios a dar = blanco
	//Y con eso hacemos los respectivos fors para poner los valores y rezar de que esto no sea imposible hahaha, matenme okno
}