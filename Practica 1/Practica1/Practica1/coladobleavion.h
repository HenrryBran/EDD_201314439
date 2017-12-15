#ifndef COLADOBLEAVION_H
#define COLADOBLEAVION_H
#include <iostream>
#include <stdlib.h>
#include <QDebug>
#include <fstream>
using namespace std;

struct NodoColaDobleAvion
{
private:
    int Tipo;
    int Pasajeros;
    int Desbordaje;
    int Mantenimiento;
public:
    NodoColaDobleAvion* Next;
    NodoColaDobleAvion* Prev;

    NodoColaDobleAvion(int Tipo,int Pasajeros,int Desbordaje,int Mantenimiento)
    {
        this->Tipo = Tipo;
        this->Pasajeros = Pasajeros;
        this->Desbordaje = Desbordaje;
        this->Mantenimiento = Mantenimiento;
        Next = nullptr;
        Prev = nullptr;
    }
    string getNodoColaDobleAvion()
    {
        return to_string(this->Tipo)
                + "^" + to_string(this->Pasajeros)
                + "^" + to_string(this->Desbordaje)
                + "^" + to_string(this->Mantenimiento);
    }
    void setDesbordaje(int Desbordaje)
    {
        this->Desbordaje = Desbordaje;
    }
    int getDesbordaje()
    {
        return this->Desbordaje;
    }
    int getTipo()
    {
        return this->Tipo;
    }
    int getPasajeros()
    {
        return this->Pasajeros;
    }
    int getMantenimiento()
    {
        return this->Mantenimiento;
    }

};

struct ColaDobleAvion
{
private:    
    int size;
public:
    NodoColaDobleAvion* First;
    NodoColaDobleAvion* Last;
    ColaDobleAvion()
    {
        First = nullptr;
        Last = nullptr;
        size = 0;
    }
    bool estaVacia()
    {
        return First == nullptr;
    }
    void addColaDobleAvion(NodoColaDobleAvion* TheNew)
    {
        if(First == nullptr){
            First = Last = TheNew;
            size++;
        }
        else{
            Last->Next = TheNew;
            TheNew->Prev = Last;
            Last = TheNew;
            size++;
        }
    }
    void delColaDobleAvion()
    {
        if(First != nullptr)
        {
            if(First != Last)
            {
                NodoColaDobleAvion* aux;
                aux = First->Next;
                First->Next = nullptr;
                aux->Prev = nullptr;
                delete First;
                First = aux;
                size--;
            }
            else
            {
                First = Last = nullptr;
                delete First;
                delete Last;
                size = 0;
            }
        }
        return;
    }
    string gColaDobleAvion(){
        string cola;
        FILE *graficar;
        graficar = fopen("ColaDobleAvion.txt","w+");

        fprintf(graficar, "subgraph cluster_0 { \n");
        fprintf(graficar, "node [shape = square] color = orange style=filled; \n");
        fprintf(graficar, "label=\" Llegada De Aviones \"; \n");

        if(First != nullptr)
        {
            NodoColaDobleAvion *aux = First;
            while(aux != nullptr){
                int Tipo = aux->getTipo();
                int Desbordaje = aux->getDesbordaje();
                int Pasajeros = aux->getPasajeros();
                int Mantenimiento = aux->getMantenimiento();
                if (Tipo == 0) {
                    fprintf(graficar,"nd%p\ [label = \"Tipo: Pequeño \\n Pasajeros : %d\ \\n Desabordaje: %d\ Turnos \\n  Mantenimiento: %d\ Turnos \" ];\n",aux,Pasajeros,Desbordaje,Mantenimiento);
                }
                else if(Tipo == 1){
                    fprintf(graficar,"nd%p\ [label = \"Tipo: Mediano \\n Pasajeros : %d\ \\n Desabordaje: %d\ Turnos \\n  Mantenimiento: %d\ Turnos \" ];\n",aux,Pasajeros,Desbordaje,Mantenimiento);
                }else{
                    fprintf(graficar,"nd%p\ [label = \"Tipo: Grande \\n Pasajeros : %d\ \\n Desabordaje: %d\ Turnos \\n  Mantenimiento: %d\ Turnos  \" ];\n",aux,Pasajeros,Desbordaje,Mantenimiento);
                }
                aux = aux->Next;
            }

            NodoColaDobleAvion *aux2 = First;
            while(aux2 != Last){
                fprintf(graficar,"nd%p\ -> nd%p\ [ penwidth = 2 fontsize = 15 fontcolor = \"black\" label = \"Next\" ];\n",aux2,aux2->Next);
                aux2 = aux2->Next;
            }

            NodoColaDobleAvion *aux3 = Last;
            while(aux3 != First){
                fprintf(graficar,"nd%p\ -> nd%p\ [ penwidth = 2 fontsize = 15 fontcolor = \"black\" label = \"Prev\" ];\n",aux3,aux3->Prev);
                aux3 = aux3->Prev;
            }
        }
        else
        {
            fprintf(graficar," ColaDobleAvionNada[label = \" Pista de Desabordaje Vacia \" ];\n");
        }

        fprintf(graficar, "} \n");
        fclose(graficar);

        fstream archivo("ColaDobleAvion.txt");

        string acum;

        if(!archivo.is_open())
            archivo.open("ColaDobleAvion.txt",ios::in);

        while(getline(archivo,acum))
            cola = cola + acum;

        archivo.close();
        return cola;
    }
    int getsize()
    {
        return size;
    }
    int getTipo()
    {
        NodoColaDobleAvion *aux = First;
        return aux->getTipo();
    }
    int getPasajeros()
    {
        NodoColaDobleAvion *aux = First;
        return aux->getPasajeros();
    }
    int getMantenimiento()
    {
        NodoColaDobleAvion *aux = First;
        return aux->getMantenimiento();
    }
    int getDesbordaje()
    {
        NodoColaDobleAvion *aux = First;
        return aux->getDesbordaje();
    }
    void setDesbordaje(int Desbordaje)
    {
        NodoColaDobleAvion *aux = First;
        return aux->setDesbordaje(Desbordaje);
    }
    void delall()
    {
        First = Last = nullptr;
        delete First;
        delete Last;
        size = 0;
    }
    string consola()
    {
        NodoColaDobleAvion* aux = Last;
        string consola = "Arribo Avion Tipo: ";
        if(aux == nullptr)
        {
            consola = consola + "Ninguno \n";
        }
        else
        {
            int Tipo = aux->getTipo();
            if (Tipo == 0) {
                consola = consola + "Pequeño \n";
            }
            else if(Tipo == 1){
                consola = consola + "Mediano \n";
            }else{
                consola = consola + "Grande \n";
            }
        }
        aux = First;
        consola = consola + "Avion desabordando: ";
        if(aux == nullptr)
        {
            consola = consola + "Ninguno \n";
        }
        else
        {
            int Tipo = aux->getTipo();
            if (Tipo == 0) {
                consola = consola + "Pequeño \n";
            }
            else if(Tipo == 1){
                consola = consola + "Mediano \n";
            }else{
                consola = consola + "Grande \n";
            }
        }

        return consola;
    }
};

#endif // COLADOBLEAVION_H
