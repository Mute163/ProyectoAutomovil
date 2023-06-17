#include <iostream>
using namespace std;

class Luces {
private:
    bool encendidas;

public:
    Luces() : encendidas(false) {}

    void prender() {
        encendidas = true;
        cout << "Las luces han sido prendidas." << endl;
    }

    void apagar() {
        encendidas = false;
        cout << "Las luces han sido apagadas." << endl;
    }

    bool getEstado() const {
        return encendidas;
    }
    
};
