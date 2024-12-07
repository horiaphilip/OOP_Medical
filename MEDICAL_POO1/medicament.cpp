#include <string>
#include <unordered_map>
#include <vector>

// Structura pentru a reprezenta contraindicațiile pentru un medicament
struct Contraindication {
    std::string condition; // Condiția medicală asociată contraindicației
    std::string description; // Descrierea contraindicației
};

// Clasa pentru a reprezenta un medicament
class Medication {
private:
    std::unordered_map<std::string, double> dosageByAgeCategory; // Dozajul mediu pentru fiecare categorie de vârstă
    std::vector<Contraindication> contraindications; // Lista de contraindicații

public:
    // Constructor
    Medication(const std::unordered_map<std::string, double>& dosage, const std::vector<Contraindication>& contraindications)
        : dosageByAgeCategory(dosage), contraindications(contraindications) {}

    // Metodă pentru a obține dozajul mediu pentru o categorie de vârstă specificată
    double getDosageForAgeCategory(const std::string& ageCategory) const {
        auto it = dosageByAgeCategory.find(ageCategory);
        if (it != dosageByAgeCategory.end()) {
            return it->second;
        } else {
            return 0.0; // Returnăm 0 dacă nu găsim dozaj pentru categoria de vârstă specificată
        }
    }

    // Metodă pentru a adăuga o contraindicație
    void addContraindication(const Contraindication& contraindication) {
        contraindications.push_back(contraindication);
    }

    // Metodă pentru a afișa contraindicațiile medicamentului
    void printContraindications() const {
        std::cout << "Contraindications for this medication:\n";
        for (const auto& contraindication : contraindications) {
            std::cout << "Condition: " << contraindication.condition << ", Description: " << contraindication.description << std::endl;
        }
    }
};
