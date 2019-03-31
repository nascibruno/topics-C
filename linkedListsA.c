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
    t_list *head;     //ponteiro para o proximo
    //declara variaveis 
    int op, numero, achou;

    do{
    printf("\n(6 para sair) Digite op: ");
    scanf_s("%d",&op);

    
                          
                if(inicio == NULL){
                   	//lista vazia e o elemento sera o primeiro e o ultimo
				inicio = (t_list *)malloc(sizeof(t_list));//##Aloca memoria para inicio sizeof ## é uma função que retorna o tamanho de um tipo( e nao da variavel) malloc
													   // retorna NULL caso NAO CONSIGA mALOCAR
						  //aponta para preencher a estrutura 
				
				anterior = NULL;
                proximo=NULL;
				head = inicio; // NOVO HEAD
				printf("(A)Primeiro elemento =>: ");
				scanf("%d", &(head -> num));	    // ponteiro para num na estrutura list o primeiro e o ultimo
                
				proximo->prox = NULL;
				
				/*inicio = novo;
				fim = novo;*/
                    
                }else{
                anterior = head;
                                 // NOVO HEAD
                head = (t_list *)malloc(sizeof(t_list));//##Aloca memoria para inicio sizeof ## é uma função que retorna o tamanho de um tipo( e nao da variavel) malloc
													   // retorna NULL caso NAO CONSIGA mALOCAR
						  //aponta para preencher a estrutura 
			    
				
				proximo = anterior;
				
				printf("(B)Primeiro elemento =>: ");
				scanf("%d", &(head -> num));	
			    head -> prox = anterior;
			
			    }
			//printf("Numero inserido no inicio da lista\n");
            
    }while((op) != 6);
    



           //proximo->prox = NULL;
           proximo = head;
           printf("head num: %d\n", head->num);
           for(int i=0; i < 10; i++ ){
           printf("num: %d\n", proximo->num);
           proximo = proximo->prox;

           }
           	
			
        /*
                proximo = head;
			    printf("head num: %d\n", head->num);
                proximo = proximo -> prox;	
				printf("proximo num: %d\n", proximo->num);	
				proximo = proximo -> prox;
				printf("proximo num: %d\n", proximo->num);
                */
//gets();
return 0;

}
