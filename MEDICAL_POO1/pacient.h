#pragma once

#include <iostream>
#include <string>

class Pacient {
private:
    std::string nume;
    std::string CNP;

public:
    Pacient(const std::string& _nume, const std::string& _CNP);
    ~Pacient();
    const std::string& getNume() const;
    const std::string& getCNP() const;
    Pacient(const Pacient& p);
    friend std::ostream& operator<<(std::ostream& os, const Pacient& p);
};

