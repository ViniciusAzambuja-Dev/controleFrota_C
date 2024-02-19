#include <stdio.h>
#include <stdlib.h>


#define MAX_CAMINHOES 20
#define MAX_MESES 24

int pegaValorValido(int max)
{
    int valorValido = 0;
    while(1)
    {
        scanf("%i", &valorValido);
        if(valorValido < 1 || valorValido > max)
        {
            printf("O valor deve estar entre 1 e %i\n", max);
        }
        else
        {
            break;
        }
    }
    return valorValido;
}

void controleFrota(int numCaminhoes, int numMeses)
{   
    float consumoMedioMensal[MAX_MESES];
    float kmPercorrido[MAX_MESES];
    float valorTotalTranspot[MAX_MESES];
    float somaCombust = 0.0;
    float somaKM = 0.0;
    int maior = 0;
    int caminhaoMaiorValor = 0;



    for (int mes = 0; mes < numMeses; mes++)
    {
        for ( int caminhao = 0; caminhao < numCaminhoes; caminhao++)
        {
            printf("Insira o consumo mensal: ");
            scanf("%f", &consumoMedioMensal[mes]);
            somaCombust = somaCombust + consumoMedioMensal[mes];

            printf("Quantos Km foram percorridos: ");
            scanf("%f", &kmPercorrido[mes]);
            somaKM = somaKM + kmPercorrido[mes];
            
            printf("Insira o valor transportado: ");
            scanf("%f", &valorTotalTranspot[mes]);

            if (valorTotalTranspot[mes] > maior)
            {
               maior = valorTotalTranspot[mes];
               caminhaoMaiorValor = caminhao;
            }
            
            
        }
       
        consumoMedioMensal[mes] = somaCombust/numCaminhoes;
        printf("O consumo mensal eh: %.2f\n", consumoMedioMensal[mes]);  
        printf("A posicao do caminhao com maior valor eh: %i\n", caminhaoMaiorValor + 1);
        printf("A quilometragem mensal eh: %.2f\n", somaKM);
    }
      
        
}

int main()
{
    printf("Bem vindo ao controlador de frota de caminhoes\n");

    printf("Insira o tamanho da frota (max. %i): ", MAX_CAMINHOES);
    int numCaminhoes = pegaValorValido(MAX_CAMINHOES);
    
    printf("Insira o numero de meses (max. %i): ", MAX_MESES);
    int numMeses = pegaValorValido(MAX_MESES);

    controleFrota(numCaminhoes, numMeses);

    return 0;
}





