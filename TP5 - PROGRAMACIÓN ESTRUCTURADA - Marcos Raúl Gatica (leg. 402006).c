#include <stdio.h>

int main(int argc, char *argv[]) {
	
	//Declaración de variables
	int cant_estudiantes;
	int calificaciones;
	int calif_max = 0;
	int calif_min = 100;
	int suma = 0;
	float promedio;
	
	//Título
	printf("Programación estructurada por Marcos Raúl Gatica - leg.402006\n\n");
	
	//Cantidad de estudiantes
	printf("Ingrese la cantidad de estudiantes a evaluar: ");
	scanf("%d", &cant_estudiantes);
	
	//Comprobación de que los estudiantes no sean 0, si no coincide, vuelve a preguntar por dicha cant.
	while (cant_estudiantes<=0){	
		printf("%d es una cantidad inválida de estudiantes, intente de nuevo.\n", cant_estudiantes);
		printf("Ingrese la cantidad de estudiantes a evaluar: ");
		scanf("%d", &cant_estudiantes);
	}
	
	//Contador: arrancando desde 1, se le irá sumando una unidad hasta que iguale a la cantidad 
	//de estudiantes, en cada ciclo pregunta por las calificaciones.
	
	for (int cont_est = 1 ; cont_est <= cant_estudiantes ; cont_est++) {
		
		printf("Ingrese las calificaciones: ");
		scanf("%d", &calificaciones);
		
		//Este while corrobora que el usuario ingrese las calificaciones en un rango de (0;100]
		while (calificaciones <= 0 || calificaciones > 100) {
			printf("La calificación %d está fuera del rango (0;100], intente de nuevo.\n", calificaciones);
			printf("Ingrese las calificaciones: ");
			scanf("%d", &calificaciones);
		}
		
		//Siendo calif_max == 0, por cada calificación mayor que se ingrese, quedará guardada
		//en la variable.
		if (calificaciones > calif_max){
			calif_max = calificaciones;
		}
		
		//Siendo calif_min == 100, por cada calificación menor que se ingrese, quedará guardada
		//en la variable.
		if (calificaciones < calif_min) {
			calif_min = calificaciones;
		}
		
		suma += calificaciones;
	}
	promedio = suma/((float) cant_estudiantes);
	
	printf("\n");
	
	//Impresión de resultados.
	printf("El promedio de las calificaciones es: %.2f\n", promedio);
	printf("La calificación más baja fue: %d\n", calif_min);
	printf("La calificación más alta fue %d\n", calif_max);
	
	return 0;
}
