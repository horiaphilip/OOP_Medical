#pragma once

#include <iostream>
#include <string>
#include "clinica.h" // Presupunem că avem o clasă Clinica care gestionează programările și datele

class PanouComanda {
private:
    bool esteDoctor;

public:
    PanouComanda();

    void afisareMeniu();
    void procesareOptiune(int optiune);
    void afisareMeniuDoctor();
    void afisareMeniuPacient();
    void executare();
};
