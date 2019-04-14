/* Author Bruno do Nascimento Franco RU 2575362  ABR 2019 Brazil*/

#include <stdio.h>//printf
#include <stdlib.h>//malloc
#include <string.h>
#include <locale.h>
//#include <conio.h>
//#include <iostream>

/* Deve-se armazenar o nome de cada música, do artista/banda e a duração da faixa. 
Para o armazenamento utilize uma estrutura heterogênea de dados  */

#define tamMusica 200
#define tamBanda 200
#define tamTempo 16

/*declara struct dentro dessa struct num e list e o ponteiro do 
 tipo struct list para o proximo elemento*/
typedef struct list { 
                     char nomeMusica[tamMusica]; //nome da musica
                     char nomeBanda[tamBanda];  //nome da Banda
                     int min; //min minutos de duraçao da musica
                     struct list *prox; 
                     }t_list; //sinonimo para struct list


                     

void ClearScreen();
void  menu();
void menuApaga();
void listaVazia(void);
void * inicInsert(t_list * head , char * music, char * band, int min);
void * midInsert(t_list * head , char * music, char *band, int min);
void * lastInsert(t_list * head , char * music, char * band, int min);
void  printList(t_list * inicio, t_list * proximo );
void * apagaItem(t_list * head , int erase);
void * esvaziaLista(t_list * head);

