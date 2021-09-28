#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(){

    float salario, salarioReajuste, maiorSalario, reajuste, menorReajuste = 0, somaSalarios = 0;
    int contador,tempoServico, semReajuste = 0, comReajuste;

    setlocale(LC_ALL, "Portuguese");

    for(contador = 1; contador <= 20; contador++){
        printf("   *******C�lculo de Reajuste Sal�rial********");

        printf("\n\nSal�rio atual do funcion�rio %i: ", contador);
        scanf("%f", &salario);

        printf("\nQual o tempo de servi�o do funcion�rio %i em anos? \nCaso seja menos de um ano digite -1: ", contador);
        scanf("%i", &tempoServico);

        //Calculando os reajustes
        if(salario > 0 && salario <= 500 && tempoServico == -1){
            salarioReajuste = salario + (salario*0.25);
            reajuste = salario*0.25;
        }

        else if(salario > 0 && salario <= 1000 && tempoServico >= 1 && tempoServico <= 3){
            salarioReajuste = salario + (salario*0.20) + 100;
            reajuste = ((salario*0.20) + 100);
        }

        else if(salario > 0 && salario <= 1500 && tempoServico >= 4 && tempoServico <= 6){
            salarioReajuste = salario + (salario*0.15) + 200;
            reajuste = ((salario*0.15) + 200);
        }

        else if(salario > 0 && salario <= 2000 && tempoServico >= 7 && tempoServico <= 10){
            salarioReajuste = salario + (salario*0.10) + 300;
            reajuste = ((salario*0.10) + 300);
        }

        else if(salario > 2000 && tempoServico > 10){
            salarioReajuste = salario + 500;
            reajuste = 500;
        }

        else{
            semReajuste++;
        }

        //Verificando o maior sal�rio
        if(contador == 1){
            maiorSalario = salarioReajuste;
        }

        else{
            if(maiorSalario < salarioReajuste){
                maiorSalario = salarioReajuste;
            }
        }

        //Somando os sal�rios com reajuste
        somaSalarios = somaSalarios + salarioReajuste;

        //Menor Reajuste
        if(contador == 1){
            menorReajuste = reajuste;
        }
        else if(menorReajuste > reajuste){
            menorReajuste = reajuste;
        }

        system("cls");

    }

    comReajuste = 20 - semReajuste; //Total de salarios com reajuste para ser calculada a m�dia

    printf("\nSal�rio mais alto: R$ %.2f", maiorSalario);
    printf("\nMenor Reajuste: R$ %.2f", menorReajuste);
    printf("\nM�dia dos sal�rios reajustados: R$ %.2f", somaSalarios/comReajuste);
    printf("\nFuncion�rios que n�o tiveram reajuste: %i", semReajuste);
    printf("\n\n");

    if(maiorSalario == 0 && menorReajuste == 0 && somaSalarios == 0){
        printf("\nNenhum funcion�rio recebeu reajustes.\n\n");
    }

    return 0;

}
