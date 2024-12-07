#include "clinica.h"
#include <iostream>
#include "consultation_factory.h"
#include <memory>
#include "review.hpp"



Clinica::Clinica()
{
///baza de date a clinicii


    Pacient pacient1("Vasile Marin", "1821124060288");
    Pacient pacient2("Ionescu Laur", "5041130035274");
    Pacient pacient3("Petrescu Ana", "6010624088137");
    Pacient pacient4("Grigore Marius", "1921125060172");
    Pacient pacient5("Ilie Constantin", "5041130060287");

    Doctor doctor1("Dr. Petre Simona", "Cardiologie", "001");
    Doctor doctor2("Dr. Iliescu Anastasia", "Cardiologie", "002");
    Doctor doctor3("Dr. Ciurea Ion", "Pneumologie", "003");
    Doctor doctor4("Dr. Viziru Sebastian", "Radiologie", "004");
    Doctor doctor5("Dr. Sandu Cristian", "Oftalmologie","005");
    Doctor doctor6("Dr. Petre Radu", "Dermatologie","006");
    Doctor doctor7("Dr. Lupu Ion", "Pneumologie","007");

    adaugaPacient(pacient1);
    adaugaPacient(pacient2);
    adaugaPacient(pacient3);
    adaugaPacient(pacient4);
    adaugaPacient(pacient5);
    adaugaDoctor(doctor1);
    adaugaDoctor(doctor2);
    adaugaDoctor(doctor3);
    adaugaDoctor(doctor4);
    adaugaDoctor(doctor5);
    adaugaDoctor(doctor6);
    adaugaDoctor(doctor7);

    programeaza(pacient1, doctor1, "15.04.2024");
    programeaza(pacient1, doctor2, "17.04.2024");
    programeaza(pacient2, doctor1, "15.04.2024");
    programeaza(pacient3, doctor1, "15.04.2024");
    programeaza(pacient4, doctor5, "16.04.2024");
    programeaza(pacient3, doctor7, "18.04.2024");
    programeaza(pacient5, doctor6, "05.04.2024");
    programeaza(pacient5, doctor5, "03.04.2024");
    programeaza(pacient5, doctor1, "01.04.2024");
    programeaza(pacient3, doctor3, "17.04.2024");
    programeaza(pacient1, doctor6, "19.04.2024");
    programeaza(pacient2, doctor4, "20.04.2024");

    Exec();
}

Clinica::~Clinica() {}

void Clinica::adaugaPacient(const Pacient& pacient)
{
    pacienti.push_back(pacient);
}

void Clinica::adaugaDoctor(const Doctor& doctor)
{
    doctori.push_back(doctor);
}

void Clinica::programeaza(const Pacient& pacient, const Doctor& doctor, const std::string& data)
{
    Programare programare(pacient, doctor, data);
    programari.push_back(programare);
}

void Clinica::afiseazaProgramariLaDoctorInZi(const Doctor& doctor, const std::string& data) const
{
    std::cout << "Programarile la " << doctor.getNume() <<" ("<< doctor.getSpecializare() <<")"<< " pentru data de " << data << " sunt:\n";
    bool gasite = false;
    for (const Programare& programare : programari)
    {
        if (programare.getDoctor().getCod() == doctor.getCod() && programare.getData() == data)
        {
            // std::cout << "- Pacient: " << programare.getPacient().getNume() << " CNP: " << programare.getPacient().getCNP() << "\n";
            operator<<(std::cout,programare.getPacient());
            gasite = true;
        }
    }
    if (!gasite)
    {
        std::cout << "Nu exista programari la acest doctor pentru aceasta data.\n";
    }
    std::cout<<"\n";
}

void Clinica::anuleazaProgramareLaDoctorInZi(const Doctor& doctor, const std::string& data, const Pacient& pacient)
{
    bool programareGasita = false;
    for (int i=0; i<programari.size(); i++)
    {
        if (programari[i].getDoctor().getNume() == doctor.getNume() && programari[i].getData() == data && programari[i].getPacient().getCNP() == pacient.getCNP())
        {
            programari.erase(programari.begin()+i);
            // std::cout << "Programarea a fost anulata.\n";
            programareGasita = true;
            break;
        }
    }

    if (!programareGasita)
    {
        std::cout<<"Nu exista o programare la acest doctor pentru aceasta data si acest pacient.\n";
    }
}

void Clinica::modificaDataPacientLaDoctor(const std::string& data, const Doctor& doctor, const Pacient& pacient)
{
    bool gasite=false;
    std::string copie_data;
    for (Programare& programare : programari)
    {
        if (programare.getDoctor().getNume() == doctor.getNume() && programare.getPacient().getCNP() == pacient.getCNP())
        {
            programare.setData(data);
            gasite = true;
        }
    }
    if (!gasite)
    {
        std::cout << "Nu exista programari la acest doctor pentru aceasta data.\n";
    }
}