void main() {
    system("cls");
    setlocale(LC_ALL, "pt-BR.UTF-8");
            //Definindo o registro
            //cada elemento da lista
        //typedef faz com que naao se precise digitar novamente o tipo de 
                           //t_list identifica o ponteiro 
    t_list *inicio = NULL ; //lista vazia, logo, ponteiro com valor NULL
    t_list *fim  ; //ponteiro fim conntera o ultimo elemento da lista
    t_list *aux;         //ponteiro auxiliar
    t_list *anterior;    //ponteiro auxiliar
    t_list *proximo;     //ponteiro para o proximo
    t_list *head = NULL;
    //declara variaveis 
    int op,apaga, tempo, achou;
    char musica[tamMusica], banda[tamBanda];
    char num[tamTempo];//converter num em tempo


    do{
            

          // menu de opções
           menu(  );
            //limpa tela
             fflush(stdin);
            if (fgets(num, sizeof(num), stdin)) {
              if (1 == sscanf(num, "%d", &op)) {
                    if( op < 1 || op > 7) //filtro
                        printf("\n\n!!!Opção Inválida!!!\n\n\a");
                     }//recebe op
                }
           
           
            if( op == 1 ){
            system("cls");
            printf("\n\nDigite os dados a serem inseridos no inicio da Playlist.\n");
            printf("O Nome da Musica: ");
            
            fflush(stdin);
            if (fgets(musica, sizeof(musica), stdin)){
                 //armazena o nome da musica a ser  inserida
                musica[strlen(musica)-1]='\0';//caractere anterior fecha a string e evita que fgets pule uma linha
                 //printf("O valor de strlen : %d\n",strlen(musica));//teste de valores
                 // printf("O valor de musica : %s\n",musica);
                }
            
            printf("O Nome da Banda: ");

            fflush(stdin);
            if (fgets(banda, sizeof(banda), stdin)){ //armazena o nome da bnda a ser  inserida
            banda[strlen(banda)-1]='\0';}//caractere anterior fecha a string e evita que fgets pule uma linha

            printf("O valor Duração da música (em Segundos): ");
            fflush(stdin);
            if (fgets(num, sizeof(num), stdin)) {
                        if (1 == sscanf(num, "%d", &tempo)) {
                         printf("\n");
            
                        head = inicInsert( head, musica, banda, tempo );//devido a funcao de imprimir precisa retornar o end de ini
             
                        }
                }//armazena o tempo a ser  inserido
            
                
            }//end if 1

            if(op == 2 ){
                system("cls");
           //printf("\n2 - Inserir no fim da lista");
            printf("\n\nDigite os dados a serem inseridos no fim da Playlist.\n");

            printf("O Nome da Música: "); 
            fflush(stdin);// limpa o buffer para entrada
            if(fgets(musica,sizeof(musica),stdin)){ //armazena o nome da bnda a ser  inserida
            musica[strlen(musica)-1]='\0';}//caractere anterior fecha a string e evita que fgets pule uma linha

            printf("O Nome da Banda: ");
            fflush(stdin);
             if(fgets(banda,sizeof(banda),stdin)){ //armazena o nome da bnda a ser  inserida
            banda[strlen(banda)-1]='\0';}

            printf("O valor Duração da Música (em Segundos ): ");
            if (fgets(num, sizeof(num), stdin)) {
                        if (1 == sscanf(num, "%d", &tempo)) {
                        printf("\n");
            
                         head = lastInsert( head, musica, banda, tempo );
                        }
                }//armazena o tempo a ser  inserido
            

            }/*end if 2*/

             if(op == 3 ){
                    system("cls");
            //printf("\n3 - Inserir no meio da lista");
            printf("\n\nDigite o valor a ser inserido no meio da lista.\n");

            printf("O Nome da Música: "); 
            fflush(stdin);// limpa o buffer para entrada
            fgets(musica,sizeof(musica),stdin);{ //armazena o nome da bnda a ser  inserida
            musica[strlen(musica)-1]='\0';}//caractere anterior fecha a string e evita que fgets pule uma linha

            printf("O Nome da Banda: ");
            fflush(stdin);
             if(fgets(banda,sizeof(banda),stdin)){ //armazena o nome da bnda a ser  inserida
            banda[strlen(banda)-1]='\0';}

            printf("O valor Duração da Música (em Segundos): ");
            if (fgets(num, sizeof(num), stdin)) {
                        if (1 == sscanf(num, "%d", &tempo)) {
                        printf("\n");
            
                        head = midInsert( head, musica, banda, tempo ); 
                        }
                }//armazena o tempo a ser  inserido
            

            }//end if 3

            
            if(op == 4 ){
                
                 // APAGA ITENS DA LISTA
            
                //limpa tela
                do{
                 system("cls");

                    if (head == NULL){

                            listaVazia();
                            apaga=5;

                        }else{

                                 menuApaga();
                         printList( head , head->prox);
                         
                         

                             if (fgets(num, sizeof(num), stdin)) {
                                    if (1 == sscanf(num, "%d", &apaga)) {//recebe op
                                         if( apaga < 1 || apaga > 5){ //filtro
                                             printf("\n\n!!!Opção Inválida!!!\n\n\a");
                                         }else{
                                             head = apagaItem(head ,  apaga);
                                             }
                                     }//converte string em int
                                }//leitura de string do teclado

                    }////deletar POR nome, banda ou tempo de duração


                 
                }while(apaga != 5);

            }//end if 4
            
            if(op == 5 ){
                //Esvaziar a lista
               system("cls"); 
               head = esvaziaLista( head );

            }//end if 5

            if(op == 6 ){
                system("cls");
                if(head == NULL){
                    
                    listaVazia();
                
                 }  
                 else{

                     printList( head , head->prox); 

                 }
                
            }//end if 6
          
     }while(op != 7);
     printf("\n\n###    Programa Encerrado  ###\n\n");
}
  

  void  menu(){
    //  system("cls");
    //ClearScreen();
   
            system("cls");
            printf("\n MENU DE OPÇÕES\n");
             printf("\n\n1 - Inserir no início da lista");
             printf("\n2 - Inserir no fim da lista");
            printf("\n3 - Inserir no meio da lista");
             printf("\n4 - Remover da lista");
             printf("\n5 - Esvaziar a lista");
            printf("\n6 - Mostrar toda a lista");
             printf("\n7 - Sair");
             printf("\n\nDigite sua opção: ");
            

    
}

void  menuApaga(void){
              

                printf("\n\n\n");
                printf("\nQual apagar:");
                printf("\n\n1 - Por nome da Música.");
                printf("\n2 - Por nome da banda.");
                printf("\n3 - Por tempo maior que:");
                printf("\n4 - Por tempo menor que:");
                printf("\n5 - Sair");
                printf("\n\nDigite sua opção: ");


}



