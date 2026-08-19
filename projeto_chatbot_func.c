#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

// Funções
int menu_inicial();//ok
void cadastro_cliente();//ultimo
void atendimento();//ok
void pedido();//ultimo

void cardapio(char cardapio_txt[][100], int tamanho);
void imprimir_array_char(char array[][100], int tamanho);


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
cadastro_cliente();
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
    printf("[0] Sair\n");
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


//parte 1 vídeo.

// ================= CADASTRO CLIENTE ===============
void cadastro_cliente () {
int res;
char nome_cliente[100];
    char telefone_cliente[11];
   
do {
system("cls");
do{
fflush(stdin);
    system("cls");

printf("\n=== CADASTRO DO CLIENTE ===\n");
    printf("Digite seu nome: ");
    fgets(nome_cliente, 100, stdin);

    printf("Digite seu telefone: ");
      fgets(telefone_cliente, 20, stdin);
   
    if (strlen(nome_cliente) == 1 || strlen(telefone_cliente)==1){
    printf(" \n \t Erro: nome ou telefone vazios, tente novamente \n ");
res = 0;
system("pause");
}else{
res=1;
}

    }while ( res == 0);

printf("\n=== Confira os dados:  ===\n");
printf("Seu nome: %s \n",nome_cliente);
    printf("Telefone: %s ",telefone_cliente);
    printf("\n=== os dados conferem?  ===\n");
    printf("0 - não\n");
    printf("1 - sim\n");
    scanf("%d",&res);
    system("pause");
   
    }while(res!=1);
   
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
