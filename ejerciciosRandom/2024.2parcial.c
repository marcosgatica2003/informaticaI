#include <stdio.h>
#define N 1000
int cuantos_valores(int, int);
void cargar(int [], float[], int);
void clasificar(float[], char[], int);
void imprimir(int [], float[], char[], int);
int main (void) {
	int n;
	int cod[N] = {0};
	float diametro[N] = {0};
	char estado[N] = {0};
	n = cuantos_valores(0, N);
	cargar(cod, diametro, n);
	clasificar(diametro, estado, n);
	imprimir(cod, diametro, estado, n);
	return 0;
}
int cuantos_valores(int min, int max){
	int n;
	do{
		printf("ingrese cuantos kieres:");
			scanf("%d",&n);
	} while(n<min||n>max);
	return n;
}
void cargar(int cod[], float diametro[], int n){
	for(int i=0;i<n;i++){
		printf("ingrese el valor del cod:");
			scanf("%d",&cod[i]);
		printf("ingrese el valor del diametro:");
			scanf("%f",&diametro[i]);
	}
}
void clasificar(float diametro[], char estado[], int n){
	for(int i=0;i<n;i++){
		if (diametro[i]<0)
			estado[i]='e';
		else 
			if (diametro[i]>=10)
				estado[i]='b';
			else 
				estado[i]='m';
	}
}
	void imprimir (int cod[], float diametro[], char estado[], int n) {
		for (int i = 0; i < n; i++) {
			printf("Cód: %d ", cod[i]);
			printf("Diámetro: %.2f ", diametro[i]);
			printf("Estado: ");
			switch(estado[i]) {
			case 'b':
				printf("Bueno\n");
				break;
			case 'm':
				printf("Malo\n");
				break;
			case 'e':
				printf("Error\n");
				break;
			default:
				printf("Desconocido\n");
			}
		}
	}	
