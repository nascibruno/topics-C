#include <stdio.h>//printf
#include <stdlib.h>//malloc


int main(int argc, char *argv[]) {
            //Definindo o registro
            //cada elemento da lista
        typedef struct list { //declara struct dentro dessa struct num e list e o ponteiro do tipo struct list para o proximo elemento
            int num;
            struct list *prox; 
        }t_list;  //typedef faz com que naao se precise digitar novamente o tipo de 
                           //t_list identifica o ponteiro 
    t_list *inicio = NULL; //lista vazia, logo, ponteiro com valor NULL
    t_list *fim = NULL ; //ponteiro fim conntera o ultimo elemento da lista
    t_list *aux;         //ponteiro auxiliar
    t_list *anterior;    //ponteiro auxiliar
    t_list *proximo;     //ponteiro para o proximo
    t_list *head = NULL;     //ponteiro para o proximo
    t_list *novo ;     //ponteiro para o novo elemento
    //declara variaveis 
    int op, numero, achou, meio, n;
    meio = 0;
    n = 0;



    do{
    printf("\n(6 para sair) Digite op: ");
    scanf("%d",&op);

    
              	if(op == 3 ){
					   //Reserva o endereço de espaço de memoria para o novo elemento da lista
					   novo = (t_list*) malloc(sizeof(t_list));
					   

						if(head == NULL){
							//lista estava vazia e o elemento sera o prim e o ultimo
							head = (t_list*) malloc(sizeof(t_list));
							 printf("(A)Digite o numero a ser inserido no meio da lista: ");
							 scanf("%d", &head->num);
							proximo = head;
							proximo->prox = NULL;
							
						}else{
							   //a lista ja contem elementos e sera inserido no fim da lista
							     printf("(B)Digite o numero a ser inserido no meio da lista: ");
							    scanf("%d", &novo->num);
							   
							   proximo = head;
							   while(proximo->prox != NULL){
							    //   percorre todos os ponteiros ate achar o ultimo
							    proximo = proximo->prox ;
								//printf("dentro\n");
								n++;
							   }
							   
							    // quando achar  o ultimo a variavel n recebe o valor do numero de ítens
							   meio = (int)(n / 2);
							   
							   proximo = head;
							  for(int i = 0; i < meio ; i++){
							  	//   percorre todos os ponteiros ate achar o meio
							    proximo = proximo->prox ;
								//printf("dentro %d\n", meio);
							  }
							  anterior = proximo;
							  //aux(novo) aponta para o ponteiro que o antigo apontava
							  novo->prox = proximo->prox;
							  
							  //proximo recebe o ponteiro para onde apontava
							  //						proximo = proximo -> prox;
							  //recebe o endereço do novo
							  anterior->prox = novo;
							  
						}
					//	printf("Numero inserido no fim da lista");

					}
					
			//printf("Numero inserido no inicio da lista\n");
            
    }while((op) != 6);
    



       
          
           //proximo->prox = NULL;
           proximo = head;
         while(proximo != NULL){
        printf("%d ,", proximo->num);
           proximo = proximo->prox ;
         }
           
			
			/*
                proximo = head;
			    printf("head num: %d\n", head->num);
                proximo = proximo -> prox;	
				printf("proximo num: %d\n", proximo->num);	
				
				printf("proximo num: %d\n", proximo->num);*/
//gets();
return 0;

}