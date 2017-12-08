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
        if(First != Last)
        {
            NodoColaMantenimiento* aux;
            aux = First->Next;
            First->Next = nullptr;
            First = nullptr;
            First = aux;
            size--;
        }
        else
        {
            First = nullptr;
            Last = nullptr;
            size = 0;
        }

    }
    string gColaMantenimiento(){
        string cola;
        FILE *graficar;
        graficar = fopen("ColaMantenimiento.txt","w+");
        fprintf(graficar, "digraph G {bgcolor=\"white:yellow\" gradientangle=0 \n");
        fprintf(graficar, "rankdir = LR; \n");
        fprintf(graficar, "node [fillcolor=\"white\" \n");
        fprintf(graficar, "style=filled gradientangle=270,shape=record, width=.1, height=.1]; \n");
        fprintf(graficar, "node[ width=1.5 ]; \n");

        if(First != nullptr)
        {
            NodoColaMantenimiento *aux = First;
            while(aux != nullptr){
                int Tipo = aux->getTipo();
                int Mantenimiento = aux->getMantenimiento();
                if (Tipo == 0) {
                    fprintf(graficar,"nd%p\ [label = \"{<a> |  Tipo: Pequeño \\n Pasajeros : %d\ \\n Mantenimiento: %d\ Turnos | <b> }\" ];\n",aux,Mantenimiento);
                }
                else if(Tipo == 1){
                    fprintf(graficar,"nd%p\ [label = \"{<a> |  Tipo: Mediano \\n Pasajeros : %d\ \\n Mantenimiento: %d\ Turnos | <b> }\" ];\n",aux,Mantenimiento);
                }else{
                    fprintf(graficar,"nd%p\ [label = \"{<a> |  Tipo: Grande \\n Pasajeros : %d\ \\n Mantenimiento: %d\ Turnos | <b> }\" ];\n",aux,,Mantenimiento);
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
            fprintf(graficar," ColaMantenimientoNada[label = \" No hay Pasajeros  \" ];\n");
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
        return First->getTipo();
    }
    int getMantenimiento()
    {
        return First->getMantenimiento();
    }
};

#endif // COLAMANTENIMIENTO_H
