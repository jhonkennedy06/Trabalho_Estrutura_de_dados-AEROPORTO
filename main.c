#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Trabalho - Simulador de Aeroporto.h"


int main() {
    srand((unsigned) time(NULL));
//ID_decolagem é par e
    int SORTEIO_DECOLAR, SORTEIO_ATERRISSAR, ID_decolagem = 0, *p_ID_decolagem = &ID_decolagem,
            ID_aterrissagem = 1, *p_ID_aterrissagem = &ID_aterrissagem, QTDITERAÇOES;
    int controleEspera = 1, *p_controleEspera = &controleEspera;

    FilaAterrissar p_ATERRISSAR1, p_ATERRISSAR2, p_ATERRISSAR3;//VARIAVEIS PARA PISTA DO AEROPORTO
    FilaAterrissar Pista_1_espera_1, Pista_1_espera_2, Pista_2_espera_1, Pista_2_espera_2; //VARIAVEIS PARA PRATELEIRAS DE PISTAS
    //Criar pistas(filas) do aeroporto
    CriarFilaAterrisar(&p_ATERRISSAR1);
    CriarFilaAterrisar(&p_ATERRISSAR2);
    CriarFilaAterrisar(&p_ATERRISSAR3);
    CriarFilaAterrisar(&Pista_1_espera_1);
    CriarFilaAterrisar(&Pista_1_espera_2);
    CriarFilaAterrisar(&Pista_2_espera_1);
    CriarFilaAterrisar(&Pista_2_espera_2);

    printf("\nDigite a quantidade de iteraçoes que o aeroporto tera: ");
    scanf("%d%*c", &QTDITERAÇOES);

    for (int i = 0; i < QTDITERAÇOES; ++i) {
        printf("\nTEMPO %d ------------------------------------------------------------------", i + 1);
        //------------------------   PARTE PARA CRIAR AVIOES ------------------------------------------------------------
        //SORTEIA O NUMERO DE AVIOES A SEREM CRIADOS
        SORTEIO_DECOLAR = rand() % 4;//Sorteio do numero de avioes para decolagem
        SORTEIO_ATERRISSAR = rand() % 4;//Sorteio do numero de avioes para aterrissagem

        //CRIA AVIOES PARA DECOLAGEM E ATERRISSAGEM
        aeronaveDecolar aviaoDECOLAR[SORTEIO_DECOLAR];//DECOLAGEM
        aeronaveAterrissar aviaoATERRISSAR[SORTEIO_ATERRISSAR];//ATERRISSAGEM

        //SORTEIA OS IDs E A QUANTIDADE DE TEMPO
        criarAviaoAterrissando(aviaoATERRISSAR, SORTEIO_ATERRISSAR, p_ID_aterrissagem);//ID E QTD DE TEMPO
        criarAviaoDecolando(aviaoDECOLAR, SORTEIO_DECOLAR, p_ID_decolagem);//ID SOMENTE

        //--------------------------------------------------------------------------------------------------------------

        //apos criar os avioes, iremos passar o vetor para a funçao e depois iremos inserir um item por vez a cada prateleira de espera
        if (SORTEIO_ATERRISSAR != 0) {
            esperaAterrissar(
                    aviaoATERRISSAR, SORTEIO_ATERRISSAR, &Pista_1_espera_1,
                    &Pista_1_espera_2,
                    &Pista_2_espera_1, &Pista_2_espera_2, p_controleEspera);
        } else {
            printf("\n\nNenhum avião aterrissando\n\n");
        }

        if (Pista_1_espera_1.tamanhoPista != 0 && Pista_1_espera_2.tamanhoPista && Pista_2_espera_1.tamanhoPista &&
            Pista_2_espera_2.tamanhoPista) {
            //parte onde iremos ver qual é o aviao nao tem reserva de combustivel
            if ((Vazia(Pista_1_espera_1) == 0) && Pista_1_espera_1.Aviao[Pista_1_espera_1.Frente - 1].quantidadeTempo == 1) {

                emergencia(&p_ATERRISSAR3, &Pista_1_espera_1);

            } else if ((Vazia(Pista_1_espera_2) == 0) && Pista_1_espera_2.Aviao[Pista_1_espera_2.Frente - 1].quantidadeTempo == 1) {

                emergencia(&p_ATERRISSAR3, &Pista_1_espera_2);

            } else if ((Vazia(Pista_2_espera_1) == 0) && Pista_2_espera_1.Aviao[Pista_2_espera_1.Frente - 1].quantidadeTempo == 1) {

                emergencia(&p_ATERRISSAR3, &Pista_2_espera_1);


            } else if ((Vazia(Pista_2_espera_2) == 0) && Pista_2_espera_2.Aviao[Pista_2_espera_2.Frente - 1].quantidadeTempo == 1) {

                emergencia(&p_ATERRISSAR3, &Pista_2_espera_2);

            }else

            //parte onde iremos ver qual é o aviao com menor tempo de combustivel
            if ((Vazia(Pista_1_espera_1) == 0) &&
                ((Pista_1_espera_1.Aviao[Pista_1_espera_1.Frente - 1].quantidadeTempo <
                  Pista_1_espera_2.Aviao[Pista_1_espera_2.Frente - 1].quantidadeTempo) &&
                 (Pista_1_espera_1.Aviao[Pista_1_espera_1.Frente - 1].quantidadeTempo <
                  Pista_2_espera_1.Aviao[Pista_2_espera_1.Frente - 1].quantidadeTempo) &&
                 (Pista_1_espera_1.Aviao[Pista_1_espera_1.Frente - 1].quantidadeTempo <
                  Pista_2_espera_2.Aviao[Pista_2_espera_2.Frente - 1].quantidadeTempo))) {

                aterrissar(&p_ATERRISSAR1, &p_ATERRISSAR2, &Pista_1_espera_1);


            } else if ((Vazia(Pista_1_espera_2) == 0) &&
                       ((Pista_1_espera_2.Aviao[Pista_1_espera_2.Frente - 1].quantidadeTempo <
                         Pista_1_espera_1.Aviao[Pista_1_espera_1.Frente - 1].quantidadeTempo) &&
                        (Pista_1_espera_2.Aviao[Pista_1_espera_2.Frente - 1].quantidadeTempo <
                         Pista_2_espera_1.Aviao[Pista_2_espera_1.Frente - 1].quantidadeTempo) &&
                        (Pista_1_espera_2.Aviao[Pista_1_espera_2.Frente - 1].quantidadeTempo <
                         Pista_2_espera_2.Aviao[Pista_2_espera_2.Frente - 1].quantidadeTempo))) {

                aterrissar(&p_ATERRISSAR1, &p_ATERRISSAR2, &Pista_1_espera_2);


            } else if ((Vazia(Pista_2_espera_1) == 0) &&
                       (Pista_2_espera_1.Aviao[Pista_2_espera_1.Frente - 1].quantidadeTempo <
                        Pista_1_espera_1.Aviao[Pista_1_espera_1.Frente - 1].quantidadeTempo) &&
                       (Pista_2_espera_1.Aviao[Pista_2_espera_1.Frente - 1].quantidadeTempo <
                        Pista_1_espera_2.Aviao[Pista_1_espera_2.Frente - 1].quantidadeTempo) &&
                       (Pista_2_espera_1.Aviao[Pista_2_espera_1.Frente - 1].quantidadeTempo <
                        Pista_2_espera_2.Aviao[Pista_2_espera_2.Frente - 1].quantidadeTempo)) {

                aterrissar(&p_ATERRISSAR1, &p_ATERRISSAR2, &Pista_2_espera_1);


            } else if ((Vazia(Pista_2_espera_2) == 0) &&
                       (Pista_2_espera_2.Aviao[Pista_2_espera_2.Frente - 1].quantidadeTempo <
                        Pista_1_espera_1.Aviao[Pista_1_espera_1.Frente - 1].quantidadeTempo) &&
                       (Pista_2_espera_2.Aviao[Pista_2_espera_2.Frente - 1].quantidadeTempo <
                        Pista_1_espera_2.Aviao[Pista_1_espera_2.Frente - 1].quantidadeTempo) &&
                       (Pista_2_espera_2.Aviao[Pista_2_espera_2.Frente - 1].quantidadeTempo <
                        Pista_2_espera_1.Aviao[Pista_2_espera_1.Frente - 1].quantidadeTempo)) {

                aterrissar(&p_ATERRISSAR1, &p_ATERRISSAR2, &Pista_2_espera_2);

            }

        }

        //apos criar os avioes, iremos passar o vetor para a funçao e depois iremos inserir um item por vez a cada prateleira de espera
        if (SORTEIO_DECOLAR != 0) {
            decolar();
        } else {
            printf("\n\nNenhum avião decolando\n\n");
        }

    }

    /*
DesenfileiraAterrisar(&fila, &item);

verifica = Vazia(fila);
CriarFilaAterrisar(&fila);
printf("\nfila esvaziada.\n");
*/





    printf("\nPrograma Finalizado com sucesso.\n");

    return 0;
}


