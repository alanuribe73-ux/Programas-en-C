#include <stdio.h>
 main() {
 	int i, *p;
 	i=254;
 	p=&i;
 	printf("%d   %u  \n", *p, p, &p);
 	getchar  ();
 	
 	return 0;
 }