void * inicInsert(t_list * head , char * music, char * band, int min){
       //typedef faz com que naao se precise digitar novamente o tipo de 
                           //t_list identifica o ponteiro 
    t_list *inicio ; //lista vazia, logo, ponteiro com valor NULL
    t_list *end = NULL ; //ponteiro fim conntera o ultimo elemento da lista
    //t_list *aux;         //ponteiro auxiliar
    t_list *before;    //ponteiro auxiliar
    t_list *next;     //ponteiro para o proximo
    inicio = head;  //recebe o head
    
    int op, tempo, achou;
    /*strcpy(char *dest,char *src); // tratamento de stringgs
    
   memset(dest, '\0', sizeof(dest));
   strcpy(src, "This is tutorialspoint.com");
   strcpy(dest, src);

    sprintf(student_mark.passfail,"DISTINCTION\n");
    */
    char musica[tamMusica], banda[tamBanda];
    memset(musica, '\0', sizeof(musica));
    memset(banda, '\0', sizeof(banda));
    strcpy(musica,music);
    strcpy(banda,band);
   
    tempo = min;
    
    //declara variaveis 
     
    if(inicio == NULL){
                     	//lista vazia e o elemento sera o primeiro e o ultimo
				inicio = (t_list *)malloc(sizeof(t_list));//##Aloca memoria para inicio sizeof ## é uma função que retorna o tamanho de um tipo( e nao da variavel) malloc
													   // retorna NULL caso NAO CONSIGA mALOCAR
						  //aponta para preencher a estrutura 
			        	if(inicio == NULL){
                            printf("ERRO AO ALOCAR MEMORIA\n");
                            return NULL;
                            system("pause");
                          }else{

			            	before = NULL;
			            	
			            	strcpy(inicio -> nomeMusica,musica);
                            strcpy(inicio -> nomeBanda,banda);
                            inicio -> min = tempo;	    // ponteiro para min na estrutura list o primeiro e o ultimo
                            
			            	end = inicio ;
                              end->prox = NULL;
                              
                        }//fim if teste malloc
                          printf("Música inserida foi a primeira da lista. Não havia ítens na lista.\n\n");
			        	system("pause");
                        return inicio;
				
                }else{
                    //se alista contem elementos e o novo elemento sera inserido no inic
                        //aloca nova memoria para o proximo campo TRABALHANDO COM OS ENDEREÇOS
                    
                            before = inicio;
                                 // NOVO HEAD
                            head = (t_list *)malloc(sizeof(t_list));//##Aloca memoria para inicio sizeof ## é uma função que retorna o tamanho de um tipo( e nao da variavel) malloc
													   // retorna NULL caso NAO CONSIGA mALOCAR
						                                 //aponta para preencher a estrutura 
			               if(head == NULL){
                               printf("ERRO AO ALOCAR  MEMORIA NOVAMENTE\n");
                               return NULL;
                               system("pause");
                                  }else{
			                	
                                     next = before;
                                	strcpy(head -> nomeMusica,musica);
                                    strcpy(head -> nomeBanda,banda);
                
				                     head -> min = tempo;	
			                        head -> prox = before;
                                      
                                  }//fim de if teste malloc
                                  
                                inicio = head; 
                                inicio->prox = before; 
                                
                                }//fim ifelse de teste de nulidade do head
                                
                printf("Música inserida no inicio da lista\n\n");
                system("pause");
                return inicio;
              
             
        }//end funcao



