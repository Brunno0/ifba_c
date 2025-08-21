#include <stdio.h>
#include <locale.h>


int menuInicial();
	void cardapio();  
	void atendimento();
	void pedido();

int main (){
	setlocale(LC_ALL, "Portuguese");
	int rodando=1,opcao;
	
	
	
	while (rodando){

		opcao = menuInicial();
		
		switch(opcao){
			
				case 1:
					cardapio();       
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


int menuInicial(){
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
    return(opcao); // retornamos a escolha do user
}  


void cardapio(){
	int subOpcao;
	system("cls");
					printf("\n--- CARDÁPIO ---\n");
	                printf("[1] Pizza de Calabresa - R$ 35.00\n");
	                printf("[2] Pizza de Frango c/ Catupiry - R$ 38.00\n");
	                printf("[3] Pizza Quatro Queijos - R$ 40.00\n");
	                printf("[0] voltar <-\n");
	                	do{
	                	printf("Digite [0] para voltar <- \n");
						scanf("%d",&subOpcao);	
						}while(subOpcao!=0);
}

void atendimento(){
	int subOpcao;
		system("cls");
					printf("\n--- ATENDIMENTO ---\n");
                    printf("Horário de funcionamento: 18h às 23h\n");
                    printf("Endereço: Rua das Pizzas, 123\n");
                    printf("Telefone: (99) 99999-9999\n");
                    printf("[0] Voltar <-\n");
                    printf("Digite uma opção: ");
                    scanf("%d", &subOpcao);
                    	do{
	                	printf("Digite [0] para voltar <- \n");
						scanf("%d",&subOpcao);	
						}while(subOpcao!=0);
}

void pedido(){
	
	int opcao, subOpcao,qtd, i;
	float taxaEntrega = 8.00;
	float totalPedido = 0;
	
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
}

