//solucao sudoku para matriz de 3x3

#include <iostream>	
#include <stdio.h>
#include <conio.h>
using namespace std;

#define M 3

void titulo() {
	printf("######################################\n");
	printf("### Teste para solução para SUDOKU ###\n");
	printf("######################################\n");
	}

void linha() {
	printf("######################################\n");
	}

int main() {
	//variaveis
	int matriz[M][M];//matriz de entrada
	int memo[9], usado[9], copiaMemo[9];
	int matrizMemoria[M][M];
	int l, k;
	int linha[M], coluna[M];
	l = 0;
	k = 0;
	//acentuação portuguesa
	setlocale(LC_ALL, "Portuguese");

	//Lendo a matriz


	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			printf("\nDigite o valor(EM CASO VAZIO DIGITE 0'ZERO') de M[%d][%d]: ", i, j);
			scanf_s("%d", &matriz[i][j], 1);
			printf("\n", i, j);

			if ((matriz[i][j] > 0) && (matriz[i][j] < 10)) {
				usado[l] = matriz[i][j];

				copiaMemo[l] = memo[l];
				l++;
			}
			else {
				matriz[i][j] = 0;

				usado[l] = -1;
				l++;
			}


			//armazena numeros da matriz problema



			if (matriz[i][j] > 0) {
				matrizMemoria[i][j] = matriz[i][j];

			}

		}
	}
	//MATRIZ Entrada
	printf("\n\nMatriz de ENTRADA: \n ");
	for (int i = 0; i < M; i++) {
		printf("[ ");
		for (int j = 0; j < M; j++) {

			printf("%d  ", matriz[i][j]);

		}
		printf("]\n ");
	}
	printf("\n");


		for (int i = 0; i < 10; i++) {
			memo[i] = i + 1;
		}

		for (int i = 0; i < 10; i++) {

			for (int j = 0; j < 10; j++) {

				if ((memo[i]) == (usado[j])) {

					memo[i] = -1;

				}
			}
		}

		for (int i = 0; i <= M; i++) {

			for (int j = 0; j <= M; j++) {

				if (((matriz[i][j]) >= 0) && ((matriz[i][j]) < 10)) {

					linha[j] = matriz[i][j];

					if ((linha[j]) < 1) {

						for (int m = 0; m <= 9; m++) {

							if ((memo[m]) > 0 && (matriz[i][j]) < 1) {

								linha[j] = memo[m];
								matriz[i][j] = memo[m];
								memo[m] = -1;
								linha[j] = 0;
							}
						}
					}
				}
				

			}


		}
		//MATRIZ FINALL
		printf("\n\nMatriz solução: \n ");
		for (int i = 0; i < M; i++) {
			printf("[ ");
			for (int j = 0; j < M; j++) {

				printf("%d  ", matriz[i][j]);

			}
			printf("]\n ");
		}
		printf("\n");



		system("pause");
		return 0;
	}
