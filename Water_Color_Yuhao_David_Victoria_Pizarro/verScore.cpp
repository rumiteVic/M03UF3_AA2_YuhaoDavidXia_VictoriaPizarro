#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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
	while (readFile.is_open()) {
		size_t readSize;
		readFile.read(reinterpret_cast<char*>(&readSize), sizeof(size_t));
		char* temp = new char[readSize + 1];
		readFile.read(temp, readSize);
		temp[readSize] = '\0';
		line = temp;
		name.push_back(line);
		delete[] temp;
		readFile.read(reinterpret_cast<char*>(&num), sizeof(int));
		score.push_back(num);
		if (readFile.eof()) {
			readFile.close();
		}
	}	
	for (int a = 0; a < name.size() -1; a++) {
		std::cout << name[a] << ": " << score[a] << "\n";
	}

	std::cout << "Press any key to continue . . .\n";
	std::cin >> caracter;
}