#include <iostream>
#define ROWS 6
#define COLUMNS 23
void liquido(int &eleccion, int &eleccion2, char table[ROWS][COLUMNS]) {
	
	int cantidadDar = 0;
	int cantidadRecibir = 0;

	char liqDar;
	char liqRec;

	//Guia para continuar, proximamente

	//Con eleccion 1 miramos la botella a vaciar
	//Miramos cual es su ultimo liquido y lo ponemos en un char (lo hacemos con un for y en cuanto tengamos el liquido le hacemos un break
	//Hacemos otro for pero esta vez contamos cuanto de ese liquido tiene (imposible tener 3)

	//Con eleccion 2 miramos cual es el ultimo liquido
	//Comprobamos si son el mismo liquido o no
	// 
	//Si no lo son pues que vuelva a elegir desdel inicio ostia, y si comparamos como X con ' ' pos todo bien hehe
	//Si lo son entonces procedemos
	//
	//Miramos cuanto espacio hay desdel liquido hasta la ultima fila donde podemos poner el liquido
	//Miramos los espacios en blanco y los espacios que podemos dar, si espacios en blanco de recibir >= espacios a dar		== ta bien
	//Si espacios en blanco < espacios a dar entonces	espacios a dar = blanco
	//Y con eso hacemos los respectivos fors para poner los valores y rezar de que esto no sea imposible hahaha, matenme okno

}