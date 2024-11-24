#include <stdio.h>

typedef struct{
	unsigned long int id;
	float precio;
	char nombre[500];
} datos;

int main(){
	
	printf("TP11 - Marcos Raúl Gatica (leg.402006) - 1R3\n\n");
	
	FILE* datos_parseados;
	FILE* datos_estadisticos;
	datos producto = {0};
	datos producto_max;
	datos producto_min;
	
	datos_parseados = fopen("datos_parseados_2.csv", "r");
	datos_estadisticos = fopen("datos_estadisticos.txt", "w");
	
	if(datos_estadisticos == NULL || datos_parseados == NULL){
		printf("Error al abrir el archivo de datos estadisticos\n");
	} else {
		printf("Archivo de datos estadisticos abierto correctamente\n\n");
		
		//Leer el archivo de datos parseados (ID-PRECIO-NOMBRE)
		fscanf(datos_parseados,"%lu,%f,%499[^\n]s", &producto_max.id, &producto_max.precio, producto_max.nombre);
		
		producto_min = producto_max;
		while(!feof(datos_parseados)){
			
		fscanf(datos_parseados,"%lu,%f,%499[^\n]s", &producto.id, &producto.precio, producto.nombre);
			
		//Lógica para determinar el producto caro(max) y barato (min)
			if(producto_max.precio < producto.precio) {
				
				producto_max.id = producto.id;
				producto_max.precio = producto.precio;
				
				for(int i = 0; i!='0'; ++i) {
					producto_max.nombre[i] = producto.nombre[i];
				}
			}
			else { if(producto_min.precio > producto.precio){
					producto_min.id = producto.id;
					producto_min.precio = producto.precio;
				
					for(int i = 0; i!='0'; ++i) {
					producto_min.nombre[i] = producto.nombre[i];
				}
				}
			}
			fscanf(datos_parseados,"%lu,%f,%499[^\n]s", &producto.id, &producto.precio, producto.nombre);
			
		}
		//Imprimir productos en consola 
		printf("---------------------------------------------------------------------------------\n");
		printf("\t\tPRODUCTO CARO\n");
		printf("---------------------------------------------------------------------------------");
		printf("\nID\t\tPRECIO\t\tPRODUCTO\n");
		if (producto_max.id == 957352382) {
			printf("%lu\t$%0.2f\t%s\t(Un Elisirrr)\n\n", producto_max.id, producto_max.precio, producto_max.nombre);
		}
		else {
			printf("Producto mas caro:\nID:%lu\tPrecio:$%0.2f\tProducto:%s\n\n", producto_max.id, producto_max.precio, producto_max.nombre);
		}
		
		printf("---------------------------------------------------------------------------------\n");
		printf("\t\tPRODUCTO BARATO\n");
		printf("---------------------------------------------------------------------------------");
		printf("\nID\t\tPRECIO\t\tPRODUCTO\n");
		printf("%lu\t$%0.2f\t\t%s\n\n", producto_min.id, producto_min.precio, producto_min.nombre);
		
		//Escribe en datos_estadisticos
		fprintf(datos_estadisticos,"TP11 - Marcos Raul Gatica (leg.402006) - 1R3\n\n");
		fprintf(datos_estadisticos, "---------------------------------------------------------------------------------\n");
		fprintf(datos_estadisticos, "\t\tPRODUCTO CARO\n");
		fprintf(datos_estadisticos, "---------------------------------------------------------------------------------");
		fprintf(datos_estadisticos, "\nID\t\tPRECIO\t\tPRODUCTO\n", producto_max.id, producto_max.precio, producto_max.nombre);
		fprintf(datos_estadisticos, "%lu\t$%0.2f\t\t%s\n\n", producto_max.id, producto_max.precio, producto_max.nombre);
		
		fprintf(datos_estadisticos, "---------------------------------------------------------------------------------\n");
		fprintf(datos_estadisticos, "\t\tPRODUCTO BARATO\n");
		fprintf(datos_estadisticos, "---------------------------------------------------------------------------------");
		fprintf(datos_estadisticos, "\nID\t\tPRECIO\t\tPRODUCTO\n", producto_min.id, producto_min.precio, producto_min.nombre);
		fprintf(datos_estadisticos, "%lu\t$%0.2f\t\t%s\n\n", producto_min.id, producto_min.precio, producto_min.nombre);
		
		fclose(datos_parseados);
		fclose(datos_estadisticos);
	}
	
}
