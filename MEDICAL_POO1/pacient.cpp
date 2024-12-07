#include "pacient.h"
#include <iostream>

Pacient::Pacient(const std::string& _nume, const std::string& _CNP) : nume(_nume), CNP(_CNP) {}
Pacient::~Pacient(){}
const std::string& Pacient::getNume() const
{
    return nume;
}

const std::string& Pacient::getCNP() const
{
    return CNP;
}

Pacient::Pacient(const Pacient& p)///constr de copiere
:
    nume(p.nume),
    CNP(p.CNP)
    {

    }

std::ostream& operator<<(std::ostream& os, const Pacient& p)
{
    os<<"Pacient: " << p.nume << " - CNP: " << p.CNP<<std::endl;
    return os;
}
