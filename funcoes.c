//FUNÇOES PARA ATERRISSAR
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Trabalho - Simulador de Aeroporto.h"

//------------------------------------ PARTE PARA CRIAR AVIOES ----------------------------------------------

//função para acrescentar ID e quantidade de tempo em avioes novos criados para aterrissagem

void criarAviao(aeronave *aviaoDECOLAR, aeronave *aviaoATERRISSAR, int SORTEIO_ATERRISSAR, int *p_ID_aterrissagem,
                int SORTEIO_DECOLAR, int *p_ID_decolagem) {

    for (int i = 0; i < SORTEIO_ATERRISSAR; ++i) {
        aviaoATERRISSAR[i].ID = *p_ID_aterrissagem;
        aviaoATERRISSAR[i].quantidadeTempo = 1 + (rand() % 20);;
        *(p_ID_aterrissagem) += 2;
    }
    for (int i = 0; i < SORTEIO_DECOLAR; ++i) {
        aviaoDECOLAR[i].ID = *p_ID_decolagem;
        *(p_ID_decolagem) += 2;
        aviaoDECOLAR[i].quantidadeTempo = 20;
    }
}

//-------------------------------------------------------------------------------------------------------



//************************    FUNÇOES PARA FILAS  ***********************************************

void CriarFila(Fila *Fila) {
    Fila->Frente = 1;
    Fila->Tras = Fila->Frente;
    Fila->tamanhoPista = 0;
}

int Vazia(Fila Fila) { //retorna 0 se estiver vazia
    return (Fila.Frente == Fila.Tras);
}

void Enfileira(aeronave *aviaoATERRISSAR, int pos, Fila *Fila) {
    if (Fila->Tras % MAXTAMFILAS + 1 == Fila->Frente) {}
    else {
        Fila->Aviao[Fila->Tras - 1] = aviaoATERRISSAR[pos];//adiciona o item da posiçao "pos" do vetor a fila
        Fila->Tras = Fila->Tras % MAXTAMFILAS + 1;
        Fila->tamanhoPista++;//iremos colocar um contador para fazer as filas crescerem juntas
    }
}

void Desenfileira(Fila *Fila, aeronave *Item) {
    if (Vazia(*Fila) == 1) {}
    else {
        *Item = Fila->Aviao[Fila->Frente - 1];
        Fila->Frente = Fila->Frente % MAXTAMFILAS + 1;
    }
}

void Imprimir(Fila *fila) {
    printf("\n");
    for (int i = fila->Frente - 1; i < fila->Tras - 1; ++i) {
        printf("Avião de ID: %d e quantidade de tempo igual a %d\n", fila->Aviao[i].ID, fila->Aviao[i].quantidadeTempo);
    }
}


//funçao para fila de espera para aterrissar avioes

void esperaAterrissar(aeronave *aviaoATERRISSAR, int SORTEIO_ATERRISSAR,
                      Fila *Pista_1_espera_1, Fila *Pista_1_espera_2,
                      Fila *Pista_2_espera_1, Fila *Pista_2_espera_2,
                      int *p_controleAterrisagem) {


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
             Enfileira(aviaoATERRISSAR, i, Pista_2_espera_2);
             Imprimir(Pista_2_espera_2);
             printf("\nPrateleira 2 PISTA 2\n");
         }*/

        if (*(p_controleAterrisagem) == 1) {
            *(p_controleAterrisagem) = 2;//altera a variavel auxiliar para adicionar na posicao seguinte
            //acrescenta o aviao atual a prateleira 1 da pista 1
            Enfileira(aviaoATERRISSAR, i, Pista_1_espera_1);
            Imprimir(Pista_1_espera_1);
            printf("\nPrateleira 1 PISTA 1");
        } else if (*(p_controleAterrisagem) == 2) {

            *(p_controleAterrisagem) = 3;//altera a variavel auxiliar para adicionar na posicao seguinte
            //acrescenta o aviao atual a prateleira 2 da pista 1
            Enfileira(aviaoATERRISSAR, i, Pista_1_espera_2);
            Imprimir(Pista_1_espera_2);
            printf("\nPrateleira 2 PISTA 1");

        } else if (*(p_controleAterrisagem) == 3) {

            *(p_controleAterrisagem) = 4;//altera a variavel auxiliar para adicionar na posicao seguinte
            //acrescenta o aviao atual a prateleira 1 da pista 2
            Enfileira(aviaoATERRISSAR, i, Pista_2_espera_1);
            Imprimir(Pista_2_espera_1);
            printf("\nPrateleira 1 PISTA 2");

        } else if (*(p_controleAterrisagem) == 4) {

            *(p_controleAterrisagem) = 1;//altera a variavel auxiliar para adicionar na posicao seguinte
            //acrescenta o aviao atual a prateleira 2 da pista 2
            Enfileira(aviaoATERRISSAR, i, Pista_2_espera_2);
            Imprimir(Pista_2_espera_2);
            printf("\nPrateleira 2 PISTA 2");

        }


    }

}

