#include <stdio.h>
#include <stdlib.h>
#include "contref.h"

memoria *lista = NULL;

void atualiza(memoria *elemento, int contador) { 
    elemento->contador += contador;
    if (elemento->contador == 0)
    {
        if (lista->prox != NULL)
        {
            memoria *indice = lista;
            if (indice !=elemento)
            {
                while (indice->prox != elemento)
                {
                    indice = indice->prox;
                }
                indice->prox = elemento->prox;
            }
            else
            {
                lista = elemento->prox;
            }
        }
        free(elemento->endereco);
        free(elemento);
    }
}

void *malloc2(int size_) 
{
    void *novaMemoria = (void *)malloc(size_);
    memoria *novoElemento = (memoria *)malloc(sizeof(memoria));
    novoElemento->endereco = novaMemoria;
    novoElemento->contador = 1;
    novoElemento->prox = NULL;
    if (lista == NULL)
    {
        lista= novoElemento;
    }
    else
    {
        memoria *aux = lista;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novoElemento;
    }
    return novaMemoria;
}

void atrib2(void **b, void *a) 
{                                               
    if ((*b) != NULL)
    {
        memoria *percorre = lista;
        while (percorre->endereco != (*b))
        {
            percorre = percorre->prox;
        }
        atualiza(percorre, -1);
        if (a != NULL)
        {
            (*b) = a;
            percorre = lista;
            while (percorre->endereco !=a)
            {
                percorre = percorre->prox;
            }
            atualiza(percorre, 1);
        }
        else
        {
            (*b)=NULL;
        }
    }
}

void dump()
{
    memoria *aux=lista;
    while (aux!=NULL)
    {
        free(aux->endereco);
        free(aux);
        aux=aux->prox;
    }
}

void print() 
{
    memoria *aux=lista;
    while (aux!=NULL)
    {
        printf("endereco: %d\t",aux->endereco);
        printf("ref:%d\n",aux->contador);
        aux=aux->prox;
    }
}

