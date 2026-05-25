#include <stdio.h>
#include <locale.h>

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	int rodando = 1;
	int opcao, sub_opcao, qtd, i;
	
	float taxa_entrega = 8.00;
	float total_pedido = 0;
	  	
	while (rodando){
		
		system("cls"); // comando que limpa a tela
		
        printf("\n=== BEM-VINDO À PIZZARIA DO CHATBOT ===\n");
        printf("Escolha uma opção:\n");
        printf("[1] Cardápio\n");
        printf("[2] Atendimento\n");
        printf("[3] Fazer Pedido\n");
        printf("[0] Sair\n");
        printf("Opção: ");
        
        scanf("%d", &opcao);
		
		switch(opcao){
			
			case 1:
					
				system("cls");
				
				printf("\n--- CARDÁPIO ---\n");
	            printf("[1] Pizza de Calabresa - R$ 35.00\n");
	            printf("[2] Pizza de Frango c/ Catupiry - R$ 38.00\n");
	            printf("[3] Pizza Quatro Queijos - R$ 40.00\n");
	            printf("[0] voltar <-\n");
	                
	            do{
	                printf("Digite [0] para voltar <- \n");
					scanf("%d", &sub_opcao);	
				} while(sub_opcao != 0);
	              
				break;
				
			case 2:
				
				system("cls");
				
				printf("\n--- ATENDIMENTO ---\n");
                printf("Horário de funcionamento: 18h às 23h\n");
                printf("Endereço: Rua das Pizzas, 123\n");
                printf("Telefone: (99) 99999-9999\n");
                printf("[0] Voltar <-\n");
                
                do{
	                printf("Digite [0] para voltar <- \n");
					scanf("%d", &sub_opcao);	
				} while(sub_opcao != 0);
	              
				break;
		
			case 3: // parte[2] - Pedido 
				
                printf("\n--- FAZER PEDIDO ---\n");
                printf("Quantas pizzas você deseja pedir? ");
                
                scanf("%d", &qtd);

                total_pedido = 0; // zera o total para novo pedido

                for (i = 1; i <= qtd; i++) {
                	
                    printf("\nEscolha o sabor da pizza #%d:\n", i);
                    printf("[1] Calabresa (R$ 35.00)\n");
                    printf("[2] Frango c/ Catupiry (R$ 38.00)\n");
                    printf("[3] Quatro Queijos (R$ 40.00)\n");
                    printf("Opção: ");
                    
                    scanf("%d", &sub_opcao);

                    switch (sub_opcao) {
                    	
                        case 1:
                            total_pedido += 35.0;
                            break;
                            
                        case 2:
                            total_pedido += 38.0;
                            break;
                            
                        case 3:
                            total_pedido += 40.0;
                            break;
                            
                        default:
                            printf("Opção inválida! Pizza #%d não adicionada.\n", i);
                            break;
                    }
                }

                total_pedido += taxa_entrega;

                printf("\n--- RESUMO DO PEDIDO ---\n");
                printf("Total (com taxa de entrega de R$ %.2f): R$ %.2f\n", taxa_entrega, total_pedido);
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