void Clinica::Exec()
{

    int optiune;
    do
    {
        afisareMeniu();
        std::cin>>optiune;
        procesareOptiune(optiune);
    }
    while (optiune!=0);


}
void Clinica::afisareMeniu()
{
    std::cout<<"\nBine ati venit la Clinica Medicala!\n";
    std::cout<<"1. Sunt doctor\n";
    std::cout<<"2. Sunt pacient\n";
    std::cout<<"0. Iesire\n";
    std::cout<<"Alegeti optiunea: ";
}

void Clinica::procesareOptiune(int optiune)
{
    if (optiune==1)
    {
        afisareMeniuDoctor();
    }
    else if (optiune==2)
    {
        afisareMeniuPacient();
    }
    else if (optiune==0)
    {
        std::cout<<"La revedere!\n";
    }
    else
    {
        std::cout<<"Optiune invalida. Va rugam sa alegeti o optiune valida.\n";
    }
}

void Clinica::afisareMeniuDoctor()
{

    std::string codSecuritate;
    std::cout<<"Introduceti codul de securitate: ";
    std::cin>>codSecuritate;

    for (const Doctor& doctor : doctori)
        if(doctor.getCod()==codSecuritate)
        {
            // esteDoctor = true;
            std::cout<<"\nBine v-am regasit dl/dna "<<doctor.getNume()<<std::endl;
            std::cout << "1. Afiseaza programarile dintr-o anumita zi\n";
            std::cout << "2. Solicitare anulare consultatii\n";
            std::cout << "Alegeti optiunea: ";
            int optiune;
            std::cin>>optiune;

            if(optiune==1)
            {
                std::cout<<"Va rugam introduceti data pentru care doriti sa afisati consultatiile\n";
                std::string data;
                std::cin>>data;
                std::cout<<"\n";
                afiseazaProgramariLaDoctorInZi(doctor,data);

            }
            else if(optiune==2)
            {
                std::cout<<"Va rugam introduceti data pentru care doriti sa va anulati consultatiile\n";
                std::string data;
                std::cin>>data;
                for (Programare& programare : programari)
                    if(programare.getDoctor().getCod()==doctor.getCod()&&programare.getData()==data)
                        anuleazaProgramareLaDoctorInZi(doctor,data,programare.getPacient());
                std::cout<<"Programul a fost eliberat cu succes. Odihna placuta!\n\n";
            }


        }
//        std::cout<<doctor.getNume();


}

