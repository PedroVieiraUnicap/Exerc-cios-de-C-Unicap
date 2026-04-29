#include <stdio.h>

#define TAM 30

typedef struct {
    float nota1;
    float nota2;
    float media;
} Aluno;

void lerNotas(Aluno alunos[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Aluno %d\n", i + 1);
        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);
        
        alunos[i].media = (alunos[i].nota1 * 2 + alunos[i].nota2 * 3) / 5;
    }
}

float calcularMediaTurma(Aluno alunos[], int n) {
    float soma = 0;
    for(int i = 0; i < n; i++) {
        soma += alunos[i].media;
    }
    return soma / n;
}

void imprimirAcimaDaMedia(Aluno alunos[], int n, float mediaTurma) {
    printf("\n--- Alunos Acima da Media da Turma (%.2f) ---\n", mediaTurma);
    for(int i = 0; i < n; i++) {
        if(alunos[i].media > mediaTurma) {
            printf("\nAluno %d\n", i + 1);
            printf("Nota 1: %.2f\n", alunos[i].nota1);
            printf("Nota 2: %.2f\n", alunos[i].nota2);
            printf("Media: %.2f\n", alunos[i].media);
        }
    }
}

int main() {
    Aluno listaAlunos[TAM];
    float mediaGeral;

    lerNotas(listaAlunos, TAM);
    mediaGeral = calcularMediaTurma(listaAlunos, TAM);
    
    printf("\nMedia da turma: %.2f\n", mediaGeral);
    
    imprimirAcimaDaMedia(listaAlunos, TAM, mediaGeral);

    return 0;
}
