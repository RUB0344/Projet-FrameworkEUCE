#include "ViewMainCSV.h"
#include <QLabel>
#include <QVBoxLayout>

ViewMainCSV::ViewMainCSV(QWidget *parent) : QMainWindow(parent) {
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    QLabel *label = new QLabel("Bienvenue sur la page MainCSV", this);
    layout->addWidget(label);
}
