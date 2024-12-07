#include "programare.h"
#include <iostream>

Programare::Programare(const Pacient& _pacient, const Doctor& _doctor, const std::string& _data)
    : pacient(_pacient), doctor(_doctor), data(_data) {}
Programare::~Programare(){}
const Pacient& Programare::getPacient() const {
    return pacient;
}

const Doctor& Programare::getDoctor() const {
    return doctor;
}

const std::string& Programare::getData() const {
    return data;
}

void Programare::setData(const std::string& _data) {
    data = _data;
}

Programare& Programare::operator=(const Programare& copie)
{
    this->data = copie.data;
    return *this;
}
