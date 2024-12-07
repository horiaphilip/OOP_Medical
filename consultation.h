#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


struct Child {};
struct Adult {};
struct Senior {};


template<typename AgeCategory>
class Consultation
{
public:
    void consult(const std::string& medication)
    {
        std::cout << "Este indicat sa consultati un medic pentru prescriptia in legatura cu " << medication;
    }
};


template<>
class Consultation<Child>
{
public:
    void consult(const std::string& medication, const std::unordered_map<std::string, std::pair<std::vector<double>, std::vector<std::string>>>& medicationDatabase)
    {
        auto it = medicationDatabase.find(medication);
        if (it != medicationDatabase.end())
        {
            const std::vector<double>& dosages = it->second.first;
            if (dosages.size() > 0)
            {
                double dosage = dosages[0];
                std::cout << "\nPrescriptia standard pentru " << medication << " la copii este de maxim " << dosage << " mg/zi"<<std::endl;
                std::cout << "Afectiuni in care medicamentul este contraindicat:" << std::endl;
                for (const auto& contraindication : it->second.second)
                {
                    std::cout << "- " << contraindication << std::endl;
                }
            }
            else
            {
                std::cout << "Medication " << medication << " not found in the database." << std::endl;
            }
        }
        else
        {
            std::cout << "Medication " << medication << " not found in the database." << std::endl;
        }
    }
};


template<>
class Consultation<Adult>
{
public:
    void consult(const std::string& medication, const std::unordered_map<std::string, std::pair<std::vector<double>, std::vector<std::string>>>& medicationDatabase)
    {
        auto it = medicationDatabase.find(medication);
        if (it != medicationDatabase.end())
        {
            const std::vector<double>& dosages = it->second.first;
            if (dosages.size() > 1)
            {
                double dosage = dosages[1];
                std::cout << "\nPrescriptia standard pentru " << medication << " la adulti este de maxim " << dosage << " mg/zi"<<std::endl;
                std::cout << "Afectiuni in care medicamentul este contraindicat:" << std::endl;
                for (const auto& contraindication : it->second.second)
                {
                    std::cout << "- " << contraindication << std::endl;
                }
            }
            else
            {
                std::cout << "Medication " << medication << " not found in the database." << std::endl;
            }
        }
        else
        {
            std::cout << "Medication " << medication << " not found in the database." << std::endl;
        }
    }
};

template<>
class Consultation<Senior>
{
public:
    void consult(const std::string& medication, const std::unordered_map<std::string, std::pair<std::vector<double>, std::vector<std::string>>>& medicationDatabase)
    {
        auto it = medicationDatabase.find(medication);
        if (it != medicationDatabase.end())
        {
            const std::vector<double>& dosages = it->second.first;
            if (dosages.size() > 2)
            {
                double dosage = dosages[2];
                std::cout << "\nPrescriptia standard pentru " << medication << " la seniori este de maxim " << dosage << " mg/zi"<<std::endl;
                std::cout << "Afectiuni in care medicamentul este contraindicat:" << std::endl;
                for (const auto& contraindication : it->second.second)
                {
                    std::cout << "- " << contraindication << std::endl;
                }
            }
            else
            {
                std::cout << "Medication " << medication << " not found in the database." << std::endl;
            }
        }
        else
        {
            std::cout << "Medication " << medication << " not found in the database." << std::endl;
        }
    }
};

