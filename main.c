#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Trabalho - Simulador de Aeroporto.h"


int main() {
    srand((unsigned) time(NULL));
//ID_decolagem é par e
    int SORTEIO_DECOLAR = 0, SORTEIO_ATERRISSAR = 0, ID_decolagem = 0, *p_ID_decolagem = &ID_decolagem,
            ID_aterrissagem = 1, *p_ID_aterrissagem = &ID_aterrissagem, QTDITERAÇOES = 0;
    int controleEspera = 1, *p_controleEspera = &controleEspera;

    FilaAterrissar PISTA_ATERRISSAR1, PISTA_ATERRISSAR2, PISTA_ATERRISSAR3;//VARIAVEIS PARA PISTA DO AEROPORTO
    FilaAterrissar prateleira1_PISTA_ATERRISSAR1, prateleira2_PISTA_ATERRISSAR1, prateleira1_PISTA_ATERRISSAR2, prateleira2_PISTA_ATERRISSAR2; //VARIAVEIS PARA PRATELEIRAS DE PISTAS
    //Criar pistas(filas) do aeroporto
    CriarFilaAterrisar(&PISTA_ATERRISSAR1);
    CriarFilaAterrisar(&PISTA_ATERRISSAR2);
    CriarFilaAterrisar(&PISTA_ATERRISSAR3);
    CriarFilaAterrisar(&prateleira1_PISTA_ATERRISSAR1);
    CriarFilaAterrisar(&prateleira2_PISTA_ATERRISSAR1);
    CriarFilaAterrisar(&prateleira1_PISTA_ATERRISSAR2);
    CriarFilaAterrisar(&prateleira2_PISTA_ATERRISSAR2);

    printf("\nDigite a quantidade de iteraçoes que o aeroporto tera: ");
    scanf("%d%*c", &QTDITERAÇOES);

    for (int i = 0; i < QTDITERAÇOES; ++i) {
        printf("\nTEMPO %d", i + 1);
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
                    aviaoATERRISSAR, SORTEIO_ATERRISSAR, &prateleira1_PISTA_ATERRISSAR1,
                    &prateleira2_PISTA_ATERRISSAR1,
                    &prateleira1_PISTA_ATERRISSAR2, &prateleira2_PISTA_ATERRISSAR2, p_controleEspera);
        } else {
            printf("\n\nNenhum avião aterrissando\n\n");
        }


        //parte onde iremos ver qual é o aviao com menor tempo de combustivel
        if ((prateleira1_PISTA_ATERRISSAR1.Aviao[prateleira1_PISTA_ATERRISSAR1.Frente].quantidadeTempo <
             prateleira2_PISTA_ATERRISSAR1.Aviao[prateleira2_PISTA_ATERRISSAR1.Frente].quantidadeTempo) &&
            (prateleira1_PISTA_ATERRISSAR1.Aviao[prateleira1_PISTA_ATERRISSAR1.Frente].quantidadeTempo <
             prateleira1_PISTA_ATERRISSAR2.Aviao[prateleira1_PISTA_ATERRISSAR2.Frente].quantidadeTempo) &&
            (prateleira1_PISTA_ATERRISSAR1.Aviao[prateleira1_PISTA_ATERRISSAR1.Frente].quantidadeTempo <
             prateleira2_PISTA_ATERRISSAR2.Aviao[prateleira2_PISTA_ATERRISSAR2.Frente].quantidadeTempo)) {


        } else if ((prateleira2_PISTA_ATERRISSAR1->tamanhoPista < prateleira1_PISTA_ATERRISSAR1->tamanhoPista) &&
                   (prateleira2_PISTA_ATERRISSAR1->tamanhoPista < prateleira1_PISTA_ATERRISSAR2->tamanhoPista) &&
                   (prateleira2_PISTA_ATERRISSAR1->tamanhoPista < prateleira2_PISTA_ATERRISSAR2->tamanhoPista)) {


        } else if ((prateleira1_PISTA_ATERRISSAR2->tamanhoPista < prateleira1_PISTA_ATERRISSAR1->tamanhoPista) &&
                   (prateleira1_PISTA_ATERRISSAR2->tamanhoPista < prateleira2_PISTA_ATERRISSAR1->tamanhoPista) &&
                   (prateleira1_PISTA_ATERRISSAR2->tamanhoPista < prateleira2_PISTA_ATERRISSAR2->tamanhoPista)) {


        } else if ((prateleira2_PISTA_ATERRISSAR2->tamanhoPista < prateleira1_PISTA_ATERRISSAR1->tamanhoPista) &&
                   (prateleira2_PISTA_ATERRISSAR2->tamanhoPista < prateleira2_PISTA_ATERRISSAR1->tamanhoPista) &&
                   (prateleira2_PISTA_ATERRISSAR2->tamanhoPista > prateleira1_PISTA_ATERRISSAR2->tamanhoPista)) {

        }


        aterrissar(&PISTA_ATERRISSAR1, &PISTA_ATERRISSAR2, &PISTA_ATERRISSAR3);

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


