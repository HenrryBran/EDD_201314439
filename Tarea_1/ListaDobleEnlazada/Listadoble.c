#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char * data;
    struct Node *Next;
    struct Node *Prev;
}Nodo;

typedef struct ListaDoble{
    Nodo *First;
    Nodo *Last;
    int size;
}ListaD;


void inicializacion(ListaD *lista);
int addFirst(ListaD *lista, char *data);
int addLast(ListaD *lista, Nodo *aux, char *data);
int delFirst(ListaD *lista);
int DelPos(ListaD *lista, int pos);
void print(ListaD *lista);
int menu(ListaD *lista,int *posi);


int main()
{
    char eleccion;
    char *data;
    ListaD *lista;
    Nodo *aux;

    if ((lista = (ListaD *) malloc (sizeof (ListaD))) == NULL)
        return -1;
    if ((data = (char *) malloc (50)) == NULL)
        return -1;

    aux = NULL;
    eleccion = 'o';

    inicializacion(lista);

    int posi, pos;

    while (eleccion!= 5){
      eleccion = menu (lista, &posi);
      switch (eleccion){
        case 1:
          printf ("Ingrese un elemento : ");
          scanf ("%s", data);
          getchar ();
          if (lista->size == 0)
            addFirst(lista, data);
          else
            addLast(lista,lista->Last,data);
          printf ("Dato ingresado  \n");
          break;
        case 2:
          printf ("Visualizacion : \n");
          if(lista->size != 0)
            print(lista);
          else
            printf("Lista Vacia!!! \n");
          break;
        case 3:
          if (lista->size != 0)
          {
            delFirst(lista);
            printf ("Elemento eliminado!!!\n");
          }
          else
            printf ("lista vacia \n");
          break;
        case 4:
          if (lista->size != 0)
          {
            do{
              printf ("Ingrese la posicion : \n");
              scanf ("%d", &pos);
            }
            while (pos < 1 || pos > lista->size);
            getchar();
            delPos(lista, pos);
            printf ("Elemento Eliminado!!! \n");
          }
          else
            printf ("lista vacia\n");
          break;
      }
  }
  return 0;
}

void inicializacion(ListaD *lista){
    lista->First = NULL;
    lista->Last = NULL;
    lista->size = 0;
}

int addFirst(ListaD *lista, char *data){
    Nodo *TheNew;

    if((TheNew = (Nodo *)malloc(sizeof(Nodo)))==NULL)
        return -1;
    if((TheNew->data = (char *)malloc(50*sizeof(char)))==NULL)
        return -1;
    strcpy(TheNew->data, data);

    TheNew->Next = NULL;
    TheNew->Prev = NULL;
    lista->First = TheNew;
    lista->Last = TheNew;
    lista->size++;
    return 0;
}

int addLast(ListaD *lista, Nodo *aux, char *data){
    Nodo *TheNew;
    if((TheNew = (Nodo *)malloc(sizeof(Nodo)))==NULL)
        return -1;
    if((TheNew->data = (char *)malloc(50*sizeof(char)))==NULL)
        return -1;

    strcpy(TheNew->data,data);

    aux->Next = TheNew;
    TheNew->Next = NULL;
    TheNew->Prev = aux;

    lista->Last = TheNew;
    lista->size++;
    return 0;
}

int delFirst(ListaD *lista){
    if(lista->size == 0)
        return -1;
    Nodo *aux_del;
    aux_del = lista->First;
    lista->First=lista->First->Next;
    if(lista->size==1)
        lista->Last= NULL;
    free(aux_del->data);
    free(aux_del);
    lista->size--;
    return 0;
}

int delPos(ListaD *lista, int pos){
    if(lista->size <= 1 ||  pos < 1 || pos >= lista->size)
        return -1;
    int i;
    Nodo *aux;
    Nodo *aux_del;
    aux = lista->First;
    for(i=1;i<pos;++i)
        aux = aux->Next;
    aux_del = aux->Next;
    aux->Next = aux->Next->Next;
    if(aux->Next==NULL)
        lista->Last = aux;
    free(aux_del->data);
    free(aux_del);
    lista->size--;
    return 0;
}

void print(ListaD *lista){
    if(lista->size != 0)
    {
        Nodo *aux;
        aux = lista->First;
        while(aux != NULL){
            printf("valor: %s\n",aux->data);
            aux = aux->Next;
        }
    }
    return;
}

int menu (ListaD *lista,int *posi){
  int eleccion;
  printf("********** MENU **********\n");
    printf ("1. Agregar \n");
    printf ("2. Visualizar\n");
    printf ("3. Eliminar Inicio\n");
    printf ("4. Eliminar Posicion (comienza 0)\n");
    printf ("5. Quitar\n");
  printf ("\n\nElegir: ");
  scanf ("%d", &eleccion);
  getchar();
  if(lista->size == 0 && eleccion == 2)
    eleccion = 5;
  return eleccion;
}
