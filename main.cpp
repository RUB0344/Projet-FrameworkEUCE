#include "mainwindow.h"

//#include <QApplication>

// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     MainWindow w;
//     w.show();
//     return a.exec();
// }
#include "main.h"
#include <QFileDialog>
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ImportCSVController controller;

    try {
        // Ouvre un explorateur de fichiers pour sélectionner le fichier CSV
        QString inputFilePath = QFileDialog::getOpenFileName(
            nullptr,
            "Sélectionner un fichier CSV",
            "",
            "Fichiers CSV (*.csv)"
            );

        if (inputFilePath.isEmpty()) {
            std::cerr << "Erreur : Aucun fichier sélectionné." << std::endl;
            return 1;
        }

        // Définir le dossier de sortie
        QString outputDirectory = QFileDialog::getExistingDirectory(
            nullptr,
            "Sélectionner un dossier de sortie"
            );

        if (outputDirectory.isEmpty()) {
            std::cerr << "Erreur : Aucun dossier de sortie sélectionné." << std::endl;
            return 1;
        }

        // Charger le fichier CSV
        controller.loadCSV(inputFilePath.toStdString());
        std::cout << "CSV chargé avec succès !" << std::endl;

        // Exporter les données par UE
        controller.exportByUE(outputDirectory.toStdString());
        std::cout << "Fichiers exportés avec succès dans : " << outputDirectory.toStdString() << std::endl;
    } catch (const std::exception &ex) {
        std::cerr << "Erreur : " << ex.what() << std::endl;
    }

    return 0;
}
