#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int data;
    struct No *proximo;
} No;

typedef struct Pilha
{
    No *topoDaPilha;
} Pilha;

Pilha *criaPilha()
{
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    if (pilha == NULL)
    {
        printf("Erro ao alocar memoria");
        exit(1);
    }
    pilha->topoDaPilha = NULL;
    return pilha;
}

void inserirElementoNoTopo(Pilha *p, int data)
{

    No *novoNO = (No *)malloc(sizeof(No));
    if (novoNO == NULL)
    {
        printf("Erro ao alocar memoria para o novo no ");
        exit(1);
    }
    novoNO->data = data;
    novoNO->proximo = p->topoDaPilha;
    printf("O valor %d foi inserido na pilha", data);
}

int removeElementoDaFila(Pilha *p)
{
    if (p->topoDaPilha == NULL)
    {
        printf("PIlha vazia");
        return -1;
    }
    No *temp = p->topoDaPilha;
    int valorRmovido = temp->data;
    p->topoDaPilha = temp->proximo;
    free(temp);
    printf("O valor da %d foi removido da pilha", valorRmovido);
    return valorRmovido;
}

int mostraElementoDoTopo(Pilha *p)
{
    if (p->topoDaPilha == NULL)
    {
        printf("A pilha esta vazia");
        return -1;
    }
    return p->topoDaPilha->data;
}

void imprimePilha(Pilha *p)
{
    No *valorAtualNOTopo = p->topoDaPilha;
    printf("Pilha---- \n");
    while (valorAtualNOTopo != NULL)
    {
        printf("-%d-", valorAtualNOTopo->data);
        valorAtualNOTopo = valorAtualNOTopo->proximo;
    }
    printf("\n");
}

int main()
{
    Pilha *p = criaPilha();

    inserirElementoNoTopo(p, 10);
    inserirElementoNoTopo(p, 20);
    inserirElementoNoTopo(p, 30);
    inserirElementoNoTopo(p, 40);
    inserirElementoNoTopo(p, 50);

    imprimePilha(p);

    removeElementoDaFila(p);

    imprimePilha(p);

    printf("mostrar elemento do Topo: %d", mostraElementoDoTopo(p));

    return 0;
}