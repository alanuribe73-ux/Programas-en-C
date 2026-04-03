#include <stdio.h>
#include <stdlib.h>

#define INF 9999

// Prototipos
void generar(int **, int);
void path(int **, int *, int, int);

int main() {
    int **cost, *dist, tam, i, j, v;

    printf("********** Ruta mas corta a partir de un origen **********\n");
    printf("\nIntroduce el numero de vertices: ");
    scanf("%d", &tam);

    cost = (int **)malloc(sizeof(int *) * tam);
    for (i = 0; i < tam; i++)
        cost[i] = (int *)malloc(sizeof(int) * tam);

    dist = (int *)malloc(sizeof(int) * tam);

    // Inicializar la matriz de costos con valores grandes (infinito)
    for (i = 0; i < tam; i++)
        for (j = 0; j < tam; j++)
            cost[i][j] = INF;

    generar(cost, tam);

    printf("Introduce el vertice de origen: ");
    scanf("%d", &v);

    printf("\nLa matriz generada es:\n");
    for (i = 0; i < tam; i++) {
        for (j = 0; j < tam; j++)
            printf("%6d", cost[i][j]);
        printf("\n");
    }

    path(cost, dist, tam, v - 1);

    printf("\n\nCosto de los caminos:\n");
    for (i = 0; i < tam; i++)
        printf("Camino %d a %d: %d\n", v, i + 1, dist[i]);

    // Liberar memoria
    for (i = 0; i < tam; i++)
        free(cost[i]);
    free(cost);
    free(dist);

    system("PAUSE");
    return 0;
}

void generar(int **cost, int tam) {
    int i, nv = 0, p, ad;
    printf("\nPara terminar de introducir un vertice introduce 99\n");

    while (nv < tam) {
        printf("\nVertice %d a... \n", nv + 1);
        while (1) {
            scanf("%d", &ad);
            if (ad == 99) {
                printf("Termino vertice %d\n", nv + 1);
                nv++;
                break;
            } else if (ad > tam || ad <= 0) {
                printf("El vertice no existe.\n");
            } else {
                printf("Introduce el peso del vertice: ");
                scanf("%d", &p);
                cost[nv][ad - 1] = p;
            }
        }
    }
}

void path(int **cost, int *dist, int tam, int v) {
    int s[tam], i, w, u = 0, num, min;

    for (i = 0; i < tam; i++) {
        s[i] = 0;
        dist[i] = cost[v][i];
    }

    s[v] = 1;
    dist[v] = 0;

    // Algoritmo de Dijkstra
    for (num = 1; num < tam - 1; num++) {
        min = INF;

        for (w = 0; w < tam; w++) {
            if (s[w] == 0 && dist[w] < min) {
                min = dist[w];
                u = w;
            }
        }

        s[u] = 1;

        for (w = 0; w < tam; w++) {
            if (s[w] == 0 && dist[u] + cost[u][w] < dist[w]) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

