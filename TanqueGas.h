/*
* Autor: Cesar Ulises Miranda Ortega 
* Representa un simulador de automovil 
* Declaracion de la clase 
* Matricula. A01750481
*/

#include <iostream>
using namespace std;
class TanqueGas {
private:
    double gasolina;
    const double capacidadTanque = 42.0;

public:
    TanqueGas() : gasolina(42) {}

    double getNivelGasolina() const {
        return gasolina;
    }

    void setNivelGasolina(double nivel) {
        gasolina = nivel;
    }

    void cargarGasolina(double litros) {
        double espacioLibre = capacidadTanque - gasolina;
        if (litros > 0) {
            if (litros <= espacioLibre) {
                gasolina += litros;
                cout << "Se han cargado " << litros << " litros de gasolina." << endl;
            } else {
                gasolina = capacidadTanque;
                cout << "El tanque esta lleno. No se pueden cargar ma8s litros." << endl;
            }
        } else {
            cout << "La cantidad de litros a cargar debe ser mayor a cero." << endl;
        }
        cout << endl;
    }

    double getCapacidadTanque() const {
        return capacidadTanque;
    }
};