void  * midInsert(t_list * head , char * music, char * band, int min){

        /*typedef faz com que naao se precise digitar novamente o tipo de 
                           t_list identifica o ponteiro */
    t_list *inicio ; //lista vazia, logo, ponteiro com valor NULL
    t_list *end = NULL ; //ponteiro fim conntera o ultimo elemento da lista
    t_list *new = NULL;         //ponteiro auxiliar
    t_list *before;    //ponteiro auxiliar
    t_list *next;     //ponteiro para o proximo
    inicio = head;

        /*eclara variaveis locais*/

    int op, segundos, achou, meio, n;
    segundos = min;
    meio = 0;
    n = 0;



     char musica[tamMusica], banda[tamBanda];
    memset(musica, '\0', sizeof(musica));
    memset(banda, '\0', sizeof(banda));
    strcpy(musica,music);
    strcpy(banda,band);

    
    
    
        //Reserva o endereço de espaço de memoria para o novo elemento da lista
					   new = (t_list*) malloc(sizeof(t_list));
					   

						if(inicio == NULL){
							//lista estava vazia e o elemento sera o prim, ultimo e central
							    inicio = new;
                                 if(inicio == NULL){
                                 printf("\nERRO AO ALOCAR MEMORIA\n");
                                    system("pause");
                                    return NULL;

                                    }else{
                                    
                                     strcpy(inicio -> nomeMusica,musica);
                                     strcpy(inicio -> nomeBanda,banda);        
                                    
							        inicio->min = segundos;
							        next = inicio;
							        next->prox = NULL;
                                 }//checa a allocaçao

							        printf("\nInserido com sucesso. Não havia ítens na lista.\n\n");
                                     system("pause");
                                     return inicio;

						    }else{
							   //a lista ja contem elementos e sera inserido no meio da lista
							    
                                strcpy(new -> nomeMusica,musica);
                                strcpy(new -> nomeBanda,banda);
                                
                                new->min= segundos;

                            //   percorre todos os ponteiros ate achar o ultimo
							     next = head;
							   while(next->prox != NULL){
							     next = next->prox ;
							    	n++;//conta elementos
							   }//end while
							   
							    // quando achar  o ultimo a variavel n recebe o valor do numero de ítens
							   meio = (int)(n / 2);

							   //   percorre todos os ponteiros ate achar o meio
							    next = head;
							    for(int i = 0; i < meio ; i++){
							  	 next = next->prox ;
								
							    }
							    
							  before = next;
							  //aux(novo) aponta para o ponteiro que o antigo apontava
							  new->prox = next->prox;
							  
							  //proximo recebe o ponteiro para onde apontava
							  //						proximo = proximo -> prox;
							  //recebe o endereço do novo
							  before->prox = new;
							  
						}
					
					
			printf("\nInserido no meio da lista\n\n");
            system("pause");
            return head;


}

void * lastInsert(t_list * head , char * music, char * band, int min){

            /*typedef faz com que naao se precise digitar novamente o tipo de 
                           t_list identifica o ponteiro */

    t_list *inicio ; //lista vazia, logo, ponteiro com valor NULL
    t_list *end = NULL ; //ponteiro fim conntera o ultimo elemento da lista
    t_list *new = NULL;         //ponteiro auxiliar
    t_list *before;    //ponteiro auxiliar
    t_list *next;     //ponteiro para o proximo
    inicio = head;
    int tempo;


     char musica[tamMusica], banda[tamBanda];
    memset(musica, '\0', sizeof(musica));
    memset(banda, '\0', sizeof(banda));
    strcpy(musica,music);
    strcpy(banda,band);
   
    tempo = min;

                   //se inicio for NULL aloque novo espaço
						if(inicio == NULL){
							//lista estava vazia e o elemento sera o prim e o ultimo
							head = (t_list*) malloc(sizeof(t_list));
                            if(head == NULL){
                                printf("ERRO AO ALOCAR MEMORIA\n");
                                system("pause");
                                return NULL;
                                }else{
                                strcpy(inicio -> nomeMusica,musica);
                                strcpy(inicio -> nomeBanda,banda);
							    head->min= tempo;
							    next = head;
							    next->prox = NULL;
                                }//fim if filtro
                                printf("\nInserido foi no final da lista. Não havia ítens na lista.\n\n");
                                system("pause");
                                return head;
							
						}else{
							   //a lista ja contem elementos e sera inserido no fim da lista
                               new = (t_list*) malloc(sizeof(t_list));
                               //add struct
                               	strcpy(new -> nomeMusica,musica);
                                strcpy(new -> nomeBanda,banda);
							    new->min = tempo;

							   next = head;

							   while(next->prox != NULL){
							    //   percorre todos os ponteiros ate achar o ultimo
							    next = next->prox ;
								
						
							   }//end while
							   
							   // quando achar  o ultimo a variavel auxiliar recebe esse ponteiro
							   next->prox = new;
							   new->prox = NULL;
                               
						}//end if and else
						printf("\nInserido no final da lista\n\n");
                        system("pause");
                        return head;
			}/*end lastInsert*/


