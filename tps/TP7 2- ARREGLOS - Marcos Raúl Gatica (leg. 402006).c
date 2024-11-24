#include <stdio.h>
#define TAM 5


void imprimir_productos (int a[], float p[], int N) {
	printf("Lista de productos\n");
	printf("Código de barra\tPrecio\n");

	for (int i = 0; i<N; i++) {
		printf("\t%d\t\t%f\n", a[i], p[i]);
	}
}

void ingresar_datos (int a[], int N, float p[]) {
	
	for (int i = 0; i<N; i++) {
		
		do {
		printf("Ingrese el código de barras N°%d: ", i);
		scanf("%d", &a[i]);
		} while (a[i] < 0);
		
		do {
			printf("Ingrese el precio N°%d: ", i);
			scanf("%f", &p[i]);
		} while (p[i] < 0);
	}
}

void tres_mayores (int a[], int N, float p[]) {
	
	float temp_precio = 0;
	int temp_barras = 0;
	
	for (int i = 0; i<N-1; i++) {
		
		for (int j = 0; j<N-i-1; j++) {
			
			if (p[j] < p[j+1]) {
				
				temp_precio = p[j];
				p[j] = p[j+1];
				p[j+1] = temp_precio;
				
				temp_barras = a[j];
				a[j] = a[j+1];
				a[j+1] = temp_barras;
			}
		}
	}
	
	printf("Tres productos caros:\n");
	printf("Código de barra\tPrecio\n");
	
	for (int i = 0; i<3; i++) {
		printf("\t%d\t\t%f\n", a[i], p[i]);
	}
}

void tres_menores (int a[], int N, float p[]) {
	
	float temp_precio = 0;
	int temp_barras = 0;
	
	for (int i = 0; i<N-1; i++) {
		
		for (int j = 0; j<N-i-1; j++) {
			
			if (p[j] > p[j+1]) {
				
				temp_precio = p[j];
				p[j] = p[j+1];
				p[j+1] = temp_precio;
				
				temp_barras = a[j];
				a[j] = a[j+1];
				a[j+1] = temp_barras;
			}
		}
	}
	
	printf("Tres productos baratos:\n");
	printf("Código de barra\tPrecio\n");
	
	for (int i = 0; i<3; i++) {
	printf("%d\t\t%f\n", a[i], p[i]);
	}

void producto_caro (int a[], int N, float p[]) {
	int imax = 0;
	int codigo_max = 0;
	float pmax = p[0];
	
	for (int i = 0; i<N; i++) {
		if (pmax < p[i]) {
			pmax = p[i];
			imax++;
		}
	}
	
	codigo_max = a[imax];
	
	printf("El producto más caro:\n");
	printf("Código de barra\tPrecio\n");
	printf("\t%d\t\t%f\n", codigo_max, pmax);
}

void producto_barato (int a[], int N, float p[]) {
	int imin = 0;
	int codigo_min = 0;
	float pmin = p[0];
	
	for (int i = 0; i<N; i++) {
		if (pmin > p[i]) {
			pmin = p[i];
			imin++;
		}
	}
	
	codigo_min = a[imin];
	
	printf("El producto más barato:\n");
	printf("Código de barra\tPrecio\n");
	printf("\t%d\t\t%f\n", codigo_min, pmin);
}


int main (void) {
	
	int codigos_barra [TAM];
	float precio [TAM];
	

	printf("El programa funciona para %d productos.\n\n", TAM);

	ingresar_datos (codigos_barra, TAM, precio);
	
	imprimir_productos (codigos_barra, precio, TAM);
	
	producto_caro(codigos_barra, TAM, precio);
	
	producto_barato(codigos_barra, TAM, precio);
	
	tres_mayores (codigos_barra, TAM, precio);
	tres_menores (codigos_barra, TAM, precio);
	
	return 0;
}

