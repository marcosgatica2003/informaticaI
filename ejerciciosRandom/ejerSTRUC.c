#include <stdio.h>
#define CANT_ALU 3
struct alumno {
	int legajo ;
	char nombre [20];
	char apellido [20];
	char curso [3];
	int notas [4];
	float promedio ;
	char estado ;
};
int main(void){
	int DNI;
	int suma=0;
	struct alumno alumnos [CANT_ALU];
	printf("ingrese nombre:");
		scanf("%s",&alumnos->nombre);
	printf("ingrese apellido:");
		scanf("%s",&alumnos->apellido);
	printf("ingrese curso:");
		scanf("%s",&alumnos->curso);	
	printf("ingrese legajo:");
		scanf("%d",&alumnos->legajo);
	printf("ingrese DNI:");
		scanf("%d",&DNI);
	if(alumnos->legajo<0 || DNI<0){
		printf("debe ser positivo");
		return 1;
	}
	for (int i =0;i<CANT_ALU;i++){
		printf("CARGAR NOTA:");
			scanf("%d",&alumnos[i].notas[i]);
			suma+=alumnos[i].notas[i];
	}
	printf("el promedio es:%.2f",alumnos->promedio=suma/3);
	if(alumnos->promedio>=8){
		printf("\nSU ESTADO ES : %c",alumnos->estado='P');
		return 2;
	}if(alumnos->promedio>=6 && alumnos->promedio<8){
		printf("\nSU ESTADO ES : %c",alumnos->estado='R');
	} else{
		printf("\nSU ESTADO ES : %c",alumnos->estado='L');
	}
	return 0;
}