void * apagaItem(t_list * head , int erase){


    /*typedef faz com que naao se precise digitar novamente o tipo de 
                           t_list identifica o ponteiro */
    t_list *inicio ; //lista vazia, logo, ponteiro com valor NULL
    t_list *end = NULL ; //inicializa o ponteiro fim contera o ultimo elemento da lista
    t_list *aux = NULL;         //ponteiro auxiliar
    t_list *before;    //ponteiro auxiliar
    t_list *next;     //ponteiro para o proximo

    inicio = head;      //recebe o head
        //declara variaveis locais
    int op, segundos, achou, meio, n, opcao;
     char musica[tamMusica], banda[tamBanda];
     char apagamusica[tamMusica], apagabanda[tamBanda],  num[tamTempo];
     /*
    memset(musica, '\0', sizeof(musica));
    memset(banda, '\0', sizeof(banda));
    strcpy(musica,music);
    strcpy(banda,band);*/

    
    segundos = 0;
    meio = 0;
    n = 0;
    opcao = erase;
                        


                 next = head;
				 while(next->prox != NULL){
				next = next->prox ;
				}//end while
                end = next->prox;//obtenho o ponteiro para o ultimo

               if(inicio == NULL){
                    printf("\n\nA lista está vazia!\n\n");
                    //lista vazia 
                   
                }else{
                    // a lista contem elementos e o elemento a ser removido deve ser digitado
                 
                 //todas as ocorrencias da lista, iguais ao minutos digitado serao removidas
                    switch (opcao)
                    {
                        
                        case 1:
                        {
                                //por NOME
                              aux = inicio;
                             before = NULL;
                             achou = 0;

                            printf("\nO Nome da Musica que deseja apagar: "); 
                            fflush(stdin);// limpa o buffer para entrada
                            fgets(apagamusica,sizeof(apagamusica),stdin);{ //armazena o nome da bnda a ser  inserida
                             apagamusica[strlen(apagamusica)-1]='\0';}//caractere anterior fecha a string e evita que fgets pule uma linha


                             while (aux != NULL){
                      
                                if(0 == strcmp(aux->nomeMusica,apagamusica)){ //compara as strings e retorna 0 se forem iguais ignorando CASE SENSITIVE
                                            //minutos digitado encontrado
                                              achou = achou +1;
                                         if(aux == inicio){
                                         //numero a ser apagado é o primeiro
                                             inicio = aux->prox;
                                             free(aux);
                                             aux=inicio;
                                             }else if(aux == end){
                                                // o numeor a ser removido é o ultimo da lista     
                                                before->prox =NULL;
                                                  end =  before;
                                                  free(aux);
                                                 aux =NULL;
                                            }else{
                                                //o numero a ser apagado esta no meio da lista
                                                 before->prox = aux->prox;
                                                free(aux);
                                               aux =before->prox;
                                              }
                                 }else{
                                    before = aux;
                                     aux =aux->prox;
                                }
                            }//fim do while

                            if(achou==0){
                                if(achou==0){
                                 printf("\nNao encontrado\n");
                                 system("pause");
                                 break;
                                }else if(achou == 1){
                                  printf("\nElemento apagado 1 vez\n");
                                  system("pause");
                                  break;
                                }else{
                                  printf("\nElemento apagado %d vezes\n", achou);
                                  system("pause");
                                  break;
                                 }
                      
                            }
                        }
                        
                            break;



                        case 3:
                        {    
                               
                                printf("\nMusicas com tempo maior que o digitado(em segundos) será apagado: "); 
                                if (fgets(num, sizeof(num), stdin)) 
                                 if (1 == sscanf(num, "%d", &segundos)) 

                                aux = inicio;
                                before = NULL;
                                 achou = 0;

                             while (aux != NULL){
                                     if(aux->min > segundos){//maior do que escolhido
                                         //minutos digitado encontrado
                                            achou = achou +1;
                                                if(aux == inicio){
                                                    //numero a ser apagado é o primeiro
                                                         inicio = aux->prox;
                                                      free(aux);
                                                     aux=inicio;
                                                 }else if(aux == end){
                                         // o numeor a ser removido é o ultimo da lista     
                                                  before->prox =NULL;
                                                  end =  before;
                                                     free(aux);
                                                     aux =NULL;
                                                 }else{
                                         //o numero a ser apagado esta no meio da lista
                                                 before->prox = aux->prox;
                                                free(aux);
                                                aux =before->prox;
                                                    }

                                        }else{
                                             before = aux;
                                             aux =aux->prox;
                                             }
                            }//fim do while
                                
                                if(achou==0){
                                 printf("\nNao encontrado\n");
                                 system("pause");
                                 break;
                                }else if(achou == 1){
                                  printf("\nElemento apagado 1 vez\n");
                                  system("pause");
                                  break;
                                }else{
                                  printf("\nElemento apagado %d vezes\n", achou);
                                  system("pause");
                                  break;
                                 }
                        
                        }
                        
                            break;



                        case 4:
                        {   
                                printf("\nMusicas com tempo maior que o digitado(em segundos) será apagado: "); 
                                if (fgets(num, sizeof(num), stdin)) 
                                 if (1 == sscanf(num, "%d", &segundos))                         
                                 
                              
                             //armazena o tempo a ser  inserido


                                aux = inicio;
                                before = NULL;
                                achou = 0;
                             while (aux != NULL){
                                    if(aux->min < segundos){//se for menor do que o digitado
                                     //minutos digitado encontrado
                                     achou = achou +1;
                                    if(aux == inicio){
                                    //numero a ser apagado é o primeiro
                                     inicio = aux->prox;
                                     free(aux);
                                     aux=inicio;
                                      }else if(aux == end){
                                    // o numeor a ser removido é o ultimo da lista     
                                     before->prox =NULL;
                                     end =  before;
                                    free(aux);
                                    aux =NULL;
                                     }else{
                                    //o numero a ser apagado esta no meio da lista
                                     before->prox = aux->prox;
                                      free(aux);
                                        aux =before->prox;
                                         }

                                      }else{
                                         before = aux;
                                         aux =aux->prox;
                                        }

                                }//fim do while
                              if(achou==0){
                                 printf("\nNao encontrado\n");
                                 system("pause");
                                 break;
                                }else if(achou == 1){
                                  printf("\nElemento apagado 1 vez\n");
                                  system("pause");
                                  break;
                                }else{
                                  printf("\nElemento apagado %d vezes\n", achou);
                                  system("pause");
                                  break;
                            }
                    }
                           
                            
                            break;


                        case 2:
                        {    //por NOME da banda
                                 aux = inicio;
                                 before = NULL;
                                 achou = 0;

                                printf("\nO Nome da Banda que deseja apagar: "); 
                                 fflush(stdin);// limpa o buffer para entrada
                                 fgets(apagabanda,sizeof(apagabanda),stdin);{ //armazena o nome da bnda a ser  inserida
                                 apagabanda[strlen(apagabanda)-1]='\0';}//caractere anterior fecha a string e evita que fgets pule uma linha
                            

                            while (aux != NULL){
                      
                                 if(0 == strcmp(aux->nomeBanda,apagabanda)){ //compara as strings e retorna 0 se forem iguais ignorando CASE SENSITIVE
                                 //minutos digitado encontrado
                                    achou = achou +1;
                                        if(aux == inicio){
                                         //numero a ser apagado é o primeiro
                                             inicio = aux->prox;
                                             free(aux);
                                              aux=inicio;
                                         }else if(aux == end){
                                            // o numeor a ser removido é o ultimo da lista     
                                             before->prox =NULL;
                                            end =  before;
                                             free(aux);
                                            aux =NULL;
                                             }else{
                                             //o numero a ser apagado esta no meio da lista
                                                before->prox = aux->prox;
                                                free(aux);
                                                aux =before->prox;
                                            }
                                 }else{
                                         before = aux;
                                         aux =aux->prox;
                                        }

                            }//fim do while
                                
                                if(achou==0){
                                 printf("\nNao encontrado\n");
                                 system("pause");
                                 break;
                                }else if(achou == 1){
                                  printf("\nElemento apagado 1 vez\n");
                                  system("pause");
                                  break;
                                }else{
                                  printf("\nElemento apagado %d vezes\n", achou);
                                  system("pause");
                                break;
                                }
                        
                        }
                        break;
                    
                    default:
                    break;   
                } 
        
        }                    
    return inicio;
}

