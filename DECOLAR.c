//FUNÇOES PARA DECOLAR
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Trabalho - Simulador de Aeroporto.h"


void CriarFilaDecolar(FilaDecolar *Fila) {
    Fila->Frente = 1;
    Fila->Tras = Fila->Frente;
}

int VaziaDecolar(FilaDecolar Fila) { //retorna 0 se estiver vazia
    return (Fila.Frente == Fila.Tras);
}


void EnfileiraDecolar(aeronaveDecolar *aviaoDecolar, int pos, FilaDecolar *Fila) {
    if (Fila->Tras % MAXTAMFILAS + 1 == Fila->Frente)
        printf(" Erro fila esta cheia\n");
    else {
        Fila->Aviao[Fila->Tras - 1] = aviaoDecolar[pos];//adiciona o item da posiçao "pos" do vetor a fila
        Fila->Tras = Fila->Tras % MAXTAMFILAS + 1;
    }
}

void DesenfileiraDecolar(FilaDecolar *Fila, aeronaveDecolar *Item) {
    if (VaziaDecolar(*Fila) == 1)
        printf("Erro fila esta vazia\n");
    else {
        *Item = Fila->Aviao[Fila->Frente - 1];
        Fila->Frente = Fila->Frente % MAXTAMFILAS + 1;
    }
}

void ImprimirDecolagem(FilaDecolar *fila) {
    printf("\n");
    for (int i = fila->Frente - 1; i < fila->Tras - 1; ++i) {
        printf("Avião de ID: %d\n", fila->Aviao[i].ID);
    }
}


void decolar(aeronaveDecolar *aviaoDECOLAR, int SORTEIO_DECOLAR,
             FilaDecolar *PistaDecolar1, FilaDecolar *PistaDecolar2, FilaDecolar *PistaDecolar3,
             int *p_controleDecolar) {


//IRA COLOCAR UM AVIAO DE CADA VEZ NA PRATELEIRA QUE TIVER MENOR NUMERO
    for (int i = 0; i < SORTEIO_DECOLAR; ++i) {


        if (*(p_controleDecolar) == 1) {
            *(p_controleDecolar) = 2;//altera a variavel auxiliar para adicionar na posicao seguinte

            //acrescenta o aviao atual na pista 2
            EnfileiraDecolar(aviaoDECOLAR, i, PistaDecolar1);
            ImprimirDecolagem(PistaDecolar1);
            printf("\nPISTA DECOLAR 1");

        } else if (*(p_controleDecolar) == 2) {
            *(p_controleDecolar) = 3;//altera a variavel auxiliar para adicionar na posicao seguinte

            //acrescenta o aviao atual na pista 2
            EnfileiraDecolar(aviaoDECOLAR, i, PistaDecolar2);
            ImprimirDecolagem(PistaDecolar2);
            printf("\nPISTA 2");

        } else if (*(p_controleDecolar) == 3) {
            *(p_controleDecolar) = 1;//altera a variavel auxiliar para adicionar na posicao seguinte

            //acrescenta o aviao atual na pista 3
            EnfileiraDecolar(aviaoDECOLAR, i, PistaDecolar3);
            ImprimirDecolagem(PistaDecolar3);
            printf("\nPISTA 3");

        }


    }

}

