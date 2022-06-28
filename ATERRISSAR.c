//FUNÇOES PARA ATERRISSAR
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Trabalho - Simulador de Aeroporto.h"

//----------------FUNçoes para FILAS


void CriarFilaAterrissar(FilaAterrissar *Fila) {
    Fila->Frente = 1;
    Fila->Tras = Fila->Frente;
    Fila->tamanhoPista = 0;
}

int VaziaAterrissar(FilaAterrissar Fila) { //retorna 0 se estiver vazia
    return (Fila.Frente == Fila.Tras);
}


void EnfileiraAterrissar(aeronaveAterrissar *aviaoATERRISSAR, int pos, FilaAterrissar *Fila) {
    if (Fila->Tras % MAXTAMFILAS + 1 == Fila->Frente) {}
    else {
        Fila->Aviao[Fila->Tras - 1] = aviaoATERRISSAR[pos];//adiciona o item da posiçao "pos" do vetor a fila
        Fila->Tras = Fila->Tras % MAXTAMFILAS + 1;
        Fila->tamanhoPista++;//iremos colocar um contador para fazer as filas crescerem juntas
    }
}

void DesenfileiraAterrissar(FilaAterrissar *Fila, aeronaveAterrissar *Item) {
    if (VaziaAterrissar(*Fila) == 1) {}
    else {
        *Item = Fila->Aviao[Fila->Frente - 1];
        Fila->Frente = Fila->Frente % MAXTAMFILAS + 1;
    }
}

void ImprimirAterrissagem(FilaAterrissar *fila) {
    printf("\n");
    for (int i = fila->Frente - 1; i < fila->Tras - 1; ++i) {
        printf("Avião de ID: %d e quantidade de tempo igual a %d\n", fila->Aviao[i].ID, fila->Aviao[i].quantidadeTempo);
    }
}

//funçao para aterrisar avioes

void esperaAterrissar(aeronaveAterrissar *aviaoATERRISSAR, int SORTEIO_ATERRISSAR,
                      FilaAterrissar *Pista_1_espera_1, FilaAterrissar *Pista_1_espera_2,
                      FilaAterrissar *Pista_2_espera_1, FilaAterrissar *Pista_2_espera_2,
                      int *p_controleEspera) {


//IRA COLOCAR UM AVIAO DE CADA VEZ NA PRATELEIRA QUE TIVER MENOR NUMERO
    for (int i = 0; i < SORTEIO_ATERRISSAR; ++i) {

        //CODIGO PRECISAR MELHORAR, SERVE PARA ORDENAR AS FILAS COM TAMANHOS IGUAIS
        /* //condição secundaria para a fila crescer igual
         if ((Pista_1_espera_1->tamanhoPista < Pista_1_espera_2->tamanhoPista) &&
             (Pista_1_espera_1->tamanhoPista < Pista_2_espera_1->tamanhoPista) &&
             (Pista_1_espera_1->tamanhoPista < Pista_2_espera_2->tamanhoPista)) {
             //acrescenta o aviao atual a prateleira 1 da pista 1
             EnfileiraAterrisar(aviaoATERRISSAR, i, Pista_1_espera_1);
             Imprimir(Pista_1_espera_1);
             printf("\nPrateleira 1 PISTA 1\n");

         } else if ((Pista_1_espera_2->tamanhoPista < Pista_1_espera_1->tamanhoPista) &&
                    (Pista_1_espera_2->tamanhoPista < Pista_2_espera_1->tamanhoPista) &&
                    (Pista_1_espera_2->tamanhoPista < Pista_2_espera_2->tamanhoPista)) {

             //acrescenta o aviao atual a prateleira 2 da pista 1
             EnfileiraAterrisar(aviaoATERRISSAR, i, Pista_1_espera_2);
             Imprimir(Pista_1_espera_2);
             printf("\nPrateleira 2 PISTA 1\n");

         } else if ((Pista_2_espera_1->tamanhoPista < Pista_1_espera_1->tamanhoPista) &&
                    (Pista_2_espera_1->tamanhoPista < Pista_1_espera_2->tamanhoPista) &&
                    (Pista_2_espera_1->tamanhoPista < Pista_2_espera_2->tamanhoPista)) {

             //acrescenta o aviao atual a prateleira 1 da pista 2
             EnfileiraAterrisar(aviaoATERRISSAR, i, Pista_2_espera_1);
             Imprimir(Pista_2_espera_1);
             printf("\nPrateleira 1 PISTA 2\n");

         } else if ((Pista_2_espera_2->tamanhoPista < Pista_1_espera_1->tamanhoPista) &&
                    (Pista_2_espera_2->tamanhoPista < Pista_1_espera_2->tamanhoPista) &&
                    (Pista_2_espera_2->tamanhoPista > Pista_2_espera_1->tamanhoPista)) {

             //acrescenta o aviao atual a prateleira 2 da pista 2
             EnfileiraAterrissar(aviaoATERRISSAR, i, Pista_2_espera_2);
             ImprimirAterrissagem(Pista_2_espera_2);
             printf("\nPrateleira 2 PISTA 2\n");
         }*/

        if (*(p_controleEspera) == 1) {
            *(p_controleEspera) = 2;//altera a variavel auxiliar para adicionar na posicao seguinte
            //acrescenta o aviao atual a prateleira 1 da pista 1
            EnfileiraAterrissar(aviaoATERRISSAR, i, Pista_1_espera_1);
            ImprimirAterrissagem(Pista_1_espera_1);
            printf("\nPrateleira 1 PISTA 1");
        } else if (*(p_controleEspera) == 2) {

            *(p_controleEspera) = 3;//altera a variavel auxiliar para adicionar na posicao seguinte
            //acrescenta o aviao atual a prateleira 2 da pista 1
            EnfileiraAterrissar(aviaoATERRISSAR, i, Pista_1_espera_2);
            ImprimirAterrissagem(Pista_1_espera_2);
            printf("\nPrateleira 2 PISTA 1");

        } else if (*(p_controleEspera) == 3) {

            *(p_controleEspera) = 4;//altera a variavel auxiliar para adicionar na posicao seguinte
            //acrescenta o aviao atual a prateleira 1 da pista 2
            EnfileiraAterrissar(aviaoATERRISSAR, i, Pista_2_espera_1);
            ImprimirAterrissagem(Pista_2_espera_1);
            printf("\nPrateleira 1 PISTA 2");

        } else if (*(p_controleEspera) == 4) {

            *(p_controleEspera) = 1;//altera a variavel auxiliar para adicionar na posicao seguinte
            //acrescenta o aviao atual a prateleira 2 da pista 2
            EnfileiraAterrissar(aviaoATERRISSAR, i, Pista_2_espera_2);
            ImprimirAterrissagem(Pista_2_espera_2);
            printf("\nPrateleira 2 PISTA 2");

        }


    }

}

