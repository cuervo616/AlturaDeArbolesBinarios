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

//---Prototipos
char menu();
nodo *crearNodo(int dato);
nodo *insertar(nodo *raiz,int dato);
nodo *arbolAleatorio(nodo *raiz);
//-------------------------

int main()
{
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
            system("pause");
            break;
        case '2':
            //Ingresar Datos
            printf("Ingrese Un Numero -> ");
            
            break;
        case '3':
            break;
        case '4':
            break;
        case '0':
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
    printf("0) S A L I R\n");
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