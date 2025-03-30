#include <stdio.h>

// Programa - Soma de Números Positivos
int main() {
    int num, soma = 0;

    printf("Digite um número positivo (ou um negativo para sair): ");
    scanf("%d", &num);

    while (num >= 0) {
        soma += num;
        printf("Digite um número positivo (ou um negativo para sair): ");
        scanf("%d", &num);
    }

    printf("Soma total: %d\n", soma);
    return 0;
}

// Questão 1 - Números de 1 a 10 com while
int questao1() {
    int i = 1;
    while (i <= 10) {
        printf("%d\n", i);
        i++;
    }
    return 0;
}

// Questão 2 - Contagem até o Número do Usuário
int questao2() {
    int num, i = 1;

    printf("Digite um número positivo: ");
    scanf("%d", &num);

    while (num <= 0) {
        printf("Número inválido! Digite um número positivo: ");
        scanf("%d", &num);
    }

    while (i <= num) {
        printf("%d\n", i);
        i++;
    }

    return 0;
}

// Questão 3 - Sistema de Senha
int questao3() {
    int senha;

    printf("Digite a senha: ");
    scanf("%d", &senha);

    while (senha != 1234) {
        printf("Senha incorreta! Tente novamente: ");
        scanf("%d", &senha);
    }

    printf("Acesso permitido!\n");
    return 0;
}
