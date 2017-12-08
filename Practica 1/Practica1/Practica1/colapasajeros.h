#ifndef COLAPASAJEROS_H
#define COLAPASAJEROS_H
#include <iostream>
#include <stdlib.h>
#include <QDebug>
using namespace std;

struct NodoColaPasajeros
{
private:

    int Id;
    int Maletas;
    int Documentos;
    int Registro;

public:
    NodoColaPasajeros* Next;

    NodoColaPasajeros(int Id,int Maletas,int Documentos,int Registro)
    {
        this->Id = Id;
        this->Maletas = Maletas;
        this->Documentos = Documentos;
        this->Registro = Registro;
        Next = nullptr;
    }
    string geNodoColaPasajeros()
    {
        return to_string(this->Id)
                + "^" + to_string(this->Maletas)
                + "^" + to_string(this->Documentos)
                + "^" + to_string(this->Registro);
    }
    void setRegistro(int Registro)
    {
        this->Registro = Registro;
    }
    int getRegistro()
    {
        return this->Registro;
    }
    int getId()
    {
        return this->Id;
    }
    int getMaletas()
    {
        return this->Maletas;
    }
    int getDocumentos()
    {
        return this->Documentos;
    }

};

struct ColaPasajeros
{
private:
    NodoColaPasajeros* First;
    NodoColaPasajeros* Last;
    int size;

public:
    ColaPasajeros()
    {
        First = nullptr;
        Last = nullptr;
        size = 0;
    }
    void addColaPasajeros(NodoColaPasajeros* TheNew)
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
    void delColaPasajeros()
    {
        if(First != Last)
        {
            NodoColaPasajeros* aux;
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
    void glistdoble(){
        FILE *graficar;
        graficar = fopen("Pasajeros.dot","w+");
        fprintf(graficar, "digraph G {bgcolor=\"white:yellow\" gradientangle=0 \n");
        fprintf(graficar, "rankdir = LR; \n");
        fprintf(graficar, "node [fillcolor=\"white\" \n");
        fprintf(graficar, "style=filled gradientangle=270,shape=record, width=.1, height=.1]; \n");
        fprintf(graficar, "node[ width=1.5 ]; \n");

        if(First != nullptr)
        {
            NodoColaPasajeros *aux = First;
            while(aux != nullptr){
                int Id = aux->getId();
                int Maletas = aux->getMaletas();
                int Documentos = aux->getDocumentos();
                int Registro = aux->getRegistro();
                fprintf(graficar,"nd%p\ [label = \"{<a> |  Pasajero Id: %d\ \\n Maletas : %d\ \\n Documentos: %d\  \\n  Registro: %d\ Turnos | <b> }\" ];\n",aux,Id,Maletas,Documentos,Registro);
                aux = aux->Next;
            }

            NodoColaPasajeros *aux2 = First;
            while(aux2 != Last){
                fprintf(graficar,"nd%p\ -> nd%p\ [ penwidth = 2 fontsize = 15 fontcolor = \"black\" label = \"Next\" ];\n",aux2,aux2->Next);
                aux2 = aux2->Next;
            }
        }
        else
        {
            fprintf(graficar," xxx \ [label = \" No hay Pasajeros  \" ];\n");
        }
        fprintf(graficar, "} \n");
        fclose(graficar);
        system("dot -Tpng Pasajeros.dot > Pasajeros.png");
        system("gnome-open Pasajeros.png");
    }
    int getsize()
    {
        return size;
    }
    int getId()
    {
        return First->getId();
    }
    int getMaletas()
    {
        return First->getMaletas();
    }
    int getDocumentos()
    {
        return First->getDocumentos();
    }
    int getRegistro()
    {
        return First->getRegistro();
    }
    void setRegistro(int Registro)
    {
        First->setRegistro(Registro);
    }
};

#endif // COLAPASAJEROS_H
