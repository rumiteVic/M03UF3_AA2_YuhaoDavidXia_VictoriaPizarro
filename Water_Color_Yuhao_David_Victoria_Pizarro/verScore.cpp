#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//Menu de mirar nuestro score
void verScore() {
	char caracter;
	std::cout << "------ HIGHSCORES ------\n";
	std::ifstream readFile;
	std::vector<std::string> name;
	std::vector<int>score;
	std::string line;
	int num;
	readFile.open("scores.wcs", std::ios::in | std::ios::binary);
	if (!readFile.is_open()) {
		std::cout << "Error de apertura de archivo\n";
	}
	while (readFile.is_open()) {	//Abrimos archivo con el score
		size_t readSize;
		readFile.read(reinterpret_cast<char*>(&readSize), sizeof(size_t));	//Miramos el tamaño del string
		char* temp = new char[readSize + 1];	//Le ponemos a una string nueva que tenga ese tamaño
		readFile.read(temp, readSize);			//Leemos lo que pone y el tamaño
		temp[readSize] = '\0';				//Le ponemos un caracter nulo para terminar el string
		line = temp;						//Le pasamos el string a otro string, por si acaso
		name.push_back(line);				//Lo pasamos a un vector
		delete[] temp;						//Eliminamos el temporal
		readFile.read(reinterpret_cast<char*>(&num), sizeof(int));	//Traducimos a normal la cantidad numerica de puntos
		score.push_back(num);	//Lo pasamos a un vector
		if (readFile.eof()) {	//Si llegamos al final del archivo lo cerramos
			readFile.close();
		}
	}	
	for (int a = 0; a < name.size() -1; a++) {	//Imprimimos en la pantalla el score (pone -1) debido a que se imprime algo con el valor \0
		std::cout << name[a] << ": " << score[a] << "\n";
	}

	std::cout << "Press any key to continue . . .\n";
	std::cin >> caracter;	//Presionamos tecla y enter y se acaba de los score
}