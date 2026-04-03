#include <stdio.h>
#include <stdlib.h>
main() {
  int *a,i;
  if ((a=(int *)malloc(80))==NULL) {
    printf("Memoria no asignada\n");
    getchar();
    exit(0);
  }
  for (i=0;i<10;i++)
    a[i]=100+i;
  for (i=10; i<20; i++)
    *(a+i)=100+2*i;
  printf("La variable -a- apunta a la localidad de memoria %u &u %u\n", a, &a, &a[0]);
  for (i=0;i<20;i++)
    printf("a[%d]=%d\t*(a+%d)=%d\tLoc %u\tLoc %u\n", i, a[i], i, *(a+i),&a[i], a+i);
  getchar();
}

