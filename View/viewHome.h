#ifndef VIEWHOME_H
#define VIEWHOME_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QString>

class ViewHome : public QMainWindow {
    Q_OBJECT

public:
    explicit ViewHome(QWidget *parent = nullptr);

private slots:
    void selectFile();
    void reloadFile();
    void goToMainCSV();

private:
    QLabel *fileLabel;
    QPushButton *generateButton;
    QString selectedFile;
};

#endif // VIEWHOME_H
