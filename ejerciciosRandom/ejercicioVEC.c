#include <stdio.h>
#define N 3
int main(void) {
	int suma=0;
	int producto;
	int vect1[N];
	int vect2[N];
	printf("primer vector\n");
	for (int i=0;i<N;i++){
		printf("ingrese los componentes del vector1:");
			scanf("%d",&vect1[i]);
	}
	printf("segundo vector\n");
	for (int i=0;i<N;i++){
	printf("ingrese los componentes del vector2:");
	scanf("%d",&vect2[i]);
	}
	for(int i=0;i<N;i++){
	producto=vect1[i]*vect2[i];
	suma+=producto;
	}
	printf("el producto escalar es:%d",suma);
	return 0;
}

