#ifndef TRABALHO___SIMULADOR_DE_AEROPORTO_TRABALHO_SIMULADOR_DE_AEROPORTO_H
#define TRABALHO___SIMULADOR_DE_AEROPORTO_TRABALHO_SIMULADOR_DE_AEROPORTO_H

#define MAXTAMFILAS 1000 //TAMANHO MAXIMO PARA FILAS


typedef struct {
    int ID, quantidadeTempo;
} aeronaveAterrissar;//TIPO PARA AVIAO ATERRISANDO


typedef struct {
    int ID;
} aeronaveDecolar;//TIPO AVIAO DECOLANDO

//TIPOS DE DADOS PARA FILAS

typedef int Apontadores;

//--------------------- TIPO DADOS PARA FILA ATERRISSAR

typedef struct {
    aeronaveAterrissar Aviao[MAXTAMFILAS];
    int tamanhoPista;
    Apontadores Frente, Tras;
} FilaAterrissar;
//----------------------------------------------------------

//--------------------- TIPO DADOS PARA FILA DECOLAGEM ----------------------------------------------------------


typedef struct {
    aeronaveDecolar Aviao[MAXTAMFILAS];
    Apontadores Frente, Tras;
} FilaDecolar;
//----------------------------------------------------------

//funçoes para controledo aeroporto77 ----------------------------------------

void esperaAterrissar(aeronaveAterrissar *aviaoATERRISSAR, int SORTEIO_ATERRISSAR,
                      FilaAterrissar *prateleira1_PISTA_ATERRISSAR1, FilaAterrissar *prateleira2_PISTA_ATERRISSAR1,
                      FilaAterrissar *prateleira1_PISTA_ATERRISSAR2, FilaAterrissar *prateleira2_PISTA_ATERRISSAR2,
                      int *p_controleEspera);

void aterrissar(FilaAterrissar *PISTA_ATERRISSAR1, FilaAterrissar *PISTA_ATERRISSAR2, FilaAterrissar *PISTA_ATERRISSAR3,
                FilaAterrissar *FILAESPERA);

void decolar();

//sortear dados de aviao aterrissando
void criarAviaoAterrissando(aeronaveAterrissar *aviaoATERRISSAR, int SORTEIO, int *p_ID_aterrissagem);

//sortear dados de aviao decolando
void criarAviaoDecolando(aeronaveDecolar *aviaoDECOLAR, int SORTEIO, int *p_ID_decolagem);



//Tipos de dados ------------------------------------------------------------



// Tipo de dados e funçoes das filas


//FUNÇOES PARA FILAS

void CriarFilaAterrisar(FilaAterrissar *Fila);

int Vazia(FilaAterrissar Fila);

void EnfileiraAterrisar(aeronaveAterrissar *aviaoATERRISSAR, int pos, FilaAterrissar *Fila);

void DesenfileiraAterrisar(FilaAterrissar *Fila, aeronaveAterrissar *Item);

void Imprimir(FilaAterrissar *fila);

#endif //TRABALHO___SIMULADOR_DE_AEROPORTO_TRABALHO_SIMULADOR_DE_AEROPORTO_H
