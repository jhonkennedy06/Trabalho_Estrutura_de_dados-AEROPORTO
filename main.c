#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Trabalho - Simulador de Aeroporto.h"


int main() {
    srand((unsigned) time(NULL));
//ID_decolagem é par e
    int SORTEIO_DECOLAR, SORTEIO_ATERRISSAR, ID_decolagem = 0, *p_ID_decolagem = &ID_decolagem,
            ID_aterrissagem = 1, *p_ID_aterrissagem = &ID_aterrissagem, QTDITERAÇOES;
    int controleAterrissar = 1, controleDecolar = 1, *p_controleAterrissar = &controleAterrissar, *p_controleDecolar = &controleDecolar;

    //VARIAVEIS PARA PISTAS DE ATERRISSAGEM DO AEROPORTO
    FilaAterrissar p_ATERRISSAR1, p_ATERRISSAR2, p_ATERRISSAR3;
    FilaAterrissar Pista_1_espera_1, Pista_1_espera_2, Pista_2_espera_1, Pista_2_espera_2; //VARIAVEIS PARA PRATELEIRAS DE PISTAS
    //Criar pistas(filas) do aeroporto
    CriarFilaAterrissar(&p_ATERRISSAR1);
    CriarFilaAterrissar(&p_ATERRISSAR2);
    CriarFilaAterrissar(&p_ATERRISSAR3);
    CriarFilaAterrissar(&Pista_1_espera_1);
    CriarFilaAterrissar(&Pista_1_espera_2);
    CriarFilaAterrissar(&Pista_2_espera_1);
    CriarFilaAterrissar(&Pista_2_espera_2);

    //VARIAVEIS PARA PISTA DE DECOLAGEM DO AEROPORTO
    FilaDecolar p_DECOLAR1, p_DECOLAR2, p_DECOLAR3;
    //Criar pistas(filas) para decolagem do aeroporto
    CriarFilaDecolar(&p_DECOLAR1);
    CriarFilaDecolar(&p_DECOLAR2);
    CriarFilaDecolar(&p_DECOLAR3);

    printf("\nDigite a quantidade de iteraçoes que o aeroporto tera: ");
    scanf("%d%*c", &QTDITERAÇOES);

    for (int i = 0; i < QTDITERAÇOES; ++i) {
        printf("\nTEMPO %d ------------------------------------------------------------------\n", i + 1);
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
            esperaAterrissar(aviaoATERRISSAR, SORTEIO_ATERRISSAR, &Pista_1_espera_1, &Pista_1_espera_2,
                             &Pista_2_espera_1, &Pista_2_espera_2, p_controleAterrissar);
        } else {
            printf("\n\nNenhum avião aterrissando\n\n");
        }

        if (Pista_1_espera_1.tamanhoPista != 0 && Pista_1_espera_2.tamanhoPista && Pista_2_espera_1.tamanhoPista &&
            Pista_2_espera_2.tamanhoPista) {
            //parte onde iremos ver qual é o aviao nao tem reserva de combustivel
            if ((VaziaAterrissar(Pista_1_espera_1) == 0) &&
                Pista_1_espera_1.Aviao[Pista_1_espera_1.Frente - 1].quantidadeTempo == 1) {

                emergencia(&p_ATERRISSAR3, &Pista_1_espera_1);

            } else if ((VaziaAterrissar(Pista_1_espera_2) == 0) &&
                       Pista_1_espera_2.Aviao[Pista_1_espera_2.Frente - 1].quantidadeTempo == 1) {

                emergencia(&p_ATERRISSAR3, &Pista_1_espera_2);

            } else if ((VaziaAterrissar(Pista_2_espera_1) == 0) &&
                       Pista_2_espera_1.Aviao[Pista_2_espera_1.Frente - 1].quantidadeTempo == 1) {

                emergencia(&p_ATERRISSAR3, &Pista_2_espera_1);


            } else if ((VaziaAterrissar(Pista_2_espera_2) == 0) &&
                       Pista_2_espera_2.Aviao[Pista_2_espera_2.Frente - 1].quantidadeTempo == 1) {

                emergencia(&p_ATERRISSAR3, &Pista_2_espera_2);

            } else

                //parte onde iremos ver qual é o aviao com menor tempo de combustivel
            if ((VaziaAterrissar(Pista_1_espera_1) == 0) &&
                ((Pista_1_espera_1.Aviao[Pista_1_espera_1.Frente - 1].quantidadeTempo <
                  Pista_1_espera_2.Aviao[Pista_1_espera_2.Frente - 1].quantidadeTempo) &&
                 (Pista_1_espera_1.Aviao[Pista_1_espera_1.Frente - 1].quantidadeTempo <
                  Pista_2_espera_1.Aviao[Pista_2_espera_1.Frente - 1].quantidadeTempo) &&
                 (Pista_1_espera_1.Aviao[Pista_1_espera_1.Frente - 1].quantidadeTempo <
                  Pista_2_espera_2.Aviao[Pista_2_espera_2.Frente - 1].quantidadeTempo))) {

                aterrissar(&p_ATERRISSAR1, &p_ATERRISSAR2, &Pista_1_espera_1);


            } else if ((VaziaAterrissar(Pista_1_espera_2) == 0) &&
                       ((Pista_1_espera_2.Aviao[Pista_1_espera_2.Frente - 1].quantidadeTempo <
                         Pista_1_espera_1.Aviao[Pista_1_espera_1.Frente - 1].quantidadeTempo) &&
                        (Pista_1_espera_2.Aviao[Pista_1_espera_2.Frente - 1].quantidadeTempo <
                         Pista_2_espera_1.Aviao[Pista_2_espera_1.Frente - 1].quantidadeTempo) &&
                        (Pista_1_espera_2.Aviao[Pista_1_espera_2.Frente - 1].quantidadeTempo <
                         Pista_2_espera_2.Aviao[Pista_2_espera_2.Frente - 1].quantidadeTempo))) {

                aterrissar(&p_ATERRISSAR1, &p_ATERRISSAR2, &Pista_1_espera_2);


            } else if ((VaziaAterrissar(Pista_2_espera_1) == 0) &&
                       (Pista_2_espera_1.Aviao[Pista_2_espera_1.Frente - 1].quantidadeTempo <
                        Pista_1_espera_1.Aviao[Pista_1_espera_1.Frente - 1].quantidadeTempo) &&
                       (Pista_2_espera_1.Aviao[Pista_2_espera_1.Frente - 1].quantidadeTempo <
                        Pista_1_espera_2.Aviao[Pista_1_espera_2.Frente - 1].quantidadeTempo) &&
                       (Pista_2_espera_1.Aviao[Pista_2_espera_1.Frente - 1].quantidadeTempo <
                        Pista_2_espera_2.Aviao[Pista_2_espera_2.Frente - 1].quantidadeTempo)) {

                aterrissar(&p_ATERRISSAR1, &p_ATERRISSAR2, &Pista_2_espera_1);


            } else if ((VaziaAterrissar(Pista_2_espera_2) == 0) &&
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
            decolar(aviaoDECOLAR, SORTEIO_DECOLAR, &p_DECOLAR1, &p_DECOLAR2, &p_DECOLAR3, p_controleDecolar);
        } else {
            printf("\n\nNenhum avião decolando\n\n");
        }

        /*
        a) o conteúdo de cada fila;
        b) o tempo médio de espera para decolagem;
        c) o tempo médio de espera para aterrissagem;
        d) o número de aviões que aterrissam sem reserva de combustível.*/
        //Saida do programa

        //a) o conteúdo de cada fila;
        printf("\nPateleiras de espera:");

        printf("\nPista 1 - Fila espera 1:");
        ImprimirAterrissagem(&Pista_1_espera_1);

        printf("\nPista 1 - Fila espera 2:");
        ImprimirAterrissagem(&Pista_1_espera_2);

        printf("\nPista 2 - Fila espera 1:");
        ImprimirAterrissagem(&Pista_2_espera_1);

        printf("\nPista 2 - Fila espera 2:");
        ImprimirAterrissagem(&Pista_2_espera_2);

        //CONTEUDOS DAS PISTAS
        printf("\n\nPistas de aterrissagem:");

        printf("\nPista de aterrissagem 1:");
        ImprimirAterrissagem(&p_ATERRISSAR1);

        printf("\nPista de aterrissagem 2:");
        ImprimirAterrissagem(&p_ATERRISSAR2);

        printf("\nPista de aterrissagem 3:");
        ImprimirAterrissagem(&p_ATERRISSAR3);

        //CONTEUDOS DAS PISTAS de decolagem

        printf("\n\nPistas de decolagem:");

        printf("\nPista de decolagem 1:");
        ImprimirDecolagem(&p_DECOLAR1);

        printf("\nPista de decolagem 2:");
        ImprimirDecolagem(&p_DECOLAR2);

        printf("\nPista de decolagem 3:");
        ImprimirDecolagem(&p_DECOLAR3);


    }

    /*
DesenfileiraAterrissar(&fila, &item);

verifica = VaziaAterrissar(fila);
CriarFilaAterrissar(&fila);
printf("\nfila esvaziada.\n");
*/





    printf("\nPrograma Finalizado com sucesso.\n");

    return 0;
}


