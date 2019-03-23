#include <stdio.h>
#include <conio.h>

typedef struct {
    int dia, mes, ano ;

}data;

int main(){

data *d;
d= malloc (sizeof(data));
d -> dia = 31; d -> mes =12 ; d -> ano = 2019;

printf("%d \n", d);
printf("%d \n", sizeof( *d));
free(d);
free(*d);
system("pause");
return 0;
}