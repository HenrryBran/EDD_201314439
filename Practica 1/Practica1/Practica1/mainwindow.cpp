#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "iostream"
#include "string"

using namespace std;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Turnos = 0;
    Aviones = 0;
    Escritorios = 0;
    Mantenimiento = 0;
    contadorturnos = 2;
    ContPasajeros = 0;
    idMaletas = 1;

    Avion_d = new ColaDobleAvion();
    Pasajeros_e = new ColaPasajeros();
    Avion_m = new ColaMantenimiento();
    Equipaje = new ListaDobleCircularEquipaje();
    Avion_l = new ListaMantenimiento();
    scrollArea = new QScrollArea();
    Escritorios_l = new ListaDobleOrdenadaEscritorio();

    EnUso = false;
    primer = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MostrarGrafo()
{
    QPixmap pix("Todo.png");
    ui->label_5->setPixmap(pix);
    ui->label_5->setScaledContents(true);
    scrollArea->setWidget(ui->label_5);
    scrollArea->setVisible(true);
    scrollArea->setWidgetResizable(this);
}

void MainWindow::on_pushButton_clicked()
{
    if(EnUso == false)
    {
        bool check1,check2,check3,check4;
        int v1 = ui->lineEdit->text().toInt(&check1);
        int v2 = ui->lineEdit_2->text().toInt(&check2);
        int v3 = ui->lineEdit_3->text().toInt(&check3);
        int v4 = ui->lineEdit_4->text().toInt(&check4);
        if(check1 == true && check2 == true && check3 == true && check4 == true && v1 >= 1 && v2 >= 1 && v3 >= 1 && v4 >= 1)
        {
            Turnos = v1 - 1;
            Aviones = v2;
            Escritorios = v3;
            Mantenimiento = v4;
            contadorturnos = 2;
            EnUso = true;
            primer = false;
            AvionEstacionllenar(Mantenimiento);
            EscritoriosLLenar(Escritorios);
            QMessageBox::information(this, "Inicio de simulacion", "Datos aceptados se comenzara la simulacion");
        }
        else
        {
            QMessageBox::warning(this, "Error de datos", "Datos no aceptados por favor ingrese datos numericos");
        }
    }
    else
    {
       QMessageBox::warning(this, "Error de Simulacion", "El sistema ya tiene una simulacion espera hasta que termine");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(primer == false)
    {
        Avionllenar();
        GraficarTodo();
        MostrarGrafo();
        primer = true;
        QMessageBox::information(this, "Siguiente turno","Turno 1");
    }
    else
    {
        if(Turnos > 0 )
        {
            Avionllenar();
            AvionQuitarTurnos_llenarColaEspera_llenarColaPasajeros();
            QString dato = QString::number(contadorturnos);
            QMessageBox::information(this, "Siguiente turno","Turno " + dato);
            GraficarTodo();
            MostrarGrafo();
            Turnos--;
            Avion_l->editListaMantenimientoTurnos();
            //Escritorios_l->entrarventanilla();
            //Escritorios_l->quitarturnos();
            contadorturnos++;
        }
        else
        {
            QMessageBox::information(this, "Simulacion Terminada", "La simulacion llego a su fin de turnos");
            EnUso = false;
            primer = false;            
            Avion_d->delall();
            Avion_m->delall();
            Pasajeros_e->delall();
            Equipaje->delall();
            Avion_l->delall();
            Escritorios_l->delall();
        }
    }

}

void MainWindow::GraficarTodo()
{
    FILE *graficar;
     graficar = fopen("Todo.dot", "w+");
    fprintf(graficar, "digraph { \n");
    fprintf(graficar, "nodesep = .90; \n");
    fprintf(graficar," %s\ \n",GrafoDobleAvion().data());
    fprintf(graficar," %s\ \n",GrafoColaPasajeros().data());
    fprintf(graficar," %s\ \n",GrafoColaAvion().data());
    fprintf(graficar," %s\ \n",GrafolistaMaletas().data());
    fprintf(graficar," %s\ \n",GrafoEstacionServicio().data());
    fprintf(graficar," %s\ \n",GrafoEstacionEscritorios().data());
    fprintf(graficar, "} \n");
    fclose(graficar);
    system("dot -Tpng Todo.dot > Todo.png");
    //system("gnome-open Todo.png");
}

//Automatico Desabordaje de Aviones
void MainWindow::Avionllenar()
{
    if(Aviones > 0)
    {
        int Tipo =rand()%3;
        int Desbordaje;
        int Pasajeros;
        int Mantenimiento;
        if (Tipo == 0) {
            Desbordaje = 1;
            Pasajeros = 5+rand()%(11-5);
            Mantenimiento = 1 + rand()%(4-1);
            Avion_d->addColaDobleAvion(new NodoColaDobleAvion(Tipo,Pasajeros,Desbordaje,Mantenimiento));

        }
        else if(Tipo == 1){
           Desbordaje = 2;
           Pasajeros =15 + rand()%(26-15);
           Mantenimiento = 2 + rand()%(5-2);
           Avion_d->addColaDobleAvion(new NodoColaDobleAvion(Tipo,Pasajeros,Desbordaje,Mantenimiento));

        }else{
            Desbordaje = 3;
            Pasajeros = 30 + rand()%(41-30);
            Mantenimiento = 3 + rand()%(7-3);
            Avion_d->addColaDobleAvion(new NodoColaDobleAvion(Tipo,Pasajeros,Desbordaje,Mantenimiento));
        }
        Aviones--;
    }
    return;

}

void MainWindow::AvionQuitarTurnos_llenarColaEspera_llenarColaPasajeros()
{
    if(!Avion_d->estaVacia())
    {
        int Desabordaje = Avion_d->getDesbordaje();
        if(Desabordaje <= 1 )
        {
            Pasajerosllenar();            
            AvionMantenimientollenar();
            Avion_d->delColaDobleAvion();            
            AvionMantenimientodel();
            //llenarcolaEscritorios();
        }
        else
        {
            Desabordaje--;
            Avion_d->setDesbordaje(Desabordaje);
        }
    }
    return;
}

string MainWindow::GrafoDobleAvion()
{
    return Avion_d->gColaDobleAvion();
}

//Automatico Espera de Pasajeros
void MainWindow::Pasajerosllenar()
{
    int Pasajeros = Avion_d->getPasajeros();
    int Maletas;
    int Documentos;
    int Registro;
    for(int i = 0; i<Pasajeros; i++)
    {
        Maletas =1 + rand()%(5-1);
        Documentos =1 + rand()%(11-1);
        Registro =1 + rand()%(4-1);
        Pasajeros_e->addColaPasajeros(new NodoColaPasajeros(ContPasajeros,Maletas,Documentos,Registro));
        Maletasllenar(Maletas);
        ContPasajeros++;
    }
}

string MainWindow::GrafoColaPasajeros()
{
    return Pasajeros_e->gColaPasajeros();
}

//Automatico Mantenimiendo de Aviones
void MainWindow::AvionMantenimientollenar()
{
    int Tipo = Avion_d->getTipo();
    int Mantenimiento = Avion_d->getMantenimiento();
    Avion_m->addColaMantenimiento(new NodoColaMantenimiento(Tipo,Mantenimiento));
}

string MainWindow::GrafoColaAvion()
{
    return Avion_m->gColaMantenimiento();
}

void MainWindow::AvionMantenimientodel()
{
    if(!Avion_m->estaVacia())
    {
        if(Avion_l->libres() == true)
        {
            int Tipo = Avion_m->getTipo();
            int Mantenimiento = Avion_m->getMantenimiento();
            Avion_l->editListaMantenimientoEstado(Tipo,Mantenimiento);
            Avion_m->delColaMantenimiento();
            AvionMantenimientodel();
        }

    }
}

//Automatico Maletas de Pasajeros
void MainWindow::Maletasllenar(int noMaletas)
{
    for(int i = 0; i<noMaletas; i++)
    {
        Equipaje->addListaDobleCircularEquipaje(new NodoListaDobleCircularEquipaje(idMaletas));
        idMaletas++;
    }
}

string MainWindow::GrafolistaMaletas()
{
    return Equipaje->gListaDobleCircularEquipaje();
}

//Lista Simple de Mantenimiento de Aviones
void MainWindow::AvionEstacionllenar(int Mantenimiento)
{
   for(int i = 0; i<Mantenimiento;i++)
   {
       Avion_l->addListaMantenimiento(new NodoMantemiento(555,false,0));
   }
}

string MainWindow::GrafoEstacionServicio()
{
    return Avion_l->gListaAvion();
}

//Lista Doble de Escritorios
void MainWindow::EscritoriosLLenar(int Escritorios)
{
    char Letra= 'A';
    for(int i=0; i< Escritorios;i++)
    {
        cout<<Letra<<endl;
        string letra(1,Letra);
        ColaPasajerosEscritorio* Escritorios_C = new ColaPasajerosEscritorio();
        PilaDocumentosEscritorio* Escritorios_P = new PilaDocumentosEscritorio();
        Escritorios_l->addListaDobleOrdenadaEscritorio(new NodoEscritorio(Escritorios_P,Escritorios_C,letra,0,false,0,0,0));
        Letra++;
        Escritorios_l->ordenar();
    }
}

string MainWindow::GrafoEstacionEscritorios()
{
    return Escritorios_l->gListaDobleOrdenadaEscritorio();
}

void MainWindow::llenarcolaEscritorios()
{
    if(!Pasajeros_e->estaVacia())
    {
        int Id =  Pasajeros_e->getId();
        int Documentos = Pasajeros_e->getDocumentos();
        int Maletas =  Pasajeros_e->getMaletas();
        int Registro = Pasajeros_e->getRegistro();
        Escritorios_l->llenarcola(new NodoColaPasajerosEscritorio(Id,Maletas,Documentos,Registro));
        Pasajeros_e->delColaPasajeros();
        llenarcolaEscritorios();
    }
}