//funçao para retirar os avioes da fila de espera e colocar eles para decolar
void aterrissar(Fila *PISTA1, Fila *PISTA2, Fila *filaEspera) {

    if (PISTA1->tamanhoPista < PISTA2->tamanhoPista) {
        //compara se o tamanho da pista 1 ta menor que a 2
        printf("\nPISTA 1 ANTES");

        printf("\nFILA ESPERA");
        Imprimir(filaEspera);
        printf("\nFILA ATERRISSAR");
        Imprimir(PISTA1);

        Enfileira(filaEspera->Aviao, filaEspera->Frente - 1, PISTA1);
        Desenfileira(filaEspera, &filaEspera->Aviao[(filaEspera->Frente) - 1]);

        printf("\nPISTA 1 DEPOIS");

        printf("\nFILA ESPERA");
        Imprimir(filaEspera);
        printf("\nFILA ATERRISSAR");
        Imprimir(PISTA1);

    } else {
        printf("\nPISTA 2 ANTES");
        printf("\nFILA ESPERA");
        Imprimir(filaEspera);
        printf("\nFILA ATERRISSAR");
        Imprimir(PISTA2);
        Enfileira(filaEspera->Aviao, filaEspera->Frente - 1, PISTA2);
        Desenfileira(filaEspera, &filaEspera->Aviao[filaEspera->Frente - 1]);

        printf("\nPISTA 2 DEPOIS");

        printf("\nFILA ESPERA");
        Imprimir(filaEspera);
        printf("\nFILA ATERRISSAR");
        Imprimir(PISTA2);
    }
}

//funçao de emergencia para avioes sem reserva de combustivel e para decolar
void emergencia_e_decolar(Fila *PISTA3, Fila *filaEspera) {
    printf("\nPISTA 3 antes");
    printf("\nFILA ESPERA");
    Imprimir(filaEspera);
    printf("\nFILA ATERRISSAR");
    Imprimir(PISTA3);

    Enfileira(filaEspera->Aviao, filaEspera->Frente - 1, PISTA3);
    Desenfileira(filaEspera, &filaEspera->Aviao[filaEspera->Frente - 1]);
    printf("\nPISTA 3 depois");

    printf("\nFILA ESPERA");
    Imprimir(filaEspera);
    printf("\nFILA ATERRISSAR");
    Imprimir(PISTA3);
}


void Combustivel(Fila *espera) {
    for (int i = espera->Frente - 1; i < espera->Tras - 1; ++i) {

        //confere o tempo do aviao antes para ele nao ficar com saldo negativo
        if (espera->Aviao[i].quantidadeTempo != 0) {
            //retira uma unidade
            espera->Aviao[i].quantidadeTempo--;
            //ele confere pra ver se o aviao tiver combustivel igual a 0 é pq ele caiu
            if (espera->Aviao[i].quantidadeTempo == 0) {

                printf("\n---------------------------------------------------"
                       "\n                 Avião Caiu            "
                       "\n---------------------------------------------------");

            }
        }
    }
}


//************************    FUNÇOES PARA FILAS DE DECOLAR  ***********************************************

void decolar(aeronave *aviaoDECOLAR, int SORTEIO_DECOLAR, Fila *fila_DECOLAR) {


//IRA COLOCAR UM AVIAO DE CADA VEZ NA PRATELEIRA QUE TIVER MENOR NUMERO
    for (int i = 0; i < SORTEIO_DECOLAR; ++i) {

        //acrescenta o aviao atual na pista 2
        Enfileira(aviaoDECOLAR, i, fila_DECOLAR);
        Imprimir(fila_DECOLAR);
        printf("\nPISTA DECOLAR 1");

    }
}





