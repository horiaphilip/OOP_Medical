#include "doctor.h"
#include <iostream>

Doctor::Doctor(const std::string& _nume, const std::string& _specializare, const std::string& _cod) : nume(_nume), specializare(_specializare) , cod(_cod) {}
Doctor::~Doctor() {

}
const std::string& Doctor::getNume() const {
    return nume;
}

const std::string& Doctor::getSpecializare() const {
    return specializare;
}

const std::string& Doctor::getCod() const {
    return cod;
}
