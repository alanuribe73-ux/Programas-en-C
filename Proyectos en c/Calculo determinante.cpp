#include <stdio.h>
#include <stdlib.h>

// PROTOTIPOS
int signo(int);
int determinante(int **, int);
int ** subm(int, int **, int);

int main() {
    int f, i, j;
    int **pm;

    printf("Da el tamaño de la matriz => ");
    scanf("%d", &f);

    pm = (int **)malloc(sizeof(int *) * f);
    for (j = 0; j < f; j++)
        pm[j] = (int *)malloc(sizeof(int) * f);

    for (i = 0; i < f; i++)
        for (j = 0; j < f; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &pm[i][j]);
        }

    printf("LA MATRIZ ES:\n");
    for (i = 0; i < f; i++) {
        for (j = 0; j < f; j++)
            printf("%d\t", pm[i][j]);
        putchar('\n');
    }

    printf("\nDeterminante(A) = %d\n", determinante(pm, f));

    // Liberar memoria
    for (j = 0; j < f; j++)
        free(pm[j]);
    free(pm);

    return 0;
}

int determinante(int **a, int tam) {
    if (tam == 1)
        return a[0][0];
    if (tam == 2)
        return a[0][0] * a[1][1] - a[1][0] * a[0][1];

    int m = 0;
    int tam1 = tam - 1;

    for (int i = 0; i < tam; i++)
        m = signo(i) * determinante(subm(i, a, tam1), tam1) * a[0][i] + m;

    return m;
}

int ** subm(int k, int **a, int tam) {
    int **b;
    int i, j;

    b = (int **)malloc(sizeof(int *) * tam);
    for (j = 0; j < tam; j++)
        b[j] = (int *)malloc(sizeof(int) * tam);

    for (i = 0; i < tam; i++) {
        int m = 0;
        for (j = 0; j < tam + 1; j++) {
            if (j != k) {
                b[i][m] = a[i + 1][j];
                m++;
            }
        }
    }
    return b;
}

int signo(int i) {
    if (i % 2 == 0)
        return 1;
    return -1;
}

