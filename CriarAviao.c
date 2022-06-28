#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "Trabalho - Simulador de Aeroporto.h"


//
// Created by jhonstar69 on 14/05/22.
//


//------------------------------------ PARTE PARA CRIAR AVIOES ----------------------------------------------

//função para acrescentar ID e quantidade de tempo em avioes novos criados
void criarAviaoAterrissando(aeronaveAterrissar *aviaoATERRISSAR, int SORTEIO, int *p_ID_aterrissagem) {
    for (int i = 0; i < SORTEIO; ++i) {
        aviaoATERRISSAR[i].ID = *p_ID_aterrissagem;
        aviaoATERRISSAR[i].quantidadeTempo = 1 + (rand() % 20);;
        *(p_ID_aterrissagem) += 2;
    }
}

//função para acrescentar ID em avioes novos criados
void criarAviaoDecolando(aeronaveDecolar *aviaoDECOLAR, int SORTEIO, int *p_ID_decolagem) {
    for (int i = 0; i < SORTEIO; ++i) {
        aviaoDECOLAR[i].ID = *p_ID_decolagem;
        *(p_ID_decolagem) += 2;
    }
}
//-------------------------------------------------------------------------------------------------------


