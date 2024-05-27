#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do documento
typedef struct Document
{
    int id;
    char name[50];
    struct Document *next;
} Document;

// Definição da estrutura da fila
typedef struct
{
    Document *front;
    Document *rear;
    int size;
} Queue;

// Função para criar um novo documento
Document *createDocument(int id, const char *name)
{
    Document *newDoc = (Document *)malloc(sizeof(Document));
    newDoc->id = id;
    strcpy(newDoc->name, name);
    newDoc->next = NULL;
    return newDoc;
}

// Função para inicializar a fila
void initializeQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

// Função para adicionar um documento à fila
void enqueue(Queue *q, int id, const char *name)
{
    Document *newDoc = createDocument(id, name);
    if (q->rear == NULL)
    {
        q->front = newDoc;
        q->rear = newDoc;
    }
    else
    {
        q->rear->next = newDoc;
        q->rear = newDoc;
    }
    q->size++;
}

// Função para imprimir o próximo documento da fila
void dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("A fila de impressão está vazia.\n");
        return;
    }
    Document *temp = q->front;
    printf("Imprimindo documento ID: %d, Nome: %s\n", temp->id, temp->name);
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
}

// Função para exibir todos os documentos na fila de impressão
void displayQueue(Queue *q)
{
    if (q->front == NULL)
    {
        printf("A fila de impressão está vazia.\n");
        return;
    }
    Document *current = q->front;
    printf("Documentos na fila de impressão:\n");
    while (current != NULL)
    {
        printf("ID: %d, Nome: %s\n", current->id, current->name);
        current = current->next;
    }
}

// Função para verificar o número total de documentos na fila de impressão
int queueSize(Queue *q)
{
    return q->size;
}

// Função principal
int main()
{
    Queue printQueue;
    initializeQueue(&printQueue);

    enqueue(&printQueue, 1, "Documento1");
    enqueue(&printQueue, 2, "Documento2");
    enqueue(&printQueue, 3, "Documento3");

    displayQueue(&printQueue);
    printf("Total de documentos na fila: %d\n", queueSize(&printQueue));

    dequeue(&printQueue);
    displayQueue(&printQueue);
    printf("Total de documentos na fila: %d\n", queueSize(&printQueue));

    return 0;
}
