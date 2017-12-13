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
public:
    NodoColaPasajerosEscritorio* First;
    NodoColaPasajerosEscritorio* Last;
    int size;
    ColaPasajerosEscritorio()
    {
        First = nullptr;
        Last = nullptr;
        size = 0;
    }
    bool estaVacia()
    {
        return First == nullptr;
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
        if(First != nullptr)
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
    }
    string gColaPasajerosEscritorio(){
        string cola;
        FILE *graficar;
        graficar = fopen("ColaPasajerosEscritorio.txt","w+");

        if(First != nullptr)
        {
            NodoColaPasajerosEscritorio *aux = First;
            while(aux != nullptr){
                int Id = aux->getId();
                int Maletas = aux->getMaletas();
                int Documentos = aux->getDocumentos();
                int Registro = aux->getRegistro();
                fprintf(graficar,"nd%p\ [label = \" Pasajero Id: %d\ \\n Maletas : %d\ \\n Documentos: %d\  \\n  Registro: %d\ Turnos \" ];\n",aux,Id,Maletas,Documentos,Registro);
                aux = aux->Next;
            }

            NodoColaPasajerosEscritorio *aux2 = First;
            while(aux2 != Last){
                fprintf(graficar,"nd%p\ -> nd%p\ [ penwidth = 2 fontsize = 15 fontcolor = \"black\" label = \"Next\" ];\n",aux2,aux2->Next);
                aux2 = aux2->Next;
            }
        }

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
    bool estallena()
    {
        return size == 11;
    }
    string firstcola()
    {
        string cola = "libre";
        if(First != nullptr)
        {
            FILE *graficar;
            graficar = fopen("firstcola.txt","w+");
            NodoColaPasajerosEscritorio *aux = First;
            fprintf(graficar,"nd%p\ ",aux);
            fclose(graficar);

            fstream archivo("firstcola.txt");
            string todo;
            string acum;
            if(!archivo.is_open())
                archivo.open("firstcola.txt",ios::in);
            while(getline(archivo,acum))
                todo = todo + acum;
            archivo.close();
            cola = todo;
        }
        return cola;
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
    NodoPilaDocumentosEscritorio* First;
    NodoPilaDocumentosEscritorio* Last;
    int size;
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

        fprintf(graficar, "subgraph cluster_7{ \n");
        fprintf(graficar, "node [shape = square] color = orange style=filled; \n");
        fprintf(graficar, "label=\" Documentos de pasajero\"; \n");

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
    bool Estado;
    int Documentos;
    int Registro;
    int Maletas;
    PilaDocumentosEscritorio* Pila;
    ColaPasajerosEscritorio* Cola;

public:
    NodoEscritorio* Next;
    NodoEscritorio* Prev;


    NodoEscritorio(PilaDocumentosEscritorio* Pila,ColaPasajerosEscritorio* Cola,string Escritorio,int Id,bool Estado,int Documentos,int Registro,int Maletas)
    {
        this->Escritorio = Escritorio;
        this->Id = Id;
        this->Estado = Estado;
        this->Documentos = Documentos;
        this->Registro = Registro;
        this->Maletas = Maletas;
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
    string gColaPasajerosEscritorio()
    {
        return this->Cola->gColaPasajerosEscritorio();
    }
    string firstcola()
    {
        return this->Cola->firstcola();
    }
    void addCola(NodoColaPasajerosEscritorio* TheNew)
    {
        this->Cola->addColaPasajerosEscritorio(TheNew);
    }
    bool ColaLLena()
    {
        return this->Cola->estallena();
    }
    void setRegistroCola(int Registro)
    {
        this->Cola->setRegistro(Registro);
    }
    void delCola()
    {
        this->Cola->delColaPasajerosEscritorio();
    }
    bool ColaVacia()
    {
        return this->Cola->estaVacia();
    }
    //Datos de la Pila
    string getPilaDocumentosEscritorio()
    {
        return Pila->gPilaDocumentosEscritorio();
    }
    void delPila()
    {
        this->Pila->delPilaDocumentosEscritorio();
    }
    void addPila(NodoPilaDocumentosEscritorio* TheNew)
    {
        this->Pila->addPilaDocumentosEscritorio(TheNew);
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
    bool getEstadoLista()
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
    int getMaletasLista()
    {
        return this->Maletas;
    }
    void setdatos(string Escritorio,int Id,bool Estado,int Documentos,int Registro,int Maletas)
    {
        this->Escritorio = Escritorio;
        this->Id = Id;
        this->Estado = Estado;
        this->Documentos = Documentos;
        this->Registro = Registro;
        this->Maletas = Maletas;
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
    bool estavacia()
    {
        return First == nullptr;
    }
    void addListaDobleOrdenadaEscritorio(NodoEscritorio *TheNew)
    {
       qInfo()<<"Se ingreso al agregar de doble ordenada"<<endl;
       cout<<TheNew->getEscritorioLista()<<"Se ingreso de primero"<<endl;
       if(First == nullptr)
       {
           First = Last = TheNew;
           //cout<<TheNew->getEscritorioLista()<<"Se ingreso de primero"<<endl;
           //qInfo()<<"primer valor " + QString::fromStdString(TheNew->getEscritorioLista())<<endl;
           size++;
           return;
       }
       if(First->Next == nullptr)
       {
           int comp = TheNew->getEscritorioLista().compare(First->getEscritorioLista());
           //cout<<"Se compara 1 - 2"<<endl;
           //cout<<TheNew->getEscritorioLista()<<" Se comparo nuevo"<<endl;
           //cout<<First->getEscritorioLista()<<" Se comparo primero"<<endl;
           if(comp > 0)
           {
               Last->Next = TheNew;
               TheNew->Prev = Last;
               Last = TheNew;
               size++;
               //cout<<TheNew->getEscritorioLista()<<" Se ingreso despueas del primero"<<endl;
               return;
           }
           if(comp < 0)
           {
               TheNew->Next = First;
               First->Prev = TheNew;
               First = TheNew;
               First->Prev = nullptr;
               size++;
               //cout<<TheNew->getEscritorioLista()<<" Se ingreso antes del primero"<<endl;
               return;
           }
           return;
       }
       NodoEscritorio* aux = First;
       NodoEscritorio* Prev = nullptr;

       while(aux->Next != nullptr)
       {

           int comp = TheNew->getEscritorioLista().compare(aux->getEscritorioLista());
           //cout<<"Se compara nuevo - auxliar"<<endl;
           //cout<<TheNew->getEscritorioLista()<<"Se comparo nuevo"<<endl;
           //cout<<aux->getEscritorioLista()<<"Se comparo auxiliar"<<endl;

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
                   //se ingreso al principio
               }
               else
               {
                   TheNew->Next = aux;
                   Prev->Next = TheNew;
                   TheNew->Prev = Prev;
                   aux->Prev = TheNew;
                   //se ingreso entre los datos
               }
               size++;
               return;
           }
           //repetido
           //cout<<"Repetido"<<endl;
           return;
       }
        TheNew->Next = aux;
        Prev->Next = TheNew;
        TheNew->Prev = Prev;
        aux->Prev = TheNew;
        size++;
        //se ingreso de ultimo
    }
    void delall()
    {
        First = Last = nullptr;
        delete First,Last;
        size = 0;
    }
    string gListaDobleOrdenadaEscritorio()
    {
        string lista;
        FILE *graficar;
        graficar = fopen("ListaDobleOrdenadaEscritorio.txt","w+");

        fprintf(graficar, "subgraph cluster_5 { {rank=min; \n");
        fprintf(graficar, "node [shape = square] color = orange style=filled; \n");
        fprintf(graficar, "label=\" Estacion de Escritorios \"; \n");

        if(First != nullptr)
        {
            NodoEscritorio *aux = First;
            while(aux != nullptr){
                int Id = aux->getIdLista();
                string Clave = aux->getEscritorioLista();
                int Documentos = aux->getDocumentosLista();
                int Registro = aux->getRegistroLista();
                bool Estado = aux->getEstadoLista();
                if (!Estado) {
                    fprintf(graficar,"nd%p\ [label = \"Escritorio: %s\ \\n Id Cliente: Libre \\n Estado: libre \\n  Documentos: 0 \\n Registro: 0 \" ];\n",aux,Clave.data());
                }
                else{
                    fprintf(graficar,"nd%p\ [label = \"Escritorio: %s\ \\n Id Cliente: %d\ \\n Estado: Ocupado \\n  Documentos: %d\ \\n Registro: %d\ \" ];\n",aux,Clave.data(),Id,Documentos,Registro);
                }
                aux = aux->Next;
            }

            fprintf(graficar, "} \n");

            NodoEscritorio *aux2 = First;
            while(aux2 != Last){
                fprintf(graficar,"nd%p\ -> nd%p\ [ penwidth = 2 fontsize = 15 fontcolor = \"black\" label = \"Next\" ];\n",aux2,aux2->Next);
                aux2 = aux2->Next;
            }

            NodoEscritorio *aux3 = Last;
            while(aux3 != First){
                fprintf(graficar,"nd%p\ -> nd%p\ [ penwidth = 2 fontsize = 15 fontcolor = \"black\" label = \"Prev\" ];\n",aux3,aux3->Prev);
                aux3 = aux3->Prev;
            }

            NodoEscritorio *aux4 = First;
            while(aux4 != nullptr){
                fprintf(graficar," %s\ \n",aux4->gColaPasajerosEscritorio().data());
                aux4 = aux4->Next;
            }

            NodoEscritorio *aux6 = First;
            while(aux6 != nullptr){
                if(aux6->ColaVacia()==false)
                {
                    fprintf(graficar,"nd%p\ -> %s\ [ penwidth = 2 fontsize = 15 fontcolor = \"black\" label = \"Next\" ];\n",aux6,aux6->firstcola().data());
                }
                aux6 = aux6->Next;
            }
        }
        else
        {
            fprintf(graficar," ListaDobleOrdenadaEscritorioNada[label = \" Escritorios Vacios \" ];\n");
            fprintf(graficar, "} \n");
        }

        fprintf(graficar, "} \n");
        fclose(graficar);

        fstream archivo("ListaDobleOrdenadaEscritorio.txt");

        string acum;

        if(!archivo.is_open())
            archivo.open("ListaDobleOrdenadaEscritorio.txt",ios::in);

        while(getline(archivo,acum))
            lista = lista + acum;

        archivo.close();
        return lista;
    }
    void ordenar(){
        NodoEscritorio *aux,*aux2;

        aux = First;
        int cont = 0;
        int comp;
        while(aux!=nullptr){
            aux2 = aux->Next;
            while(aux2!=nullptr){
                    comp = aux->getEscritorioLista().compare(aux2->getEscritorioLista());
                if(comp > 0 ){
                    string Escritorio = aux->getEscritorioLista();
                    int Id = aux->getIdLista();
                    bool Estado = aux->getEstadoLista();
                    int Documentos = aux->getDocumentosLista();
                    int Registro = aux->getDocumentosLista();
                    int Maletas = aux->getMaletasCola();

                    string Escritorio2 = aux2->getEscritorioLista();
                    int Id2 = aux2->getIdLista();
                    bool Estado2 = aux2->getEstadoLista();
                    int Documentos2 = aux2->getDocumentosLista();
                    int Registro2 = aux2->getDocumentosLista();
                    int Maletas2 = aux2->getMaletasCola();

                    aux->setdatos(Escritorio2,Id2,Estado2,Documentos2,Registro2,Maletas2);
                    aux2->setdatos(Escritorio,Id,Estado,Documentos,Registro,Maletas);
                    aux2 = aux2->Next;
                    cont++;
                }
                if(comp <= 0){
                    aux2 = aux2->Next;
                    cont++;
                }
            }
            aux = aux->Next;
            cont = 0;
        }
     }
    void llenarcola(NodoColaPasajerosEscritorio* TheNew)
    {
        NodoEscritorio* aux = First;
        while(aux!=nullptr)
        {
            if(!aux->ColaLLena())
            {
                aux->addCola(TheNew);
                break;
            }
            aux = aux->Next;
        }
    }
    void quitarturnos()
    {
        NodoEscritorio *aux = First;
        while(aux!=nullptr){
            if(!aux->ColaVacia())
            {
                if(aux->getRegistroLista() <= 1){
                    aux->delCola();
                    entrarventanilla();
                }else{
                    int dato = aux->getRegistroLista() - 1;
                    aux->setRegistroLista(dato);
                    aux->setRegistroCola(dato);
                }
            }
            aux=aux->Next;
        }
    }
    void entrarventanilla()
    {
        NodoEscritorio *aux = First;
        while(aux!=nullptr){
            if(!aux->ColaVacia())
            {
                aux->setdatos(aux->getEscritorioLista(),aux->getIdCola(),true,aux->getDocumentosCola(),aux->getRegistroCola(),aux->getMaletasCola());
            }
            aux=aux->Next;
        }
    }

};
#endif // LISTADOBLEORDENADAESCRITORIO_H
