#include <stdio.h>
#include <locale.h> 

float notas[3];
float media = 0;
int i;


void main() {
   setlocale(LC_ALL, "Portuguese"); 
   
    for (i= 0; i < 3; i++) {
        printf("Digite a nota ");
        scanf("%f", &notas[i]);
        media += notas[i]; // soma as notas
    }
    system("cls");
    
    for (i= 0; i < 3; i++) {
        printf("---Unidade %d: ", i + 1);
        printf("----nota: %.1f ", notas[i]);
        printf("\n", notas[i]);
    }
      
    media = media / 3;
    printf("A média foi: %.1f\n", media);
}

