#ifndef LISTADOBLEORDENADAESCRITORIO_H
#define LISTADOBLEORDENADAESCRITORIO_H
#include <iostream>
#include <stdlib.h>
#include <QDebug>
using namespace std;
//****************************Estructura de la cola de personas por cada escritorio ****************************//
struct NodoColaPasajerosEscritorio
{
private:

    int Id;
    int Maletas;
    int Documentos;
    int Registro;

public:
    NodoColaPasajerosEscritorio* Next;

    NodoColaPasajerosEscritorio(int Id,int Maletas,int Documentos,int Registro)
    {
        this->Id = Id;
        this->Maletas = Maletas;
        this->Documentos = Documentos;
        this->Registro = Registro;
        Next = nullptr;
    }
    string geNodoColaPasajerosEscritorio()
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

struct ColaPasajerosEscritorio
{
private:
    NodoColaPasajerosEscritorio* First;
    NodoColaPasajerosEscritorio* Last;
    int size;

public:
    ColaPasajerosEscritorio()
    {
        First = nullptr;
        Last = nullptr;
        size = 0;
    }
    void addColaPasajerosEscritorio(NodoColaPasajerosEscritorio* TheNew)
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
    void delColaPasajerosEscritorio()
    {
        if(First != Last)
        {
            NodoColaPasajerosEscritorio* aux;
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
    /*string getcolapasajeros(){
        string cola;
        FILE *graficar;
        graficar = fopen("Pasajeros.dot","w+");
        fprintf(graficar, "digraph G {bgcolor=\"white:yellow\" gradientangle=0 \n");
        fprintf(graficar, "rankdir = LR; \n");
        fprintf(graficar, "node [fillcolor=\"white\" \n");
        fprintf(graficar, "style=filled gradientangle=270,shape=record, width=.1, height=.1]; \n");
        fprintf(graficar, "node[ width=1.5 ]; \n");

        if(First != nullptr)
        {
            NodoColaPasajerosEscritorio *aux = First;
            while(aux != nullptr){
                int Id = aux->getId();
                int Maletas = aux->getMaletas();
                int Documentos = aux->getDocumentos();
                int Registro = aux->getRegistro();
                fprintf(graficar,"nd%p\ [label = \"{<a> |  Pasajero Id: %d\ \\n Maletas : %d\ \\n Documentos: %d\  \\n  Registro: %d\ Turnos | <b> }\" ];\n",aux,Id,Maletas,Documentos,Registro);
                aux = aux->Next;
            }

            NodoColaPasajerosEscritorio *aux2 = First;
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
        return cola;
    }*/
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

//****************************Estructura de la Pila de Documentos por persona atendida *************************//

struct NodoPilaDocumentosEscritorio
{
private:

    int Documentos;

public:
    NodoPilaDocumentosEscritorio* Next;

    NodoPilaDocumentosEscritorio(int Documentos)
    {
        this->Documentos = Documentos;
        Next = nullptr;
    }
    string geNodoPilaDocumentosEscritorio()
    {
        return to_string(this->Documentos);
    }
    int getDocumentos()
    {
        return this->Documentos;
    }

};

struct PilaDocumentosEscritorio
{
private:
    NodoPilaDocumentosEscritorio* First;
    NodoPilaDocumentosEscritorio* Last;
    int size;

public:
    PilaDocumentosEscritorio()
    {
        First = nullptr;
        Last = nullptr;
        size = 0;
    }
    void addPilaDocumentosEscritorio(NodoPilaDocumentosEscritorio* TheNew)
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
    void delPilaDocumentosEscritorio()
    {
        if(First != Last)
        {
            NodoPilaDocumentosEscritorio* aux;
            aux = First;
            while(aux->Next->Next != nullptr){
                aux = aux->Next;
            }
            aux->Next = nullptr;
            Last = nullptr;
            Last = aux;
            size--;
        }
        else
        {
            First = nullptr;
            Last = nullptr;
            size = 0;
        }

    }
    /*void glistdoble(){
        FILE *graficar;
        graficar = fopen("Pasajeros.dot","w+");
        fprintf(graficar, "digraph G {bgcolor=\"white:yellow\" gradientangle=0 \n");
        fprintf(graficar, "rankdir = LR; \n");
        fprintf(graficar, "node [fillcolor=\"white\" \n");
        fprintf(graficar, "style=filled gradientangle=270,shape=record, width=.1, height=.1]; \n");
        fprintf(graficar, "node[ width=1.5 ]; \n");

        if(First != nullptr)
        {
            NodoPilaDocumentosEscritorio *aux = First;
            while(aux != nullptr){
                int Id = aux->getId();
                int Maletas = aux->getMaletas();
                int Documentos = aux->getDocumentos();
                int Registro = aux->getRegistro();
                fprintf(graficar,"nd%p\ [label = \"{<a> |  Pasajero Id: %d\ \\n Maletas : %d\ \\n Documentos: %d\  \\n  Registro: %d\ Turnos | <b> }\" ];\n",aux,Id,Maletas,Documentos,Registro);
                aux = aux->Next;
            }

            NodoPilaDocumentosEscritorio *aux2 = First;
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
    }*/
    int getsize()
    {
        return size;
    }
    int getDocumentos()
    {
        return First->getDocumentos();
    }
};

//****************************Estructura lista doblemente enlazada ordenada del escritorio*********************//



#endif // LISTADOBLEORDENADAESCRITORIO_H
