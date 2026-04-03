#include <stdio.h> 
int ackermann(int, int); 
main(){ 
int m,n; 
printf("Da el valor de m=>"); 
scanf("%d",&m); 
printf("Da el valor de n=>"); 
scanf("%d",&n); 
printf("Ackerman(%d,%d)=%d\n",m,n,ackermann(m,n)); 
getchar(); 
} 
int ackermann(int m, int n){
    if (m==0)
        return n+1;
    else if (n==0)
        return ackermann(m-1,1);
    else
        return ackermann(m-1, ackermann(m,n-1));
}

