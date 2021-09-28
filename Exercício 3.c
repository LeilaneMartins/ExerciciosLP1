#include <stdio.h>
#include <locale.h>

int main(){

    float peso, altura, imc;
    int contador, acimaPesoIdeal = 0;

    setlocale(LC_ALL, "Portuguese");

    printf("           ***Calculo de IMC***\n\n");

    for(contador = 1; contador <= 10; contador ++){
        printf("Digite o %iº peso: ", contador);
        scanf("%f", &peso);

        printf("Digite a %iº altura: ", contador);
        scanf("%f", &altura);

        if(altura <= 0 || peso <= 0 ){
            printf("\nVocê informou algum dado inválido! comece denovo.\n");
            break;
        }

        else{
            imc = (peso / (altura*altura));

            printf("\nIMC pessoa %i: %.2f\n\n", contador, imc);

            if(imc >= 25){
               acimaPesoIdeal++;
            }
        }
    }

    if(altura != 0 && peso != 0){
        printf("\nPessoas acima do peso ideal: %i\n\n", acimaPesoIdeal);
    }

    return 0;
}
