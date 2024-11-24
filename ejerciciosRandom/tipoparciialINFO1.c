#include <stdio.h>
#define N 10
/** Completar las definiciones de las funciones */
int ingreso_y_validacion(void);
void ingresar_elementos(int a[], int tam);
void imprimir_arreglo(int a[], int tam);
int busca_mayor(int a[], int tam);
int busca_menor(int a[], int tam);
float calcular_promedio(int a[], int tam);

int main(void) {
	
	int arreglo[N];
	// 1. Solicitar al usuario ingresar N
	// número en un arreglo utilizando la 
	// función ingresar_elementos
	//  - Dentro de la función ingresar_elementos 
	//  se debe llamar a la función ingreso_y_validación 
	//  para
	//    validar cada uno de los elementos asignados 
	//    al arreglo
	//  - Se deben ingresar los elementos en el rango 
	//  válido de (-100,100)
	ingresar_elementos(arreglo, N);
	
	// 2. Imprimir los elementos uno debajo del otro
	printf("Los elementos son:\n");
	imprimir_arreglo(arreglo, N);
	
	// 3. Imprimir valores
	printf("El mayor elemento es: %d\n", busca_mayor(arreglo, N));
	printf("El menor elemento es: %d\n", busca_menor(arreglo, N));
	printf("El promedio de los elementos es: %f\n", calcular_promedio(arreglo, N));
	
	return 0;
}	
void ingresar_elementos(int a[], int tam){
for (int i =0; i<tam ;i++){
	a[i]=ingreso_y_validacion();
	}
}
int ingreso_y_validacion(void){
	int n;
	do{
		printf("ingrese N numeros:");
		scanf("%d",&n);
	} while(n<-100 || n>100);
	return n;
}
void imprimir_arreglo(int a[], int tam){
	for(int i =0; i<tam; i++){
		printf("%d\n",a[i]);
	}
}
int busca_mayor(int a[], int tam){
	int mayor=0;
	for (int i=0; i<tam ; i++){
		if(mayor<a[i])
			mayor=a[i];
	}
	return mayor;
}
int busca_menor(int a[], int tam){
	int menor=a[0];
	for(int i =0; i<tam; i++){
		if (menor>a[i])
			menor=a[i];
	}
	return menor;
}
float calcular_promedio(int a[], int tam){
	int suma=0;
	for (int i =0; i<tam; i++){
		suma=suma+a[i];
	}
	float resultado;
	resultado=(float)suma/ (float)tam;
	return resultado;
	
}
	
