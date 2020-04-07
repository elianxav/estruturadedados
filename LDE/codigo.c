#include <stdio.h>
#include <stdlib.h>

typedef struct tempNo{
    int dado;
    struct tempNo *prox;
    struct tempNo *ant;
}no;

void criar(no *prim){
    prim->prox = NULL;
}

void imprimir(no *prim){
    if(prim->prox == NULL){
        printf("Vazia");
    }else{
        printf("\n");
        no *aux = prim->prox;
        while(aux != NULL){
            printf("<-[%i]->", aux->dado);
            aux = aux->prox;
        }
    }
}

void inserir(no *prim, int v){
    no *novo = (no *) malloc(sizeof(no));
    novo->dado = v;
    novo->prox = NULL;
    novo->ant = NULL;
    if(prim->prox == NULL){
        prim->prox = novo;
    }else{
        no *aux = prim->prox;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
    }
}

void contar(no *prim)
{
    int x=0;

    no *aux = prim->prox;
    while(aux != NULL)
    {
        x++;
        aux = aux->prox;
    }
    printf("Quantidade de itens na lista: %i",x);
}

void maiorMenor(no *prim)
{
    int maior, menor;

    no *aux = prim->prox;
    maior = aux->dado;
    menor = aux->dado;

    while(aux != NULL)
    {
        if(aux->dado >= maior)
        {
            maior = aux->dado;
        }

        if(aux->dado <= menor)
        {
            menor = aux->dado;
        }

        aux = aux->prox;
    }
    printf("O maior valor é o %i e o menor é o %i", maior, menor);
}

void caiAoContrario(no *prim){
    if(prim->prox == NULL){
        printf("Vazia");
    }else{
        printf("\n");
        no *aux = prim->prox;
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }

        while(aux != NULL)
        {
            printf("[%i]",aux->dado);
            aux = aux->ant;
        }
    }
}

void menu(no *prim, int opc)
{
    int val;
    char x;

    printf("[1] Imprimir\n");
    printf("[2] Inserir\n");
    printf("[3] Contar\n");
    printf("[4] Mostrar maior e menor valor\n");
    printf("[5] Imprimir de trás para frente\n");
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
            printf("Entre com o valor a ser inserido: ");
            scanf("%i",&val);
            inserir(prim, val);
        }else if(opc == 3) 
        {
            contar(prim);
        }else if(opc == 4) 
        {
            maiorMenor(prim);
        }else if(opc == 5) 
        {
            caiAoContrario(prim);
        }

        printf("\n\n[1] continuar\n\nentrada: ");
        scanf("%i",&opc);
        system("clear");
        menu(prim, opc);
    }
}

void main(){
    no *prim = (no *) malloc(sizeof(no));
    criar(prim);
    menu(prim, 1);
}