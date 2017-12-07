#ifndef COLADOBLE_H
#define COLADOBLE_H
#include <iostream>
#include <stdlib.h>
#include <QDebug>
using namespace std;

struct NodoColaDoble
{
    int Tipo;
    int Pasajeros;
    int Desbordaje;
    int Mantenimiento;
    NodoColaDoble* Next;
    NodoColaDoble* Prev;

    NodoColaDoble(int Tipo,int Pasajeros,int Desbordaje,int Mantenimiento)
    {
        this->Tipo = Tipo;
        this->Pasajeros = Pasajeros;
        this->Desbordaje = Desbordaje;
        this->Mantenimiento = Mantenimiento;
        Next = NULL;
        Prev = NULL;
    }
    string getNodoColaDoble()
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

};

struct ColaDoble
{
    NodoColaDoble* First;
    NodoColaDoble* Last;
    int size;

    ColaDoble()
    {
        First = NULL;
        Last = NULL;
        size = 0;
    }
    void addColaDoble(NodoColaDoble* TheNew)
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
    void delColaDoble()
    {
        NodoColaDoble* aux;
        aux = First->Next;
        First->Next = nullptr;
        aux->Prev = nullptr;
        First = nullptr;
        First = aux;
        size--;
    }

};

#endif // COLADOBLE_H
