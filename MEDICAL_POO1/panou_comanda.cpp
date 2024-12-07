#include "panou_comanda.h"
#include "clinica.h"
#include <iostream>

PanouComanda::PanouComanda() : esteDoctor(false) {}

void PanouComanda::afisareMeniu()
{
    std::cout << "Bine ati venit la Clinica Medicala!\n";
    std::cout << "1. Sunt doctor\n";
    std::cout << "2. Sunt pacient\n";
    std::cout << "0. Iesire\n";
    std::cout << "Alegeti optiunea: ";
}

void PanouComanda::procesareOptiune(int optiune)
{
    if (optiune == 1)
    {
        afisareMeniuDoctor();
    }
    else if (optiune == 2)
    {
        afisareMeniuPacient();
    }
    else if (optiune == 0)
    {
        std::cout << "La revedere!\n";
    }
    else
    {
        std::cout << "Optiune invalida. Va rugam sa alegeti o optiune valida.\n";
    }
}

void PanouComanda::afisareMeniuDoctor()
{

    std::string codSecuritate;
    std::cout << "Introduceti codul de securitate: ";
    std::cin >> codSecuritate;

   // for (const Doctor& doctor : clinica.doctori)
        /*if(doctor.getCod()==codSecuritate)
        {
            esteDoctor = true;
            std::cout << "1. Afiseaza programarile dintr-o anumita zi\n";
            std::cout << "0. Iesire\n";
            std::cout << "Alegeti optiunea: ";


        }*/
//        std::cout<<doctor.getNume();


}

void PanouComanda::afisareMeniuPacient()
{
    std::cout << "1. Faceti o programare la un doctor intr-o anumita zi\n";
    std::cout << "0. Iesire\n";
    std::cout << "Alegeti optiunea: ";
}

void PanouComanda::executare()
{
    int optiune;
    do
    {
        afisareMeniu();
        std::cin >> optiune;
        procesareOptiune(optiune);
    }
    while (optiune != 0);
}
