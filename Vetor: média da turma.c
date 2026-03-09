#include <stdio.h>

int main() {

    float nota1[30], nota2[30], media[30];
    float soma = 0, mediaTurma;
    int i;

     for(i = 0; i < 30; i++) {

        printf("Aluno %d\n", i+1);

        printf("Nota 1: ");
        scanf("%f", &nota1[i]);

        printf("Nota 2: ");
        scanf("%f", &nota2[i]);

        media[i] = (nota1[i]*2 + nota2[i]*3) / 5;

        soma += media[i];
    }

    mediaTurma = soma / 30;

    printf("\nMedia da turma: %.2f\n", mediaTurma);

    for(i = 0; i < 30; i++) {

        if(media[i] > mediaTurma) {

            printf("\nAluno %d\n", i+1);
            printf("Nota1: %.2f\n", nota1[i]);
            printf("Nota2: %.2f\n", nota2[i]);
            printf("Media: %.2f\n", media[i]);

        }

    }

    return 0;
}
