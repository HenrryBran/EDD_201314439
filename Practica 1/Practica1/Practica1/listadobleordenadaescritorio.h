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
    int turnos;
public:
    NodoColaPasajerosEscritorio* Next;
    NodoColaPasajerosEscritorio(int Id,int Maletas,int Documentos,int turnos)
    {
        this->Id = Id;
        this->Maletas = Maletas;
        this->Documentos = Documentos;
        this->turnos = turnos;
        Next = nullptr;
    }
    string geNodoColaPasajerosEscritorio()
    {
        return to_string(this->Id)
                + "^" + to_string(this->Maletas)
                + "^" + to_string(this->Documentos)
                + "^" + to_string(this->turnos);
    }
    void setturno(int turnos)
    {
        this->turnos = turnos;
    }
    int getturno()
    {
        return this->turnos;
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
    int size;
public:
    NodoColaPasajerosEscritorio* First;
    NodoColaPasajerosEscritorio* Last;
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
                delete First;
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
                int Registro = aux->getturno();
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
    int getturnocola()
    {
        return First->getturno();
    }
    void setturnocola(int turno)
    {
        this->First->setturno(turno);
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
private:
    int size;
public:
    NodoPilaDocumentosEscritorio* First;
    NodoPilaDocumentosEscritorio* Last;
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
        delete First;
        delete Last;
        size = 0;
    }
    string gPilaDocumentosEscritorio(){
        string pila;
        FILE *graficar;
        graficar = fopen("PilaDocumentosEscritorio.txt","w+");

        if(First != nullptr)
        {
            NodoPilaDocumentosEscritorio *aux = First;
            while(aux != nullptr){
                int Documentos = aux->getDocumentos();
                fprintf(graficar,"nd%p\ [label = \"Documento No: %d\ \" ];\n",aux,Documentos);
                aux = aux->Next;
            }

            NodoPilaDocumentosEscritorio *aux2 = First;
            while(aux2 != Last){
                fprintf(graficar,"nd%p\ -> nd%p\ [ penwidth = 2 fontsize = 15 fontcolor = \"black\" label = \"\" ];\n",aux2->Next,aux2);
                aux2 = aux2->Next;
            }
        }

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
    string firstpila()
    {
        string cola = "libre";
        if(First != nullptr)
        {
            FILE *graficar;
            graficar = fopen("firstpila.txt","w+");
            NodoPilaDocumentosEscritorio *aux = Last;
            fprintf(graficar,"nd%p\ ",aux);
            fclose(graficar);

            fstream archivo("firstpila.txt");
            string todo;
            string acum;
            if(!archivo.is_open())
                archivo.open("firstpila.txt",ios::in);
            while(getline(archivo,acum))
                todo = todo + acum;
            archivo.close();
            cola = todo;
        }
        return cola;
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
    int Maletas;
    int turnos;
    PilaDocumentosEscritorio* Pila;
    ColaPasajerosEscritorio* Cola;
public:
    NodoEscritorio* Next;
    NodoEscritorio* Prev;
    NodoEscritorio(PilaDocumentosEscritorio* Pila,ColaPasajerosEscritorio* Cola,string Escritorio,int Id,bool Estado,int Documentos,int Maletas,int turnos)
    {
        this->Escritorio = Escritorio;
        this->Id = Id;
        this->Estado = Estado;
        this->Documentos = Documentos;
        this->Maletas = Maletas;
        this->turnos = turnos;
        this->Pila = Pila;
        this->Cola = Cola;
        Next = nullptr;
        Prev = nullptr;
    }

    //Datos de la Cola
    int getIdCola()
    {
        return this->Cola->getId();
    }
    int getMaletasCola()
    {
        return this->Cola->getMaletas();
    }
    int getDocumentosCola()
    {
        return this->Cola->getDocumentos();
    }
    int getRegistroCola()
    {
        return this->Cola->getturnocola();
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
    void setRegistroCola(int turno)
    {
        this->Cola->setturnocola(turno);
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
    string firstpila()
    {
        return this->Pila->firstpila();
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
    int getturnos()
    {
        return this->turnos;
    }
    void setturnos(int turnos)
    {
        this->turnos = turnos;
    }
    int getMaletasLista()
    {
        return this->Maletas;
    }
    void setdatos(string Escritorio,int Id,bool Estado,int Documentos,int Maletas,int turnos)
    {
        this->Escritorio = Escritorio;
        this->Id = Id;
        this->Estado = Estado;
        this->Documentos = Documentos;
        this->Maletas = Maletas;
        this->turnos = turnos;
    }
};

struct ListaDobleOrdenadaEscritorio
{
private:    
    int size;
public:
    NodoEscritorio* First;
    NodoEscritorio* Last;
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
       //qInfo()<<"Se ingreso al agregar de doble ordenada"<<endl;
       //cout<<TheNew->getEscritorioLista()<<"Se ingreso de primero"<<endl;
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
        delete First;
        delete Last;
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
                int Maletas = aux->getMaletasLista();
                bool Estado = aux->ColaVacia();
                int turnos;
                if(aux->ColaVacia() == false)
                {
                    aux->setturnos(aux->getRegistroCola());
                    turnos = aux->getturnos();
                }
                if (Estado == true) {
                    fprintf(graficar,"nd%p\ [label = \"Escritorio: %s\ \\n Id Cliente: Libre \\n Estado: libre \\n  Documentos: 0 \\n Registro: 0 \\n Maletas: 0 \" ];\n",aux,Clave.data());
                }
                else{
                    fprintf(graficar,"nd%p\ [label = \"Escritorio: %s\ \\n Id Cliente: %d\ \\n Estado: Ocupado \\n  Documentos: %d\ \\n Registro: %d\ \\n Maletas: %d\ \" ];\n",aux,Clave.data(),Id,Documentos,turnos,Maletas);
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

            NodoEscritorio *aux5 = First;
            while(aux5 != nullptr){
                fprintf(graficar," %s\ \n",aux5->getPilaDocumentosEscritorio().data());
                aux5 = aux5->Next;
            }

            NodoEscritorio *aux6 = First;
            while(aux6 != nullptr){
                if(aux6->ColaVacia()==false)
                {
                    fprintf(graficar,"nd%p\ -> %s\ [ penwidth = 2 fontsize = 15 fontcolor = \"black\" label = \"Atiende (Cola)\" ];\n",aux6,aux6->firstcola().data());
                    fprintf(graficar,"nd%p\ -> %s\ [ penwidth = 2 fontsize = 15 fontcolor = \"black\" label = \"Contiene (Pila)\" ];\n",aux6,aux6->firstpila().data());
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
                    int turnos = aux->getturnos();
                    int Maletas = aux->getMaletasLista();

                    string Escritorio2 = aux2->getEscritorioLista();
                    int Id2 = aux2->getIdLista();
                    bool Estado2 = aux2->getEstadoLista();
                    int Documentos2 = aux2->getDocumentosLista();
                    int turnos2 = aux2->getturnos();
                    int Maletas2 = aux2->getMaletasLista();

                    aux->setdatos(Escritorio2,Id2,Estado2,Documentos2,Maletas2,turnos2);
                    aux2->setdatos(Escritorio,Id,Estado,Documentos,Maletas,turnos);
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
    int quitarturnos()
    {
        int quitar = 0;
        NodoEscritorio *aux = First;
        while(aux!=nullptr){
            if(!aux->ColaVacia())
            {
                if(aux->getRegistroCola() <= 1){
                    quitar = quitar + aux->getMaletasLista();
                    aux->delCola();
                    aux->delPila();
                    entrarventanilla();
                }else{
                    int dato = aux->getRegistroCola() - 1;
                    aux->setRegistroCola(dato);
                }
            }
            aux=aux->Next;
        }
        return quitar;
    }
    void entrarventanilla()
    {
        NodoEscritorio *aux = First;
        while(aux!=nullptr){
            if(!aux->ColaVacia())
            {
                aux->setdatos(aux->getEscritorioLista(),aux->getIdCola(),true,aux->getDocumentosCola(),aux->getMaletasCola(),aux->getturnos());
                aux->delPila();
                for(int i = 0; i< aux->getDocumentosCola();i++)
                {
                    aux->addPila(new NodoPilaDocumentosEscritorio(i));
                }
            }
            aux=aux->Next;
        }
    }
    bool colallena()
    {
        bool salida = false;
        NodoEscritorio* aux = First;
        while(aux!=nullptr)
        {
            if(aux->ColaLLena() == true)
            {
                salida = true;
            }
            else
            {
                return salida = false;
            }
            aux = aux->Next;
        }
        return salida;
    }
    int getsize()
    {
        return size;
    }
    string consola()
    {
        NodoEscritorio *aux = First;
        string consola = "\n         --------- --------- Escritorios de registro --------- --------- \n";
        if(First != nullptr)
        {
            while(aux != nullptr){
                int Id = aux->getIdLista();
                string Clave = aux->getEscritorioLista();
                int Documentos = aux->getDocumentosLista();
                bool Estado = aux->ColaVacia();
                int turnos = aux->getturnos();
                if (Estado == true) {
                     consola = consola + "Escritorio " + Clave + " : Libre \n ";
                     consola = consola + "\t Pasajero atendido: ninguno \n";
                     consola = consola + "\t Turnos restantes: 0 \n";
                     consola = consola + "\t Cantidad de documentos: 0 \n";
                }
                else{
                    consola = consola + "Escritorio " + Clave + " : Ocupado \n ";
                    consola = consola + "\t Pasajero atendido: " + to_string(Id) + "\n";
                    consola = consola + "\t Turnos restantes: " + to_string(turnos) + "\n";
                    consola = consola + "\t Cantidad de documentos: " + to_string(Documentos) + "\n";
                }
                aux = aux->Next;
            }
            consola = consola + "         ---------------------------------------------------------------\n";
            return consola;
        }
        consola = consola + "Vacio \n";
        return consola;
    }
};
#endif // LISTADOBLEORDENADAESCRITORIO_H
