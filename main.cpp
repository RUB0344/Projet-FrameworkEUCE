#include <QApplication>
#include "./View/viewHome.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ViewHome home;
    home.setWindowTitle("Page d'accueil");

    // Maximiser la fenêtre à l'ouverture tout en permettant le redimensionnement
    home.showMaximized();

    return app.exec();
}
