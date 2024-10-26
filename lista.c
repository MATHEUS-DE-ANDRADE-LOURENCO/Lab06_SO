# include <stdlib.h>
# include <stdio.h>

typedef struct {
    int elem;
    struct Node *next;
}Node;

Node *criarNo(int elemento) {
    Node *novoNo = (Node*) malloc(sizeof(Node));

    if (novoNo != NULL) {
        novoNo->elem = elemento;
        novoNo->next = NULL;
    }

    return novoNo;
}

void inserir(Node **head, int elemento) {
    Node *no = criarNo(elemento);

    if (*head == NULL) {
        *head = no;  // Se a lista está vazia, o novo nó é o primeiro elemento
    } else {
        Node *aux = *head;
        
        while(aux->next != NULL) { // Percorre até o final da lista
            aux = aux->next;
        }

        aux->next = no; // Adiciona o novo nó ao final
    }
}

void imprimirLista(Node *lista) {
    Node *aux = lista;
    int i = 0;

    while (aux != NULL) {
        printf("Elem %d -> %d\n", i, aux->elem);
        aux = aux->next;
        i++;
    }
}

int main() {
    Node *lista = NULL;

    inserir(&lista, 1);
    inserir(&lista, 2);
    inserir(&lista, 3);

    imprimirLista(lista);
    return 0;
}