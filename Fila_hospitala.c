#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definir a estrutura do paciente

typedef struct Documento {
    char nome_documento [100]; //Nome do Paciente
    int idade; // Idade 
    struct Documento* proximo; //Ponteiro para o proximo paciente
}Documento;

//Estrutura da fila
typedef struct Fila{
    Documento* primeiro; //Ponteiro para o primeiro da fila
    Documento* final; //Ponteiro para o final da fila
    int tamanhoDaFila; //Tamanho da fila
} Fila;


//Funcao criacao da fila vazia

Fila* criaFila(){
    Fila* f = (Fila*) malloc(sizeof(Fila)); 
    
    if(!f){
        printf("Falha ao alocar a memória");
        exit(1);
    }
    
    f->primeiro = f->final = NULL; //Inicializa os ponteiros inicial e final como nulo
    f->tamanhoDaFila = 0; //Inicializa o tamanho como 0
}

//Função para enfileirar novo Paciente

void enfileirar(Fila* f, char* nome, int idade ){
    Documento* novoPaciente = (Documento*) malloc(sizeof(Fila));//Aloca memória para novo paciente
    
    if(!novoPaciente){
        printf("Falha ao alocar memória para paciente");
        exit(1);
    }
    
    novoPaciente->idade = idade;
    strcpy(novoPaciente->nome_documento,nome); // Copia o nome do paciente para estrutura
    novoPaciente->proximo = NULL; //Define o proximo como nulo
    
    if(f->final==NULL){ // Se a fila está vazia
        f->primeiro = f->final = novoPaciente;
    }
    else {
        f->final->proximo = novoPaciente; //Vincula o novo paciente ao final da fila
        f->final = novoPaciente; //Atualizaão do ponteiro último para o novo paciente
    }
    
    f->tamanhoDaFila++;//Incrementa o tamanho da fila
    printf("Paciente %s adicionado a fila\n", nome); 
}


Documento desinfeilar(Fila* f){
    if(f->primeiro==NULL){ //Se a fila está vazia
        printf("Fila vazia");
        return (Documento){0}; //Retorna a estrutura de paciente vazia
    }
    
    Documento* temp = f->primeiro; //Guarda o ponteiro para o primeiro paciente
    Documento info = *temp;// Copia as informações do paciente
    f->primeiro =f->primeiro->proximo; //Move o ponteiro do inicio para o proximo paciente
    
    if(f->primeiro == NULL) {//Se a fila ficar vazia
        f->final = NULL; //Atualiza ponteiro ultimo para null
    }
    
    free(temp);//libera a memoria do paciente que foi removido
    f->tamanhoDaFila--;//Decrementa 
    
    return info; //retorna o paciente desinfileirado
}

void imprimirFila(Fila* f){
    Documento* temp = f->primeiro; //Ponteiro temporario para percorrer a fila   
    printf("Fila \n");
    
    while(temp!=NULL){//Enquanto existir pacientes na fila
        printf("%s, idade %d\n",temp->nome_documento,temp->idade );
        temp= temp->proximo; //Move para o proximo paciente
    }
    
}

//tamanho da fila

int exibeTamanhoDaFila(Fila *f){
    return f->tamanhoDaFila; // Retorna o tamanho da fila
}


int main()
{
    Fila* f = criaFila(); //Cria a Fila
    
    enfileirar(f,"João",30);
    enfileirar(f,"José",22);
    enfileirar(f,"Maria",29);
    
    imprimirFila(f);//Exibe todos os pacientes
    
    printf("Tamanho atual da fila: %d\n", exibeTamanhoDaFila(f));
    
    Documento p = desinfeilar(f); //Remove o primeiro paciente da fila
    
    printf("Paciente desinfileirado: %s, %d idade\n",p.nome_documento,p.idade);
    
    imprimirFila(f);//Exibe a fila atualizada
    
    
    printf("Tamanho atual da fila: %d\n", exibeTamanhoDaFila(f));
    
    
    
    return 0;
}