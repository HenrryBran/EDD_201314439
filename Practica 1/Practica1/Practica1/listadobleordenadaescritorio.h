#ifndef LISTADOBLEORDENADAESCRITORIO_H
#define LISTADOBLEORDENADAESCRITORIO_H
#include <iostream>
#include <stdlib.h>
#include <QDebug>
#include <fstream>
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
    string gColaPasajerosEscritorio(){
        string cola;
        FILE *graficar;
        graficar = fopen("ColaPasajerosEscritorio.txt","w+");
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
            fprintf(graficar," ColaPasajerosEscritorio[label = \" No hay Pasajeros  \" ];\n");
        }
        fprintf(graficar, "} \n");
        fclose(graficar);

        fstream archivo("ColaPasajerosEscritorio.txt");
        string acum;
        if(!archivo.is_open())
            archivo.open("ColaPasajerosEscritorio.txt",ios::in);
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
        First = nullptr;
        Last = nullptr;
        size = 0;
    }
    string gPilaDocumentosEscritorio(){
        string pila;
        FILE *graficar;
        graficar = fopen("PilaDocumentosEscritorio.txt","w+");
        fprintf(graficar, "digraph G {bgcolor=\"white:yellow\" gradientangle=0 \n");
        fprintf(graficar, "rankdir = LR; \n");
        fprintf(graficar, "node [fillcolor=\"white\" \n");
        fprintf(graficar, "style=filled gradientangle=270,shape=record, width=.1, height=.1]; \n");
        fprintf(graficar, "node[ width=1.5 ]; \n");

        if(First != nullptr)
        {
            NodoPilaDocumentosEscritorio *aux = First;
            while(aux != nullptr){
                int Documentos = aux->getDocumentos();
                fprintf(graficar,"nd%p\ [label = \"{<a> | Documento No: %d\ | <b> }\" ];\n",aux,Documentos);
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
            fprintf(graficar," PilaDocumentosEscritorio[label = \" No Hay Documentos  \" ];\n");
        }
        fprintf(graficar, "} \n");
        fclose(graficar);

        fstream archivo("PilaDocumentosEscritorio.txt");
        string acum;
        if(!archivo.is_open())
            archivo.open("PilaDocumentosEscritorio.txt",ios::in);
        while(getline(archivo,acum))
            pila = pila + acum;

        archivo.close();
        return pila;
    }
    int getsize()
    {
        return size;
    }
};

//****************************Estructura lista doblemente enlazada ordenada del escritorio*********************//

struct NodoEscritorio
{
private:

    string Escritorio;
    int Id;
    string Estado;
    int Documentos;
    int Registro;
    PilaDocumentosEscritorio* Pila;
    ColaPasajerosEscritorio* Cola;

public:
    NodoEscritorio* Next;
    NodoEscritorio* Prev;


    NodoEscritorio(PilaDocumentosEscritorio* Pila,ColaPasajerosEscritorio* Cola,string Escritorio,int Id,string Estado,int Documentos,int Registro)
    {
        this->Escritorio = Escritorio;
        this->Id = Id;
        this->Estado = Estado;
        this->Documentos = Documentos;
        this->Registro = Registro;
        this->Pila = Pila;
        this->Cola = Cola;
        Next = nullptr;
        Prev = nullptr;
    }
    //Datos de la Cola
    int getIdCola()
    {
        return Cola->getId();
    }
    int getMaletasCola()
    {
        return Cola->getMaletas();
    }
    int getDocumentosCola()
    {
        return Cola->getDocumentos();
    }
    int getRegistroCola()
    {
        return Cola->getRegistro();
    }
    string getColaPasajerosEscritorio()
    {
        return Cola->gColaPasajerosEscritorio();
    }
    //Datos de la Pila
    string getPilaDocumentosEscritorio()
    {
        return Pila->gPilaDocumentosEscritorio();
    }
    //Datos de la Lista Doble Ordenada
    string getEscritorioLista()
    {
        return this->Escritorio;
    }
    int getIdLista()
    {
        return this->Id;
    }
    string getEstadoLista()
    {
        return this->Estado;
    }
    int getDocumentosLista()
    {
        return this->Documentos;
    }
    int getRegistroLista()
    {
        this->Registro;
    }
    void setRegistroLista(int Registro)
    {
        this->Registro = Registro;
    }
};

struct ListaDobleOrdenadaEscritorio
{
private:

