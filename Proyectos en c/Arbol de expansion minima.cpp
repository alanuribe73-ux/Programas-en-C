#include <stdio.h>
#define TAM 6

int main() {
    // costo[n][n] es la matriz de costos del trayecto del grafo
    // costo[i][i] es infinito (999), costo[i][j] > 0 para i != j
    // El trayecto se guarda en el arreglo t[n][2]
    // El costo final se asigna a mincost
    // El vector ne indica el nodo más cercano al nodo j

    int cost[TAM][TAM] = {
        {999, 10, 999, 30, 45, 999},
        {10, 999, 50, 999, 40, 25},
        {999, 50, 999, 999, 35, 15},
        {30, 999, 999, 999, 999, 20},
        {45, 40, 35, 999, 999, 55},
        {999, 25, 15, 20, 55, 999}
    };

    int ne[TAM];
    int t[TAM][2];
    int min = 999, mincost = 0;
    int i, j, k = 0, l = 0;

    // Encontrar el arco de costo mínimo inicial
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            if (cost[i][j] < min && i != j) {
                min = cost[i][j];
                k = i;
                l = j;
            }
        }
    }

    mincost = cost[k][l];
    t[0][0] = k;
    t[0][1] = l;

    // Inicializar vector de nodos cercanos
    for (i = 0; i < TAM; i++) {
        if (cost[i][l] < cost[i][k])
            ne[i] = l;
        else
            ne[i] = k;
    }

    ne[k] = -1;
    ne[l] = -1;

    // Construcción del árbol
    for (i = 1; i < TAM - 1; i++) {
        min = 999;
        int next = -1;

        // Buscar el nodo más cercano al árbol actual
        for (k = 0; k < TAM; k++) {
            if (ne[k] != -1 && cost[k][ne[k]] < min) {
                min = cost[k][ne[k]];
                next = k;
            }
        }

        if (next == -1) break;  // seguridad

        j = next;
        t[i][0] = j;
        t[i][1] = ne[j];
        mincost += cost[j][ne[j]];
        ne[j] = -1;

        // Actualizar los nodos cercanos
        for (k = 0; k < TAM; k++) {
            if (ne[k] != -1 && cost[k][ne[k]] > cost[k][j])
                ne[k] = j;
        }
    }

    // Resultados
    printf("Costo del árbol de expansión mínima = %d\n", mincost);
    for (i = 0; i < TAM - 1; i++)
        printf("Trayecto de %d a %d\n", t[i][0] + 1, t[i][1] + 1);

    getchar();
    return 0;
}

