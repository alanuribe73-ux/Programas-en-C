#include <stdio.h>
#include <stdlib.h>

void marcar(int **matriz, int n, int filaQ, int colQ);
void vaciar(int **vect, int n);
void mostrar_solucion(int **tablero, int n);
void dam(int **matriz, int **tablero, int fila, int columna, int reinas_colocadas, int n);
void regresar(int **matriz, int **tablero, int fila, int columna, int n);

int cont = 0;

int main(void) {

    int **matriz = NULL, **tablero = NULL;
    int reinas;

    printf("Introduce el numero de reinas: ");
    if (scanf("%d", &reinas) != 1 || reinas <= 0) {
        printf("Entrada invalida.\n");
        return 1;
    }

    matriz = (int **)malloc(sizeof(int *) * reinas);
    tablero = (int **)malloc(sizeof(int *) * reinas);
    if (!matriz || !tablero) {
        printf("Error de memoria.\n");
        return 1;
    }

    for (int i = 0; i < reinas; ++i) {
        matriz[i] = (int *)malloc(sizeof(int) * reinas);
        tablero[i] = (int *)malloc(sizeof(int) * reinas);
        if (!matriz[i] || !tablero[i]) {
            printf("Error de memoria.\n");
            return 1;
        }
    }

    vaciar(matriz, reinas);
    vaciar(tablero, reinas);

    for (int i = 0; i < reinas; ++i) {
        dam(matriz, tablero, i, 0, 1, reinas);
    }

    if (cont == 0)
        printf("No hay soluciones para el problema con %d reinas\n", reinas);
    else
        printf("Total soluciones encontradas: %d\n", cont);

    for (int i = 0; i < reinas; ++i) {
        free(matriz[i]);
        free(tablero[i]);
    }
    free(matriz);
    free(tablero);

    return 0;
}

void dam(int **matriz, int **tablero, int fila, int columna, int reinas_colocadas, int n) {
    tablero[fila][columna] = 1;
    matriz[fila][columna] = 1;

    marcar(matriz, n, fila, columna);

    if (reinas_colocadas == n) {
        mostrar_solucion(tablero, n);
    } else {
        int siguiente_col = columna + 1;
        if (siguiente_col < n) {
            for (int j = 0; j < n; ++j) {
                if (matriz[j][siguiente_col] == 0) {
                    dam(matriz, tablero, j, siguiente_col, reinas_colocadas + 1, n);
                }
            }
        }
    }

    regresar(matriz, tablero, fila, columna, n);
}

void regresar(int **matriz, int **tablero, int fila, int columna, int n) {
    tablero[fila][columna] = 0;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            matriz[i][j] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (tablero[i][j] == 1) {
                matriz[i][j] = 1;
                marcar(matriz, n, i, j);
            }
        }
    }
}

void mostrar_solucion(int **tablero, int n) {
    printf("Solucion %d\n", ++cont);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", tablero[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void vaciar(int **vect, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            vect[i][j] = 0;
}

void marcar(int **matriz, int n, int filaQ, int colQ) {

    for (int k = 0; k < n; ++k) {
        matriz[filaQ][k] = 1;
        matriz[k][colQ] = 1;
    }

    for (int dr = -n; dr <= n; ++dr) {
        int r = filaQ + dr;
        int c = colQ + dr;
        if (r >= 0 && r < n && c >= 0 && c < n) matriz[r][c] = 1;

        c = colQ - dr;
        if (r >= 0 && r < n && c >= 0 && c < n) matriz[r][c] = 1;
    }

    matriz[filaQ][colQ] = 1;
}

