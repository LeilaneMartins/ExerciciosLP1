#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct{
    char nomeCliente [100];
    char nomeProduto [100];
    int quantidade;
    float valorUnitario;
    float valorTotal;
}Vendas;

int main(){

    int opcaoMenu;
    Vendas vendas[99];
    int i = 0, j = 0;
    char cadastro, nomeCliente2 [100];
    float somaTotal = 0;

    //case 5
    char clienteMaiorVenda[100], produtoMaiorVenda[100];
    int qtdMaiorVenda;
    float valorUntMaiorVenda, maiorValor = 0;

    setlocale(LC_ALL, "Portuguese");

    do{
        printf("           MENU            \n\n");
        printf(" 1. Cadastrar venda\n");
        printf(" 2. Listar vendas realizadas\n");
        printf(" 3. Buscar vendas pelo nome do cliente\n");
        printf(" 4. Total de vendas realizadas\n");
        printf(" 5. Dados da maior venda realizada\n");
        printf(" 6. Sair\n");

        printf("\nDigite o número da opção desejada: ");
        scanf("%i", &opcaoMenu);

        system("cls");

        switch(opcaoMenu)
        {
            case 1:
                do{
                   printf("\nInforme o nome do cliente: ");
                   setbuf(stdin, NULL);
                   scanf("%100[^\n]",vendas[i].nomeCliente);

                   printf("Informe o nome do produto: ");
                   setbuf(stdin, NULL);
                   scanf("%100[^\n]",vendas[i].nomeProduto);

                   printf("Informe a quantidade: ");
                   scanf("%i", &vendas[i].quantidade);

                   printf("Informe o valor do produto: ");
                   scanf("%f", &vendas[i].valorUnitario);

                   vendas[i].valorTotal = (vendas[i].quantidade * vendas[i].valorUnitario);
                   somaTotal = somaTotal + vendas[i].valorTotal;

                   printf("\nDeseja realizar outro cadastro(s/n)? ");
                   setbuf(stdin, NULL);
                   scanf(" %c", &cadastro);

                   if(i == 0){
                        maiorValor = vendas[i].valorTotal;
                        strcpy(clienteMaiorVenda, vendas[i].nomeCliente);
                        strcpy(produtoMaiorVenda, vendas[i].nomeProduto);
                        qtdMaiorVenda = vendas[i].quantidade;
                        valorUntMaiorVenda = vendas[i].valorUnitario;
                   }
                   else if(maiorValor < vendas[i].valorTotal){
                        maiorValor = vendas[i].valorTotal;

                        strcpy(clienteMaiorVenda, vendas[i].nomeCliente);
                        strcpy(produtoMaiorVenda, vendas[i].nomeProduto);
                        qtdMaiorVenda = vendas[i].quantidade;
                        valorUntMaiorVenda = vendas[i].valorUnitario;

                   }

                   i++;


                }while(cadastro == 's' && i < 100);

                system("cls");

                break;


            case 2:
                for(j = 0; j < i; j++){
                    printf("\nVenda %i: \n\tNome do cliente: %s \n\tNome do produto: %s \n\tQuantidade: %i\n\tValor Unitario: R$ %.2f\n\tValor total: R$ %.2f\n", j+1, vendas[j].nomeCliente, vendas[j].nomeProduto, vendas[j].quantidade, vendas[j].valorUnitario, vendas[j].valorTotal);
                }

                printf("\n\n");

                break;

            case 3:
                printf("\nDigite o nome do cliente: ");
                setbuf(stdin, NULL);
                scanf("%100[^\n]", nomeCliente2);

                for(j = 0; j < i; j++){
                    if(strcmp(nomeCliente2, vendas[j].nomeCliente) == 0){
                        printf("\n\tNome do cliente: %s \n\tNome do produto: %s \n\tQuantidade: %i\n\tValor Unitario: R$ %.2f\n\tValor total: R$ %.2f\n\n", vendas[j].nomeCliente, vendas[j].nomeProduto, vendas[j].quantidade, vendas[j].valorUnitario, vendas[j].valorTotal);
                    }
                }

                break;

            case 4:
                printf("\nSomatório dos valores totais: R$ %.2f\n", somaTotal);
                printf("Total de vendas realizadas: %i\n\n", i);
                break;

            case 5:
                printf("\nMaior venda realizada: \n\n\t\tCliente: %s\n\t\tProduto: %s\n\t\tQuantidade %i\n\t\tValor unitario R$ %.2f\n\t\tValor total R$ %.2f\n\n", clienteMaiorVenda, produtoMaiorVenda, qtdMaiorVenda, valorUntMaiorVenda, maiorValor);
                break;

            default:
                if(opcaoMenu == 6){
                    printf("\nFIM\n\n");
                }
                else{
                    printf("\nOpção inválida\n\n");
                }
        }

    }while(opcaoMenu != 6);

    return 0;
}



