#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "noVacio.h"
#include "elegirVaciar.h"
#include "liquido.h"
#include "eleccionMenu.h"
#include "puntuacion.h"
#include "verScore.h"
#define ROWS 6
#define COLUMNS 23

// Función para inicializar el tablero con líquidos aleatorios
void tableroInicio(char table[ROWS][COLUMNS]) {
    char contraBarra = 92;
    char barra = 47;
    char comilla = 39;
    char num = 49;
    char liquidos[] = { 'X', 'O', '#', 'S' };
    int Score = 0;
    std::srand(std::time(0));

    // Llenar el tablero de espacios en blanco
    for (int a = 0; a < ROWS; a++) {
        for (int b = 0; b < COLUMNS; b++) {
            table[a][b] = ' ';
        }
    }

    // Tapa
    for (int b = 0; b < COLUMNS; b += 4) {
        table[0][b] = contraBarra;
    }
    for (int b = 2; b < COLUMNS; b += 4) {
        table[0][b] = barra;
    }

    // Cuerpo botella
    for (int a = 1; a < ROWS - 2; a++) {
        for (int b = 0; b < COLUMNS; b += 2) {
            table[a][b] = '|';
        }
    }

    // Parte final botella
    for (int a = 0; a < COLUMNS; a++) {
        table[4][a] = comilla;
    }
    for (int a = 3; a < COLUMNS; a += 4) {
        table[4][a] = ' ';
    }
    for (int a = 1; a < COLUMNS; a += 4) {
        table[5][a] = num;
        num++;
    }

    // Llenar las botellas con líquidos aleatorios
    std::vector<char> distribucion;
    for (int i = 0; i < ((COLUMNS / 4) * 2) + 2; i++) {
        distribucion.push_back(liquidos[i % 4]);
    }

    // Asignar líquidos a las botellas de manera aleatoria
    for (int b = 1; b < COLUMNS; b += 4) {
        if (b < COLUMNS) {
            // Asignar líquido a la posición inferior
            if (!distribucion.empty()) { // Verificar que el vector no esté vacío
                int randomIndex = std::rand() % distribucion.size();
                table[3][b] = distribucion[randomIndex];
                distribucion.erase(distribucion.begin() + randomIndex);
            }

            // Asignar líquido a la posición superior inferior
            if (!distribucion.empty()) { // Verificar que el vector no esté vacío
                int randomIndex = std::rand() % distribucion.size();
                table[2][b] = distribucion[randomIndex];
                distribucion.erase(distribucion.begin() + randomIndex);
            }
        }
    }

    // Escoger dos botellas aleatorias para llenar la posición superior
    for (int i = 0; i < 2; i++) {
        int randBottle = (std::rand() % (COLUMNS / 4)) * 4 + 1;
        if (randBottle < COLUMNS) {
            table[1][randBottle] = liquidos[std::rand() % 4];
        }
    }
}

// Imprimimos el tablero
void imprimirTablero(char table[ROWS][COLUMNS]) {
    for (int a = 0; a < ROWS; a++) {
        for (int b = 0; b < COLUMNS; b++) {
            std::cout << table[a][b];
        }
        std::cout << "\n";
    }
}

// Menú principal
void menu(char table[ROWS][COLUMNS], bool& partida, bool& salimos, int& turnos) {
    int eleccion = 0;
    std::cout << "------WATER COLOUR SORT-----\n";
    std::cout << "\t1 - Nova partida\n";
    std::cout << "\t2 - Scores\n";
    std::cout << "\t3 - Sortir\n";
    std::cout << "\tDecision: ";
    while (eleccion < 1 || eleccion > 3) {
        std::cin >> eleccion;
    }
    switch (eleccion) {
    case 1:
        std::cout << "Generant nova partida\n";
        partida = true;
        salimos = false;
        turnos = 10;
        tableroInicio(table);
        break;
    case 2:
        std::cout << "Buscant i imprimint en la pantalla la puntuacio\n";
        verScore();
        break;
    case 3:
        std::cout << "Sortint\n";
        partida = false;
        salimos = true;
        break;
    }
}

int main() {
    char table[ROWS][COLUMNS];
    int eleccion = 0, eleccion2 = 0, turnos = 10, turnos2;
    bool completado = false, forzado = false, salimos = false, partida = false;

    while (!salimos) {
        menu(table, partida, salimos, turnos);
        if (partida) {
            while (turnos > 0) {
                completado = false;
                imprimirTablero(table);
                elegirMenu(eleccion, table, turnos, salimos, partida, turnos2);
                if (partida) {
                    elegirLlenar(eleccion2, eleccion, table);
                    liquido(eleccion, eleccion2, table, completado);
                    if (completado) turnos--;
                    puntuacio(table, turnos, turnos2, salimos, partida, forzado);
                }
                else {
                    forzado = true;
                    puntuacio(table, turnos, turnos2, salimos, partida, forzado);
                }
                std::cout << "Turnos restantes: " << turnos << "\n";
            }
        }
    }
    std::cout << "Adeu!";
    return 0;
}
