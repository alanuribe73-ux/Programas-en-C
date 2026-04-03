#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int datos[MAX];
    int tope;
} Pila;

void inicializar(Pila *p) {
    p->tope = -1;
}

bool push(Pila *p, int valor) {
    if (p->tope < MAX - 1) {
        p->datos[++(p->tope)] = valor;
        return true;
    }
    return false; // overflow
}

bool pop(Pila *p, int *out) {
    if (p->tope >= 0) {
        *out = p->datos[(p->tope)--];
        return true;
    }
    return false; // underflow
}

int main(void) {
    Pila pila;
    inicializar(&pila);

    if (!push(&pila, 10)) {
        fprintf(stderr, "Error: overflow al hacer push\n");
        return 1;
    }
    if (!push(&pila, 5)) { /* ... */ }

    int v;
    if (pop(&pila, &v)) {
        printf("Valor sacado: %d\n", v);
    } else {
        printf("Pila vacía\n");
    }

    return 0;
}

