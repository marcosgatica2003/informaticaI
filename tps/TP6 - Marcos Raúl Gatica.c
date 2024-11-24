#include <stdio.h>

float calcularPerimetro (float longitud, float altura) {
	
	longitud = 2*longitud + 2*altura;
	return longitud;
	
}

float calularArea (float longitud, float altura) {
	
	longitud = longitud * altura;
	return longitud;
	
}

void imprimirResultados (float area, float perimetro) {
	printf("\nEl �rea del rect�ngulo es: %.2f\n", area);
	printf ("El per�metro del rect�ngulo es: %.2f\n", perimetro);
}


int main(void) {
	
	float lado1, lado2, perimetro, area;
	
	do {
		printf("Ingrese la longitud del rect�ngulo: ");
		scanf("%f", &lado1);
	} while (lado1 <= 0);
	
	
	do {
		
		printf("Ingrese la altura del rect�ngulo: ");
		scanf("%f", &lado2);
	} while (lado2 <= 0);
	

	perimetro = calcularPerimetro(lado1, lado2);
	area = calularArea(lado1, lado2);
	
	imprimirResultados(area, perimetro);
	
	return 0;
}
