#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct {
	char nombre[40];
	int anio_nacimiento;
} autor_t;

typedef struct libro {
	char nombre[40];
	int cant_paginas;
	int cant_capitulos;
	int* paginas_por_capitulo;
	float precio;
	autor_t datos_autor;
} libro_t;

int ingreso_cantidad_libros(void);
void cargar_biblioteca(libro_t* bib, int cant);
void imprimir_biblioteca(libro_t* bib, int cant);

int main(void) {
	libro_t biblioteca[TAM];
	int cantidad;
	
	cantidad = ingreso_cantidad_libros();
	cargar_biblioteca(biblioteca, cantidad);
	
	printf("===============================================\n");
	printf("Imprimir biblioteca: \n");
	imprimir_biblioteca(biblioteca, cantidad);
	
	// Liberar la memoria dinámica asignada para las páginas por capítulo
	for (int i = 0; i < cantidad; i++) {
		free(biblioteca[i].paginas_por_capitulo);
	}
	
	return 0;
}

int ingreso_cantidad_libros(void) {
	int cantidad;
	do {
		printf("Ingrese la cantidad de libros a cargar (1-9): ");
		scanf("%d", &cantidad);
		if (cantidad <= 0 || cantidad >= 10) {
			printf("La cantidad de libros debe ser mayor a 0 y menor a 10.\n");
		}
	} while (cantidad <= 0 || cantidad >= 10);
	return cantidad;
}

void cargar_biblioteca(libro_t* bib, int cant) {
	for (int i = 0; i < cant; i++) {
		printf("\nIngrese los datos del libro %d:\n", i + 1);
		
		printf("Nombre del libro: ");
		getchar(); // Para limpiar el buffer
		fgets(bib[i].nombre, 40, stdin);
		bib[i].nombre[strcspn(bib[i].nombre, "\n")] = '\0'; // Eliminar salto de línea
		
		printf("Cantidad de páginas: ");
		scanf("%d", &bib[i].cant_paginas);
		
		printf("Cantidad de capítulos: ");
		scanf("%d", &bib[i].cant_capitulos);
		
		// Asignar memoria dinámica para las páginas por capítulo
		bib[i].paginas_por_capitulo = (int*)malloc(bib[i].cant_capitulos * sizeof(int));
		if (bib[i].paginas_por_capitulo == NULL) {
			printf("Error al asignar memoria.\n");
			exit(1);
		}
		
		for (int j = 0; j < bib[i].cant_capitulos; j++) {
			printf("Páginas en el capítulo %d: ", j + 1);
			scanf("%d", &bib[i].paginas_por_capitulo[j]);
		}
		
		printf("Precio: ");
		scanf("%f", &bib[i].precio);
		
		printf("Nombre del autor: ");
		getchar(); // Limpiar el buffer
		fgets(bib[i].datos_autor.nombre, 40, stdin);
		bib[i].datos_autor.nombre[strcspn(bib[i].datos_autor.nombre, "\n")] = '\0'; // Eliminar salto de línea
		
		printf("Año de nacimiento del autor: ");
		scanf("%d", &bib[i].datos_autor.anio_nacimiento);
	}
}

void imprimir_biblioteca(libro_t* bib, int cant) {
	for (int i = 0; i < cant; i++) {
		printf("\nLibro %d:\n", i + 1);
		printf("Nombre: %s\n", bib[i].nombre);
		printf("Cantidad de páginas: %d\n", bib[i].cant_paginas);
		printf("Cantidad de capítulos: %d\n", bib[i].cant_capitulos);
		printf("Páginas por capítulo: ");
		for (int j = 0; j < bib[i].cant_capitulos; j++) {
			printf("%d ", bib[i].paginas_por_capitulo[j]);
		}
		printf("\nPrecio: %.2f\n", bib[i].precio);
		printf("Autor: %s\n", bib[i].datos_autor.nombre);
		printf("Año de nacimiento del autor: %d\n", bib[i].datos_autor.anio_nacimiento);
	}
}
