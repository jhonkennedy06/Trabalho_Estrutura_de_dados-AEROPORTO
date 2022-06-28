#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Trabalho - Simulador de Aeroporto.h"


int main() {
    srand((unsigned) time(NULL));
//ID_decolagem é par e
    int SORTEIO_DECOLAR, SORTEIO_ATERRISSAR, ID_decolagem = 0, *p_ID_decolagem = &ID_decolagem,
            ID_aterrissagem = 1, *p_ID_aterrissagem = &ID_aterrissagem, QTDITERAÇOES;
    int controleAterrissar = 1, *p_controleAterrissar = &controleAterrissar, reserva_zerada = 0;

    //VARIAVEIS PARA PISTAS DE ATERRISSAGEM DO AEROPORTO
    Fila PISTA1, PISTA2, PISTA3, fila_DECOLAR;
    Fila espera_1, espera_2, espera_3, espera_4; //VARIAVEIS PARA PRATELEIRAS DE PISTAS

    //Criar pistas(filas) do aeroporto
    CriarFila(&PISTA1);//pista
    CriarFila(&PISTA2);//pista
    CriarFila(&PISTA3);//pista
    CriarFila(&espera_1);//espera1
    CriarFila(&espera_2);//espera2
    CriarFila(&espera_3);//espera3
    CriarFila(&espera_4);//espera4
    CriarFila(&fila_DECOLAR);//decolar


    printf("\nDigite a quantidade de iteraçoes que o aeroporto tera: ");
    scanf("%d%*c", &QTDITERAÇOES);

    for (int i = 0; i < QTDITERAÇOES; ++i) {
        printf("\nTEMPO %d ------------------------------------------------------------------\n", i + 1);

        //******************************   PARTE PARA CRIAR AVIOES  **************************************

        //SORTEIA O NUMERO DE AVIOES A SEREM CRIADOS
        SORTEIO_DECOLAR = rand() % 4;//Sorteio do numero de avioes para decolagem
        SORTEIO_ATERRISSAR = rand() % 4;//Sorteio do numero de avioes para aterrissagem

        //CRIA AVIOES PARA DECOLAGEM E ATERRISSAGEM
        aeronave aviaoDECOLAR[SORTEIO_DECOLAR];//DECOLAGEM
        aeronave aviaoATERRISSAR[SORTEIO_ATERRISSAR];//ATERRISSAGEM

        //SORTEIA OS IDs E A QUANTIDADE DE TEMPO
        criarAviao(aviaoDECOLAR, aviaoATERRISSAR, SORTEIO_ATERRISSAR, p_ID_aterrissagem, SORTEIO_DECOLAR,
                   p_ID_decolagem);//ID E QTD DE TEMPO

        //***********************************************************************************************


        //***************************** SESSAO PARA INSERIR NA FILA DE ESPERA E DECOLAGEM *********************

        //inserir um item por vez a cada prateleira de espera
        if (SORTEIO_ATERRISSAR != 0) {
            esperaAterrissar(aviaoATERRISSAR, SORTEIO_ATERRISSAR, &espera_1, &espera_2,
                             &espera_3, &espera_4, p_controleAterrissar);
        } else {
            printf("\n\nNenhum avião aterrissando\n\n");
        }

        //inserir um item por vez na fila de desolagem
        if (SORTEIO_DECOLAR != 0) {
            decolar(&aviaoDECOLAR, SORTEIO_DECOLAR, &fila_DECOLAR);

        } else {
            printf("\n\nNenhum avião decolando\n\n");
        }

        //***************************** SESSAO PARA INSERIR AVIAO NA PISTA **********************************

        //    if ((espera_1.tamanhoPista != 0) && (espera_2.tamanhoPista && espera_3.tamanhoPista &&
        //      espera_4.tamanhoPista)) {


        //parte para retirar os avioes que cairam da fila

        if (espera_1.Aviao[espera_1.Frente - 1].quantidadeTempo == 0) {

            Desenfileira(&espera_1, &espera_1.Aviao[espera_1.Frente - 1]);

        } else if (espera_2.Aviao[espera_2.Frente - 1].quantidadeTempo == 0) {

            Desenfileira(&espera_2, &espera_2.Aviao[espera_2.Frente - 1]);

        } else if (espera_3.Aviao[espera_3.Frente - 1].quantidadeTempo == 0) {

            Desenfileira(&espera_3, &espera_3.Aviao[espera_3.Frente - 1]);

        } else if (espera_4.Aviao[espera_4.Frente - 1].quantidadeTempo == 0) {

            Desenfileira(&espera_4, &espera_4.Aviao[espera_4.Frente - 1]);
        }

        //parte onde iremos ver qual é o aviao com menor tempo de combustivel
        if ((Vazia(espera_1) == 0) &&
            ((espera_1.Aviao[espera_1.Frente - 1].quantidadeTempo <
              espera_2.Aviao[espera_2.Frente - 1].quantidadeTempo) &&
             (espera_1.Aviao[espera_1.Frente - 1].quantidadeTempo <
              espera_3.Aviao[espera_3.Frente - 1].quantidadeTempo) &&
             (espera_1.Aviao[espera_1.Frente - 1].quantidadeTempo <
              espera_4.Aviao[espera_4.Frente - 1].quantidadeTempo))) {

            aterrissar(&PISTA1, &PISTA2, &espera_1);
            *(p_controleAterrissar) = 1; //variavel para controlar crescimento igual das pistas

        } else if ((Vazia(espera_2) == 0) &&
                   ((espera_2.Aviao[espera_2.Frente - 1].quantidadeTempo <
                     espera_1.Aviao[espera_1.Frente - 1].quantidadeTempo) &&
                    (espera_2.Aviao[espera_2.Frente - 1].quantidadeTempo <
                     espera_3.Aviao[espera_3.Frente - 1].quantidadeTempo) &&
                    (espera_2.Aviao[espera_2.Frente - 1].quantidadeTempo <
                     espera_4.Aviao[espera_4.Frente - 1].quantidadeTempo))) {

            aterrissar(&PISTA1, &PISTA2, &espera_2);
            *(p_controleAterrissar) = 2;


        } else if ((Vazia(espera_3) == 0) &&
                   (espera_3.Aviao[espera_3.Frente - 1].quantidadeTempo <
                    espera_1.Aviao[espera_1.Frente - 1].quantidadeTempo) &&
                   (espera_3.Aviao[espera_3.Frente - 1].quantidadeTempo <
                    espera_2.Aviao[espera_2.Frente - 1].quantidadeTempo) &&
                   (espera_3.Aviao[espera_3.Frente - 1].quantidadeTempo <
                    espera_4.Aviao[espera_4.Frente - 1].quantidadeTempo)) {

            aterrissar(&PISTA1, &PISTA2, &espera_3);
            *(p_controleAterrissar) = 3;


        } else if ((Vazia(espera_4) == 0) &&
                   (espera_4.Aviao[espera_4.Frente - 1].quantidadeTempo <
                    espera_1.Aviao[espera_1.Frente - 1].quantidadeTempo) &&
                   (espera_4.Aviao[espera_4.Frente - 1].quantidadeTempo <
                    espera_2.Aviao[espera_2.Frente - 1].quantidadeTempo) &&
                   (espera_4.Aviao[espera_4.Frente - 1].quantidadeTempo <
                    espera_3.Aviao[espera_3.Frente - 1].quantidadeTempo)) {

            aterrissar(&PISTA1, &PISTA2, &espera_4);
            *(p_controleAterrissar) = 4;

        } else if ((Vazia(espera_1) == 0) && (Vazia(espera_2) == 0) && (Vazia(espera_3) == 0) &&
                   (Vazia(espera_4) == 0)) {//se forem todos iguais, adiciona no 1 mesmo
            aterrissar(&PISTA1, &PISTA2, &espera_1);
            *(p_controleAterrissar) = 1;

        }

        //  }


        //*********** SESSAO PARA DECOLAR AVIAO OU ATERRISSAGEM DE EMERGENCIA  *******************

        if ((Vazia(espera_1) == 0) &&
            espera_1.Aviao[espera_1.Frente - 1].quantidadeTempo == 1) {

            emergencia_e_decolar(&PISTA3, &espera_1);

        } else if ((Vazia(espera_2) == 0) &&
                   espera_2.Aviao[espera_2.Frente - 1].quantidadeTempo == 1) {

            emergencia_e_decolar(&PISTA3, &espera_2);

        } else if ((Vazia(espera_3) == 0) &&
                   espera_3.Aviao[espera_3.Frente - 1].quantidadeTempo == 1) {

            emergencia_e_decolar(&PISTA3, &espera_3);


        } else if ((Vazia(espera_4) == 0) &&
                   espera_4.Aviao[espera_4.Frente - 1].quantidadeTempo == 1) {

            emergencia_e_decolar(&PISTA3, &espera_4);

        } else {//se nao tiver nenhum aviao com emergencia para pousar, entao os avioes iram poder decolar
            emergencia_e_decolar(&PISTA3, &fila_DECOLAR);
        }

        //****************************************************************************************



        //******************** Sessão para ir retirando combustiveis dos avioes ******************

        Combustivel(&espera_1);
        Combustivel(&espera_2);
        Combustivel(&espera_3);
        Combustivel(&espera_4);

        //****************************************************************************************

    }


    /*
    a) o conteúdo de cada fila;
    b) o tempo médio de espera para decolagem;
    c) o tempo médio de espera para aterrissagem;
    d) o número de aviões que aterrissam sem reserva de combustível.*/
    //Saida do programa
    printf("\n\nFIm de controle.\n\n");

    //a) o conteúdo de cada fila;
    printf("\nPateleiras de espera:");

    printf("\nFila espera 1:");
    Imprimir(&espera_1);

    printf("\nFila espera 2:");
    Imprimir(&espera_2);

    printf("\nFila espera 3:");
    Imprimir(&espera_3);

    printf("\nFila espera 4:");
    Imprimir(&espera_4);

    //CONTEUDOS DAS PISTAS
    printf("\n\nPistas de aterrissagem:");

    printf("\nPista 1:");
    Imprimir(&PISTA1);

    printf("\nPista 2:");
    Imprimir(&PISTA2);

    printf("\nPista 3:");
    Imprimir(&PISTA3);

    //CONTEUDOS DAS PISTAS de decolagem

    printf("\n\nPistas de decolagem:");

    printf("\nFila de decolagem:");
    Imprimir(&fila_DECOLAR);;

    //d) o número de aviões que aterrissam sem reserva de combustível.*/


    printf("\nPrograma Finalizado com sucesso.\n");

    return 0;
}


