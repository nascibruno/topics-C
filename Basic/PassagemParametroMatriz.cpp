#include <stdio.h>
//#include <iostream.h>
#include <stdio.h>
#include <locale.h>

#define M 9

void titulo() {
	printf("######################################\n");
	printf("### Teste para solu��o para SUDOKU ###\n");
	printf("######################################\n");
}

void imprimeLinha() {
	printf("######################################\n");
}


void imprimeMatriz(int matriz[][M]) {

	//MATRIZ Entrada
	printf("\n\nMatriz : \n ");
	for (int i = 0; i < M; i++) {
		printf("[ ");
		for (int j = 0; j < M; j++) {

			printf(" %d  ", matriz[i][j]);

		}
		printf(" ]\n ");
	}
	printf("\n");


	}




int main() {
	int matriz[M][M] = {
	{ 5,3,0,0,7,0,0,0,0 },
	{ 6,0,0,1,9,5,0,0,0 },
	{ 0,9,8,0,0,0,0,6,0 },
	{ 8,0,0,0,6,0,0,0,3 },
	{ 4,0,0,8,0,3,0,0,1 },
	{ 7,0,0,0,2,0,0,0,6 },
	{ 0,6,0,0,0,0,2,8,0 },
	{ 0,0,0,4,1,9,0,0,5 },
	{ 0,0,0,0,8,0,0,7,5 } };

	int quadra[M][M], naoPodeLin[M][M], naoPodeCol[M][M], naoPodeRes[M][M];
	int memoLin[M][M], memoCol[M][M], memoQua[M][M], memoRes[M][M];

	int l, c, controle;
	l = 0;
	c = 0;
	controle = 0;



	setlocale(LC_ALL, "Portuguese");

	titulo();



	

	//escreve de 1 a 9 no vetor memoLin
	for (int i = 0; i <= M; i++) {
		l = 0;
		for (int j = 0; j <= M; j++) {
			l++;
			memoLin[i][j] = l;
		}
	}

	//escreve de 1 a 9 no vetor memoCol
	for (int i = 0; i <= M; i++) {
		c = 0;
		for (int j = 0; j <= M; j++) {
			c++;
			memoCol[i][j] = c;
		}
	}
	l = 0;
	//escreve de 1 a 9 no vetor memoQua
	//quadra1
	for (int i = 0; i <= 2; i++) {
		
		for (int j = 0; j <=2; j++) {
			l++;
			memoQua[i][j] = l;
		}
	}
	//quadra2
	l = 0;
	for (int i =0; i <= 2; i++) {

		for (int j = 3; j <= 5; j++) {
			l++;
			memoQua[i][j] = l;
		}
	}
	//quadra3
	l = 0;
	for (int i = 0; i <= 2; i++) {

		for (int j = 6; j <= 8; j++) {
			l++;
			memoQua[i][j] = l;
		}
	}
	//quadra4
	l = 0;
	for (int i = 3; i <= 5; i++) {

		for (int j = 0; j <= 2; j++) {
			l++;
			memoQua[i][j] = l;
		}
	}
	//quadra5
	l = 0;
	for (int i = 3; i <= 5; i++) {

		for (int j = 3; j <= 5; j++) {
			l++;
			memoQua[i][j] = l;
		}
	}
	//quadra6
	l = 0;
	for (int i = 3; i <= 5; i++) {

		for (int j = 6; j <= 8; j++) {
			l++;
			memoQua[i][j] = l;
		}
	}
	//quadra7
	l = 0;
	for (int i = 6; i <= 8; i++) {

		for (int j = 0; j <= 2; j++) {
			l++;
			memoQua[i][j] = l;
		}
	}
	//quadra8
	l = 0;
	for (int i = 6; i <= 8; i++) {

		for (int j = 3; j <= 5; j++) {
			l++;
			memoQua[i][j] = l;
		}
	}
	//quadra9
	l = 0;
	for (int i = 6; i <= 8; i++) {

		for (int j = 6; j <= 8; j++) {
			l++;
			memoQua[i][j] = l;
		}
	}

	//escreve de 1 a 9 no vetor memoRes??
	c = 0;
	for (int i = 0; i <= M; i++) {
		c = 0;
		for (int j = 0; j <= M; j++) {
			c++;
			memoRes[i][j] = c;
		}
	}

	//escreve quadras
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= M; j++) {
			if ((matriz[i][j]) > 0) {
				quadra[i][j] = matriz[i][j];

			}
			else {
				quadra[i][j] = -1;
			}
		}
	}

	//escreve numeros proibidos por linha
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= M; j++) {
			if ((matriz[i][j]) > 0) {
				naoPodeLin[i][j] = matriz[i][j];

			}
			else {
				naoPodeLin[i][j] = -1;
			}
		}
	}

	//escreve numeros proibidos por col
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= M; j++) {
			if ((matriz[j][i]) > 0) {
				naoPodeCol[i][j] = matriz[j][i];

			}
			else {
				naoPodeCol[i][j] =-1;
			}
		}
	}

	//escreve numeros proibidos Resultado??
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= M; j++) {
			if (((naoPodeCol[i][j]) > 0)) {
				naoPodeRes[i][j] = naoPodeCol[j][i];

			}
			if (((naoPodeCol[i][j]) < 0)) {
				
				naoPodeRes[i][j] = -1;
			}
			
				
			if ((naoPodeLin[i][j]) > 0) {
				naoPodeCol[i][j] = naoPodeLin[j][i];

			}
			if ((naoPodeLin[i][j]) < 0) {
				naoPodeRes[i][j] = -1;
			}
			if ((quadra[i][j]) > 0) {
				naoPodeCol[i][j] = quadra[j][i];

			}
			if ((quadra[i][j]) < 0) {
				naoPodeRes[i][j] = -1;
			}
		}
	}

	//filtra entradas proibidads nas memorias
	//por linha
	for (int i = 0; i < M; i++) {
		for (int c = 0; c < M; c++) {
			for (int j = 0; j < M; j++) {
				if ((memoLin[i][c]) == (naoPodeLin[i][j])) {
					memoLin[i][c] = -1;

				}

			}

		}
	}
	//por coluna 
	for (int i = 0; i < M; i++) {
		for (int c = 0; c < M; c++) {
			for (int j = 0; j < M; j++) {
				if ((memoCol[i][c]) == (naoPodeCol[i][j])) {
					memoCol[i][c] = -1;

				}

			}

		}
	}

	//filtra por quadra
	//quadra1
	for (int c = 0; c <= 2; c++) {
		for (int d = 0; d <= 2; d++) {
			for (int i = 0; i <= 2; i++) {

				for (int j = 0; j <= 2; j++) {
					if ((memoQua[c][d]) == (matriz[i][j])) {
						memoQua[c][d] = -1;

					}
					

				}
			}
		}
		
	}
	//quadra2
	
	for (int c = 0; c <= 2; c++) {
		for (int d = 3; d <= 5; d++) {
			for (int i = 0; i <= 2; i++) {

				for (int j = 3; j <= 5; j++) {
					if ((memoQua[c][d]) == (matriz[i][j])) {
						memoQua[c][d] = -1;

					}

				}
			}
		}

	}
	//quadra3
	
	for (int c = 0; c <= 2; c++) {
		for (int d = 6; d <= 8; d++) {
			for (int i = 0; i <= 2; i++) {

				for (int j = 6; j <= 8; j++) {
					if ((memoQua[c][d]) == (matriz[i][j])) {
						memoQua[c][d] = -1;

					}

				}
			}
		}

	}
	//quadra4
	
	for (int c = 3; c <= 5; c++) {
		for (int d = 0; d <= 2; d++) {
			for (int i = 3; i <= 5; i++) {

				for (int j = 0; j <= 2; j++) {
					if ((memoQua[c][d]) == (matriz[i][j])) {
						memoQua[c][d] = -1;

					}

				}
			}
		}

	}
	//quadra5
	
	for (int c = 3; c <= 5; c++) {
		for (int d = 3; d <= 5; d++) {
			for (int i = 3; i <= 5; i++) {

				for (int j = 3; j <= 5; j++) {
					if ((memoQua[c][d]) == (matriz[i][j])) {
						memoQua[c][d] = -1;

					}

				}
			}
		}

	}
	//quadra6
	
	for (int c = 3; c <= 5; c++) {
		for (int d = 6; d <= 8; d++) {
			for (int i = 3; i <= 5; i++) {

				for (int j = 6; j <= 8; j++) {
					if ((memoQua[c][d]) == (matriz[i][j])) {
						memoQua[c][d] = -1;

					}

				}
			}
		}

	}
	//quadra7
	
	for (int c = 6; c <= 8; c++) {
		for (int d = 0; d <= 2; d++) {
			for (int i = 6; i <= 8; i++) {

				for (int j = 0; j <= 2; j++) {
					if ((memoQua[c][d]) == (matriz[i][j])) {
						memoQua[c][d] = -1;

					}

				}
			}
		}

	}
	//quadra8
	
	for (int c = 6; c <= 8; c++) {
		for (int d = 3; d <= 5; d++) {
			for (int i = 6; i <= 8; i++) {

				for (int j = 3; j <= 5; j++) {
					if ((memoQua[c][d]) == (matriz[i][j])) {
						memoQua[c][d] = -1;

					}

				}
			}
		}

	}
	//quadra9
	
	for (int c = 6; c <= 8; c++) {
		for (int d = 6; d <= 8; d++) {
			for (int i = 6; i <= 8; i++) {

				for (int j = 6; j <= 8; j++) {
					if ((memoQua[c][d]) == (matriz[i][j])) {
						memoQua[c][d] = -1;

					}

				}
			}
		}

	}

	//######################################################################

	//filtrando por interse��o de quadras, linhas e colunas
	//quadra1
	for (int c = 0; c <= 2; c++) {
		for (int d = 0; d <= 2; d++) {
			for (int i = 0; i <= 2; i++) {

				for (int j = 0; j <= 2; j++) {
					if ((memoQua[c][d]) == (matriz[i][j])) {
						memoQua[c][d] = -1;

					}

				}
			}
		}

	}
	//quadra2

	for (int c = 0; c <= 2; c++) {
		for (int d = 3; d <= 5; d++) {
			for (int i = 0; i <= 2; i++) {

				for (int j = 3; j <= 5; j++) {
					if ((memoQua[c][d]) == (matriz[i][j])) {
						memoQua[c][d] = -1;

					}

				}
			}
		}

	}
	//quadra3

	for (int c = 0; c <= 2; c++) {
		for (int d = 6; d <= 8; d++) {
			for (int i = 0; i <= 2; i++) {

				for (int j = 6; j <= 8; j++) {
					if ((memoQua[c][d]) == (matriz[i][j])) {
						memoQua[c][d] = -1;

					}

				}
			}
		}

	}
	//quadra4

	for (int c = 3; c <= 5; c++) {
		for (int d = 0; d <= 2; d++) {
			for (int i = 3; i <= 5; i++) {

				for (int j = 0; j <= 2; j++) {
					if ((memoQua[c][d]) == (matriz[i][j])) {
						memoQua[c][d] = -1;

					}

				}
			}
		}

	}
	//quadra5

	for (int c = 3; c <= 5; c++) {
		for (int d = 3; d <= 5; d++) {
			for (int i = 3; i <= 5; i++) {

				for (int j = 3; j <= 5; j++) {
					if ((memoQua[c][d]) == (matriz[i][j])) {
						memoQua[c][d] = -1;

					}

				}
			}
		}

	}
	//quadra6

	for (int c = 3; c <= 5; c++) {
		for (int d = 6; d <= 8; d++) {
			for (int i = 3; i <= 5; i++) {

				for (int j = 6; j <= 8; j++) {
					if ((memoQua[c][d]) == (matriz[i][j])) {
						memoQua[c][d] = -1;

					}

				}
			}
		}

	}
	//quadra7

	for (int c = 6; c <= 8; c++) {
		for (int d = 0; d <= 2; d++) {
			for (int i = 6; i <= 8; i++) {

				for (int j = 0; j <= 2; j++) {
					if ((memoQua[c][d]) == (matriz[i][j])) {
						memoQua[c][d] = -1;

					}

				}
			}
		}

	}
	//quadra8

	for (int c = 6; c <= 8; c++) {
		for (int d = 3; d <= 5; d++) {
			for (int i = 6; i <= 8; i++) {

				for (int j = 3; j <= 5; j++) {
					if ((memoQua[c][d]) == (matriz[i][j])) {
						memoQua[c][d] = -1;

					}

				}
			}
		}

	}
	//quadra9

	for (int c = 6; c <= 8; c++) {
		for (int d = 6; d <= 8; d++) {
			for (int i = 6; i <= 8; i++) {

				for (int j = 6; j <= 8; j++) {
					if ((memoQua[c][d]) == (matriz[i][j])) {
						memoQua[c][d] = -1;

					}

				}
			}
		}

	}





	imprimeMatriz(matriz);

	imprimeLinha();

	//system("pause");

	return 0;
}