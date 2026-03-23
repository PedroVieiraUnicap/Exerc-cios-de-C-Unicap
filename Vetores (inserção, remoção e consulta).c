#include <stdio.h>

#define MAX 50

int buscaBinaria(int v[], int n, int valor) {
    int inicio = 0, fim = n - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (v[meio] == valor)
            return meio;
        else if (valor > v[meio])
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1;
}

int main() {
    int v[MAX];
    int n = 0;
    int tamanho;

    do {
        printf("Digite o tamanho do vetor (3 a 50): ");
        scanf("%d", &tamanho);
    } while (tamanho < 3 || tamanho > 50);

    int qtd;
    printf("Quantos valores deseja inserir inicialmente? ");
    scanf("%d", &qtd);

    if (qtd > tamanho)
        qtd = tamanho;

    for (int i = 0; i < qtd; i++) {
        int valor;
        printf("Digite um valor: ");
        scanf("%d", &valor);

        int j = n - 1;
        while (j >= 0 && v[j] > valor) {
            v[j + 1] = v[j];
            j--;
        }

        v[j + 1] = valor;
        n++;
    }

    int opcao;

    do {
        printf("\n1 - Imprimir\n2 - Buscar\n3 - Remover\n4 - Inserir\n0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            for (int i = 0; i < n; i++)
                printf("%d ", v[i]);
            printf("\n");
        }

        else if (opcao == 2) {
            int valor;
            printf("Valor para buscar: ");
            scanf("%d", &valor);

            int pos = buscaBinaria(v, n, valor);
            printf("Posicao: %d\n", pos);
        }

        else if (opcao == 3) {
            int valor;
            printf("Valor para remover: ");
            scanf("%d", &valor);

            int pos = buscaBinaria(v, n, valor);

            if (pos != -1) {
                for (int i = pos; i < n - 1; i++)
                    v[i] = v[i + 1];
                n--;
                printf("Removido!\n");
            } else {
                printf("Nao encontrado!\n");
            }
        }

        else if (opcao == 4) {
            if (n >= tamanho) {
                printf("Vetor cheio!\n");
            } else {
                int valor;
                printf("Valor para inserir: ");
                scanf("%d", &valor);

                int j = n - 1;
                while (j >= 0 && v[j] > valor) {
                    v[j + 1] = v[j];
                    j--;
                }

                v[j + 1] = valor;
                n++;
            }
        }

    } while (opcao != 0);

    return 0;
}
