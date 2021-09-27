#include <stdio.h>
#include <string.h>
#include <locale.h>

int main(){

    char login [20];
    char senha [10];
    char loginCadastrado [20];
    char senhaCadastrada [10];

    setlocale(LC_ALL, "Portuguese");

    printf("Informe o login: ");
    setbuf(stdin, NULL);
    scanf("%20[^\n]", login);

    printf("Informe a senha: ");
    setbuf(stdin, NULL);
    scanf("%10[^\n]", senha);

    setbuf(stdin, NULL);
    strcpy(loginCadastrado, "admin@sist.com");
    setbuf(stdin, NULL);
    strcpy(senhaCadastrada, "adm123");

    if(strcmp(senha, senhaCadastrada) == 0 && strcmp(login, loginCadastrado) == 0)
    {
        printf("\nLogado como administrador.\n");
    }
    else
    {
        printf("\nLogado como usuário comum.\n");
    }

    return 0;
}