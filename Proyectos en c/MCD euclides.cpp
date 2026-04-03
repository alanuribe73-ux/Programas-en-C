#include <stdio.h>

int MCD(int a, int b) {
    if (b == 0)        
        return a;
    return MCD(b, a % b);  
}

int main() {
    int x, y;
    printf("Introduce dos numeros: ");
    scanf("%d %d", &x, &y);

    printf("El MCD de %d y %d es: %d\n", x, y, MCD(x, y));

    return 0;
}

