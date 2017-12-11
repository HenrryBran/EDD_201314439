#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class Simulador;
}

class Simulador : public QMainWindow
{
    Q_OBJECT

public:
    explicit Simulador(QWidget *parent = 0);
    ~Simulador();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Simulador *ui;
    int Turnos;
    int Aviones;
    int Escritorios;
    int Mantenimiento;
};

#endif // SIMULADOR_H
