/*
* Autor: Cesar Ulises Miranda Ortega 
* Representa un simulador de automovil 
* Declaracion de la clase 
* Matricula. A01750481
*/
#include <iostream>
#include "Llanta.h"
#include "Luces.h"
#include "TanqueGas.h"
using namespace std;
class Automovil {
private:
    bool encendido;
    int velocidad;
    TanqueGas tanqueGas;
    Luces luces;
    Llanta llantas[4];
    const double presionNormal = 33.0;

public:
    Automovil() : encendido(false), velocidad(0) {}

    void mostrarTablero() const {
        cout << "----- TABLERO -----" << endl;
        cout << "Estado del automovil: " << (encendido ? "Encendido" : "Apagado") << endl;
        cout << "Velocidad actual: " << velocidad << " km/h" << endl;
        if (velocidad > 160) {
            cout << "Cuidado. Velocidad alta." << endl;
        }
        cout << "Nivel de gasolina: " << tanqueGas.getNivelGasolina()<< " litros" << endl;
        if (tanqueGas.getNivelGasolina() <= 0.15 * tanqueGas.getCapacidadTanque()) {
            cout << "Advertencia! Nivel de gasolina bajo. Por favor, llene el tanque." << endl;
        }
        cout << "Las luces estan: " << (luces.getEstado() ? "Prendidas" : "Apagadas") << endl;
        cout << endl;
        cout << "Presion de las llantas:" << endl;
        for (int i = 0; i < 4; i++) {
            double presion = llantas[i].getPresion();
            cout << "Llanta " << (i + 1) << ": " << presion << " psi";
            if (presion < 0.8 * presionNormal || presion > 1.2 * presionNormal) {
                cout << " - ¡Peligro!";
            }
            cout << endl;
        }

    }

    void prenderApagar() {
        encendido = !encendido;
        if (encendido) {
            cout << "El automovil ha sido prendido." << endl;
        } else {
            cout << "El automovil ha sido apagado." << endl;
        }
        cout << endl;
    }

    void acelerar() {
    if (encendido) {
        double nuevaVelocidad = velocidad + 15.0;
        if (nuevaVelocidad <= 230.0) {
            velocidad = nuevaVelocidad;
            tanqueGas.setNivelGasolina(tanqueGas.getNivelGasolina() - 0.005 * velocidad);
            if (tanqueGas.getNivelGasolina() < 0.0) {
                velocidad = 0;
                tanqueGas.setNivelGasolina(0.0);
                cout << "El automovil se quedo sin gasolina. Se ha detenido." << endl;
            } else {
                cout << "Acelerando... Velocidad actual: " << velocidad << " km/h." << endl;
            }
        } else {
            cout << "No es posible acelerar mas. Velocidad maxima alcanzada." << endl;
        }
    } else {
        cout << "El automovil esta apagado. No se puede acelerar." << endl;
    }
    cout << endl;
}


    void frenar() {
        if (encendido) {
            if (velocidad >= 25) {
                velocidad -= 25;
            } else {
                velocidad = 0;
            }
            cout << "El automovil ha frenado. Velocidad actual: " << velocidad << " km/h" << endl;
        } else {
            cout << "El automovil esta apagado. Enciendelo para poder frenar." << endl;
        }
        cout << endl;
    }
    void cargarGasolina(double litros) {
        tanqueGas.cargarGasolina(litros);
    }

    void inflarDesinflarLlanta(int numeroLlanta, double nuevaPresion) {
    if (numeroLlanta >= 1 && numeroLlanta <= 4) {
        llantas[numeroLlanta - 1].setPresion(nuevaPresion);
        cout << "La llanta " << numeroLlanta << " ha sido inflada/desinflada a " << nuevaPresion << " psi." << endl;
        
        // Verificar el estado de la llanta actualizada
        if (llantas[numeroLlanta - 1].estaEnEstadoDePeligro()) {
            cout << "La llanta " << numeroLlanta << " esta en estado de peligro." << endl;
        } else {
            cout << "La llanta " << numeroLlanta << " esta en estado normal." << endl;
        }
    } else {
        cout << "Numero de llanta invalido. Debe ser un valor entre 1 y 4." << endl;
    }
    cout << endl;
    }

    void prenderLuces() {
        if (encendido) {
            luces.prender();
        } else {
            cout << "El automovil esta apagado. Enciendelo para poder prender las luces." << endl;
        }
        cout << endl;
    }

    void apagarLuces() {
        luces.apagar();
        cout << endl;
    }
};
