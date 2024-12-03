#include <stdio.h>
int main() {
    int idade;
    // Solicita a idade do usuário
    printf("Digite a sua idade: ");
    scanf("%d", &idade);

    // Estrutura condicional encadeada
    if (idade >= 18) {
        printf("Você é maior de idade.\n");
    } else if (idade < 18) {
        printf("Você é menor de idade.\n");
    } else {
        printf("Idade inválida.\n");
    }
    return 0;
}

