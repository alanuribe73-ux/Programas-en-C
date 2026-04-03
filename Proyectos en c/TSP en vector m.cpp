#include <stdio.h>
#include <stdlib.h>

void generar(int **cost, int tam);
int tsp(int **cost, int *m, int d, int o, int v, int r);

int main() {
    int **cost, *m;
    int v, i, j, r;

    printf("***************    TSP    ***************\n\n");
    printf("Introduce el numero de vertices: ");
    scanf("%d", &v);

    // Asignación dinámica
    cost = (int **)malloc(sizeof(int *) * v);
    for (i = 0; i < v; i++)
        cost[i] = (int *)malloc(sizeof(int) * v);

    m = (int *)calloc(v, sizeof(int));

    // Inicializar matriz con 0 en diagonal y 9999 en otros
    for (i = 0; i < v; i++)
        for (j = 0; j < v; j++)
            cost[i][j] = (i == j) ? 0 : 9999;

    generar(cost, v);

    printf("\nIntroduce el origen (1 a %d): ", v);
    scanf("%d", &r);

    printf("\nLa matriz generada es:\n");
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++)
            printf("%6d", cost[i][j]);
        printf("\n");
    }

    printf("\nCosto minimo a partir de %d: %d\n",
           r, tsp(cost, m, v, r - 1, v, r - 1));

    // Liberación de memoria
    for (i = 0; i < v; i++)
        free(cost[i]);
    free(cost);
    free(m);

    return 0;
}

void generar(int **cost, int tam) {
    int nv = 0, ad, p;

    printf("\nPara terminar de introducir adyacencias de un vértice escribe 99\n");

    while (nv < tam) {
        printf("\nVertice %d se conecta a...\n", nv + 1);

        while (1) {
            scanf("%d", &ad);

            if (ad == 99) {
                printf("Termino vertice %d\n", nv + 1);
                nv++;
                break;
            }

            if (ad < 1 || ad > tam) {
                printf("El vertice no existe. Intenta otro: ");
                continue;
            }

            printf("Introduce el peso hacia vertice %d: ", ad);
            scanf("%d", &p);

            cost[nv][ad - 1] = p;
            printf("Añadido. Otro adyacente o 99 para terminar: ");
        }
    }
}

int tsp(int **cost, int *m, int d, int o, int v, int r) {
    if (d == 1)
        return cost[o][r];

    int dist, dmin = 9999;

    m[o] = 1;

    for (int i = 0; i < v; i++) {
        if (m[i] == 0) {
            dist = cost[o][i] + tsp(cost, m, d - 1, i, v, r);
            m[i] = 0;

            if (dist < dmin)
                dmin = dist;
        }
    }

    return dmin;
}

