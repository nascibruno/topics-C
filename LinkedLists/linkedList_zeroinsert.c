#include <stdio.h>//printf
#include <stdlib.h>//malloc
//#include <conio.h>
//#include <iostream>

void menu(void) {
	//clrscr();
	printf("\n MENU DE OPÇÕES \n");
	printf("\n1 - Inserir no início da lista");
	printf("\n2 - Inserir no fim da lista");
	printf("\n3 - Consultar toda a lista");
	printf("\n4 - Remover da lista");
	printf("\n5 - Esvaziar a lista");
	printf("\n6 - Sair");
	printf("\nDigite sua opção: ");
}

	typedef struct list { //declara struct dentro dessa struct num e list e o ponteiro do tipo struct list para o proximo elemento
		int num;
		struct list * prox;
	}t_list;  //typedef faz com que naao se precise digitar novamente o tipo de 
					   //t_list identifica o ponteiro 

int main(int argc, char *argv[]) {
	//Definindo o registro
	//cada elemento da lista

	t_list * inicio = NULL; //lista vazia, logo, ponteiro com valor NULL
	t_list * fim = NULL; //ponteiro fim conntera o ultimo elemento da lista
	t_list * aux;         //ponteiro auxiliar
	t_list * anterior;    //ponteiro auxiliar para o elemento anterior
	t_list * proximo;     //ponteiro para o proximo
	t_list * head;
	//declara variaveis 
	int op, numero, achou;

	do {
		// menu de opções
		menu();
		
	
	   
		
		scanf("%d", &op);//escolhe a opção
		
		if (op < 1 || op > 6) { //filtro
			printf("Opção Inválida");
		}
		
		
		
		if (op == 1) {
			printf("Digite o numero a ser inserido no inicio da lista: ");
			
			
			 
			if (inicio == NULL) {
				//lista vazia e o elemento sera o primeiro e o ultimo
				
				inicio = (t_list *)malloc(sizeof(t_list));//##Aloca memoria para inicio sizeof ## é uma função que retorna o tamanho de um tipo( e nao da variavel) malloc
													   // retorna NULL caso NAO CONSIGA mALOCAR
						  //aponta para preencher a estrutura 
				anterior = NULL;
				head = inicio; // NOVO HEAD
				proximo = anterior;
				printf("(A)Primeiro elemento =>: ");
				scanf("%d", &head-> num);	    // ponteiro para num na estrutura list o primeiro e o ultimo
				proximo->prox = proximo;
				
			

			}
			else {
			

				
				inicio = (t_list *)malloc(sizeof(t_list));//##Aloca memoria para inicio sizeof ## é uma função que retorna o tamanho de um tipo( e nao da variavel) malloc
													   // retorna NULL caso NAO CONSIGA mALOCAR
						  //aponta para preencher a estrutura 
			    anterior = head;
				head = inicio; // NOVO HEAD
				proximo = anterior;
				proximo -> prox = proximo;
				printf("(B)Primeiro elemento =>: ");
				scanf("%d", &head -> num);	
			    
			
			}
			printf("Numero inserido no inicio da lista\n");
		
			
		}



		
		//##################SEGUNDA OPÇÃO
		
					if(op == 2 ){
					   printf("Digite o numero a ser inserido no fim da lista: ");
					   //list *novo = new list();


					   list *novo = (list*) malloc(sizeof(list));
					   scanf_s("%d" ,novo->num);


						if(inicio == NULL){
							//lista estava vazia e o elemento sera o prim e o ultimo
							inicio = novo;
							fim = novo;
							fim->prox = NULL;
						}else{
							   //a lista ja contem elementos e sera inserido no fim da lista
							fim->prox = novo;
							fim = novo;
							fim->prox =  NULL;
						}
						printf("Numero inserido no fim da lista\n");

					}
					
					
					if(op == 3 ){

						if(inicio == NULL){
							printf("Lista Vazia ");
							//lista vazia

						}else{
							//a lista contam elementos e estes serao mostrados do inic ao fim
							printf("\n Consultando a lista do inicio ao fim\n ");
							aux = inicio;
							while (aux != NULL){
								printf("%d ",aux->num);
								aux = aux->prox;
							}
						}


					}
					if(op == 4 ){
							if(inicio == NULL){
							printf("Lista Vazia ");
							//lista vazia

						}else{
							// a lista contem elementos e o elemento a ser removido deve ser digitado
						 printf("\nDigite o elemento a ser apagado\n");
						 scanf_s("%d",numero);
						 //todas as ocorrencias da lisa, iguais ao numero digitado serao removidas
						 aux = inicio;
						 anterior = NULL;
						 achou = 0;
						 while (aux != NULL){
							 if(aux->num == numero){
								 //numero digitado encontrado
								 achou = achou +1;
								 if(aux == inicio){
									 //numero a ser apagado é o primeiro
									 inicio = aux->prox;
									 delete(aux);
									 aux=inicio;
								 }else if(aux ==fim){
								   // o numeor a ser removido é o ultimo da lista
									anterior->prox =NULL;
									fim =  anterior;
									delete(aux);
									aux =NULL;
								 }else{
									 //o numero a ser apagado esta no meio da lista
									anterior->prox = aux->prox;
									delete(aux);
									aux =anterior->prox;
								 }
							 }else{
								 anterior = aux;
								 aux =aux->prox;
							 }
						 }
						if(achou==0){
							printf("\nNumero nao encontrado\n");
							}else if(achou == 1){
								printf("\nelemento apagado 1 vez\n");
							}else{
								printf("\n elemento apagado %d vezes\n", achou);
							}
						}
					}
					if(op == 5 ){
						if(inicio == NULL){
							printf("Lista Vazia ");
							//lista vazia
						}else{
							//a lista será esvaziada
							aux = inicio;
							while(aux!= NULL){
								inicio = inicio ->prox;
								delete(aux);
								aux =inicio;
							}
							printf("Lista esvaziada");
						}
					}
					getch();
					
					//tests
		
		
	} while (op != 6);

       /*
		 proximo = head;
           do{
           printf("%d ,", proximo->num);
           proximo = proximo->prox ;
           }while(proximo != NULL);
									}*/
			proximo->prox = NULL;						
			proximo = head ;
			
			printf("num: %d\n", head->num);	
				printf("num: %d\n", aux ->num);
				printf("num: %d\n", inicio->num);	
				proximo = proximo -> prox;
				printf("num: %d\n", proximo->num);
				
	return 0;
}

