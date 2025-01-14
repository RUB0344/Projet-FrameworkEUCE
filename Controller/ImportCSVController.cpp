#include "main.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

void ImportCSVController::loadCSV(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Erreur : impossible d'ouvrir le fichier CSV.");
    }

    std::string line;
    // Lecture de la première ligne pour déterminer les colonnes
    if (std::getline(file, line)) {
        auto columns = parseLine(line, ',');
        for (const auto& column : columns) {
            std::cout << column << " ";
        }
        std::cout << std::endl;
    }

    // Lecture des lignes suivantes
    while (std::getline(file, line)) {
        auto fields = parseLine(line, ',');
        if (fields.size() >= 2) {
            std::string ue_ecue = fields[0];
            size_t delimiter_pos = ue_ecue.find(" - ");
            if (delimiter_pos != std::string::npos) {
                std::string ue = ue_ecue.substr(0, delimiter_pos);
                std::string ecue = ue_ecue.substr(delimiter_pos + 3);
                dataByUE[ue][ecue].emplace_back(fields);
            }
        }
    }

    file.close();
}

void ImportCSVController::exportByUE(const std::string& outputDirectory) {
    for (const auto& [ue, ecueData] : dataByUE) {
        std::string fileName = outputDirectory + "/" + ue + ".csv";
        std::ofstream outFile(fileName);
        if (!outFile.is_open()) {
            throw std::runtime_error("Erreur : impossible de créer le fichier " + fileName);
        }

        for (const auto& [ecue, rows] : ecueData) {
            for (const auto& row : rows) {
                outFile << ecue;
                for (const auto& field : row) {
                    outFile << "," << field;
                }
                outFile << "\n";
            }
        }

        outFile.close();
    }
}

std::vector<std::string> ImportCSVController::parseLine(const std::string& line, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(line);
    std::string field;

    while (std::getline(ss, field, delimiter)) {
        result.push_back(field);
    }

    return result;
}
