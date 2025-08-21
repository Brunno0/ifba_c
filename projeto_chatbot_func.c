#include <stdio.h>
#include <locale.h>
#include <stdlib.h>  // Para system("cls") e system("pause")

// Funções
int menuInicial();
void cardapio(char cardapioTxt[][100], int tamanho);
void atendimento();
void pedido();
void imprimirCardapio(char array[][100], int tamanho);

// Cardapio com 4 itens (cada string com até 100 caracteres)
#define TAMANHO_ARRAY 4

char cardapioTxt[TAMANHO_ARRAY][100] = {
    "[1] Pizza de Calabresa - R$ 35.00",
    "[2] Pizza de Frango c/ Catupiry - R$ 38.00",
    "[3] Pizza Quatro Queijos - R$ 40.00",
    "[4] Pizza Nordestina - R$ 50.00"
};

int main() {
    setlocale(LC_ALL, "Portuguese");
    int rodando = 1, opcao;

    while (rodando) {
        opcao = menuInicial();

        switch (opcao) {
            case 1:
                cardapio(cardapioTxt, TAMANHO_ARRAY);
                break;

            case 2:
                atendimento();
                break;

            case 3:
                pedido();
                break;

            case 0:
                printf("Encerrando atendimento. Obrigado por visitar nossa pizzaria!\n");
                rodando = 0;
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}

int menuInicial() {
    int opcao;
    system("cls");
    printf("\n=== BEM-VINDO À PIZZARIA DO CHATBOT ===\n");
    printf("Escolha uma opção:\n");
    printf("[1] Cardápio\n");
    printf("[2] Atendimento\n");
    printf("[3] Fazer Pedido\n");
    printf("[0] Sair\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    return opcao;
}

void cardapio(char cardapioTxt[][100], int tamanho) {
    int subOpcao;
    system("cls");
    printf("\n--- CARDÁPIO ---\n");
    imprimirCardapio(cardapioTxt, tamanho);

    do {
        printf("\nDigite [0] para voltar <- \n");
        scanf("%d", &subOpcao);
    } while (subOpcao != 0);
}

void imprimirCardapio(char array[][100], int tamanho) {
	int i;
    for ( i=0; i<tamanho; i++) {
        printf("%s\n", array[i]);
    }
}

void atendimento() {
    int subOpcao;
    system("cls");
    printf("\n--- ATENDIMENTO ---\n");
    printf("Horário de funcionamento: 18h às 23h\n");
    printf("Endereço: Rua das Pizzas, 123\n");
    printf("Telefone: (99) 99999-9999\n");

    do {
        printf("\nDigite [0] para voltar <- \n");
        scanf("%d", &subOpcao);
    } while (subOpcao != 0);
}

void pedido() {
    int opcao, subOpcao, qtd, i;
    float taxaEntrega = 8.00;
    float totalPedido = 0;

    system("cls");
    printf("\n--- FAZER PEDIDO ---\n");
    printf("Quantas pizzas você deseja pedir? ");
    scanf("%d", &qtd);

    totalPedido = 0; // zera o total para novo pedido

    for (i = 1; i <= qtd; i++) {
    //chamada para imprimir 
	   imprimirCardapio(cardapioTxt, tamanhoCardapio);
	   
	   printf("Opção: ");
        scanf("%d", &subOpcao);

        switch (subOpcao) {
            case 1:
                totalPedido += 35.0;
                break;
            case 2:
                totalPedido += 38.0;
                break;
            case 3:
                totalPedido += 40.0;
                break;
            case 4:
                totalPedido += 50.0;
                break;
            default:
                printf("Opção inválida! Pizza #%d não adicionada.\n", i);
                break;
        }
    }

    totalPedido += taxaEntrega;

    printf("\n--- RESUMO DO PEDIDO ---\n");
    printf("Total (com taxa de entrega de R$ %.2f): R$ %.2f\n", taxaEntrega, totalPedido);
    printf("Pedido realizado com sucesso!\n");
    system("pause");
}
