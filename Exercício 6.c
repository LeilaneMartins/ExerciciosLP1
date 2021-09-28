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
    strcpy(autora, "Jane Austen");

    printf("Listagem dos livros cadastrados\n\n");
    for(i = 0; i <= 19; i++){
        printf("\tTítulo: %s \n\tAutor: %s \n\tAno de publicação: %i\n\n", livros[i].titulo, livros[i].autor, livros[i].anoPublicacao);

        if(strcmp(livros[i].autor, autora) == 0){
            cont++;
        }
    }
    printf("\nLivros publicados após o ano 2000\n\n");
    for(i = 0; i <= 19; i++){
       if(livros[i].anoPublicacao > 2000){
            printf("\t%s\n", livros[i].titulo);
       }
    }

    printf("\nQuantidade de livros cadastrados da autora Jane Austen: %i\n\n", cont);

    return 0;

}
