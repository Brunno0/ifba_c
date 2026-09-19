#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

// Funções
int menu_inicial();
void atendimento();
void pedido();

void cardapio(char cardapio_txt[][100], int tamanho);
void imprimir_array_char(char array[][100], int tamanho);

char lista_de_clientes[100][100];
int quantidade_clientes = 0;
void cadastrar_cliente(char lista_de_clientes[][100],int posicao);

// Cardápio com 4 itens
#define TAMANHO_ARRAY 4


char cardapio_txt[TAMANHO_ARRAY][100] = {
    "[1] Pizza de Calabresa - R$ 35.00",
    "[2] Pizza de Frango c/ Catupiry - R$ 38.00",
    "[3] Pizza Quatro Queijos - R$ 40.00",
    "[4] Pizza Nordestina - R$ 50.00"
};

float precos[TAMANHO_ARRAY] = {
    35.00,
    38.00,
    40.00,
    50.00
};



int main() {
    setlocale(LC_ALL, "Portuguese");

    int rodando = 1, opcao;

    while (rodando) {
    	
    	system("cls");
		cadastrar_cliente(lista_de_clientes,quantidade_clientes); 
        opcao = menu_inicial();

        switch (opcao) {

            case 1:
                cardapio(cardapio_txt, TAMANHO_ARRAY);
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
                
                case 100:

    				/*
        			Nesta opção, deverá ser apresentado:

        			- a lista de clientes que compraram no dia;
        			- o total de vendas realizadas no dia.
    				*/
				break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}


// ================= ATENDIMENTO =================

void atendimento() {

    int sub_opcao;

    system("cls");

    printf("\n--- ATENDIMENTO ---\n");
    printf("Horário de funcionamento: 18h às 23h\n");
    printf("Endereço: Rua das Pizzas, 123\n");
    printf("Telefone: (99) 99999-9999\n");

    do {
        printf("\nDigite [0] para voltar <- \n");
        scanf("%d", &sub_opcao);

    } while (sub_opcao != 0);
}


// ================= MENU INICIAL ================= 

int menu_inicial() {

    int opcao;

    system("cls");

    printf("\n=== BEM-VINDO À PIZZARIA DO CHATBOT ===\n");
    printf("Escolha uma opção:\n");
    printf("[1] Cardápio\n");
    printf("[2] Atendimento\n");
    printf("[3] Fazer Pedido\n");
    printf("[0] Sair\n\n");
    printf("[100] Relatório do dia\n");
    printf("Opção: ");

    scanf("%d", &opcao);

    return opcao;
}

// ================= IMPRIMIR ARRAY CHAR =================

void imprimir_array_char(char array[][100], int tamanho) {
    int i;

    for (i = 0; i < tamanho; i++) {
        printf("%s\n", array[i]);
    }
}






// ================= CARDÁPIO =================

void cardapio(char cardapio_txt[][100], int tamanho) {

    int sub_opcao;

    system("cls");

    printf("\n--- CARDÁPIO ---\n");

    imprimir_array_char(cardapio_txt, tamanho);

    do {
        printf("\nDigite [0] para voltar <- \n");
        scanf("%d", &sub_opcao);

    } while (sub_opcao != 0);
}



// ================= PEDIDO =================

void pedido() {

    int opcao, sub_opcao, qtd, i;

    float taxa_entrega = 8.00;
    float total_pedido = 0;

    system("cls");

    printf("\n--- FAZER PEDIDO ---\n");
    printf("Quantas pizzas você deseja pedir? ");

    scanf("%d", &qtd);
    total_pedido = 0; // zera o total para novo pedido

    for (i = 1; i <= qtd; i++) {

        // chamada para imprimir o cardápio
        imprimir_array_char(cardapio_txt, TAMANHO_ARRAY);

        printf("Opção: ");
        scanf("%d", &sub_opcao);

        switch (sub_opcao) {

            case 1:
                total_pedido += precos[0];
                break;

            case 2:
                total_pedido += precos[1];
                break;

            case 3:
                total_pedido += precos[2];
                break;

            case 4:
                total_pedido += precos[3];
                break;

            default:
                printf("Opção inválida! Pizza #%d não adicionada.\n", i);
                break;
        }
    }

    total_pedido += taxa_entrega;

    printf("\n--- RESUMO DO PEDIDO ---\n");
    printf("Total (com taxa de entrega de R$ %.2f): R$ %.2f\n",taxa_entrega,total_pedido);
    printf("Pedido realizado com sucesso!\n");
    system("pause");
}



// ================= CADASTRO CLIENTE ===============

void cadastrar_cliente(char lista_de_clientes[][100],int posicao){
	
	system("cls");

    printf("\n=== CADASTRO DO CLIENTE ===\n");
    printf("Digite seu nome: ");
    fflush(stdin);

    fgets(lista_de_clientes[posicao], 100, stdin);
  
	lista_de_clientes[posicao][strcspn(lista_de_clientes[posicao], "\n")] = '\0';

    printf("\nCadastrado realizado com sucesso!\n");
    printf("Seja bem vindo(a): %s, boas compras\n\n", lista_de_clientes[posicao]);
	quantidade_clientes++;
    system("pause");
}
