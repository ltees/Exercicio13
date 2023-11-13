#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 3

// Modelo do registro
typedef struct{
    char nome[20];
    int idade;
    int id;
    int status;
} Aluno;

void cadastrar(Aluno a[], int indice) {
    a[indice].status = 1;
    a[indice].id = rand() % 200;
    fflush(stdin);
    printf("\nDigite o nome do aluno: ");
    fflush(stdin);
    fgets(a[indice].nome, sizeof(a[indice].nome), stdin);
    fflush(stdin);
    printf("Digite a idade do aluno: ");
    fflush(stdin);
    scanf("%d", &a[indice].idade);
    fflush(stdin);
    printf("\n\n");
}

void imprimir(Aluno a[], int totalCadastro) {
    if (totalCadastro == 0) {
        printf("\n\nNao existem alunos cadastrados");
    } else {
        for (int i = 0; i < totalCadastro; i++) {
            printf("Id: %d", a[i].id);
            printf("\nNome: %s", a[i].nome);
            printf("\nIdade: %d", a[i].idade);
            a[i].status == 1 ? printf("\nStatus : Ativo") : printf("\nStatus : Inativo");
            printf("\n\n");
        }
    }
}

void buscarRegistro(Aluno a[], int totalCadastro, int buscarId) {
    if (totalCadastro == 0) {
        printf("\nNao existe cadastros na lista\n");
        return;
    } else {
        for (int i = 0; i < totalCadastro; i++) {
            if (a[i].id == buscarId) {
                printf("\nNome do registro encontrado: %s", a[i].nome);
                return;
            }
        }
    }
    printf("\nRegistro nao encontrado na lista");
}

void buscar(Aluno a[], int totalCadastro, const char buscarNome[]) {
    if (totalCadastro == 0) {
        printf("\nNao existem alunos cadastrados\n");
        return;
    } else {
        for (int i = 0; i < totalCadastro; i++) {
            if (strcmp(a[i].nome, buscarNome) == 0) {
                printf("\nRegistro encontrado para o nome %s", buscarNome);
                printf("\nId: %d", a[i].id);
                printf("\nIdade: %d", a[i].idade);
                a[i].status == 1 ? printf("\nStatus : Ativo") : printf("\nStatus : Inativo");
                printf("\n\n");
                return;
            }
        }
    }
    printf("\nRegistro nao encontrado para o nome %s", buscarNome);
}

// Restante do código...

int main() {
    Aluno a[TAM];
    int opcao, totalCadastro = 0, buscarId;
    char buscarNome[20];

    do {
        printf("\nDigite 1 para cadastrar");
        printf("\nDigite 2 para imprimir os cadastros");
        printf("\nDigite 3 para buscar um cadastro por ID");
        printf("\nDigite 4 para buscar um cadastro por nome");
        printf("\nDigite 5 para alterar um cadastro");
        printf("\nDigite 6 para excluir um cadastro");
        printf("\nDigite 0 para encerrar o programa");
        scanf("%d", &opcao);

        switch (opcao) {
            // Restante do código...
            case 4:
                // buscar por nome
                printf("Digite o nome para buscar: ");
                fflush(stdin);
                fgets(buscarNome, sizeof(buscarNome), stdin);
                buscar(a, totalCadastro, buscarNome);
                break;
            // Restante do código...
        }
    } while (opcao != 0);

    return 0;
}
