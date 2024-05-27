#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da pilha
typedef struct No
{
    int data;
    struct No *proximo;
} No;

// Definição da estrutura da pilha
typedef struct Pilha
{
    No *topoDaPilha;
} Pilha;

// Função para criar uma nova pilha
Pilha *criaPilha()
{
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha)); // Aloca memória para a pilha
    if (pilha == NULL)
    {
        printf("Erro ao alocar memória\n"); // Verifica se a alocação foi bem-sucedida
        exit(1);
    }
    pilha->topoDaPilha = NULL; // Inicializa o topo da pilha como NULL
    return pilha;              // Retorna a pilha criada
}

// Função para inserir um elemento no topo da pilha
void inserirElementoNoTopo(Pilha *p, int data)
{
    No *novoNO = (No *)malloc(sizeof(No)); // Aloca memória para um novo nó
    if (novoNO == NULL)
    {
        printf("Erro ao alocar memória para o novo nó\n"); // Verifica se a alocação foi bem-sucedida
        exit(1);
    }
    novoNO->data = data;                                // Define o valor do novo nó
    novoNO->proximo = p->topoDaPilha;                   // Aponta o novo nó para o antigo topo da pilha
    p->topoDaPilha = novoNO;                            // Atualiza o topo da pilha para o novo nó
    printf("O valor %d foi inserido na pilha\n", data); // Imprime uma mensagem de confirmação
}

// Função para remover um elemento do topo da pilha
int removeElementoDaFila(Pilha *p)
{
    if (p->topoDaPilha == NULL)
    {
        printf("Pilha vazia\n"); // Verifica se a pilha está vazia
        return -1;
    }
    No *temp = p->topoDaPilha;                                   // Armazena o nó do topo da pilha em uma variável temporária
    int valorRemovido = temp->data;                              // Armazena o valor do nó do topo
    p->topoDaPilha = temp->proximo;                              // Atualiza o topo da pilha para o próximo nó
    free(temp);                                                  // Libera a memória do nó removido
    printf("O valor %d foi removido da pilha\n", valorRemovido); // Imprime uma mensagem de confirmação
    return valorRemovido;                                        // Retorna o valor removido
}

// Função para mostrar o elemento do topo da pilha
int mostraElementoDoTopo(Pilha *p)
{
    if (p->topoDaPilha == NULL)
    {
        printf("A pilha está vazia\n"); // Verifica se a pilha está vazia
        return -1;
    }
    return p->topoDaPilha->data; // Retorna o valor do topo da pilha
}

// Função para imprimir todos os elementos da pilha
void imprimePilha(Pilha *p)
{
    No *valorAtualNOTopo = p->topoDaPilha; // Começa no topo da pilha
    printf("Pilha----\n");
    while (valorAtualNOTopo != NULL)
    {                                                 // Percorre todos os nós da pilha
        printf("-%d-\n", valorAtualNOTopo->data);     // Imprime o valor de cada nó
        valorAtualNOTopo = valorAtualNOTopo->proximo; // Vai para o próximo nó
    }
    printf("\n");
}

// Procedimento para ordenar a pilha em ordem crescente
void ordenacao(Pilha *p)
{
    Pilha *pilhaAuxiliar = criaPilha(); // Cria uma pilha auxiliar
    while (p->topoDaPilha != NULL)
    {                                       // Enquanto a pilha original não estiver vazia
        int temp = removeElementoDaFila(p); // Remove o elemento do topo da pilha original
        while (pilhaAuxiliar->topoDaPilha != NULL && mostraElementoDoTopo(pilhaAuxiliar) > temp)
        {
            inserirElementoNoTopo(p, removeElementoDaFila(pilhaAuxiliar)); // Move elementos da pilha auxiliar para a original até encontrar a posição correta
        }
        inserirElementoNoTopo(pilhaAuxiliar, temp); // Insere o elemento na pilha auxiliar
    }
    while (pilhaAuxiliar->topoDaPilha != NULL)
    { // Move os elementos da pilha auxiliar de volta para a pilha original
        inserirElementoNoTopo(p, removeElementoDaFila(pilhaAuxiliar));
    }
    free(pilhaAuxiliar); // Libera a memória da pilha auxiliar
}

int main()
{
    Pilha *p = criaPilha(); // Cria uma nova pilha

    // Insere elementos na pilha
    inserirElementoNoTopo(p, 50);
    inserirElementoNoTopo(p, 20);
    inserirElementoNoTopo(p, 30);
    inserirElementoNoTopo(p, 40);
    inserirElementoNoTopo(p, 10);

    // Imprime a pilha antes da ordenação
    printf("Pilha antes da ordenação:\n");
    imprimePilha(p);

    // Ordena a pilha
    ordenacao(p);

    // Imprime a pilha após a ordenação
    printf("Pilha após a ordenação:\n");
    imprimePilha(p);

    // Mostra o elemento do topo da pilha
    printf("Mostrar elemento do topo: %d\n", mostraElementoDoTopo(p));

    return 0;
}
