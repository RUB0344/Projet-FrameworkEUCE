// ImportCSVController.h
#ifndef IMPORTCSVCONTROLLER_H
#define IMPORTCSVCONTROLLER_H

#include <string>
#include <vector>
#include <map>

class ImportCSVController {
public:
    // Méthode pour charger un fichier CSV
    void loadCSV(const std::string& filePath);

    // Méthode pour exporter les fichiers CSV par UE
    void exportByUE(const std::string& outputDirectory);

private:
    // Structure de stockage des données par UE et ECUE
    std::map<std::string, std::map<std::string, std::vector<std::vector<std::string>>>> dataByUE;

    // Méthode pour parser une ligne CSV
    std::vector<std::string> parseLine(const std::string& line, char delimiter);
};

#endif // IMPORTCSVCONTROLLER_H
