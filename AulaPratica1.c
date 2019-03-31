//Referente as Aulas Teoricas 1 e 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHOVETOR 10

void BubbleSort(int vet[]);
void QuickSort(int vet[]);
int particao(int vet[], int p , int u);
void troca(int vet[], int p , int );
int BuscaSequencial(int vet[], int buscado);

int main(){

    int vet[TAMANHOVETOR] = {0};
    int buscado, achou; //busca
    srand(time(NULL));// gera a semente aleatoria

//INSERÇÃO DE DADOS
    for(int i = 0; i < TAMANHOVETOR ; i++)
        vet[i] =rand () % 100; //gera valores aleatorios

    printf("VETOR NAO ORDENADO: \n");
    for(int i = 0; i < TAMANHOVETOR; i++)
        printf("%d\n", vet[i]);

    printf("Selecione o valor para buscar: \n");
    scanf_s("%d", &buscado);//BUSCA

    achou = BuscaSequencial(vet, buscado);
        if(achou == -1)
        printf("Valor nao encontrado");
        else
        printf("Valor encontrado na posiçao %d", achou);

    BubbleSort(vet);
    QuickSort(vet, 0, TAMANHOVETOR -1);

    printf("VETOR ORDENADO: \n");
    for(int i = 0; i < TAMANHOVETOR; i++)
        printf("%d\n", vet[i]);

        
    system("pause");
    return 0;
}

void BubbleSort(int vet[]){

int aux;
    for(int n = 1; n < TAMANHOVETOR ; n++){
        for( int i = 0; i < TAMANHOVETOR ; i++){

            if(vet[i] > vet[i+1]){// DECRESCENTE "<"

                aux =vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
            } //CRESCENTE

        }

    }

}
//recursiva
void QuickSort(int vet[], int p, int u){

int m; //PIVO
     if( p < u){
         m = particao(vet, p , u);
         QuickSort(vet, p , m);//esquerdo
         QuickSort(vet, m+1 , u);//direito

     }

}

int particao(int vet[], int p , int u){
// calcula PIVO
int pivo, pivo_pos, i, j;
pivo_pos = (p+u)/2;
pivo = vet[pivo_pos];

i = p-1;// sempre um valor a menos
j= u+1; //sempre um valor a mais

    while(i<j){
        //enquanto as varrediuras esquerdas e direitas nao se encontrarem
        do{//TESTA LADO DIREITO
            j--;
        }while(vet[j] > pivo);

        do{//TESTA LADO ESQUERDO
            i++;
        }while(vet[i] > pivo);

        if(i < j)
        troca(vet, i , j);

    }

    return j;
}

void troca(int vet[], int i , int j){
     int aux;
     aux = vet[i];
     vet[i] = vet[j];
     vet[j] = vet[i];

}

int BuscaSequencial(int vet[], int buscado){

    int achou, i;
    achou = 0;
    i = 0;

    while((i <= TAMANHOVETOR ) && (achou == 0)){
        if(vet[i] == buscado)
            achou = 1;
        else
         i++;    

    }
    if( achou == 0)
        return -1;
    else
        return  i + 1;   
}