#include "viewHome.h"
#include "viewMainCSV.h"
#include <QVBoxLayout>
#include <QFileDialog>

ViewHome::ViewHome(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    fileLabel = new QLabel("Aucun fichier sélectionné", this);
    layout->addWidget(fileLabel);

    QPushButton *openFileButton = new QPushButton("Ouvrir un fichier .csv", this);
    layout->addWidget(openFileButton);
    connect(openFileButton, &QPushButton::clicked, this, &ViewHome::selectFile);


    generateButton = new QPushButton("Générer", this);
    generateButton->setEnabled(false);
    layout->addWidget(generateButton);
    connect(generateButton, &QPushButton::clicked, this, &ViewHome::goToMainCSV);
}

void ViewHome::selectFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Sélectionner un fichier .csv", QString(), "Fichiers CSV (*.csv)");
    if (!fileName.isEmpty()) {
        selectedFile = fileName;
        fileLabel->setText("Fichier sélectionné : " + fileName);
        generateButton->setEnabled(true);
    }
}


void ViewHome::goToMainCSV() {
    auto *mainCSV = new ViewMainCSV(this);
    mainCSV->setWindowTitle("Page MainCSV");
    mainCSV->resize(400, 200);
    mainCSV->show();
 this->close();
}
