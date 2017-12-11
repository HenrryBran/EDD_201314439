#include "simulador.h"
#include "ui_simulador.h"

Simulador::Simulador(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Simulador)
{
    ui->setupUi(this);
    MainWindow &datos = new MainWindow();
    Turnos = datos.getTurnos();
    ui->textEdit->setText(QString::number(Turnos));
}

Simulador::~Simulador()
{
    delete ui;
}

void Simulador::on_pushButton_clicked()
{
    close();
    MainWindow *datos = new MainWindow();
    datos->show();
}
