#include <stdio.h>//printf
#include <stdlib.h>//malloc
#include <string.h>

#define TAM 15
#define STR 60

void main() {

char OBJ1[TAM];
char OBJ2[TAM];
char OBJ3[TAM];
char title[TAM] = "TABLE-NAME" ;
char end[TAM]   = "END" ;
//char aux[TAM] = 
int dif, aux ;

 
    //strlen returns integer equals the length of the string
    
    dif = strlen(title) - strlen(end);
    

//writing iten wherever value
for(int i=0; i<TAM; i++){
    
    OBJ1[i] = "obj1";
}
//writing iten wherever value
for(int i=0; i<TAM; i++){
    
    OBJ2[i] = "obj2";
}
//writing iten wherever value
for(int i=0; i<TAM; i++){
    
    OBJ3[i] = "obj3";
}
//clean the terminal
    system("cls");
    fflush(stdout);//clean buffer
    
    //title line and ASCII caracter, will be used in the others
    
    for(int i=0; i<((int)(STR/2) - (int)strlen(title)); i++)printf("%c",177);
    printf(" %s ",title);
    for(int i=0; i<((int)(STR/2) ); i++)printf("%c",177);
    printf("\n");
   
   //second line
    printf("%c",201);
    for(int i=0; i<(STR) ; i++)printf("%c",205);
    printf("%c\n",187);
    
    //columns line
    printf("%c%-20s%c%-20s%c%-18s%c\n", 186 ,"Column1", 179 ,"Column2",179 , "Column3",186);
    
    //line bellow the column line
    printf("%c",204);
    for(int i=0; i<(STR) ; i++)printf("%c",205);
    printf("%c",185);
    printf("\n");
    
    
    //printing iten
        for(int i=0; i<TAM; i++){
    
            printf("%c%-20s%c%-20s%c%-18s%c",186,"OBJ1",179,"OBJ2",179,"OBJ3",186);
            printf("\n");
            }
    
    //line befor the end
    printf("%c",204);
    for(int i=0; i<(STR) ; i++)printf("%c",205);//LENGTH OF TABLE
    printf("%c",185);
    printf("\n");
    
    //end line
            
                
                fflush(stdout);
                printf("%c",200);
                 for(int i=0; i<(1+(int)STR/2 - (int)strlen(end)); i++)printf("%c",205);
                 printf("%s",end);
                 for(int i=0; i<(2+(int)STR/2 - (int)strlen(end)); i++)printf("%c",205);
                 printf("%c",188);
                 printf("\n");
        
           
                
              
                 
            
    
    
     system("pause");
}