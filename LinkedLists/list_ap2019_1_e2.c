#include <stdio.h>//printf
#include <stdlib.h>//malloc
#include <string.h>
#include <locale.h>
//#include <conio.h>
//#include <iostream>

/* Deve-se armazenar o nome de cada música, do artista/email e a duração da faixa. 
Para o armazenamento utilize uma estrutura heterogênea de dados  */

#define tamNome 200
#define tamEmail 200
#define tamRU 16

/*declara struct dentro dessa struct num e list e o ponteiro do 
 tipo struct list para o proximo elemento*/
typedef struct list { 
                     char nomeAluno[tamNome]; //nome do Aluno
                     char email[tamEmail];  //email do Aluno
                     int RU; //RU do Aluno
                     struct list *prox; 
                     }t_list; //sinonimo para struct list


                     

void ClearScreen();
void  menu();
void menuApaga(void);
void listaVazia(void);
void * inicInsert(t_list * head , char * name, char * band, int RU);
void * midInsert(t_list * head , char * name, char *band, int RU);
void * lastInsert(t_list * head , char * name, char * band, int RU);
void  printList(t_list * inicio, t_list * proximo );
void * apagaItem(t_list * head , int erase);
void * esvaziaLista(t_list * head);

void main() {
    system("cls");
    setlocale(LC_ALL, "pt-BR");
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
    int op,apaga, nRU, achou;
    char nome[tamNome], email[tamEmail];
    char num[tamRU];//converter num em nRU


    do{
            

          // menu de opções
            menu(  );
            //limpa tela
            fflush(stdin);//limpa buffer para receber o proximo string
            if (fgets(num, sizeof(num), stdin)) {
              if (1 == sscanf(num, "%d", &op)) {
                    if( op < 1 || op > 7) //filtro
                        printf("\n\n!!!Opção Inválida!!!\n\n\a");
                     }//recebe op
            }
           
           
            if( op == 1 ){
                     system("cls");
                      printf("\n\nDigite os dados a serem inseridos no inicio da planilha.\n");
                    printf("O Nome do Aluno: ");
            
                      fflush(stdin);
                     if (fgets(nome, sizeof(nome), stdin)){
                     //armazena o nome da musica a ser  inserida
                      nome[strlen(nome)-1]='\0';//caractere anterior fecha a string e evita que fgets pule uma linha
                     //printf("O valor de strlen : %d\n",strlen(musica));//teste de valores
                     // printf("O valor de musica : %s\n",musica);
                  }
            
                     printf("Digite o E-mail do aluno: ");

                    fflush(stdin);
                    if (fgets(email, sizeof(email), stdin)){ //armazena o nome da bnda a ser  inserida
                        email[strlen(email)-1]='\0';}//caractere anterior fecha a string e evita que fgets pule uma linha

                      printf("O número da matrícula (RU): ");
                      fflush(stdin);
                     if (fgets(num, sizeof(num), stdin)) {
                        if (1 == sscanf(num, "%d", &nRU)) {
                         printf("\n");
            
                        head = inicInsert( head, nome, email, nRU );//devido a funcao de imprimir precisa retornar o end de ini
             
                        }
             }//armazena o nRU a ser  inserido
            
                
            }//end if 1

            if(op == 2 ){
                system("cls");
                 //printf("\n2 - Inserir no fim da lista");
                 printf("\n\nDigite os dados a serem inseridos no fim da planilha.\n");

                    printf("O Nome do Aluno: ");
                 fflush(stdin);// limpa o buffer para entrada
                    if(fgets(nome,sizeof(nome),stdin)){ //armazena o nome da bnda a ser  inserida
                  nome[strlen(nome)-1]='\0';}//caractere anterior fecha a string e evita que fgets pule uma linha

                printf("Digite o E-mail do aluno: ");
                 fflush(stdin);
                 if(fgets(email,sizeof(email),stdin)){ //armazena o nome da bnda a ser  inserida
                 email[strlen(email)-1]='\0';}

                 printf("O número da matrícula (RU): ");
                 if (fgets(num, sizeof(num), stdin)) {
                        if (1 == sscanf(num, "%d", &nRU)) {
                        printf("\n");
            
                         head = lastInsert( head, nome, email, nRU );
                        }
                }//armazena o nRU a ser  inserido
            

            }/*end if 2*/

             if(op == 3 ){
                    system("cls");
                    //printf("\n3 - Inserir no meio da lista");
                        printf("\n\nDigite os dados a serem inseridos no fim da planilha.\n");

                        printf("O Nome do Aluno: ");
                        fflush(stdin);// limpa o buffer para entrada
                        fgets(nome,sizeof(nome),stdin);{ //armazena o nome da bnda a ser  inserida
                        nome[strlen(nome)-1]='\0';}//caractere anterior fecha a string e evita que fgets pule uma linha

                         printf("Digite o E-mail do aluno: ");
                         fflush(stdin);
                         if(fgets(email,sizeof(email),stdin)){ //armazena o nome da bnda a ser  inserida
                            email[strlen(email)-1]='\0';}

                        printf("O número da matrícula (RU): ");
                        if (fgets(num, sizeof(num), stdin)) {
                        if (1 == sscanf(num, "%d", &nRU)) {
                        printf("\n");
            
                        head = midInsert( head, nome, email, nRU ); 
                        }
                }//armazena o nRU a ser  inserido
            

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

                         printList( head , head->prox);
                         menuApaga();
                         

                             if (fgets(num, sizeof(num), stdin)) {
                                    if (1 == sscanf(num, "%d", &apaga)) {//recebe op
                                         if( apaga < 1 || apaga > 4){ //filtro
                                             printf("\n\n!!!Opção Inválida!!!\n\n\a");
                                         }else{
                                             head = apagaItem(head ,  apaga);
                                             }
                                     }//converte string em int
                                }//leitura de string do teclado

                    }////deletar POR nome, email ou nRU de duração


                 
                }while(apaga != 4);

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
     printf("\n\nPrograma Encerrado.\n\n");
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

void menuApaga(void){
                
                
                printf("\nQual ítem apagar:");
                printf("\n\n1 - Por nome do aluno.");
                printf("\n2 - Por email.");
                printf("\n3 - Por nRU :");
               
                printf("\n4 - Sair");
                printf("\n\nDigite sua opcao: ");

}



void * inicInsert(t_list * head , char * name, char * band, int RU){
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
    char nome[tamNome], email[tamEmail];
    memset(nome, '\0', sizeof(nome));
    memset(email, '\0', sizeof(email));
    strcpy(nome,name);
    strcpy(email,band);
   
    tempo = RU;
    
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
			            	
			            	strcpy(inicio -> nomeAluno,nome);
                            strcpy(inicio -> email,email);
                            inicio -> RU = tempo;	    // ponteiro para RU na estrutura list o primeiro e o ultimo
                            
			            	end = inicio ;
                              end->prox = NULL;
                              
                        }//fim if teste malloc
                          printf("Musica inserida foi a primeira da lista. Não havia ítens na lista.\n\n");
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
                                	strcpy(head -> nomeAluno,nome);
                                    strcpy(head -> email,email);
                
				                     head -> RU = tempo;	
			                        head -> prox = before;
                                      
                                  }//fim de if teste malloc
                                  
                                inicio = head; 
                                inicio->prox = before; 
                                
                                }//fim ifelse de teste de nulidade do head
                                
                printf("Inserido no inicio da lista\n\n");
                system("pause");
                return inicio;
              
             
        }//end funcao



