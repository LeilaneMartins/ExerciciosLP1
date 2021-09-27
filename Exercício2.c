#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>

typedef struct{
   char titulo[100];
   char autor[100];
   int anoPublicacao;
}Livro;

int main(){

    Livro livros[20];
    int i = 0, cont = 0;
    char autora[12];

    setlocale(LC_ALL, "Portuguese");

    for(i = 0; i <= 19; i++){
        printf("Informe o título do %iº livro: ", i+1);
        setbuf(stdin, NULL);
        scanf("%100[^\n]", livros[i].titulo);

        printf("Informe o nome do autor do %iº livro: ", i+1);
        setbuf(stdin, NULL);
        scanf("%100[^\n]", livros[i].autor);

        do{
            printf("Informe o ano de publicação do %iº livro: ", i+1);
            scanf("%i", &livros[i].anoPublicacao);

            if(livros[i].anoPublicacao <= 1700){
                printf("\nAno de publicação inválido\n\n");
            }
        }while(livros[i].anoPublicacao <= 1700);


        printf("\n");
    }

    system("cls");

    setbuf(stdin, NULL);