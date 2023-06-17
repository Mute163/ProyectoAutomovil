#include <iostream>
#include "Automovil.h"
using namespace std;
int main() {
    Automovil carro;

    int opcion;
    do {
        carro.mostrarTablero();

        std::cout << "_______MENU_______" << std::endl;
        std::cout << "1. Prender/Apagar el auto" << std::endl;
        std::cout << "2. Acelerar" << std::endl;
        std::cout << "3. Frenar" << std::endl;
        std::cout << "4. Cargar gasolina" << std::endl;
        std::cout << "5. Inflar/Desinflar llanta" << std::endl;
        std::cout << "6. Prender luces" << std::endl;
        std::cout << "7. Apagar luces" << std::endl;
        std::cout << "8. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                carro.prenderApagar();
                break;
            case 2:
                carro.acelerar();
                break;
            case 3:
                carro.frenar();
                break;
            case 4: {
                double litros;
                std::cout << "Ingrese la cantidad de litros a cargar: ";
                std::cin >> litros;
                carro.cargarGasolina(litros);
                break;
            }
            case 5: {
                int numeroLlanta;
                double nuevaPresion;
                std::cout << "Ingrese el numero de la llanta (1-4): ";
                std::cin >> numeroLlanta;
                std::cout << "Ingrese la nueva presión de la llanta: ";
                std::cin >> nuevaPresion;
                carro.inflarDesinflarLlanta(numeroLlanta, nuevaPresion);
                break;
            }
            case 6:
                carro.prenderLuces();
                break;
            case 7:
                carro.apagarLuces();
                break;
            case 8:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo." << std::endl;
                break;
        }

    } while (opcion != 8);

    return 0;
}
