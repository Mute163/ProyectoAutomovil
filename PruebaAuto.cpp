#include <iostream>
#include "Automovil.h"
using namespace std;
int main() {
    Automovil carro;

    int opcion;
    do {
        carro.mostrarTablero();

        cout << "_______MENU_______" << endl;
        cout << "1. Prender/Apagar el auto" << endl;
        cout << "2. Acelerar" << endl;
        cout << "3. Frenar" << endl;
        cout << "4. Cargar gasolina" << endl;
        cout << "5. Inflar/Desinflar llanta" << endl;
        cout << "6. Prender luces" << endl;
        cout << "7. Apagar luces" << endl;
        cout << "8. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

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
                cout << "Ingrese la cantidad de litros a cargar: ";
                cin >> litros;
                carro.cargarGasolina(litros);
                break;
            }
            case 5: {
                int numeroLlanta;
                double nuevaPresion;
                cout << "Ingrese el numero de la llanta (1-4): ";
                cin >> numeroLlanta;
                cout << "Ingrese la nueva presión de la llanta: ";
                cin >> nuevaPresion;
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
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }

    } while (opcion != 8);

    return 0;
}
