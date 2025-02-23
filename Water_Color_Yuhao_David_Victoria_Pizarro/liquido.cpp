#include <iostream>
#include "elegirVaciar.h"
#define ROWS 6
#define COLUMNS 23

//Pasem liquids entre ampolles
void liquido(int& eleccion, int& eleccion2, char table[ROWS][COLUMNS], bool& completado) {
	int columna = 0;
	if (eleccion == 1) { columna = 1; }			//Això és per fer més fàcil el bucle i no repetir-ho 12 vegades
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

	bool poderVaciar = false;	
	int cantidadDar = 0;
	int cantidadRec = 0;
	int puesto = 0;
	char liqDar;
	char liqRec;

	for (int a = 1; a < ROWS - 2; a++) {		//Busquem l'ultim liquid de l'ampolla a buidar
		if (table[a][columna] != ' ') {
			liqDar = table[a][columna];
			break;
		}
	}
	for (int a = 1; a < ROWS - 2; a++) {		//Busquem la quantitat que té d'aquest líquid
		if (table[a][columna] == liqDar) {
			cantidadDar++;
		}
		if ((table[2][columna] != liqDar && table[2][columna] != ' ') && table[3][columna] == liqDar) {	//Si hay por ejemplo una botella de SOS, evitaremos dar un liquido extra del de abajo del todo
			break;
		}
	}
	//Con eleccion 2 miramos cual es el ultimo liquido de la botella a llenar
	for (int a = 1; a < ROWS - 2; a++) {
		if (table[a][columna2] != ' ') {
			liqRec = table[a][columna2];
			break;
		}
		else if (table[3][columna2] == ' ') {	//Si no hay nada le ponemos un espacio en blanco
			liqRec = table[3][columna2];
		}
	}
	for (int a = 1; a < ROWS - 2; a++) {	//Comprobamos espacios vacios
		if (table[a][columna2] == ' ') {
			cantidadRec++;
		}
	}
	//Modificamos lo que puede recibir o dar, dependiendo de cuanto podemos dar o recibir
	if (cantidadDar > cantidadRec) {
		cantidadDar = cantidadRec;
	}
	else if (cantidadDar < cantidadRec) {
		cantidadRec = cantidadDar;
	}

	//Comprobamos si se puede o no vertir el liquido
	if (liqRec == ' ') {
		poderVaciar = true;
		completado = true;
		liqRec = liqDar;
	}
	else if (liqDar == liqRec) {
		poderVaciar = true;
		completado = true;
	}
	else if (!poderVaciar) {
		elegirLlenar(eleccion2, eleccion, table);
	}

	//Vaciamos botella
	for (int a = 1; a < ROWS - 2 && puesto < cantidadDar; a++) {
		if (table[a][columna] == liqDar) {
			table[a][columna] = ' ';
			puesto++;
		}
	}
	puesto = 0;

	//Llenamos botella
	for (int a = 3; a >= 1 && puesto < cantidadRec; a--) {
		if (table[a][columna2] == ' ') {
			table[a][columna2] = liqRec;
			puesto++;
		}
	}
}