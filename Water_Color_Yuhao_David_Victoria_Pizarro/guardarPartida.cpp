#include <iostream>
#include <fstream>
void guardarPartida(std::string &name, int &score) {
	size_t size = name.size();
	std::ofstream out("scores.wcs", std::ios::out | std::ios::app | std::ios::binary);
	if (!out.is_open()) {
		std::cout << "Error de apertura de archivo\n";
	}
	out.write(reinterpret_cast<char*>(&size), sizeof(size_t));
	out.write(name.c_str(), sizeof(char) * size);
	out.write(reinterpret_cast<char*>(&score), sizeof(int));
	out.close();

}