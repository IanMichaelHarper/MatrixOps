#include <stdio.h>
#include <stdlib.h>

#define N 5 //generic size for all matrices

void print_matrix(int ** A){
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}

}

//matrix matrix multiplcation, returns pointer to first element in output matrix
int ** mm(int ** A, int ** B){
	int ** C = malloc(N*N * sizeof(int));
	int * Cdata = calloc(N*N, sizeof(int));
	for (int i=0; i<N; i++){
		C[i] = &Cdata[i*N];
	}
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			for (int k=0; k<N; k++){
				C[i][j] = A[i][k]*B[k][j];
			}
		}
	}

	return C;
			
}

int main(){
	int ** A = malloc(N*N * sizeof(int));
	int * Adata = calloc(N*N, sizeof(int));
	int ** B = malloc(N*N * sizeof(int));
	int * Bdata = calloc(N*N, sizeof(int));
	for (int i=0; i<N; i++){
		A[i] = &Adata[i*N];
		B[i] = &Bdata[i*N];
		for (int j=0; j<N; j++){
			A[i][j] = rand() % 20;
			B[i][j] = rand() % 10;
		}
	}

	int ** C = mm(A,B);
	print_matrix(A);
	printf("\n multiplied by \n");
	print_matrix(B);
	printf("\n gives \n");
	print_matrix(C);

	free(A[0]);
	free(A);
	free(B[0]);
	free(B);
	free(C[0]);
	free(C);
	return 0;
}
