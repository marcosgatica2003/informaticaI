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
case 10:
	break ;
case 9:
	break ;
case 8:
	break ;
case 7:
	break ;
case 6:
	break ;
case 5:
	break ;
case 4:
	break ;
case 3:
	break ;
case 2:
	break ;
case 1:
	break ;
case 0:
	break ;
}
	return 0;
}
