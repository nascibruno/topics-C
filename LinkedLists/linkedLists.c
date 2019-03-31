#include <stdio.h>//printf
#include <stdlib.h>//malloc
#include <locale.h>
//#include <conio.h>
//#include <iostream>

typedef struct list { //declara struct dentro dessa struct num e list e o ponteiro do tipo struct list para o proximo elemento
                     int num;
                     struct list *prox; 
                     }t_list; //sinonimo para struct list


void menu(void);
void * inicInsert(t_list * inicio , int itens);
void midInsert(t_list * inicio , int itens);
void lastInsert(t_list * inicio , int itens);
void printList(t_list * inicio, t_list * proximo );


void main() {
    setlocale(LC_ALL, "Portuguese");
            //Definindo o registro
            //cada elemento da lista
        //typedef faz com que naao se precise digitar novamente o tipo de 
                           //t_list identifica o ponteiro 
    t_list *inicio = NULL ; //lista vazia, logo, ponteiro com valor NULL
    t_list *fim  ; //ponteiro fim conntera o ultimo elemento da lista
    t_list *aux;         //ponteiro auxiliar
    t_list *anterior;    //ponteiro auxiliar
    t_list *proximo;     //ponteiro para o proximo
    t_list *head;
    //declara variaveis 
    int op, item, achou;

    do{
            

          // menu de opções
          menu();
            //limpa tela
            
            scanf_s("%d", &op);//escolhe a opção

            if( op < 1 || op > 6){ //filtro
                printf("Opção Inválida");}

           
            if( op == 1 ){
            printf("Digite o valor a ser inserido.\n");
            printf("O valor escolhido: ");
            scanf_s("%d", &item);//armazena o item a ser  inserido
             printf("\n");
             //printf("Teste O valor escolhido inicio: %d", inicio -> num);
             head = inicInsert(  inicio , item);
            
                
            }//end if 1



            if(op == 2 ){
              
             lastInsert( inicio ,  item);

            }//end if 2

             if(op == 3 ){
              
             midInsert( inicio ,  item);

            }//end if 3

            if(op == 4 ){
                
                printList( head , head->prox);    
                

            }//end if 4



            /*
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
            */
           //tests
          
     }while(op != 6);
    
}
  

  void menu(void){
     
    printf("\n MENU DE OPCOES \n");
    printf("\n1 - Inserir no início da lista");
    printf("\n2 - Inserir no fim da lista");
    printf("\n3 - Inserir no meio da lista");
    printf("\n4 - Consultar toda a lista");

    
    //printf("\n4 - Remover da lista");
   // printf("\n5 - Esvaziar a lista");
    printf("\n6 - Sair");
    printf("\nDigite sua opcao: ");
}

void * inicInsert(t_list * head , int itens){
       //typedef faz com que naao se precise digitar novamente o tipo de 
                           //t_list identifica o ponteiro 
    t_list *inicio ; //lista vazia, logo, ponteiro com valor NULL
    t_list *end = NULL ; //ponteiro fim conntera o ultimo elemento da lista
    //t_list *aux;         //ponteiro auxiliar
    t_list *before;    //ponteiro auxiliar
    t_list *next;     //ponteiro para o proximo
    inicio = head;
    int item;
    item = itens;
    //head = inicio;
    //declara variaveis 
     
    if(inicio == NULL){
                     	//lista vazia e o elemento sera o primeiro e o ultimo
				inicio = (t_list *)malloc(sizeof(t_list));//##Aloca memoria para inicio sizeof ## é uma função que retorna o tamanho de um tipo( e nao da variavel) malloc
													   // retorna NULL caso NAO CONSIGA mALOCAR
						  //aponta para preencher a estrutura 
				if(inicio == NULL){
                    printf("ERRO AO ALOCAR MEMORIA\n");
                }else{
				before = NULL;
				
				printf("Primeiro elemento =>: %d\n", item);
				inicio -> num = item;	    // ponteiro para num na estrutura list o primeiro e o ultimo
				end = inicio ;
                end->prox = NULL;
                 //inicio = head ;
                }//fim if teste malloc
				return head;
				
                }else{
                    //se alista contem elementos e o novo elemento sera inserido no inic
                        //aloca nova memoria para o proximo campo TRABALHANDO COM OS ENDEREÇOS
                    
                before = head;
                                 // NOVO HEAD
                head = (t_list *)malloc(sizeof(t_list));//##Aloca memoria para inicio sizeof ## é uma função que retorna o tamanho de um tipo( e nao da variavel) malloc
													   // retorna NULL caso NAO CONSIGA mALOCAR
						                                 //aponta para preencher a estrutura 
			   if(head == NULL){
                    printf("ERRO AO ALOCAR  MEMORIA NOVAMENTE\n");
                }else{
				next = before;
				printf("Primeiro elemento ==>>: %d\n", item);
				head -> num = item;	
			    head -> prox = before;}//fim de if teste malloc
                inicio = head; 
                inicio->prox = before;  
                }//fim ifelse de teste de nulidade do head
                printf("Numero inserido no inicio da lista\n");
                return head;
                //printf("Teste O valor escolhido inicio: %d", inicio -> num);
}//end funcao


