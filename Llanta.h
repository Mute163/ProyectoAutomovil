#ifndef Llanta_h
#define Llanta_h
#include <string>
class Llanta {
private:
    double presion; // Presión en psi
    double presionNormal; // Presión normal en psi

public:
    Llanta() : presion(33.0), presionNormal(33.0) {}

    double getPresion() const {
        return presion;
    }

    void setPresion(double nuevaPresion) {
        presion = nuevaPresion;
    }

    double getPresionNormal() const {
        return presionNormal;
    }

    void setPresionNormal(double nuevaPresionNormal) {
        presionNormal = nuevaPresionNormal;
    }

    bool estaEnEstadoDePeligro() const {
        double limiteInferior = presionNormal - (0.2 * presionNormal);
        double limiteSuperior = presionNormal + (0.2 * presionNormal);
        return (presion < limiteInferior || presion > limiteSuperior);
    }

    std::string obtenerEstado() const {
        if (estaEnEstadoDePeligro()) {
            return "Peligro";
        } else {
            return "Normal";
        }
    }
};

# endif