void  * midInsert(t_list * head , char * name, char * band, int RU){

        /*typedef faz com que naao se precise digitar novamente o tipo de 
                           t_list identifica o ponteiro */
    t_list *inicio ; //lista vazia, logo, ponteiro com valor NULL
    t_list *end = NULL ; //ponteiro fim conntera o ultimo elemento da lista
    t_list *new = NULL;         //ponteiro auxiliar
    t_list *before;    //ponteiro auxiliar
    t_list *next;     //ponteiro para o proximo
    inicio = head;
        //declara variaveis locais
    int op, nRU, achou, meio, n;
    nRU = RU;
    meio = 0;
    n = 0;



     char nome[tamNome], email[tamEmail];
    memset(nome, '\0', sizeof(nome));
    memset(email, '\0', sizeof(email));
    strcpy(nome,name);
    strcpy(email,band);

    
    
    
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
                                    
                                     strcpy(inicio -> nomeAluno,nome);
                                     strcpy(inicio -> email,email);        
                                    
							        inicio->RU = nRU;
							        next = inicio;
							        next->prox = NULL;
                                 }//checa a allocaçao

							printf("\nInserido com sucesso. Não havia ítens na lista.\n\n");
                            system("pause");
                            return inicio;

						}else{
							   //a lista ja contem elementos e sera inserido no meio da lista
							    
                                strcpy(new -> nomeAluno,nome);
                                strcpy(new -> email,email);
                                
                                new->RU= nRU;

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

void * lastInsert(t_list * head , char * name, char * band, int RU){

            /*typedef faz com que naao se precise digitar novamente o tipo de 
                           t_list identifica o ponteiro */

    t_list *inicio ; //lista vazia, logo, ponteiro com valor NULL
    t_list *end = NULL ; //ponteiro fim conntera o ultimo elemento da lista
    t_list *new = NULL;         //ponteiro auxiliar
    t_list *before;    //ponteiro auxiliar
    t_list *next;     //ponteiro para o proximo
    inicio = head;
    int tempo;


     char nome[tamNome], email[tamEmail];
    memset(nome, '\0', sizeof(nome));
    memset(email, '\0', sizeof(email));
    strcpy(nome,name);
    strcpy(email,band);
   
    tempo = RU;

                   //se inicio for NULL aloque novo espaço
						if(inicio == NULL){
							//lista estava vazia e o elemento sera o prim e o ultimo
							head = (t_list*) malloc(sizeof(t_list));
                            if(head == NULL){
                                printf("ERRO AO ALOCAR MEMORIA\n");
                                system("pause");
                                return NULL;
                                }else{
                                strcpy(inicio -> nomeAluno,nome);
                                strcpy(inicio -> email,email);
							    head->RU= tempo;
							    next = head;
							    next->prox = NULL;
                                }//fim if filtro
                                printf("Inserido foi no final da lista. Não havia ítens na lista.\n\n");
                                system("pause");
                                return head;
							
						}else{
							   //a lista ja contem elementos e sera inserido no fim da lista
                               new = (t_list*) malloc(sizeof(t_list));
                               //add struct
                               	strcpy(new -> nomeAluno,nome);
                                strcpy(new -> email,email);
							    new->RU = tempo;

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
    int op, nRU, achou, meio, n, opcao;
     char nome[tamNome], email[tamEmail];
     char apaganome[tamNome], apagaemail[tamEmail],  num[tamRU];
    

    
    nRU = 0;
    meio = 0;
    n = 0;
    opcao = erase;
                        


                 next = head;
				 while(next->prox != NULL){
				next = next->prox ;
				}//end while
                end = next->prox;//obtenho o ponteiro para o ultimo

               if(inicio == NULL){
                    printf("\n\nA planilha está vazia!\n\n");
                    //lista vazia 
                   
                }else{
                    // a lista contem elementos e o elemento a ser removido deve ser digitado
                 
                 //todas as ocorrencias da lista, iguais ao RU digitado serao removidas
                    switch (opcao)
                    {
                        
                        case 1:
                        {
                                //por NOME
                              aux = inicio;
                             before = NULL;
                             achou = 0;

                            printf("O Nome do Aluno que deseja apagar: "); 
                            fflush(stdin);// limpa o buffer para entrada
                            fgets(apaganome,sizeof(apaganome),stdin);{ //armazena o nome da bnda a ser  inserida
                             apaganome[strlen(apaganome)-1]='\0';}//caractere anterior fecha a string e evita que fgets pule uma linha


                             while (aux != NULL){
                      
                                if(0 == strcmp(aux->nomeAluno,apaganome)){ //compara as strings e retorna 0 se forem iguais ignorando CASE SENSITIVE
                                            //RUutos digitado encontrado
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
                               
                                printf("\nAluno com a matricula(RU) digitada será apagado: "); 
                                if (fgets(num, sizeof(num), stdin)) 
                                 if (1 == sscanf(num, "%d", &nRU)) 

                                aux = inicio;
                                before = NULL;
                                 achou = 0;

                             while (aux != NULL){
                                     if(aux->RU > nRU){//maior do que escolhido
                                         //RUutos digitado encontrado
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
                        {    //por NOME da email
                                 aux = inicio;
                                 before = NULL;
                                 achou = 0;

                                printf("O Nome da Banda que deseja apagar: "); 
                                 fflush(stdin);// limpa o buffer para entrada
                                 fgets(apagaemail,sizeof(apagaemail),stdin);{ //armazena o nome da bnda a ser  inserida
                                 apagaemail[strlen(apagaemail)-1]='\0';}//caractere anterior fecha a string e evita que fgets pule uma linha
                            

                            while (aux != NULL){
                      
                                 if(0 == strcmp(aux->email,apagaemail)){ //compara as strings e retorna 0 se forem iguais ignorando CASE SENSITIVE
                                 //RUutos digitado encontrado
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
    
    int nRU;
    nRU=0;//inicializando as variaveis
    
    //system("cls");
  // ClearScreen();//limpa texto do terminal

        next = inicio;
          printf("\n|###########################################      PLAYLIST      ###########################################|\n\n");
          printf("\n %-43s%-45s%s","NOME","E-mail","Matrícula(RU)\n");
        while(next != NULL){
            nRU = next -> RU;
            
             printf(" %-40s - %-45sRU:%d\n",next->nomeAluno, next->email , nRU);
               
            next = next->prox;
           
        }//end while
        printf("\n|###########################################      PLAYLIST      ###########################################|\n\n");

        system("pause");
        
}

void listaVazia(void){
     printf("\n|########################################      PLAYLIST      ########################################|\n\n");
     printf("\n %-43s%-45s%s","MUSICA","BANDA","TEMPO\n\n");
     printf(" Nunhum item na lista\n");
     printf("\n\n");
     printf("\n|########################################      PLAYLIST      ########################################|\n");

    system("pause");
}

void ClearScreen(){
    int n;
    for (n = 0; n < 5; n++)
      printf( "\n\n\n\n" );
    }

   