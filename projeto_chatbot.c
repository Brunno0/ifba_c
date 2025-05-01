#include <stdio.h>
#include <locale.h>

int main() {
	//declarações e configurações 
    setlocale(LC_ALL, "Portuguese");
	int opcao, subOpcao, qtd, i;
    float totalPedido = 0.0;
    const float taxaEntrega = 8.0;
    int rodando = 1;
    
	//while que mantém o programa rodando: 
    while (rodando) {
    	system("cls"); // comando que limpa a tela
        printf("\n=== BEM-VINDO À PIZZARIA DO CHATBOT ===\n"); //primeiro menu
        printf("Escolha uma opção:\n");
        printf("[1] Cardápio\n");
        printf("[2] Atendimento\n");
        printf("[3] Fazer Pedido\n");
        printf("[0] Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
		 // a partir da opção 
        switch (opcao) {
            case 1: // Parte [1] opção e subOpção
            	system("cls"); // comando que limpa a tela
                printf("\n--- CARDÁPIO ---\n");
                printf("[1] Pizza de Calabresa - R$ 35.00\n");
                printf("[2] Pizza de Frango c/ Catupiry - R$ 38.00\n");
                printf("[3] Pizza Quatro Queijos - R$ 40.00\n");
                printf("[0] voltar <-\n");
                scanf("%d", &subOpcao);
               		if(subOpcao != 0) {
        				printf("Opção inválida! Aperte 0 para voltar ao menu principal.\n");
        				scanf("%d", &subOpcao);
        				system("pause");
    				} 
						 break;  //
					
            case 2:
            	system("cls"); // comando que limpa a tela
                printf("\n--- ATENDIMENTO ---\n");
                printf("Horário de funcionamento: 18h às 23h\n");
                printf("Endereço: Rua das Pizzas, 123\n");
                printf("Telefone: (99) 99999-9999\n");
                printf("[0] voltar <-\n");
				scanf("%d", &subOpcao);
               		if(subOpcao != 0) {
        				printf("Opção inválida! Aperte 0 para voltar ao menu principal.\n");
        				scanf("%d", &subOpcao);
        				system("pause");
    				} 
						 break;
            case 3: // parte[2] - Pedido 
                printf("\n--- FAZER PEDIDO ---\n");
                printf("Quantas pizzas você deseja pedir? ");
                scanf("%d", &qtd);

                totalPedido = 0; // zera o total para novo pedido

                for (i = 1; i <= qtd; i++) {
                    printf("\nEscolha o sabor da pizza #%d:\n", i);
                    printf("[1] Calabresa (R$ 35.00)\n");
                    printf("[2] Frango c/ Catupiry (R$ 38.00)\n");
                    printf("[3] Quatro Queijos (R$ 40.00)\n");
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
