#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   
#include <locale.h> 

int main() {
    int numero;
    setlocale(LC_ALL, "Portuguese");

    srand(time(NULL));
    numero = (rand() % 10) + 1;
    printf("Número sorteado entre 1 e 10: %d\n", numero);

    return 0;
}