void * esvaziaLista(t_list * head){

     /*typedef faz com que naao se precise digitar novamente o tipo de 
                           t_list identifica o ponteiro */
    t_list *inicio ; //lista vazia, logo, ponteiro com valor NULL
    t_list *end = NULL ; //ponteiro fim conntera o ultimo elemento da lista
    t_list *aux = NULL;         //ponteiro auxiliar
    t_list *before;    //ponteiro auxiliar
    t_list *next;     //ponteiro para o proximo
    inicio = head;
     if(inicio == NULL){
                    printf("\n\nA Lista já está Vazia\n\n");
                    system("pause");
                    //lista vazia 
                }else{
                    //a lista será esvaziada
                    aux = inicio;
                    while(aux!= NULL){
                        inicio = inicio ->prox;
                        free(aux);
                        aux =inicio;
                    }
                    printf("\n\nLista Esvaziada\n\n");
                    system("pause");
                }
        return inicio;
}

void  printList(t_list * inicio, t_list * proximo ){

    t_list *head = NULL; //lista vazia, logo, ponteiro com valor NULL
    t_list *end = NULL ; //ponteiro fim conntera o ultimo elemento da lista
    t_list *new;         //ponteiro auxiliar
    t_list *before;    //ponteiro auxiliar
    t_list *next;     //ponteiro para o proximo
    int h,m,s;
    int segundos;
    s=0;m=0;h=0;segundos=0;//inicializando as variaveis
    
    //system("cls");
  // ClearScreen();//limpa texto do terminal

        next = inicio;
          printf("\n|###########################################      PLAYLIST      ###########################################|\n\n");
          printf("\n %-43s%-45s%s","MÚSICA","BANDA","TEMPO\n");
        while(next != NULL){
            segundos = next -> min;
            
            if(segundos<3600){
                s=segundos%60;
                m=(int)segundos/60;
                h=(int)m/60;
                fflush(stdout);
                printf(" %-40s - %-45s%d min:%d seg\n",next->nomeMusica, next->nomeBanda , m, s);
               
            next = next->prox;
            }else{
                segundos = next -> min;
                s=segundos%60;
                m=(int)segundos/60;
                h=(int)m/60;
                 fflush(stdout);
                printf(" %-40s - %-42s%d h:%d min:%d seg\n",next->nomeMusica,next->nomeBanda , h,m,s);
                next = next->prox;
            }
           
        }//end while
        printf("\n|###########################################      PLAYLIST      ###########################################|\n\n");

         system("pause");
        
}

void listaVazia(void){
     printf("\n|########################################      PLAYLIST      ########################################|\n\n");
     printf("\n %-43s%-45s%s","MÚSICA","BANDA","TEMPO\n\n");
     printf(" Nunhum ítem na lista\n");
     printf("\n\n");
     printf("\n|########################################      PLAYLIST      ########################################|\n");
     system("pause");
}




void ClearScreen(){
    int n;
    for (n = 0; n < 5; n++)
      printf( "\n\n\n\n" );
    }

   