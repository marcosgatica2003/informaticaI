#include <stdio.h>
#define TAM 200

// Función para cargar la cantidad tam de elementos a utilizar
int ingresarValidarTam(void);

// Mensajes en pantalla
void mensajes (int);

// Función para cargar los tam elementos en el arreglo
void cargarArreglo(float* ,const int);

// Función para calcular la cantidad de piezas defectuosas
int calcularDefectuosas(const float*, const int);

// Función para calcular la cantidad de piezas válidas
int calcularValidas(const float*, const int);

// Función para mostrar todas las piezas ingresadas
void mostrarPiezas(const float* ,const int);

// Función para mostrar las piezas válidas ordenadas
void mostrarPiezasValidasOrdenadasMenorMayor(const float*, const int );
//Ordenamiento
void quicksort (float[], int, int);

int main(void) {
	
	//Variables y arreglo
	float arreglo[TAM] = {0};
	int tam, defectuosas, validas;
	

	
	//Llamado a funciones
	
	mensajes(0); //Título
	tam = ingresarValidarTam();
	cargarArreglo(arreglo, tam);
	
	defectuosas = calcularDefectuosas(arreglo, tam);
	validas = calcularValidas(arreglo, tam);
	
	printf("\nVálidas: %d\nDefectuosas: %d\n", validas, defectuosas);
	printf("\n\t\tArreglo desordenado\n");
	
	
	mostrarPiezas(arreglo, tam);
	mostrarPiezasValidasOrdenadasMenorMayor(arreglo, tam);
	
	return 0;
}

//Definiciones de prototipos


void mensajes (int buscar) {
	
	const static char* mensajes[] = {
		"TP8 - Punteros - Por Marcos Raúl Gatica",
		"ERROR 2: Cantidad de piezas inválida",
		"ERROR 3: La calidad no puede ser negativa"
	};
	
	for (int i = 0; i < sizeof(mensajes) / sizeof(mensajes[0]); i++) {
		if (i == buscar) {
			printf("%s\n", mensajes[i]);
		}
	}
}

int ingresarValidarTam (void) {
	
	static int n;
	printf("Ingrese la cantidad de piezas a evaluar: ");
	scanf("%d", &n);
	
	if (n <= 0 || n > TAM) {
		mensajes(1);
		ingresarValidarTam();
	}
	
	return n;
	
}

void cargarArreglo(float* arr,const int cantidad_piezas)  {
	
	printf("Solicitud de calidad de las %d piezas\n", cantidad_piezas);
	
	for (int i = 0; i < cantidad_piezas; i++) {
		printf("Calidad de la pieza N°%d: ", i);
		scanf("%f", (arr + i));
		
		if (*(arr+i) < 0) {
			mensajes(2);
			printf("Calidad de la pieza N°%d: ", i);
			scanf("%f", (arr + i));
		}
	}
}

int calcularDefectuosas(const float *arr, const int cantidad_piezas){
	
	int n = 0;
	
	for(int i = 0; i < cantidad_piezas; i++) {
		if ((*(arr + i)) < 20 || (*(arr+i)) > 200) {
			n++;
		}
	}
	
	return n;
}

int calcularValidas (const float *arr, const int cantidad_piezas){

	int n = 0;
	
	for(int i = 0; i < cantidad_piezas; i++) {
		if (*(arr + i) >= 20 && *(arr + i) <= 200) {
			n++;
		}
	}
	
	return n;
}

void mostrarPiezas (const float *arr,const int cantidad_piezas) {
	
	printf("\n");
	printf("+---------------------------------------------+\n");
	printf("        Pieza N°\t|\tCalidad\n");
	printf("+---------------------------------------------+\n");
	
	for (int i = 0; i < cantidad_piezas; i++) {
		printf("          %d\t\t\t%.5f\n", i, *(arr+i));
	}
	
	printf("+---------------------------------------------+\n");
}

void mostrarPiezasValidasOrdenadasMenorMayor(const float* arr, const int cantidad_piezas) {
	//Ordenamiento por QuickSort
	//Copiar el arreglo
	float temp[cantidad_piezas];
	
	for (int i = 0; i < cantidad_piezas; i++) {
		temp[i] = (*(arr+i));
	}
	
	quicksort(temp, 0, cantidad_piezas - 1);

	printf("\n\tPiezas válidas ordenadas\n");
	printf("+---------------------------------------------+\n");
	
	for (int i = 0; i < cantidad_piezas; i++) {
		if (temp[i] >= 20 && temp[i] <= 200) {
		printf("            \t\t%.5f\n", temp[i]);
		}
	}
	
	printf("+---------------------------------------------+\n");
}

void quicksort (float item[], int left, int right) {
	int i, j;
	float temp;
	i = left; j = right;
	do {
		while (item[i] < item[j] && i < j) j--;
		if (i < j) {
			temp = item[i];
			item[i] = item[j];
			item[j] = temp;
			i++;
		}
		while ( item[i] < item[j] && i < j) i++;
		if(i < j) {
			temp = item[i];
			item[i] = item[j];
			item[j] = temp;
			j--;
		}
	} while (i < j);
	if (left < j) {
		quicksort(item, left, j-1);
	}
	if (i < right){
		quicksort (item, i+1, right);
	}
}
