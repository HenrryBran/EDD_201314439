#ifndef COLADOBLEAVION_H
#define COLADOBLEAVION_H
#include <iostream>
#include <stdlib.h>
#include <QDebug>
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
    NodoColaDobleAvion* First;
    NodoColaDobleAvion* Last;
    int size;
public:
    ColaDobleAvion()
    {
        First = nullptr;
        Last = nullptr;
        size = 0;
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
        if(First != Last)
        {
            NodoColaDobleAvion* aux;
            aux = First->Next;
            First->Next = nullptr;
            aux->Prev = nullptr;
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
    void glistdoble(){
        FILE *graficar;
        graficar = fopen("Aviones.dot","w+");
        fprintf(graficar, "digraph G {bgcolor=\"white:yellow\" gradientangle=0 \n");
        fprintf(graficar, "rankdir = LR; \n");
        fprintf(graficar, "node [fillcolor=\"white\" \n");
        fprintf(graficar, "style=filled gradientangle=270,shape=record, width=.1, height=.1]; \n");
        fprintf(graficar, "node[ width=1.5 ]; \n");

        if(First != nullptr)
        {
            NodoColaDobleAvion *aux = First;
            while(aux != nullptr){
                int Tipo = aux->getTipo();
                int Desbordaje = aux->getDesbordaje();
                int Pasajeros = aux->getPasajeros();
                int Mantenimiento = aux->getMantenimiento();
                if (Tipo == 0) {
                    fprintf(graficar,"nd%p\ [label = \"{<a> |  Tipo: Pequeño \\n Pasajeros : %d\ \\n Desabordaje: %d\ Turnos \\n  Mantenimiento: %d\ Turnos | <b> }\" ];\n",aux,Pasajeros,Desbordaje,Mantenimiento);
                }
                else if(Tipo == 1){
                    fprintf(graficar,"nd%p\ [label = \"{<a> |  Tipo: Mediano \\n Pasajeros : %d\ \\n Desabordaje: %d\ Turnos \\n  Mantenimiento: %d\ Turnos | <b> }\" ];\n",aux,Pasajeros,Desbordaje,Mantenimiento);
                }else{
                    fprintf(graficar,"nd%p\ [label = \"{<a> |  Tipo: Grande \\n Pasajeros : %d\ \\n Desabordaje: %d\ Turnos \\n  Mantenimiento: %d\ Turnos | <b> }\" ];\n",aux,Pasajeros,Desbordaje,Mantenimiento);
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
            fprintf(graficar," xxx \ [label = \" Pista de Desabordaje Vacia \" ];\n");
        }
        fprintf(graficar, "} \n");
        fclose(graficar);
        system("dot -Tpng Aviones.dot > Aviones.png");
        system("gnome-open Aviones.png");
    }
    int getsize()
    {
        return size;
    }
    int getTipo()
    {
        return First->getTipo();
    }
    int getPasajeros()
    {
        return First->getPasajeros();
    }
    int getMantenimiento()
    {
        return First->getMantenimiento();
    }
    int getDesbordaje()
    {
        return First->getDesbordaje();
    }
    void setDesbordaje(int Desbordaje)
    {
        First->setDesbordaje(Desbordaje);
    }
};
#endif // COLADOBLEAVION_H