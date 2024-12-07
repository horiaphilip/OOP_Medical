#pragma once

#include "pacient.h"
#include "doctor.h"
#include <string>
#include <iostream>

class Programare {
private:
    Pacient pacient;
    Doctor doctor;
    std::string data;

public:
    Programare(const Pacient& _pacient, const Doctor& _doctor, const std::string& _data);
    ~Programare();
    const Pacient& getPacient() const;
    const Doctor& getDoctor() const;
    const std::string& getData() const;
    //Programare(const Programare& copie);
    Programare& operator=(const Programare& copie);
    void setData(const std::string& _data);
};

