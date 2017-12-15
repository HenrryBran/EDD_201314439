#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdlib.h>
#include <QImage>
#include <QtWidgets>
#include "coladobleavion.h"
#include "colapasajeros.h"
#include "colamantenimiento.h"
#include "listadoblecircularequipaje.h"
#include "listamantenimiento.h"
#include "listadobleordenadaescritorio.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    //Metodos y funciones globales
    void GraficarTodo();
    void MostrarGrafo();
    void consola();
    void GraficarTodo2();

    //Desabordaje avion
    void Avionllenar();
    void AvionQuitarTurnos_llenarColaEspera_llenarColaPasajeros();
    string GrafoDobleAvion();

    //Cola Pasajeros
    void Pasajerosllenar();
    string GrafoColaPasajeros();

    //Cola Avion Mantenimiento
    void AvionMantenimientollenar();
    string GrafoColaAvion();
    void AvionMantenimientodel();

    //Lista Doble circular Maletas
    void Maletasllenar(int noMaletas);
    string GrafolistaMaletas();

    //Lista simple Mantenimiento
    void AvionEstacionllenar(int Mantenimiento);
    string GrafoEstacionServicio();

    //lista doble Escritorios
    void EscritoriosLLenar(int Escritorios);
    string GrafoEstacionEscritorios();
    void llenarcolaEscritorios();


private:
    Ui::MainWindow *ui;

    //Variables globales de estado
    int Turnos;//numero de turnos
    int Aviones;//numero de aviones
    int Escritorios;//numero de escritorios
    int Mantenimiento;//numero de espacios de servicio

    int contadorturnos; // llevar contador de turnos

    bool EnUso;//verifica si la simulacion esta en uso

    int ContPasajeros;//id de pasajeros
    int idMaletas;//id de maletas

    int Turnos_2;//auxiliar de turnos

    //instancias de las estructuras
    QScrollArea *scrollArea;
    ColaDobleAvion *Avion_d;
    ColaPasajeros *Pasajeros_e;
    ColaMantenimiento *Avion_m;
    ListaDobleCircularEquipaje *Equipaje;
    ListaMantenimiento* Avion_l;
    ListaDobleOrdenadaEscritorio* Escritorios_l;

};

#endif // MAINWINDOW_H
