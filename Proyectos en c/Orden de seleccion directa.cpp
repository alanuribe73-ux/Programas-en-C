#include <stdio.h>

int main() {
    int MENOR, i, j, k;
    int a[7] = {10, 7, 6, 4, 9, 8, 1};

    for (i = 0; i < 6; i++) {
        MENOR = a[i];
        k = i;
        for (j = i + 1; j < 7; j++) {
            if (a[j] < MENOR) {
                MENOR = a[j];
                k = j;
            }
        }
        // Intercambio solo si se encontró un valor menor
        if (k != i) {
            int temp = a[i];
            a[i] = a[k];
            a[k] = temp;
        }
    }

    printf("Arreglo ordenado:\n");
    for (i = 0; i < 7; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
    getchar();
    return 0;
}

