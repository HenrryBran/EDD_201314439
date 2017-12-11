#ifndef COLAPASAJEROS_H
#define COLAPASAJEROS_H
#include <iostream>
#include <stdlib.h>
#include <QDebug>
#include <fstream>
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
    bool estaVacia()
    {
        return First == nullptr;
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
        if(First != nullptr)
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

    }
    string gColaPasajeros(){
        string cola;
        FILE *graficar;
        graficar = fopen("ColaPasajeros.txt","w+");

        fprintf(graficar, "subgraph cluster_1 { \n");
        fprintf(graficar, "node [shape = square] color = orange style=filled; \n");
        fprintf(graficar, "label=\" Pasajeros en Espera \"; \n");

        if(First != nullptr)
        {
            NodoColaPasajeros *aux = First;
            while(aux != nullptr){
                int Id = aux->getId();
                int Maletas = aux->getMaletas();
                int Documentos = aux->getDocumentos();
                int Registro = aux->getRegistro();
                fprintf(graficar,"nd%p\ [label = \"Pasajero Id: %d\ \\n Maletas : %d\ \\n Documentos: %d\  \\n  Registro: %d\ Turnos\" ];\n",aux,Id,Maletas,Documentos,Registro);
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
            fprintf(graficar," ColaPasajerosNada[label = \" No hay Pasajeros  \" ];\n");
        }
        fprintf(graficar, "} \n");
        fclose(graficar);

        fstream archivo("ColaPasajeros.txt");
        string acum;
        if(!archivo.is_open())
            archivo.open("ColaPasajeros.txt",ios::in);
        while(getline(archivo,acum))
            cola = cola + acum;

        archivo.close();
        return cola;
    }
    int getsize()
    {
        return size;
    }
    int getId()
    {
        NodoColaPasajeros *aux = First;
        return aux->getId();
    }
    int getMaletas()
    {
        NodoColaPasajeros *aux = First;
        return aux->getMaletas();
    }
    int getDocumentos()
    {
        NodoColaPasajeros *aux = First;
        return aux->getDocumentos();
    }
    int getRegistro()
    {
        NodoColaPasajeros *aux = First;
        return aux->getRegistro();
    }
    void setRegistro(int Registro)
    {
        NodoColaPasajeros *aux = First;
        return aux->setRegistro(Registro);
    }
    void delall()
    {
        First = Last = nullptr;
        size = 0;
    }
};

#endif // COLAPASAJEROS_H
