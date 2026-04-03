#include <stdio.h>
main (){
	int a [4][4],i,j;
for (i=0;i<3;i++)
	for(j=0;j<3;j++)
		{
		printf("a[%d][%d]=",i,j);
		scanf("%d",(*(a+i)+j));
		
	}
	for (i=0;i<3;i++)
	{
		printf ("\n");
		for (j=0;j<3;j++)
		printf("%d\t",*(*(a+i)+j));
		
	}
	getchar();
	getchar();
}


