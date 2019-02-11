//definicao das constantes
//tamanho do vetor maximo

#define vMAX 100
//numero maximo de linhas
#define lMAX 5
//numero maximo de colunas
#define cMAX 5  

//dispensar mensagem de erro de seguran�a
#define _CRT_SECURE_NO_WARNINGS


//bibliotecas
//#include<conio.h>
#include<stdlib.h>
#include<stdio.h> 
#include<stdbool.h>
#include<math.h>
#include<string.h>
#include<locale.h>       //ACEITAR ACENTUA��O DA LINGUA PORTUGUESA



//exercicio 1
int testaTriangulo(float lado1, float lado2, float lado3) {

	float X, Y, Z;

	X = lado1; // recebe o lado 1 do triangulo
	Y = lado2;// recebe o lado 2 do triangulo
	Z = lado3;// recebe o lado 3 do triangulo

	//verifica se o triangulo e valido matematicamente
	if (X <= 0 || Y <= 0 || Z <= 0 || ((Y - Z) > X) || (X > (Y + Z)) ||
		((X - Z) > Y) || (Y > (X + Z)) ||
		((X - Y) > Z) || (Z > (X + Y)))
	{
		printf( "##############################################\n");
		printf( "## O TRIANGULO NAO EXISTE OU EH IMPOSSIVEL ###\n" ) ;
		printf( "##############################################\n");
		return 0;
		
	}
	else
	{
		//testa tipo do triangulo
		
		if (X == Y && X == Z && Z == Y)
		{
			printf( "######################################################\n");
			printf( "## O TRIANGULO EH EQUILATERO (TODOS OS LADOS IGUAIS)##\n" );
			printf( "######################################################\n");
			return 1;
		}
		if (X != Y && X != Z && Z != Y)
		{
			printf( "############################################################\n");
			printf( "## O TRIANGULO EH ESCALENO (TODOS OS LADOS SAO DIFERENTES)##\n" );
			printf( "############################################################\n");
			return 1;
		}

		
	}

	if (X == Y || X == Z || Z == Y) {

		printf("##################################################\n");
		printf("## O TRIANGULO EH ISOSCELES (DOIS LADOS IGUAIS) ##\n");
		printf("##################################################\n");
		return 1;
	}

}
//exercicio 2
void imposto(float salario) {

	float X, I;
	I = 0;//imposto devido
	X = salario;//X recebe o valor do salario digitado


	if (X <= 0)
	{
		printf( "######################################################\n");
		printf( "## O SALARIO EH NULO OU FOI DIGITADO INCORRETAMENTE ##\n" );
		printf( "######################################################\n");

		//return 0;

	}
	else
	{
		//X � O SALARIO
		if (X <= 1903.98) {

			printf( "###########################################################\n");
			printf( "## O TRABALHADOR ESTA NA FAIXA 1, EH ISENTO DE IMPOSTOS ##\n" );
			printf( "##########################################################\n");
			printf( "## O Imposto devido eh: R$ %.2f  ##\n" , I);
			printf( "## O Salario devido eh: R$ %.2f  ##\n\n\n" , X);
		}
		if (X > 1903.98 && X <= 2826.65)
		{
			I = ((0.075)*X) - 142.80;
			X = X - I;

			printf( "######################################################\n");
			printf( "##          O TRABALHADOR ESTA NA FAIXA 2           ##\n" );
			printf( "######################################################\n");
			printf("## O Imposto devido eh: R$ %.2f  ##\n", I);
			printf("## O Salario devido eh: R$ %.2f  ##\n\n\n", X);
		}
		if (X > 2826.65 && X <= 3751.05)
		{
			I = (X*(0.15)) - 354.80;
			X = X - I;
			printf( "############################################################\n");
			printf( "##             O TRABALHADOR ESTA NA FAIXA 3              ##\n" );
			printf( "############################################################\n");
			printf("## O Imposto devido eh: R$ %.2f  ##\n", I);
			printf("## O Salario devido eh: R$ %.2f  ##\n\n\n", X);
		}

		if (X > 3751.05 && X <= 4664.68)
		{
			I = (X*(0.225)) - 636.13;
			X = X - I;
			
			printf( "############################################################\n");
			printf( "##          O TRABALHADOR ESTA NA FAIXA 4                 ##\n" );
			printf( "############################################################\n");
			printf("## O Imposto devido eh: R$ %.2f  ##\n", I);
			printf("## O Salario devido eh: R$ %.2f  ##\n\n\n", X);
		}
		if (X > 4664.68)
		{
			I = (X*(0.275)) - 869.36;
			X = X - I;
			printf( "############################################################\n");
			printf( "##           O TRABALHADOR ESTA NA FAIXA 5               ## \n" );
			printf( "############################################################\n");
			printf("## O Imposto devido eh: R$ %.2f  ##\n", I);
			printf("## O Salario devido eh: R$ %.2f  ##\n\n\n", X);
		}


	}


}
//exercicio 3
void lerVetor(int tamanho) {

	int testaNumero; //variavel de teste para saber se o numeor � par ou impar
	int	N = tamanho; //numero de elementos do vetor
	int V[vMAX]; int P[vMAX]; int I[vMAX]; //declara�ao dos vetores V de entrada I de impar e P de par
	

	
	int k = 0, j = 0, t = 0;
	//teste de validade de N
	if (N <= 0 || N > 100) {

		printf("Valor de N esta invalido ou incorreto \n");

		//return 0;

	}
	//ler vetor de tamanho N
	for (int i = 0; N > i; i++) {
		printf("\n Insira o valor do elemento %d do Vetor: ", i + 1);
		//scanf("%f%[*^\n]", &V[i]);
		scanf("%d", &V[i]);

		
		//filtro de valor INTEIRO E POSITIVO
		while (  getchar() != '\n') {
			//V[i] = 0; V[i] < 0 ||
			printf("\n######              VALOR INVALIDO           ########\n");
			printf("\n Insira o valor INTEIRO do elemento %d do Vetor: ", i + 1);
			scanf("%d", &V[i]);
			
		}
		
		//vreifica se eh par
		testaNumero = V[i];
		t = testaNumero % 2;

		if (t == 0) {
			P[j] = V[i];
			j++;
			//PARA OS PARES
		}


		if (t > 0 || V[i] == 1) {
			I[k] = V[i];
			k++;
			//PARA OS IMPARES
		}
	}
	
	printf("\n\n ");

	
	//impress�o do vetor

	printf("O VETOR :V[ ");
	for (int i = 0; N > i; i++) {
		
		printf(" %d  ", V[i]);

	}
	printf( "] \n\n");

	   
	printf( " Aluno: BRUNO   RU  : x.xxxxx.xxx-xx\n");
	//vetor PAR
	printf( "O vetor dos PARES :P[ ");
	for (int i = 0; j > i; i++) {
		if (j == 1) {
			printf(" %d ", P[i]);

			break;
		}

		printf(" %d ", P[i] );

	}
	printf( "] \n");
	//vetor IMPAR X(ultimos dois digitos da   RU   )
	printf( "\n O vetor dos Impares x [62] :I[");
	for (int i = 0; k > i; i++) {
		if (k == 1) {
			printf(" %d ", I[i] * 62);
			break;
		}

		printf( " %d ", I[i]*62);

	}
	printf( "] \n");
}
//exercicio 4
void exercicioMatriz(int linha, int coluna) {

	int L = linha; //numero de linhas
	int C = coluna;  //numero de colunas
	float M1[lMAX][cMAX]; //matriz 1
	float M2[lMAX][cMAX]; //matriz 2
	float soma[lMAX][cMAX]; //matriz soma
	float diagonal[lMAX]; //vetor diagonal

	//escrevendo zeros nos valores de diagonal e soma
	for (int i = 0; L > i; i++) {
		diagonal[i] = 0;
		
		for (int j = 0; C > j; j++) {
			soma[i][j] = 0;
			M1[i][j]=0;
			M2[i][j]=0;

		}
	}
		
	//Leitura da matriz 1
	for (int i = 0; L > i; i++) {
		for (int j = 0; C > j; j++) {

			printf( "\n Insira o valor MATRIZ1[ %d , %d ] :", i+1,j+1);
			scanf("%f", &M1[i][j]);
			
			//filtro de valor DIFERENTE DE CARACTERE
			while (getchar() != '\n') {
				
				printf("\n#############              VALOR INV�LIDO           ###################\n");
				printf("\n Insira o valor V�LIDO para o elemento MATRIZ1[ %d , %d ] :", i + 1, j + 1);
				scanf("\n%f", &M1[i][j]);
				
			}

			}
	}

	//Leitura da matriz 2
	for (int i = 0; L > i; i++) {
		for (int j = 0; C > j; j++) {

			printf("\n Insira o valor MATRIZ2[ %d , %d ] :", i + 1, j + 1);
			scanf("%f", &M2[i][j]);

			//filtro de valor DIFERENTE DE CARACTERE
			while (getchar() != '\n') {
				
				printf("\n#############              VALOR INV�LIDO           ###################\n");
				printf("\n Insira o valor V�LIDO para o elemento MATRIZ2[ %d , %d ] :", i + 1, j + 1);
				scanf("%f", &M2[i][j]);

			}
		}
	}

	//EXIBI��O DAS MATRIZES

	//MATRIZ 1
	printf("\n\nMatriz 1: \n ");
	for (int i = 0; L > i; i++) {
		printf("[ ");
		for (int j = 0; C > j; j++) {
			
			printf( "%.2f  " , M1[i][j]);
			
		}
		printf("]\n ");
	}
	printf("\n");

	//MATRIZ 2
	printf("\n\nMatriz 2: \n ");
	for (int i = 0; L > i; i++) {
		printf("[ ");
		for (int j = 0; C > j; j++) {
			
			printf("%.2f  ", M2[i][j]);
			
		}
		printf("]\n ");
	}
	
	printf("\n\n");

	printf(" Aluno: BRUNO   RU  : x.xxxxx.xxx-xx\n");
	printf("\n\nMatriz da Soma  de M1 com M2 multiplicadas por  62 : \n ");
	for (int i = 0; L > i; i++) {
		printf("[ ");
		for (int j = 0; C > j; j++) {

			soma[i][j] = soma[i][j] + (M1[i][j] + M2[i][j])*62;
			printf("%.2f  ", soma[i][j]);

		}
		printf("]\n ");
	}
	//vetor diagonal
	if (L == C) {

		printf("\n\nVetor da Soma das diagonais de M1 com M2 multiplicadas por  62 : \n ");
		printf("[ ");
		for (int i = 0; L > i; i++) {
			
			diagonal[i] = diagonal[i] + (M1[i][i] + M2[i][i]) * 62;
			printf("%.2f  ", diagonal[i]);

		}
		printf("]\n\n\n ");
	}
	else {
		printf("\n\nAs Matrizes nao sao quadradas( numero de linhas = numero de colunas )\n" );
		printf("logo nao eh possivel encontrar o Vetor da Soma das diagonais de M1 com M2 multiplicadas por  62 : \n\n\n ");
	 }


}
//exercicio 5
int alunoUninter(float notaApol, float provaObjetiva, float provaDiscursiva,float atividadePratica) {

	float NA = notaApol;       //nota media da apol
	float PO = provaObjetiva;  //nota da prova objetiva
	float PD = provaDiscursiva;  //nota da prova discursiva
	float AP = atividadePratica; // nota da atividade pratica
	float nota = 0; //inicializa�ao e declara�ao da variavel
	
	nota = ((NA * 20) + (PO * 20) + (PD * 30) + (AP * 30)) / 100;
	
	if ( nota >= 70)
	{
		
		printf("#########################################\n");
		printf("####### O ALUNO OBTEVE MEDIA:  %.2f ###\n", nota);
		printf("#########################################\n");

		return 1;
	}

	if (nota < 70 && nota >=30)
	{
		

		printf("#########################################\n");
		printf("####### O ALUNO OBTEVE MEDIA:  %.2f ###\n", nota);
		printf("#########################################\n");

		return 2;
	}

	if (nota < 30)
	{
		

		printf("#########################################\n");
		printf("####### O ALUNO OBTEVE MEDIA:  %.2f ###\n", nota);
		printf("#########################################\n");

		return 0;
	}

}
//funcao principal
int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	//variaveis globais
	float lado1, lado2, lado3;//lados do triangulo atividade 1
	float salario; //salario do funcionario na atividade 2
	int APOL[4]; //notas da atividade 5
	int somaApol; //notas da atividade 5
	float notaApol = 0; //notas da atividade 5
	int provaObjetiva=0; //notas da atividade 5
	float provaDiscursiva=0; //notas da atividade 5
	float atividadePratica=0; //notas da atividade 5
	char escolha; //valor da escolha de qual atividade o usuario escolheu na introdu�ao
	bool saida = true; //testa comando de saida
	int teste;  //testa a situacao academica do aluno na atividade 5
	int tamanho ; //tamanho do vetor ou numero de elementos atividade 3
	int linha ; //numero de linhas da matriz atividade 4
	int coluna ; //numero de colunas da matrizatividade 4
