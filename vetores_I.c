#include <stdio.h>
#include <locale.h> 

// declara��o de vetor:
float notas[3]; // vetor com 3 posi��es: �ndices 0, 1 e 2
float media;

void main() {
    setlocale(LC_ALL, "Portuguese"); 

    printf("Digite sua primeira nota: ");
    scanf("%f", &notas[0]); // guarda na posi��o 0 do vetor
    printf("Digite sua segunda nota: ");
    scanf("%f", &notas[1]); // guarda na posi��o 1 do vetor
    printf("Digite sua terceira nota: ");
    scanf("%f", &notas[2]); // guarda na posi��o 2 do vetor
    	media = (notas[0] + notas[1] + notas[2]) / 3;
   		printf("Sua m�dia foi: %.1f\n", media);
}

