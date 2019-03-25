#include <stdio.h>
int main(){
    int  i = 10 ;
    int *p ;
    p = &i ;
    *p =  5 ;
    
    printf ("%d\t%d\t%p\n", i, *p, p);
    
    
    
    system("pause");
    return 0;
}