#pragma once

#include <iostream>
#include <string>

class Doctor {
private:
    std::string nume;
    std::string specializare;
    std::string cod;

public:
    Doctor(const std::string& _nume, const std::string& _specializare, const std::string& _cod);
    ~Doctor();
    const std::string& getNume() const;
    const std::string& getSpecializare() const;
    const std::string& getCod() const;
};