//laco da escolha das opcoes
	do {
		//Limpa tela
		system("cls");
		//menu para acesso rapido aos exercicios
		printf("\n\n#####   PROGRAMA PARA RESOLVER OS EXERC�CIOS DO TRABALHO LOGICA DE PROGRAMA��O E ALGOR�TMOS      ####\n");
		printf("#####   ATIVIDADE PRATICA 2018 C - PROFESSOR                                    ####\n");
		printf("#####   ALUNO: BRUNO    RU : x.xxxxx.xxx-xx                                        ####\n");
		printf("\n\n");
		printf(":##################################    MENU     #####################################################:  ");
		printf("\n");
		printf("#)Digite (1) e tecle ENTER. Entra EXERCICIO 1  TESTAR O TIPO DO TRIANGULO: ");
		printf("\n");
		printf("#)Digite (2) e tecle ENTER. Entra EXERCICIO 2  IMPOSTO DEVIDO: ");
		printf("\n");
		printf("#)Digite (3) e tecle ENTER. Entra EXERCICIO 3  LER VETOR: ");
		printf("\n");
		printf("#)Digite (4) e tecle ENTER. Entra EXERCICIO 4  LER MATRIZ: ");
		printf("\n");
		printf("#)Digite (5) e tecle ENTER. Entra EXERCICIO 5  MEDIA DE ALUNO Uninter: ");
		printf("\n");
		printf("#)Digite (S) e tecle ENTER. Para Sair. ");
		printf("\n");
		printf("Sua Escolha: ");
		scanf("%s", &escolha);
		printf("\n");
		//inicializacao das variaveis para zerar a cada ciclo do laco
		teste = 0;
		salario = 0;
		lado1 = 0; lado2 = 0; lado3 = 0;
		somaApol = 0;
		 tamanho = 0;
		 linha = 0;
		 coluna = 0;
		 notaApol = 0;
		 provaObjetiva = 0;
		 provaDiscursiva = 0;
		 atividadePratica = 0;


		//EXERCICIO1
		if (escolha == '1' || escolha == '1') {
			//LIMPA TELA
			system("cls");

			printf("\n\n#############################   EXERCICIO 1 DA ATIVIDADE  ###########################################\n");
			printf("####   Imprima na tela um teste do seu programa utilizando os tres ultimos valores de                ####\n");
			printf("####   seu RU da UNINTER como lados do triangulo, cada valor do seus tres ultimos digitos do RU      ####\n");
			printf("####   sera um dos valores X, Y ou Z                                                                 ####\n");
			printf("####                                                                                                 ####\n");
			printf("####   Aluno: BRUNO,   RU : x.xxxxx.xxx-xx   X=3, Y=6 ou Z=2                           ####\n");
			
			//leitura dos lados do triangulo
			printf("\n  Digite o PRIMEIRO LADO ");
			printf("\n  A medida do Lado 1: ");
			scanf("%f", &lado1);
			//FILTRO para tamanho do vetor digitado errado
			while (lado1 < 0 || getchar() != '\n') {

				printf("\nInsira no tamanho um valor POSITIVO\n");
				printf("\n  A medida do Lado 1: ");
				//releitura do valor
				scanf("%f", &lado1);
			}
			
			printf("\n  Digite o SEGUNDO LADO ");
			printf("\n  A medida do Lado 2: ");
			scanf("%f", &lado2);
			
			//FILTRO para tamanho do vetor digitado errado
			while (lado2 < 0 || getchar() != '\n') {

				printf("\nInsira no tamanho um valor  POSITIVO\n");
				printf("\n  A medida do Lado 2: ");
				//releitura do valor
				scanf("%f", &lado2);
			}
			
			printf("\n  Digite o TERCEIRO LADO ");
			printf("\n  A medida do Lado 3: ");
			scanf("%f", &lado3);
			
			//FILTRO para tamanho do vetor digitado errado
			while (lado3 < 0 || getchar() != '\n') {

				printf("\nInsira no tamanho um valor  POSITIVO\n");
				printf("\n  A medida do Lado 3: ");
				//releitura do valor
				scanf("%f", &lado3);
			}

			printf("####   Lados X = %.2f  Y = %.2f  Z = %.2f    ####\n",lado1,lado2,lado3);

			//chama funcao com dados lidos
			testaTriangulo(lado1, lado2, lado3);
			printf("####   Aluno: BRUNO,  RU: x.xxxxx.xxx-xx     ####\n");
			printf("####  FAZENDO  X = 3, Y = 6 ou Z = 2  FORMA UM TRIANGULO : ####\n");
			//chama funcao com dados do RU de Bruno 
			testaTriangulo(3, 6, 2);

			system("pause");
		}

		//EXERCICIO 2
		if (escolha == '2' || escolha == '2') {
			//LIMPA TELA
			system("cls");
			
			printf("\n\n#############################   EXERCICIO 2 DA ATIVIDADE  ###########################################\n");
			printf("####   Imprima na tela um exemplo contendo o salario do trabalhador, o imposto devido e o           #####\n");
			printf("####   salario final ja com este desconto.                                                          #####\n");
			printf("####   Para o exemplo, utilize a sua   RU  da UNINTER                                               #####\n");
			printf("####   pegando somente os 4 ultimos d�gitos dela e usando  os como salarios.                        #####\n");
			printf("####                                                                                                #####\n");
			printf("####   Aluno: BRUNO,   RU  : x.xxxxx.xxx-xx   salario=5362                            #####\n");

			//LEITURA DO SALARIO DO FUNCIONARIO
			printf("\n Digite o SALARIO DO FUNCIONARIO ");
			printf(" Valor R$: ");
			scanf("%f", &salario);

			//CHAMA FUNCAO TENDO COMO PARAMETRO O VALOR DO SALARIO
			imposto(salario);

			//CHAMA FUNCAO TENDO COMO PARAMETRO O VALOR dos 4 ultimos digitos do RU de Bruno 
			imposto(5362);

			system("pause");
		}

		//EXERCICIO 3
		if (escolha == '3' || escolha == '3') {

			system("cls");

			
			printf("\n\n#############################   EXERCICIO 3 DA ATIVIDADE  ###########################################\n");
			printf("####   Faca um algoritmo em linguagem C com as seguintes funcionalidades :                          #####\n");
			printf("####   -Leia um vetor de N posicoes.O valor maximo de N devera ser no maximo 100. A leitura devera  #####\n");
			printf("####        ser feita manualmente pelo teclado;                                                     #####\n");
			printf("####   -Crie mais dois vetores.Armazene em um destes vetores todos os valores PARES digitados,      #####\n");
			printf("####        e no outro, todos os valores IMPARES digitados;                                         #####\n");
			printf("####   -Imprima na tela, de uma forma legivel, o numero do seu RU, o vetor dos pares e o vetor      #####\n");
			printf("####        dos �mpares, este ultimo deve ter multiplicado cada valor pelos dois ultimos n�meros    #####\n");
			printf("####        da sua matricula.Por exemplo : se sua matricula for 1234567, multiplique cada valor     #####\n");
			printf("####        do vetor por 67.                                                                        #####\n");
			printf("####    Aluno: BRUNO,   RU  : x.xxxxx.xxx-xx                                          #####\n");


			//Leitura do tamanho do vetor
			printf("\n Digite o TAMANHO DO VETOR DE (NO MAX 100) ");
			printf(" NUMERO DE ELEMENTOS DO VETOR: ");
			scanf("%d", &tamanho);
			//FILTRO para tamanho do vetor digitado errado
			while (tamanho < 0 || tamanho > 100 || getchar() != '\n') {

				printf("\nInsira no tamanho um valor INTEIRO, POSITIVO e MENOR QUE 100\n");
				printf("\nNUMERO DE ELEMENTOS DO VETOR: ");
				
				scanf("%d", &tamanho);
			}
			//chama funcao com o tamanho lido
			lerVetor(tamanho);
			
			system("pause");
		}

		//EXERCICIO 4
		if (escolha == '4' || escolha == '4') {
			system("cls");

			printf("\n\n#############################   EXERCICIO 4 DA ATIVIDADE  ###########################################\n");
			printf("####   Fa�a um algoritmo em linguagem C com as seguintes funcionalidades :                          #####\n");
			printf("####   -Receba duas matrizes como dados de entrada.A dimensao das matrizes deve ser de, no maximo   #####\n");
			printf("####        5x5. Ambas matrizes devem ter as mesmas dimensoes;                                      #####\n");
			printf("####   -O usu�rio deve digitar a dimensao das matrizes(m�ximo 5x5).Fa�a uma checagem usando um laco #####\n");
			printf("####         de repeticao que so permita o programa avan�ar caso ele digite dimensoes corretas de   #####\n");
			printf("####         no maximo 5;                                                                           #####\n");
			printf("####   -Escreva ambas matrizes na tela, de uma forma legivel;                                       #####\n");
			printf("####   -Escreva a matriz resultante da soma destas duas matrizes multiplicada pelos �ltimos dois    #####\n");
			printf("####        n�meros da sua matricula da UNINTER;                                                    #####\n");
			printf("####   -Escreva um vetor resultante da soma das diagonais principais das duas matrizes multiplicado #####\n");
			printf("####        pelos ultimos dois numeros da sua matricula da UNINTER;                                 #####\n");
			printf("####    Aluno: BRUNO,   RU  : x.xxxxx.xxx-xx                                          #####\n");

			printf("\nDigite o TAMANHO DAS MATRIZES (NO MAX 5X5) \n");
			printf("NUMERO DE LINHAS DE CADA MATRIZ: ");
			scanf("%d", &linha);
			//FILTRO para NUMERO DE LINHAS digitado errado
			while (linha < 0 || linha > 5 || getchar() != '\n') {
				printf("\nInsira no tamanho um valor INTEIRO, POSITIVO e (VALOR MAX 5)\n");
				printf("\nNUMERO DE LINHAS DE CADA MATRIZ: ");
				
				scanf("%d", &linha);
			}

			printf("\nNUMERO DE COLUNAS DE CADA MATRIZ: ");
			scanf("%d", &coluna);
			//FILTRO para NUMERO DE COLUNAS digitado errado
			while (coluna < 0 || coluna > 5 || getchar() != '\n') {
				printf("\nInsira no tamanho um valor INTEIRO, POSITIVO e (VALOR MAX 5)\n");
				printf("\nNUMERO DE COLUNAS DE CADA MATRIZ: ");
				
				scanf("%d", &coluna);
			}
			//chama funcao com o tamanho lido
			exercicioMatriz(linha, coluna);

			system("pause");
		}

		//EXERCICIO 5
		if (escolha == '5' || escolha == '5') {
			system("cls");

			printf("\n\n#############################   EXERCICIO 5 DA ATIVIDADE  ###########################################\n");
			printf("####   Fa�a um algoritmo em linguagem C que contenha uma FUNCAO que :                               #####\n");
			printf("####   a.Recebe como par�metro as notas de uma disciplina(APOLs, prova objetiva,                    #####\n");
			printf("####     prova discursiva e atividade pratica), seguindo os crit�rios da UNINTER;                   #####\n");
			printf("####   b.Retorna como resposta da fun��o : 1 se o aluno foi aprovado, 2 se esta em                  #####\n");
			printf("####     exame, ou 0 se esta reprovado.                                                             #####\n");
			printf("####   Aluno: BRUNO,   RU  : x.xxxxx.xxx-xx                                           #####\n");

			printf("\n Digite as notas das APOLS\n");

			//atribuindo zero ao vetor APOL
			for (int i = 0; i < 5; i++) {
				APOL[i] = 0;
			}

			for (int i = 0; i < 5; i++) {
				//LEITURA DAS APOLS
				printf("Valor APOL( %d ): ", i + 1);
				scanf("%d", &APOL[i]);
				//FILTRO para valor da APOL digitado errado
				//VERIFICA SE EH CARACTERE
				
				while (APOL[i] < 0 || APOL[i] > 100 || getchar() != '\n')
				{
					printf("\n###############################################################\n");
					printf("## O NOTA DA APOL FOI DIGITADO INCORRETAMENTE(entre 0 e 100) ##\n");
					printf("###############################################################\n");
					printf("Valor APOL( %d ): ", i + 1);
					scanf("%d", &APOL[i]);
					
				}
				//somatorio das notas das APOLs
				somaApol = somaApol + APOL[i];

			}
			//media das APOLs
			notaApol = somaApol / 5;

			//imprime valor da media
			printf("\nValor medio das APOLs: %.2f\n\n", notaApol);


			//LEITURA DA NOTA OBJETIVA
			printf("\n Digite a nota da Prova Objetiva \n ");
			printf(" Valor PO: ");
			scanf("%d", &provaObjetiva);
			printf("\n");
			//FILTRO para valor da PO digitado errada
			while (provaObjetiva < 0 || provaObjetiva > 100 || getchar() != '\n')
			{
				printf("\n#########################################################################\n");
				printf("## O NOTA DA Prova Objetiva FOI DIGITADO INCORRETAMENTE(entre 0 e 100) ##\n");
				printf("#########################################################################\n");
				printf(" Valor PO: ");
				scanf("%d", &provaObjetiva);

			}

			//LEITURA DA PROVA DISCURSIVA
			printf("\n Digite a nota da Prova Discursiva (USAR VIRGULA PARA DECIMAIS)  \n ");
			printf(" Valor PD: ");
			scanf("%f", &provaDiscursiva);
			printf("\n");
			//FILTRO para valor da PD digitado errada
			while (provaDiscursiva < 0 || provaDiscursiva > 100 || getchar() != '\n')
			{
				printf("\n######################################################################################################\n");
				printf("## O NOTA DA Prova Discursiva FOI DIGITADO INCORRETAMENTE(entre 0 e 100) (USAR VIRGULA PARA DECIMAIS)  ##\n");
				printf("#########################################################################################################\n");
				printf(" Valor PD: ");
				scanf("%f", &provaDiscursiva);

			}

			//LEITURA DA ATIVIDADE PRATICA
			printf("\n Digite a nota da Atividade Pratica (USAR VIRGULA PARA DECIMAIS) \n ");
			printf(" Valor AP: ");
			scanf("%f", &atividadePratica);
			printf("\n");

			//FILTRO para valor da AP digitado errada
			while (atividadePratica < 0 || atividadePratica > 100 || getchar() != '\n')
			{
				printf("\n########################################################################################################\n");
				printf("## O NOTA DA Atividade Pratica FOI DIGITADO INCORRETAMENTE(entre 0 e 100) (USAR VIRGULA PARA DECIMAIS)  ##\n");
				printf("##########################################################################################################\n");
				printf(" Valor AP: ");
				scanf("%f", &atividadePratica);

			}

			//chama funcao com os valores lidos
			teste = alunoUninter(notaApol, provaObjetiva, provaDiscursiva, atividadePratica);



			 //TESTES DE SITUACAO ACADEMICA DO ALUNO
			if (teste == 0)
			{
				printf("################################################\n");
				printf("##            REPROVADO POR MEDIA             ##\n");
				printf("################################################\n");


			}

			if (teste == 1)
			{
				printf("################################################\n");
				printf("##            APROVADO POR MEDIA              ##\n");
				printf("################################################\n");

			}

			if (teste == 2)
			{
				printf("################################################\n");
				printf("##              EM EXAME...                   ##\n");
				printf("################################################\n");

			}

			system("pause");
		}

		

		//saida do programa
		if (escolha == 'S' || escolha == 's') {
			saida = false;

		}
		//se nao teclar uma das alternativas aparece mensagem de critica
		if (escolha != '1' && escolha != '2'&& escolha != '3'
			&& escolha != '4'&& escolha != '5'&& escolha != 's' && escolha != 'S') {
			printf("\nESCOLHA UM NUMERO DE ( 1 ) a ( 5 ) e  depois tecle ENTER PARA ENTRAR EM UM EXERCICIO DA ATIVIDADE\nOU TECLE ( S )  e depois ENTER PARA SAIR\n");
			system("pause");
		}
		
		//Confirma a decisao de sair
	} while (saida);


	return 0;
	
}