void aterrissar(FilaAterrissar *p_ATERRISSAR1, FilaAterrissar *p_ATERRISSAR2, FilaAterrissar *filaEspera) {

    if (p_ATERRISSAR1->tamanhoPista < p_ATERRISSAR2->tamanhoPista) {
        //compara se o tamanho da pista 1 ta menor que a 2
        printf("\nPISTA 1 ANTES");

        printf("\nFILA ESPERA");
        ImprimirAterrissagem(filaEspera);
        printf("\nFILA ATERRISSAR");
        ImprimirAterrissagem(p_ATERRISSAR1);

        EnfileiraAterrissar(filaEspera->Aviao, filaEspera->Frente - 1, p_ATERRISSAR1);
        DesenfileiraAterrissar(filaEspera, &filaEspera->Aviao[(filaEspera->Frente) - 1]);

        printf("\nPISTA 1 DEPOIS");

        printf("\nFILA ESPERA");
        ImprimirAterrissagem(filaEspera);
        printf("\nFILA ATERRISSAR");
        ImprimirAterrissagem(p_ATERRISSAR1);

    } else {
        printf("\nPISTA 2 ANTES");
        printf("\nFILA ESPERA");
        ImprimirAterrissagem(filaEspera);
        printf("\nFILA ATERRISSAR");
        ImprimirAterrissagem(p_ATERRISSAR2);
        EnfileiraAterrissar(filaEspera->Aviao, filaEspera->Frente - 1, p_ATERRISSAR2);
        DesenfileiraAterrissar(filaEspera, &filaEspera->Aviao[filaEspera->Frente - 1]);

        printf("\nPISTA 2 DEPOIS");

        printf("\nFILA ESPERA");
        ImprimirAterrissagem(filaEspera);
        printf("\nFILA ATERRISSAR");
        ImprimirAterrissagem(p_ATERRISSAR2);
    }
}

//funçao para emergencia de avioes sem reserva de combustivel
void emergencia(FilaAterrissar *PISTA_ATERRISSAR3, FilaAterrissar *filaEspera) {
    printf("\nPISTA 3 antes");
    printf("\nFILA ESPERA");
    ImprimirAterrissagem(filaEspera);
    printf("\nFILA ATERRISSAR");
    ImprimirAterrissagem(PISTA_ATERRISSAR3);

    EnfileiraAterrissar(filaEspera->Aviao, filaEspera->Frente - 1, PISTA_ATERRISSAR3);
    DesenfileiraAterrissar(filaEspera, &filaEspera->Aviao[filaEspera->Frente - 1]);
    printf("\nPISTA 3 depois");

    printf("\nFILA ESPERA");
    ImprimirAterrissagem(filaEspera);
    printf("\nFILA ATERRISSAR");
    ImprimirAterrissagem(PISTA_ATERRISSAR3);


}




