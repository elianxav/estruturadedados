#include <stdio.h>
#include <stdlib.h>

typedef struct tempNo
{
    int dado;
    struct tempNo *prox;
}no;

void criar(no *prim)
{
    prim->prox = NULL;
}

void imprimir(no *prim)
{
    if(prim->prox == NULL)
    {
        printf("Vazia");
    }else
    {
        printf("\n");
        no *aux = prim->prox;
        do
        {
            printf("[%i]->", aux->dado);
            aux = aux->prox;
        }while(aux != prim->prox);
    }
    printf("\n");
}

void inserir(no *prim, int v)
{
    no *novo = (no *) malloc(sizeof(no));
    novo->dado = v;
    if(prim->prox == NULL)
    {
        prim->prox = novo;
    }else
    {
        no *aux = prim->prox;
        do
        { 
            aux = aux->prox;
        }while(aux->prox != prim->prox);
        aux->prox = novo;
    }
    novo->prox = prim->prox;
}

void menu(no *prim)
{
    int opc;
    char x;
    printf("[1] Imprimir\n");
    printf("[2] Inserir\n");
    printf("[3] Pesquisar\n");
    printf("[0] Sair\n\n");
    printf("Opção: ");
    scanf("%i",&opc);

    system("clear");

    if(opc != 0)
    {
        if(opc == 1)
        {
            imprimir(prim);
        }else if(opc == 2) 
        {
            //inserir(prim, );
        }else if(opc == 3) 
        {
            //pesquisar();s
        }

        printf("\nInsira qualquer valor: ");
        scanf("%c",&x);
        system("clear");
        menu(prim);
    }
}

void main(){
    no *prim;
    prim = malloc(sizeof(no));
    criar(prim);
    menu(prim);
}