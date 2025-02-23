#include <iostream>
#include <fstream>
void guardarPartida(std::string &name, int &score) {
	size_t size = name.size();
	std::ofstream out("scores.wcs", std::ios::out | std::ios::app | std::ios::binary);
	if (!out.is_open()) {
		std::cout << "Error de apertura de archivo\n";
	}
	out.write(reinterpret_cast<char*>(&size), sizeof(size_t));	//Pasem a binari la llargada del string
	out.write(name.c_str(), sizeof(char) * size);				//Pasem a binari el string
	out.write(reinterpret_cast<char*>(&score), sizeof(int));	//Pasem a binari la puntuació
	out.close();

}