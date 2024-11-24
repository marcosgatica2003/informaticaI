# include <stdio.h>
# define CANT_ALU 3
struct alumno {
	int legajo ;
	char nombre [20];
	char apellido [20];
	char curso [3];
	int notas [4];
	float promedio ;
	char estado ;
};
/** Completar */
int main ( void ){
	struct alumno alumnos [CANT_ALU];
	for(int i=0;i< CANT_ALU;i++){
		printf("\ningres el legajo:");
			scanf("%d",&alumnos[i].legajo);
		printf("ingres el nombre:");
			scanf("%s",alumnos[i].nombre);
		printf("ingres el apellido:");
			scanf("%s",alumnos[i].apellido);
		printf("ingres el curso:");
			scanf("%s",alumnos[i].curso);
			int suma=0;
			for(int j=0; j< 4;j++){
				printf("\ningre la nota:");
				scanf("%d",&alumnos[i].notas[j]);
				suma+=alumnos[i].notas[j];
			}
			printf("\nla suma de las notas es: %d",suma);
			alumnos[i].promedio=suma/4.0;
			printf("\nel promedio es:%f",alumnos[i].promedio);
			if (alumnos[i].promedio >= 6) {
				printf("\nAprobación directa\n");
			} 
			else if (alumnos[i].promedio >= 4 && alumnos[i].promedio < 6) {
				printf("\nRegular\n");
			} 
			else {
				printf("\nLibre :C\n");
			}
	}
	
	
	
	return 0;//guia martin
}