void midInsert(t_list * inicio , int itens){

        /*typedef faz com que naao se precise digitar novamente o tipo de 
                           t_list identifica o ponteiro */
    t_list *head = NULL; //lista vazia, logo, ponteiro com valor NULL
    t_list *end = NULL ; //ponteiro fim conntera o ultimo elemento da lista
    t_list *new;         //ponteiro auxiliar
    t_list *before;    //ponteiro auxiliar
    t_list *next;     //ponteiro para o proximo
        //declara variaveis 
        int op, numero, achou, meio, n;
    meio = 0;
    n = 0;
        //Reserva o endereço de espaço de memoria para o novo elemento da lista
					   new = (t_list*) malloc(sizeof(t_list));
					   

						if(head == NULL){
							//lista estava vazia e o elemento sera o prim e o ultimo
							head = (t_list*) malloc(sizeof(t_list));
							 printf("Digite o numero a ser inserido no meio da lista =>: ");
							 scanf("%d", &head->num);
							next = head;
							next->prox = NULL;
							
						}else{
							   //a lista ja contem elementos e sera inserido no fim da lista
							     printf("Digite o numero a ser inserido no meio da lista ==>>: ");
							    scanf("%d", &new->num);
							   
							   next = head;
							   while(next->prox != NULL){
							    //   percorre todos os ponteiros ate achar o ultimo
							    next = next->prox ;
								//printf("dentro\n");
								n++;
							   }
							   
							    // quando achar  o ultimo a variavel n recebe o valor do numero de ítens
							   meio = (int)(n / 2);
							   
							   next = head;
							  for(int i = 0; i < meio ; i++){
							  	//   percorre todos os ponteiros ate achar o meio
							    next = next->prox ;
								//printf("dentro %d\n", meio);
							  }
							  before = next;
							  //aux(novo) aponta para o ponteiro que o antigo apontava
							  new->prox = next->prox;
							  
							  //proximo recebe o ponteiro para onde apontava
							  //						proximo = proximo -> prox;
							  //recebe o endereço do novo
							  before->prox = new;
							  
						}
					
					
			printf("Numero inserido no meio da lista\n");



}


void lastInsert(t_list * inicio , int itens){

            /*typedef faz com que naao se precise digitar novamente o tipo de 
                           t_list identifica o ponteiro */

    t_list *head = NULL; //lista vazia, logo, ponteiro com valor NULL
    t_list *end = NULL ; //ponteiro fim conntera o ultimo elemento da lista
    t_list *new;         //ponteiro auxiliar
    t_list *before;    //ponteiro auxiliar
    t_list *next;     //ponteiro para o proximo


                        //Reserva o endereço de espaço de memoria para o ultimo elemento da lista
					   new = (t_list*) malloc(sizeof(t_list));
					   

						if(head == NULL){
							//lista estava vazia e o elemento sera o prim e o ultimo
							head = (t_list*) malloc(sizeof(t_list));
							 printf("(A)Digite o numero a ser inserido no fim da lista: ");
							 scanf("%d", &head->num);
							next = head;
							next->prox = NULL;
							
						}else{
							   //a lista ja contem elementos e sera inserido no fim da lista
							     printf("(B)Digite o numero a ser inserido no fim da lista: ");
							    scanf("%d", &new->num);
							   next = head;
							   while(next->prox != NULL){
							    //   percorre todos os ponteiros ate achar o ultimo
							    
								next = next->prox ;
								printf("dentro\n");
						
							   }//end while
							   
							   // quando achar  o ultimo a variavel auxiliar recebe esse ponteiro
							  
							   next->prox = new;
							   new->prox = NULL;
						}//end if and else
					//	printf("Numero inserido no fim da lista");

			}/*end lastInsert*/



void printList(t_list * inicio, t_list * proximo ){

    t_list *head = NULL; //lista vazia, logo, ponteiro com valor NULL
    t_list *end = NULL ; //ponteiro fim conntera o ultimo elemento da lista
    t_list *new;         //ponteiro auxiliar
    t_list *before;    //ponteiro auxiliar
    t_list *next;     //ponteiro para o proximo
    
    head = inicio;
    next = proximo;
    //printf("num: %d\n", head->num);
          // next->prox = NULL;
           next = head;

           while(next != NULL){
           printf("num: %d\n", next->num);
           next = next->prox; }//end while

}
