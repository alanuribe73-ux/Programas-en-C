#include <stdio.h>

int main() {
    int a, b;

    printf("Ingrese dos números enteros: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Entrada inválida.\n");
        return 1;
    }

    printf("La suma es: %d\n", a + b);
    return 0;
}

