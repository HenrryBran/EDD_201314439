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

    ListaDobleOrdenadaEscritorio() {}
};

private:
    MyNodeDouble<T> *first;
    MyNodeDouble<T> *last;
    MyNodeDouble<T> *current;

    int size;

    void deletefirst(){
        MyNodeDouble<T> *aux;
        aux = first->next;
        first->next=nullptr;
        aux->ant = nullptr;
        first = nullptr;
        first = aux;
        size--;
    }
    void deletelast(){
        MyNodeDouble<T>*aux;
        aux = last->ant;
        last->ant = nullptr;
        aux->next = nullptr;
        last=nullptr;
        last = aux;
        size--;
    }
    void deletepos(int pos){
        MyNodeDouble<T> *aux = first;
        MyNodeDouble<T> *ant = nullptr;
        int contador = 0;
        while(contador<pos){
            ant = aux;
            aux = aux->next;
            contador++;
        }
        ant->next = aux->next;
        aux->next->ant = ant;
        delete aux;
        size--;
    }

public:
    MyListDouble(){
        listaVacia();
    }
    void listaVacia(){
        first = nullptr;
        last = nullptr;
        current = nullptr;
        size = 0;
    }
    bool estaVacia(){
        return first == nullptr;
    }
    QString getNext(){
        if(current == nullptr){
            return nullptr;
        }
        else if(current->next == nullptr){
            return nullptr;
        }else{
            current = current->next;
            return current->getVal().getnombre();
        }
    }
    QString getPrev(){
        if(current == nullptr){
            return nullptr;
        }
        else if(current->ant == nullptr){
            return nullptr;
        }else{
            current = current->ant;
            return current->getVal().getnombre();
        }
    }
    QString getCurrent(){
        if(current == nullptr){
            return nullptr;
        }else{
            return current->getVal().getnombre();
        }

    }
    QString getnombre(){
        if(current == nullptr){
            return nullptr;
        }
        return current->getVal().getnombre;
    }
    void firstcurrent(){
        current = first;
    }

    void add(T val){
        MyNodeDouble<T> *TheNew = new MyNodeDouble<T>(val);
        if(first == nullptr){
            first = last = current = TheNew;
            qInfo() << "Insertar el inicio de lista " + TheNew->getVal().getnombre();
            size++;
            return;
        }
        if(first->next == nullptr ){
            int comp = val.compareco(first->getVal());
            if(comp > 0){
                qInfo() << "Insertar directamente al final " + TheNew->getVal().getnombre();
                last->next = TheNew;
                TheNew->ant = last;
                last = TheNew;
                size++;
                return;
            }
            if(comp < 0){
                qInfo() << "Insertar directamente al inicio "+ TheNew->getVal().getnombre();
                TheNew->next = first;
                first->ant = TheNew;
                first = TheNew;
                first->ant = nullptr;
                size++;
                return;
            }
            return;
        }
        MyNodeDouble<T> *aux = first;
        MyNodeDouble<T> *ant = nullptr;
        while(aux->next != nullptr){
            int comp = val.compareco(aux->getVal());
            if(comp > 0){
                ant = aux;
                aux = aux->next;
                continue;
            }
            if(comp < 0){
                if(ant==nullptr){
                    qInfo() << "Insertando al inicio, antes de: " << aux->getVal().getnombre();
                    TheNew->next = first;
                    first->ant = TheNew;
                    first = TheNew;
                    first->ant = nullptr;

                }else{
                    qInfo() << "Insertando entre: " << ant->getVal().getnombre() << " y " << aux->getVal().getnombre();
                    TheNew->next = aux;
                    ant->next = TheNew;
                    TheNew->ant = ant;
                    aux->ant = TheNew;
                }
                size++;
                return;
            }
            qInfo() << "Elemento repetido " + TheNew->getVal().getnombre();
            return;
        }
        qInfo() << "Insertado al final " + TheNew->getVal().getnombre();
        TheNew->next = aux;
        ant->next = TheNew;
        TheNew->ant = ant;
        aux->ant = TheNew;
        size++;

    }
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
    QString print(){
        MyNodeDouble<T> *aux = first;
        QString acum = nullptr;
        while(aux != nullptr){
            acum = acum + aux->getVal().getnombre() + ";" ;
            aux = aux ->next;
        }
        return acum;
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

    void deleteall(int pos){
        if(first==nullptr){
            qInfo()<< "No hay elementos en la lista";
        }
        else if(pos == 0){
            deletefirst();
            qInfo()<< "Se elimino el primer elemento";
        }
        else if(pos == size -1){
            deletelast();
            qInfo()<<  "Se elimino el ultimo elemento";
        }
        else if(pos==size){
            qInfo()<<  "Esta fuera de rango";
        }
        else if(pos>0 && pos < size-1){
            deletepos(pos);
            qInfo()<<  "Se elimino el elemento intermedio";
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
    int sizelist(){
       return size-1;
    }
   void reseteardoble(){
       first = nullptr;
       last = nullptr;
       current = nullptr;
   }

   void ordenar(int orden){
       MyNodeDouble<T> *aux,*aux2;

       aux = first;
       int cont = 0;
       int comp;
       while(aux!=nullptr){
           aux2 = aux->next;
           while(aux2!=nullptr){
               if(orden == 0){
                   comp = aux->getVal().comparena(aux2->getVal());
               }
               if(orden == 1){
                   comp = aux->getVal().compareap(aux2->getVal());
               }
               if(orden == 2){
                   comp = aux->getVal().compareni(aux2->getVal());
               }
               if(comp > 0 ){
                   QString correo = aux->getVal().getcorreo();
                   QString nombre = aux->getVal().getnombre();
                   QString apellido =  aux->getVal().getapellido();
                   QString nickname = aux->getVal().getnickname();
                   QString edad = aux->getVal().getedad();
                   QString numero = aux->getVal().getnumero();
                   Agenda p(correo,nombre,apellido,nickname,edad,numero);
                   aux->setVal(aux2->getVal());
                   aux2->setVal(p);
                   aux2 = aux2->next;
                   cont++;
               }
               if(comp <= 0){
                   aux2 = aux2->next;
                   cont++;
               }
           }
           aux = aux->next;
           cont = 0;
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
