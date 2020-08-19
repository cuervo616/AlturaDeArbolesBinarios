//De manera Recursiva encontrar el numero de nodos de un arbol arbol y su altura

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10

//---Estructuras
typedef struct nodo
{
    int dato;
    struct nodo *der;
    struct nodo *izq;
}nodo;

//-------------------------
int cont;
//---Prototipos
char menu();

nodo *crearNodo(int dato);
nodo *insertar(nodo *raiz,int dato);
nodo *arbolAleatorio(nodo *raiz);
void mostrarArbol(nodo *ruta);
void liberar(nodo*);
void contNodos(nodo *ruta);
void alturaArb(nodo*);
//-------------------------

int main()
{
    int dato;
    char op;
    bool ext = false;
    nodo *raiz = NULL;

    while (ext != true)
    {
        system("cls");
        op = menu();
        system("cls");
        switch (op)
        {
        case '1':
            raiz = arbolAleatorio(raiz);
            printf("\n");
            system("pause");
            break;
        case '2':
            //Ingresar Datos
            do
            {
                printf("\nIngrese -1 para Terminar");
                printf("\nIngrese Un Numero -> ");
                scanf("%d",&dato);
                if(dato != -1)
                {
                    raiz = insertar(raiz,dato);
                }
            } while (dato != -1);
            break;
        case '3':
            cont = 0;
            contNodos(raiz);
            printf("El numero de Nodos es -> %d\n",cont);
            system("pause");
            break;
        case '4':
            cont = 0;
            //alturaArb(raiz);
            printf("El arbol tiene una Altura -> %d Niveles\n",cont);
            system("pause");
            break;
        case '5':
            mostrarArbol(raiz);
            system("pause");
            break;
        case '6':
            liberar(raiz);
            raiz = NULL;
            printf("\nArbol eliminado\n");
            system("pause");
            break;
        case '0':
            ext = true;
            liberar(raiz);
            break;
        default:
            break;
        }
        
    }
    

}

char menu()
{
    char op;
    printf("\n------M E N U------\n");
    printf("1) Generar Arbol Aleatorio\n");
    printf("2) Ingresar Datos\n");
    printf("3) Numero de Nodos Ingresado\n");
    printf("4) Altura del Arbol Binario\n");
    printf("5) Mostrar Arbol\n");
    printf("6) Limpiar Arbol\n");
    printf("0) S A L I R\n");
    printf("OPCION -> ");
    scanf("%c",&op);
    return op;
}


nodo *crearNodo(int dato)
{
    nodo *nuevoNodo = (nodo*)malloc(sizeof(nodo));

    nuevoNodo->dato = dato;
    nuevoNodo->der = NULL;
    nuevoNodo->izq = NULL;

    return nuevoNodo;
}

nodo *insertar(nodo *raiz,int dato)
{
    if(raiz == NULL)
    { //Caso base
        return crearNodo(dato);
    }
    else
    {//recorrido por el arbol de manera recursiva
        if(dato < raiz->dato)
        {
            raiz->izq = insertar(raiz->izq,dato);
        }
        else
        {
            raiz->der = insertar(raiz->der,dato);
        }
    }
    
}

nodo *arbolAleatorio(nodo *raiz)
{
    srand(time(NULL));
    int i;
    int num;
    for(i = 0; i<N; ++i)
    {
        num = 1 + rand()%100;
        printf("\nNumero Aletorio Ingresado -> %d",num);
        raiz = insertar(raiz,num);
    }
    return raiz;
}

void mostrarArbol(nodo *raiz)
{//Arbol en inOrden
    if(raiz != NULL)
    {
        mostrarArbol(raiz->izq);
        printf("%d - ",raiz->dato);
        mostrarArbol(raiz->der);
    }
}

void liberar(nodo *ruta)
{
    nodo *eliminar = ruta;
    if(eliminar != NULL)
    {
        liberar(eliminar->izq);
        liberar(eliminar->der);
        free(eliminar);
    }

    return;
    
}

void contNodos(nodo *ruta)
{
    if(ruta != NULL)
    {
        contNodos(ruta->izq);
        contNodos(ruta->der);
        ++cont;
    }
}
/*
void alturaArb(nodo *raiz)
{
    nodo *ruta = raiz;
    if(ruta->izq && ruta->der != NULL)
    {
        ++cont;
        alturaArb(ruta->izq);
        alturaArb(ruta->der);
    }
    else if(ruta->izq != NULL)
    {
        ++cont;
        alturaArb(ruta->izq);

    }
    else if(ruta->der != NULL)
    { 
        ++cont;
        alturaArb(ruta->der);
    }
    return;
}*/