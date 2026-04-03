#include <stdio.h>   // Biblioteca estándar para entrada/salida (printf, getchar, etc.)

main(){              // Función principal (mejor usar int main(), pero algunos compiladores lo permiten así)
    int i, *p;       // Declara una variable entera 'i' y un puntero a entero 'p'
    
    i = 254;         // Asigna el valor 254 a la variable 'i'
    
    p = &i;          // El puntero 'p' guarda la dirección de memoria de 'i'
                     // Es decir, p apunta a i.
    
    printf ("%d %d %u %u %u\n", 
            i,       // Imprime el valor de 'i' -> 254
            *p,      // Imprime lo que hay en la dirección guardada en 'p' (el contenido de 'i') -> 254
            &i,      // Imprime la dirección de memoria de 'i'
            p,       // Imprime el valor del puntero 'p' (que es la dirección de 'i')
            &p);     // Imprime la dirección de memoria del puntero 'p' (donde se guarda 'p' mismo)

    getchar ();      // Espera que presiones una tecla antes de terminar el programa (pausa)
}

