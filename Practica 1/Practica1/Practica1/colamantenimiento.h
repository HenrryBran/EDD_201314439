#ifndef COLAMANTENIMIENTO_H
#define COLAMANTENIMIENTO_H
#include <iostream>
#include <stdlib.h>
#include <QDebug>
#include <fstream>
using namespace std;

struct NodoColaMantenimiento
{
private:

    int Tipo;
    int Mantenimiento;

public:

    NodoColaMantenimiento* Next;

    NodoColaMantenimiento(int Tipo,int Mantenimiento)
    {
        this->Tipo = Tipo;
        this->Mantenimiento = Mantenimiento;
        Next = nullptr;
    }
    string geNodoColaMantenimiento()
    {
        return to_string(this->Tipo)
                + "^" + to_string(this->Mantenimiento);
    }
    int getTipo()
    {
        return this->Tipo;
    }
    int getMantenimiento()
    {
        return this->Mantenimiento;
    }

};

struct ColaMantenimiento
{
private:
    NodoColaMantenimiento* First;
    NodoColaMantenimiento* Last;
    int size;

public:
    ColaMantenimiento()
    {
        First = nullptr;
        Last = nullptr;
        size = 0;
    }
    bool estaVacia()
    {
        return First == nullptr;
    }
    void addColaMantenimiento(NodoColaMantenimiento* TheNew)
    {
        if(First == nullptr){
            First = Last = TheNew;
            size++;
        }
        else{
            Last->Next = TheNew;
            Last = TheNew;
            size++;
        }
    }
    void delColaMantenimiento()
    {
        if(First != nullptr)
        {
            if(First != Last)
            {
                NodoColaMantenimiento* aux;
                aux = First->Next;
                First->Next = nullptr;
                First = nullptr;
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
    string gColaMantenimiento(){
        string cola;
        FILE *graficar;
        graficar = fopen("ColaMantenimiento.txt","w+");

        fprintf(graficar, "subgraph cluster_2 { \n");
        fprintf(graficar, "node [shape = square] color = orange style=filled; \n");
        fprintf(graficar, "label=\" Aviones en Espera \"; \n");

        if(First != nullptr)
        {
            NodoColaMantenimiento *aux = First;
            while(aux != nullptr){
                int Tipo = aux->getTipo();
                int Mantenimiento = aux->getMantenimiento();
                if (Tipo == 0) {
                    fprintf(graficar,"nd%p\ [label = \"Tipo: Pequeño \\n Mantenimiento: %d\ Turnos \" ];\n",aux,Mantenimiento);
                }
                else if(Tipo == 1){
                    fprintf(graficar,"nd%p\ [label = \"Tipo: Mediano \\n Mantenimiento: %d\ Turnos \" ];\n",aux,Mantenimiento);
                }else{
                    fprintf(graficar,"nd%p\ [label = \"Tipo: Grande \\n Mantenimiento: %d\ Turnos \" ];\n",aux,Mantenimiento);
                }
                aux = aux->Next;
            }

            NodoColaMantenimiento *aux2 = First;
            while(aux2 != Last){
                fprintf(graficar,"nd%p\ -> nd%p\ [ penwidth = 2 fontsize = 15 fontcolor = \"black\" label = \"Next\" ];\n",aux2,aux2->Next);
                aux2 = aux2->Next;
            }
        }
        else
        {
            fprintf(graficar," ColaMantenimientoNada[label = \" No hay Aviones en Cola de mantenimiento  \" ];\n");
        }
        fprintf(graficar, "} \n");
        fclose(graficar);

        fstream archivo("ColaMantenimiento.txt");
        string acum;
        if(!archivo.is_open())
            archivo.open("ColaMantenimiento.txt",ios::in);
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
        NodoColaMantenimiento *aux = First;
        return aux->getTipo();
    }
    int getMantenimiento()
    {
        NodoColaMantenimiento *aux = First;
        return aux->getMantenimiento();
    }
    void delall()
    {
        First = Last = nullptr;
        delete First;
        delete Last;
        size = 0;
    }

};

#endif // COLAMANTENIMIENTO_H
