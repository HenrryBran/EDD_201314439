#ifndef LISTAMANTENIMIENTO_H
#define LISTAMANTENIMIENTO_H
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

struct NodoMantemiento
{
private:
    int Tipo;
    int Id;
    bool Estado;
    int Mantenimiento;
public:
    NodoMantemiento* Next;
    NodoMantemiento(int Tipo,int Id,bool Estado,int Mantenimiento)
    {
        this->Tipo = Tipo;
        this->Id = Id;
        this->Estado = Estado;
        this->Mantenimiento = Mantenimiento;
        Next = nullptr;
    }
    void setMantenimiento(int Mantenimiento)
    {
        this->Mantenimiento = Mantenimiento;
    }
    int getMantenimiento()
    {
        return this->Mantenimiento;
    }
    void setTipo(int Tipo)
    {
        this->Tipo = Tipo;
    }
    int getTipo()
    {
        return this->Tipo;
    }
    int getId()
    {
        return this->Id;
    }
    void setId(int Id)
    {
        this->Id = Id;
    }
    void setEstado(bool Estado)
    {
        this->Estado = Estado;
    }
    bool getEstado()
    {
        return this->Estado;
    }
};

struct ListaMantenimiento
{
private:
    NodoMantemiento* First;
    NodoMantemiento* Last;
    int size;
public:
    ListaMantenimiento() {
        First = nullptr;
        Last = nullptr;
        size = 0;
    }
    bool estaVacia()
    {
        return First == nullptr;
    }
    void addListaMantenimiento(NodoMantemiento* TheNew)
    {
        if(First == nullptr){
            First = Last = TheNew;
            size++;
        }
        else{
            Last->Next = TheNew;
            Last = TheNew;
            Last->Next = nullptr;
            size++;
        }
    }
    void editListaMantenimientoEstado(int Tipo,int Mantenimiento){
        NodoMantemiento *aux = First;
        while(aux!=nullptr){
            if(aux->getEstado() == false){
                aux->setTipo(Tipo);
                aux->setEstado(true);
                aux->setMantenimiento(Mantenimiento);
                break;
            }
            aux=aux->Next;
        }
    }
    bool libres()
    {
        NodoMantemiento *aux = First;
        while(aux!=nullptr){
            if(aux->getEstado() == false){
                return true;
                break;
            }
            aux=aux->Next;
        }
        return false;
    }
    void editListaMantenimientoTurnos()
    {
        NodoMantemiento *aux = First;
        while(aux!=nullptr){
            if(aux->getMantenimiento() <= 1){
                aux->setTipo(555);
                aux->setEstado(false);
                aux->setMantenimiento(0);
            }else{
                int dato = aux->getMantenimiento() - 1;
                aux->setMantenimiento(dato);
            }
            aux=aux->Next;
        }
    }
    void delall(){
        First = Last = nullptr;
        delete First;
        delete Last;
        size = 0;
    }
    string gListaAvion(){
        string lista;
        FILE *graficar;
        graficar = fopen("ListaMantenimiento.txt","w+");

        fprintf(graficar, "subgraph cluster_4 { \n");
        fprintf(graficar, "node [shape = square] color = orange style=filled; \n");
        fprintf(graficar, "label=\" Estacion de Mantenimiento \"; \n");

        if(First != nullptr)
        {
            NodoMantemiento *aux = First;
            while(aux != nullptr){
                int Tipo = aux->getTipo();
                int Id = aux->getId();
                int Mantenimiento = aux->getMantenimiento();
                if (Tipo == 0) {
                    fprintf(graficar,"nd%p\ [label = \"Estacion : %d\ \\n Tipo: Pequeño \\n Estado : Ocupado \\n  Mantenimiento: %d\ Turnos \" ];\n",aux,Id,Mantenimiento);
                }
                else if(Tipo == 1){
                    fprintf(graficar,"nd%p\ [label = \"Estacion : %d\ \\n Tipo: Mediano \\n Estado: Ocupado \\n  Mantenimiento: %d\ Turnos \" ];\n",aux,Id,Mantenimiento);
                }
                else if(Tipo == 2){
                    fprintf(graficar,"nd%p\ [label = \"Estacion : %d\ \\n Tipo: Grande \\n Estado: Ocupado \\n  Mantenimiento: %d\ Turnos  \" ];\n",aux,Id,Mantenimiento);
                }
                else{
                    fprintf(graficar,"nd%p\ [label = \"Estacion : %d\ \\n Tipo: Libre \\n Estado: Libre \\n  Mantenimiento: 0 Turnos  \" ];\n",aux,Id);
                }
                aux = aux->Next;
            }

            NodoMantemiento *aux2 = First;
            while(aux2 != Last){
                fprintf(graficar,"nd%p\ -> nd%p\ [ penwidth = 2 fontsize = 15 fontcolor = \"black\" label = \"Next\" ];\n",aux2,aux2->Next);
                aux2 = aux2->Next;
            }
        }
        else
        {
            fprintf(graficar," ListaMantenimientoNada[label = \" Estacion de Mantenimiento libre \" ];\n");
        }

        fprintf(graficar, "} \n");
        fclose(graficar);

        fstream archivo("ListaMantenimiento.txt");

        string acum;

        if(!archivo.is_open())
            archivo.open("ListaMantenimiento.txt",ios::in);

        while(getline(archivo,acum))
            lista = lista + acum;

        archivo.close();
        return lista;
    }
    int getsize(){
        return size;
    }
    string consola()
    {
        string consola = "\n++++++++++++Estacion de servicio+++++++++++++\n";
        if(First != nullptr)
        {
            NodoMantemiento *aux = First;
            while(aux != nullptr){
                int Tipo = aux->getTipo();
                int Id = aux->getId();
                int Mantenimiento = aux->getMantenimiento();
                if (Tipo == 0) {
                    consola = consola + "Estacion " + to_string(Id) + ": Ocupada \n ";
                    consola = consola + "\t Avion en Mantenimiento: Pequeño \n" ;
                    consola = consola + "\t Turnos restantes: " + to_string(Mantenimiento) + "\n";
                }
                else if(Tipo == 1){
                    consola = consola + "Estacion " + to_string(Id) + ": Ocupada \n ";
                    consola = consola + "\t Avion en Mantenimiento: Mediano \n" ;
                    consola = consola + "\t Turnos restantes: " + to_string(Mantenimiento) + "\n";
                }
                else if(Tipo == 2){
                    consola = consola + "Estacion " + to_string(Id) + ": Ocupada \n ";
                    consola = consola + "\t Avion en Mantenimiento: Grande \n" ;
                    consola = consola + "\t Turnos restantes: " + to_string(Mantenimiento) + "\n";
                }
                else{
                    consola = consola + "Estacion " + to_string(Id) + ": Libre\n ";
                    consola = consola + "\t Avion en Mantenimiento: ninguno \n";
                    consola = consola + "\t Turnos restantes: 0 \n";
                }
                aux = aux->Next;
            }
            consola = consola + "+++++++++++++++++++++++++++++++++++++++++++++\n";
            return consola;

        }
        consola = consola +  "Vacio \n";
        return consola;
    }

};
#endif // LISTAMANTENIMIENTO_H
