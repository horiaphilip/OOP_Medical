#include <iostream>
#include <vector>
#include <memory>
#include "pacient.h"
#include "doctor.h"
#include "programare.h"
#include "consultation.h"
#include "consultation_factory.h"
class Clinica {
private:
    std::vector<Pacient> pacienti;
    std::vector<Doctor> doctori;
    std::vector<Programare> programari;

    Clinica();


    static std::shared_ptr<Clinica> instance;

public:
    Clinica(const Clinica&) = delete;
    Clinica& operator=(const Clinica&) = delete;

    static std::shared_ptr<Clinica> getInstance() {
        if (instance == nullptr) {
            instance = std::shared_ptr<Clinica>(new Clinica());
        }
        return instance;
    }

    ~Clinica();
    void adaugaPacient(const Pacient& pacient);
    void adaugaDoctor(const Doctor& doctor);
    void programeaza(const Pacient& pacient, const Doctor& doctor, const std::string& data);
    void afiseazaProgramariLaDoctorInZi(const Doctor& doctor, const std::string& data) const;
    void anuleazaProgramareLaDoctorInZi(const Doctor/**<  */& doctor, const std::string& data, const Pacient& pacient);
    void modificaDataPacientLaDoctor(const std::string& data, const Doctor& doctor, const Pacient& pacient);
    void Exec();
    void afisareMeniu();
    void procesareOptiune(int optiune);
    void afisareMeniuDoctor();
    void afisareMeniuPacient();
};

