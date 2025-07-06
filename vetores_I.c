#include <stdio.h>
#include <locale.h> 

// declaração de vetor:
float notas[3]; // vetor com 3 posições: índices 0, 1 e 2
float media;

void main() {
    setlocale(LC_ALL, "Portuguese"); 

    printf("Digite sua primeira nota: ");
    scanf("%f", &notas[0]); // guarda na posição 0 do vetor
    printf("Digite sua segunda nota: ");
    scanf("%f", &notas[1]); // guarda na posição 1 do vetor
    printf("Digite sua terceira nota: ");
    scanf("%f", &notas[2]); // guarda na posição 2 do vetor
    	media = (notas[0] + notas[1] + notas[2]) / 3;
   		printf("Sua média foi: %.1f\n", media);
}

