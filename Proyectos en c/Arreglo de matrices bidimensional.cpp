#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char a[20];
    char b[30];
    int edad;
} alumno;

int main(void) {
    alumno *b;
    int max, i;
    printf("Da el numero de registros a manejar=>");
    if (scanf("%d", &max) != 1) return 1;
    b = (alumno *)malloc(sizeof(alumno) * max);
    if (b == NULL) return 1;
    for (i = 0; i < max; i++) {
        printf("Da el nombre del elemento %d=>", i);
        scanf("%19s", (b + i)->a);
        printf("Da la direccion del elemento %d=>", i);
        scanf("%29s", (b + i)->b);
        printf("Da la edad del elemento %d=>", i);
        scanf("%d", &(b + i)->edad);
    }
    for (i = 0; i < max; i++) {
        printf("%s\t%s\t%d\n", (b + i)->a, (b + i)->b, (b + i)->edad);
        printf("%s\t%s\t%d\n", (*(b + i)).a, (*(b + i)).b, (*(b + i)).edad);
    }
    free(b);
    return 0;
}

