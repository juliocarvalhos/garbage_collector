#ifndef CONTREF_H
#define CONTREF_H

typedef struct memoria
{
    void *endereco;
    int contador;
    struct memoria *prox;

}memoria;

void atualiza(memoria *elemento,int contador);
void *malloc2(int size_);
void atrib2(void **b,void *a);
void dump();
void print();

#endif // CONTREF_H
