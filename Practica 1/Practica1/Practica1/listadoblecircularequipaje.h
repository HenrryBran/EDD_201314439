#ifndef LISTADOBLECIRCULAREQUIPAJE_H
#define LISTADOBLECIRCULAREQUIPAJE_H
#include <iostream>
#include <stdlib.h>
#include <QDebug>
#include <fstream>
using namespace std;

struct NodoListaDobleCircularEquipaje
{
private:

    int IdMaletas;

public:

    NodoListaDobleCircularEquipaje* Next;
    NodoListaDobleCircularEquipaje* Prev;

    NodoListaDobleCircularEquipaje(int IdMaletas)
    {
        this->IdMaletas = IdMaletas;
        Next = nullptr;
        Prev = nullptr;
    }
    string getNodoListaDobleCircularEquipaje()
    {
        return to_string(this->IdMaletas);
    }
    int getMaletas()
    {
        return this->IdMaletas;
    }

};

struct ListaDobleCircularEquipaje
{
private:

    NodoListaDobleCircularEquipaje* First;
    NodoListaDobleCircularEquipaje* Last;
    int size;

public:

    ListaDobleCircularEquipaje()
    {
        First = nullptr;
        Last = nullptr;
        size = 0;
    }
    bool estaVacia()
    {
        return First == nullptr;
    }
    void addListaDobleCircularEquipaje(NodoListaDobleCircularEquipaje* TheNew)
    {        
        if(First == nullptr){
            First = TheNew;
            Last = TheNew;
            First->Next = First;
            First->Prev = Last;
        }else{
            Last->Next = TheNew;
            TheNew->Prev = Last;
            TheNew->Next = First;
            Last = TheNew;
            First->Prev = Last;
        }
        size++;
    }
    void delListaDobleCircularEquipaje()
    {
        if(First != nullptr)
        {
            if(First != Last)
            {
                NodoListaDobleCircularEquipaje *aux;
                aux = First->Next;
                First = nullptr;
                delete First;
                aux->Prev = Last;
                Last->Next=aux;
                First = aux;
                size--;
            }
            else
            {
                First = Last = nullptr;
                delete First;
                delete Last;
                size--;
            }

        }
        return;
    }
    string gListaDobleCircularEquipaje(){
        string lista;
        FILE *graficar;
        graficar = fopen("ListaDobleCircularEquipaje.txt","w+");

        fprintf(graficar, "subgraph cluster_3 { \n");
        fprintf(graficar, "node [shape = square] color = orange style=filled; \n");
        fprintf(graficar, "label=\" Estacion de Maletas \"; \n");

        if(First != nullptr)
        {
            NodoListaDobleCircularEquipaje *aux = First;

            do{
                int IdMaleta = aux->getMaletas();
                fprintf(graficar,"nd%p\ [label = \"Id Maleta: %d\ \" ];\n",aux,IdMaleta);
                aux = aux->Next;
            }while(aux!=First);

            NodoListaDobleCircularEquipaje *aux2 = First;
            do{
                fprintf(graficar,"nd%p\ -> nd%p\ [ penwidth = 2 fontsize = 15 fontcolor = \"black\" label = \"Next\" ];\n",aux2,aux2->Next);
                aux2 = aux2->Next;
            }while(aux2 != First);


            NodoListaDobleCircularEquipaje *aux3 = Last;
            do{
                fprintf(graficar,"nd%p\ -> nd%p\ [ penwidth = 2 fontsize = 15 fontcolor = \"black\" label = \"Prev\" ];\n",aux3,aux3->Prev);
                aux3 = aux3->Prev;
            }while(aux3 != Last);
        }
        else
        {
            fprintf(graficar," ListaDobleCircularEquipaje[label = \" Estacion de Maletas vacia \" ];\n");
        }

        fprintf(graficar, "} \n");
        fclose(graficar);

        fstream archivo("ListaDobleCircularEquipaje.txt");

        string acum;

        if(!archivo.is_open())
            archivo.open("ListaDobleCircularEquipaje.txt",ios::in);

        while(getline(archivo,acum))
            lista = lista + acum;

        archivo.close();
        return lista;
    }
    int getsize()
    {
        return size;
    }
    int getMaletas()
    {
        NodoListaDobleCircularEquipaje *aux = First;
        return aux->getMaletas();
    }
    void delall()
    {
        First = Last = nullptr;
        delete First;
        delete Last;
        size = 0;
    }
};


#endif // LISTADOBLECIRCULAREQUIPAJE_H