void Clinica::afisareMeniuPacient()
{


    std::cout<<"1. Doresc o programare noua\n";
    std::cout<<"2. Vreau sa consult programarile deja existente\n";
    std::cout<<"3. Vreau o consultatie automata cu privire la un medicament accesibil fara reteta\n";
     std::cout<<"4. Lasa o recenzie pentru un doctor\n";
    //std::cout << "0. Iesire\n";
    std::cout<<"Alegeti optiunea: ";

    int optiune;
    std::cin>>optiune;

    std::string nume;
    std::string cnp;
    std::cout<<"Va rugam introduceti datele cu caracter personal:\n";
    std::cout<<" - nume si prenume: ";
    std::getline(std::cin, nume);
    std::getline(std::cin, nume);
    //std::cout<<"\n";
    std::cout<<" - CNP: ";
    std::cin>>cnp;

    if(optiune==1)
    {

        std::cout<<"\nVa rugam sa alegeti un specialist la care doriti sa efectuati o programare:\n";
        for(int i=0; i<doctori.size(); i++)
            std::cout<<i+1<<". "<<doctori[i].getNume()<<" ("<<doctori[i].getSpecializare()<<")\n";
        std::cout<<"Alegeti optiunea: ";
        int doc;
        std::cin>>doc;
        doc--;
        std::cout<<"Introduceti data la care doriti o programare la "<<doctori[doc].getNume()<<" : ";
        std::string data;
        std::cin>>data;
        Pacient pacient(nume,cnp);
        adaugaPacient(pacient);
        programeaza(pacient,doctori[doc],data);
        std::cout<<"\nProgramare efectuata cu succes!\n\n";

    }
    else if(optiune==2)
    {

        bool ok=0;
        for (int i=0; i<programari.size(); i++)
        {
            if(programari[i].getPacient().getCNP()==cnp)
            {
                ok=1;
                std::cout<<" - In data de "<<programari[i].getData()<<" aveti programare la "<<programari[i].getDoctor().getNume()<<"\n";
            }

        }
        if(ok)
        {

            std::cout<<"\n1.Vreau sa imi anulez programarile dintr-o anumita zi\n";
            std::cout<<"2.Vreau sa imi modific data unor programari\n";
            std::cout<<"0.Vreau inapoi la Pagina Principala\n";
            std::cout<<"Alegeti optiunea: ";

            int op;
            std::cin>>op;
            if(op==1)
            {
                std::cout<<"\nVa rugam introduceti data pentru care doriti sa va anulati programarile: ";
                std::string data;
                std::cin>>data;
                for (int i = 0; i < programari.size(); ++i)
                {
                    if(programari[i].getPacient().getCNP()==cnp&&programari[i].getData()==data)
                        anuleazaProgramareLaDoctorInZi(programari[i].getDoctor(),data,programari[i].getPacient());

                }

                std::cout<<"\nProgramarile au fost anulate!\n\n";
            }
            else if(op==2)
            {
                std::cout<<"\nVa rugam introduceti data la care aveati programarile: ";
                std::string data1,data2;
                std::cin>>data1;
                std::cout<<"\nVa rugam introduceti data la care doriti sa fie mutate programarile: ";
                std::cin>>data2;


                for (int i=0; i<programari.size(); i++)
                {
                    if(programari[i].getPacient().getCNP()==cnp&&programari[i].getData()==data1)
                        modificaDataPacientLaDoctor(data2,programari[i].getDoctor(),programari[i].getPacient());

                }

                std::cout<<"\nProgramarile au fost schimbate!\n\n";
            }


        }
        else std::cout<<"Nu apareti in baza de date!\n\n";
    }
    else if (optiune == 3)
    {
        std::cout << "Introduceti categoria de varsta (1: Copil, 2: Adult, 3: Senior): ";
        int categorie;
        std::cin >> categorie;

        std::string medicament;
        std::cout << "Introduceti numele medicamentului: ";
        std::cin.ignore();
        std::getline(std::cin, medicament);
        std::unordered_map<std::string, std::pair<std::vector<double>, std::vector<std::string>>> medicationDatabase =
        {
            {"paracetamol", {{500.0,2000.0,1500.0}, {"Boli hepatice", "Alcoolism"}}},
            {"ibuprofen", {{500.0,2000.0,1500.0}, {"Ulcer gastric", "Astm"}}},
            {"amoxicilina", {{250.0,1000.0,500.0}, {"Alergie la penicilina", "Mononucleoza"}}},
            {"loratadina", {{10.0,20.0,10.0}, {"Glaucom", "Boli hepatice severe"}}},
            {"omeprazol", {{10.0,40.0,30.0}, {"Boli hepatice", "Osteoporoza"}}}
        };


        switch (categorie)
        {
        case 1:
        {
            std::unique_ptr<ConsultationCreator<Child>> childCreator = std::make_unique<ChildConsultationCreator>();
            if (childCreator)
            {
                std::unique_ptr<Consultation<Child>> consultation = childCreator->createConsultation();
                consultation->consult(medicament, medicationDatabase);
            }
            else
            {
                std::cout << "Eroare la crearea consultației pentru copii.\n";
            }
            break;
        }
        case 2:
        {
            std::unique_ptr<ConsultationCreator<Adult>> adultCreator = std::make_unique<AdultConsultationCreator>();

            if (adultCreator)
            {
                std::unique_ptr<Consultation<Adult>> consultation = adultCreator->createConsultation();
                consultation->consult(medicament, medicationDatabase);
            }
            else
            {
                std::cout << "Eroare la crearea consultației pentru adulți.\n";
            }
            break;
        }
        case 3:
        {
            std::unique_ptr<ConsultationCreator<Senior>> seniorCreator = std::make_unique<SeniorConsultationCreator>();
            if (seniorCreator)
            {
                std::unique_ptr<Consultation<Senior>> consultation = seniorCreator->createConsultation();
                consultation->consult(medicament, medicationDatabase);
            }
            else
            {
                std::cout << "Eroare la crearea consultației pentru seniori.\n";
            }
            break;
        }
        default:
            std::cout << "Categorie de varsta invalida!\n";
            break;
        }

    }
    else if(optiune==4)
{
    std::cin.ignore();

    std::cout<<"\nVa rugam sa alegeti un specialist pentru care doriti sa lasati o recenzie:\n";
        for(int i=0; i<doctori.size(); i++)
            std::cout<<i+1<<". "<<doctori[i].getNume()<<" ("<<doctori[i].getSpecializare()<<")\n";
        std::cout<<"Alegeti optiunea: ";
        int doc;
        std::cin>>doc;
        doc--;
    std::string numeDoctor=doctori[doc].getNume();
   /// std::getline(std::cin, numeDoctor);

    std::cout << "Selectati tipul recenziei (1 pentru nota, 2 pentru mesaj): ";
    int tipRecenzie;
    std::cin >> tipRecenzie;

    if (tipRecenzie == 1)
    {
        double nota;
        std::cout << "Introduceti nota: ";
        std::cin >> nota;

        leaveReview(numeDoctor, nota);
    }
    else if (tipRecenzie == 2)
    {
        std::cin.ignore();
        std::cout << "Introduceti mesajul: ";
        std::string mesaj;
        std::getline(std::cin, mesaj);

        leaveReview(numeDoctor, mesaj);
    }
    else
    {
        std::cout << "Optiune invalida pentru tipul recenziei.\n";
    }
}

    else
    {
        std::cout << "Optiune invalida. Va rugam sa alegeti o optiune valida.\n";
    }



}
std::shared_ptr<Clinica> Clinica::instance = nullptr;
int main()
{
    auto clinica = Clinica::getInstance();
    clinica->Exec();
    return 0;
}