    NodoEscritorio* First;
    NodoEscritorio* Last;
    int size;

public:
    ListaDobleOrdenadaEscritorio()
    {
       First = nullptr;
       Last = nullptr;
       size = 0;
    }
    void addListaDobleOrdenadaEscritorio(NodoEscritorio *TheNew)
    {
       if(First == nullptr)
       {
           First = Last = TheNew;
           size++;
       }
       if(First->Next == nullptr)
       {
           int comp = TheNew->getEscritorioLista().compare(First->getEscritorioLista());
           if(comp > 0)
           {
               Last->Next = TheNew;
               TheNew->Prev = Last;
               Last = TheNew;
               size++;
           }
           if(comp < 0)
           {
               TheNew->Next = First;
               First->Prev = TheNew;
               First = TheNew;
               First->Prev = nullptr;
               size++;
           }
       }
       NodoEscritorio* aux = First;
       NodoEscritorio* Prev = nullptr;
       while(aux->Next != nullptr)
       {
           int comp = TheNew->getEscritorioLista().compare(aux->getEscritorioLista());
           if(comp > 0)
           {
               Prev = aux;
               aux = aux->Next;
               continue;
           }
           if(comp < 0)
           {
               if(Prev == nullptr)
               {
                   TheNew->Next = First;
                   First->Prev = TheNew;
                   First = TheNew;
                   First->Prev = nullptr;
               }
               else
               {
                   TheNew->Next = aux;
                   Prev->Next = TheNew;
                   TheNew->Prev = Prev;
                   aux->Prev = TheNew;
               }
               size++;
           }
       }
        TheNew->Next = aux;
        Prev->Next = TheNew;
        TheNew->Prev = Prev;
        aux->Prev = TheNew;
        size++;
    }
    void delListaDobleOrdenadaEscritorio()
    {
        First = Last = nullptr;
        size = 0;
    }

};

    QString buscarcadena(QString val){
        MyNodeDouble<T> *aux = first;
        QString cad = nullptr;
        while(aux!=nullptr){
            if(val == aux->getVal().getnombre()){
                cad = aux->getVal().getcadena();
                return cad;
            }
            aux = aux->next;
        }
    }
    int buscar(QString val){
        MyNodeDouble<T> *aux = first;
        int cont = 0;
        while(aux!=nullptr){
            if(val == aux->getVal().getnombre()){
                return cont;
            }
            aux = aux->next;
            cont++;
        }
    }
    void editlist(int pos,T val){
        MyNodeDouble<T> *aux = first;
        int cont=0;
        if(pos>=size){
            qInfo()<<"estas fuera de rango de la lista";
        }else{
            while(aux!=nullptr){
                if(pos==cont){
                    aux->setVal((val));
                }
                cont++;
                aux = aux->next;
            }
        }
    }
   void glistdoble(){
       FILE *graficar;
       graficar = fopen("agenda.dot","w+");
       fprintf(graficar, "digraph G {bgcolor=\"white:yellow\" gradientangle=0 \n");
       fprintf(graficar, "rankdir = LR; \n");
       fprintf(graficar, "node [fillcolor=\"white\" \n");
       fprintf(graficar, "style=filled gradientangle=270,shape=record, width=.1, height=.1]; \n");
       fprintf(graficar, "node[ width=1.5 ]; \n");
       MyNodeDouble<T> *aux = first;
       int cont = 0;
       while(aux != nullptr){
           QString nameq =  aux->getVal().getnombre();
           string name = nameq.toStdString();
           QString apellidoq = aux->getVal().getapellido();
           string apellido = apellidoq.toStdString();
           QString aliasq = aux->getVal().getnickname();
           string alias = aliasq.toStdString();
           fprintf(graficar,"nd%d\ [label = \"{<a> | <b> | %s\ %s\ %s\ | <c> | <d>  }\" ];\n",cont,name.data(),apellido.data(),alias.data());
           cont++;
           aux = aux ->next;
       }
       fprintf(graficar," nd0:a -> nullinicio [ penwidth = 2 fontsize = 15 fontcolor = \"black\" label = \"ant\" ];\n");
       int cont2 = 0;
       while(cont2<cont-1){
           int aux = cont2 +1;
           fprintf(graficar,"nd%d\:d -> nd%d\:a [ penwidth = 2 fontsize = 15 fontcolor = \"black\" label = \"sig\" ];\n",cont2,aux);
           fprintf(graficar,"nd%d\:b -> nd%d\:c [ penwidth = 2 fontsize = 15 fontcolor = \"black\" label = \"ant\" ];\n",aux,cont2);
           cont2++;
       }
       fprintf(graficar,"nd%d\:d -> nullfinal [ penwidth = 2 fontsize = 15 fontcolor = \"black\" label = \"sig\" ];\n",cont2);
       fprintf(graficar, "} \n");
       fclose(graficar);
       system("dot -Tpng agenda.dot > agenda.png");
       system("gnome-open agenda.png");
   }

#endif // LISTADOBLEORDENADAESCRITORIO_H
