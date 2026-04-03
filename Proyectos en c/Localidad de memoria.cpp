#include <stdio.h>
main(){
	int i, *p;
	i=365;
	p=&i;
	*p=485;
	printf("%d \n", i);
	
}
