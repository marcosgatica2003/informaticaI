#include <stdio.h>
	
	int main(int argc, char *argv[]) {
	
	int cal;
	
	printf("TP N�4 - Introducci�n a C \nPor Marcos Gatica (leg.402006)\n");
	
	printf("\nIngrese su calificaci�n: ");
	scanf("%d", &cal);
	
	if (cal>100) {
		
		printf("La nota ingresada es inv�lida, la m�xima nota posible es 100");
		
	}
	
	else {
		if (cal<=0) {
			
			printf("La nota ingresada es inv�lida, la m�nima nota posible es 1");
			
		}
		
		else {
			if (cal>=90) {
				printf("Calificaci�n: A");
			}
			else if (cal>=80) {
				printf("Calificaci�n: B");
			}
			else if (cal>=70) {
				printf("Calificaci�n: C");
			}
			else if (cal>=60) {
				printf("Calificaci�n: D");
			}
			
			if (cal<60) {
				printf("Calificaci�n: F");
			}
			
		}
	}
	
	return 0;
}


	
