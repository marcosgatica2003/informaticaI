#include <stdio.h>
#define N 4
int main(int argc, char *argv[]) {
	int alu;
	int suma=0;
	int promedio;
for(int i=0;i < N ; i++){
	printf("ingrese la [%d]nota:",i);
		scanf("%d",&alu);
		suma+=alu;
}
promedio=suma/4;
printf("el promedio es [%d]\n",promedio);
switch(promedio){
case 10:	printf("apro. dic");
	break ;
case 9:	printf("apro. dic");
	break ;
case 8:	printf("apro. dic");
	break ;
case 7:	printf("apro. dic");
	break ;
case 6:	printf("apro. dic");
	break ;
case 5:	printf("regular");
	break ;
case 4:	printf("regular");
	break ;
case 3:	printf("libre :V");
	break ;
case 2:	printf("libre :V");
	break ;
case 1:	printf("libre :V");
	break ;
case 0:	printf("libre :V");
	break ;
}
	return 0;
}

