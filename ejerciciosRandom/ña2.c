#include <stdio.h>
#include <stdlib.h>
#define TAM 10

//Estructuras
typedef struct {
	char nombre[40];
	int anio_nacimiento;
}autor_t;

typedef struct libro{
	char nombre[40];
	int cant_paginas;
	int cant_capitulos;
	int* paginas_por_capitulo;
	float precio;
	autor_t datos_autor;
}libro_t;

//Prototipos
void ingresar_cantidad(int*);
void cargar_biblioteca(libro_t* bib, int cant);
void imprimir_biblioteca(libro_t* bib, int cant);
void ordenar_por_precio_menor_mayor(libro_t* bib, int cant);


int main(void) {
	
	libro_t biblioteca[TAM];
	int cantidad;
	
	printf("TP9 - ESTRUCTURAS - Marcos Raúl Gatica (leg.402006)\n\n");
	
	ingresar_cantidad(&cantidad);
	
	cargar_biblioteca(biblioteca, cantidad);
	
	printf("===============================================\n");
	printf("\tImprimr biblioteca desordenada\n\n");
	imprimir_biblioteca(biblioteca, cantidad);
	
	printf("===============================================\n");
	printf("\tImprimir biblioteca ordenada\n\n");
	ordenar_por_precio_menor_mayor(biblioteca, cantidad);
	imprimir_biblioteca(biblioteca, cantidad);
	
	//Liberar memoria
	for(int i = 0; i < cantidad; ++i) {
		free(biblioteca[i].paginas_por_capitulo);
	}
	
	return 0;
}

//Definicion de prototipos

void ingresar_cantidad(int* tam) { /*Solicitar al usuario la cantidad de libros a cargar. Validar que la cantidad sea mayor a 0 y menor a TAM.*/
	
	do {
		printf("Ingrese la cantidad de libros a cargar: ");
		scanf("%d", tam);
	} while((*tam)<=0 || (*tam)>TAM);
	
}

void cargar_biblioteca(libro_t* bib, int cant) { /*Cargar la biblioteca de libros*/
	
	printf("\nSe procederá a cargar la bibloteca con %d libros.\n", cant);
	
	for (int i = 0; i < cant; ++i) {
		
		printf("\nIngrese el nombre del libro: ");
		scanf(" %[^\n]s", bib[i].nombre);
		
		do {
			printf("Ingrese la cantidad de capitulos: ");
			scanf("%d", &bib[i].cant_capitulos);
		} while (bib[i].cant_capitulos <= 0);
		
		bib[i].paginas_por_capitulo = malloc(bib[i].cant_capitulos * sizeof(int));
		
		if (bib[i].paginas_por_capitulo == NULL) {
			printf("Error, no se pudo asignar memoria para las cantidad de paginas por capitulo\n");
			exit(1);
		}
		
		bib[i].cant_paginas = 0;
		
		for (int j = 0; j < bib[i].cant_capitulos; ++j) {
			do {
				printf("Ingrese la cantidad de paginas del capitulo %d: ", j+1);
				scanf("%d", &bib[i].paginas_por_capitulo[j]);
			} while (bib[i].paginas_por_capitulo[j] <=0);
			
			bib[i].cant_paginas += bib[i].paginas_por_capitulo[j];
		}
		
		do {
			printf("Ingrese el precio del libro: ");
			scanf("%f", &bib[i].precio);
		} while (bib[i].precio < 0);
		
		printf("Ingrese el nombre del autor: ");
		scanf(" %[^\n]s", bib[i].datos_autor.nombre);
		
		printf("Ingrese el año de nacimiento del autor: ");
		scanf("%d", &bib[i].datos_autor.anio_nacimiento);
	}
}

void imprimir_biblioteca(libro_t* bib, int cant) {
	for (int i = 0; i < cant; ++i) {
		printf("Nombre del libro: %s\n", bib[i].nombre);
		printf("Cantidad de páginas: %d\n", bib[i].cant_paginas);
		printf("Cantidad de capitulos: %d\n", bib[i].cant_capitulos);
		
		for (int j = 0; j < bib[i].cant_capitulos; ++j) {
			printf("Páginas del capítulo %d: %d\n", j+1, bib[i].paginas_por_capitulo[j]);
		}
		
		if (bib[i].precio == 0.00) {
			printf("Precio del libro: Gratis\n");
		}
		else {
			printf("Precio del libro: %.2f\n", bib[i].precio);
		}
		
		printf("Nombre del autor: %s\n", bib[i].datos_autor.nombre);
		printf("Fecha de nacimiento del autor: %d\n\n", bib[i].datos_autor.anio_nacimiento);
	}
}

void ordenar_por_precio_menor_mayor(libro_t* bib, int cant) { //Ordenamiento por burbuja
	
	libro_t temp;
	
	for (int j = 0; j < cant-1; j++) {
		for (int i = 0; i < cant-1-j; i++) {
			if (bib[i].precio > bib[i+1].precio) {
				
				temp = bib[i];
				bib[i] = bib[i+1];
				bib[i+1] = temp;
				
			}
		}
	}
}
