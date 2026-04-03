#include <stdio.h>
#include <string.h>
main (){
	char a[5], *b, **c;
	strcpy (a,"hola");
	b=a;
	c=&b;
	printf	("%s,\t%c\t%c\n",a,*b,**c);
	getchar();
	
}
