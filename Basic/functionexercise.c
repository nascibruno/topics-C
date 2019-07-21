#include<stdio.h>

#define M 1

void imprimeMatriz(int matriz[M][M]){
int mem, mem2;
mem=0;
mem2=0;
for(int i=0;i<=M;i++){
     
    for(int j=0;j<=M;j++){
                if( i != j ){
        mem=matriz[i][j];
        matriz[i][j]=matriz[j][i];
        matriz[j][i]=mem;
                            }
                if( (i = j) ){
        mem2=matriz[i][i];
        matriz[i][i]=matriz[M-i][M-i];
        matriz[M-i][M-i]=mem2;
                            }
                            
                            
                            
                  }
        
         }
    

for(int i=0;i<=M;i++){
      printf("[ ");
    for(int j=0;j<=M;j++){
        printf(" %d ",matriz[i][j]);
        
        
                       }
    printf(" ]\n");
                    }

}

int main(){
int[M][M] mat={{1,2},{6,5}}; 
for(int i=0;i<=M;i++){
     
    for(int j=0;j<=M;j++){
        if((mat[i][j])<1){mat[i][j]=0;}
    }
    
}




imprimeMatriz(mat);


}