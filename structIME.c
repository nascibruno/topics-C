 #include <stdio.h>
 
 /* MODO DE DECLARAR STRUCT ALTERNATIVO
 typedef struct reg {
      int         conteudo; 
      struct reg *prox;
   }celula;
   */
   
   
   //MODO DE DECLARAR STRUCT PADRAO
   typedef struct reg celula;
   struct reg  {
    
     int conteudo;
     celula *prox;
     
   };
   
   void imprime (celula *le){
        if(le != NULL){
         printf("%d\n",le->conteudo);
         imprime(le -> prox);
        }
    
   }
   
   int main(void){
    celula exemplo;
    celula *pexemplo;
    exemplo.conteudo =1;
    pexemplo = &exemplo;
     printf("tamanho da celula : %d ", sizeof(celula));
     printf("conteudo da celula : %d ", exemplo.conteudo );
     printf("endereco da celula : %d ", pexemplo->conteudo);
     //imprime();
     return 0;
    
   }