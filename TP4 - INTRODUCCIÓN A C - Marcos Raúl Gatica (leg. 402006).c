#include <stdio.h>
	
	int main(int argc, char *argv[]) {
	
	int cal;
	
	printf("TP N°4 - Introducción a C \nPor Marcos Gatica (leg.402006)\n");
	
	printf("\nIngrese su calificación: ");
	scanf("%d", &cal);
	
	if (cal>100) {
		
		printf("La nota ingresada es inválida, la máxima nota posible es 100");
		
	}
	
	else {
		if (cal<=0) {
			
			printf("La nota ingresada es inválida, la mínima nota posible es 1");
			
		}
		
		else {
			if (cal>=90) {
				printf("Calificación: A");
			}
			else if (cal>=80) {
				printf("Calificación: B");
			}
			else if (cal>=70) {
				printf("Calificación: C");
			}
			else if (cal>=60) {
				printf("Calificación: D");
			}
			
			if (cal<60) {
				printf("Calificación: F");
			}
			
		}
	}
	
	return 0;
}


	
