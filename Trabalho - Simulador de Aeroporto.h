#ifndef TRABALHO___SIMULADOR_DE_AEROPORTO_TRABALHO_SIMULADOR_DE_AEROPORTO_H
#define TRABALHO___SIMULADOR_DE_AEROPORTO_TRABALHO_SIMULADOR_DE_AEROPORTO_H

#define MAXTAMFILAS 1000 //TAMANHO MAXIMO PARA FILAS


//TIPOS DE DADOS PARA FILAS

typedef int Apontadores;

//--------------------- TIPO DADOS PARA FILA ATERRISSAR
typedef struct {
    int ID, quantidadeTempo;
} aeronaveAterrissar;//TIPO PARA AVIAO ATERRISANDO


typedef struct {
    aeronaveAterrissar Aviao[MAXTAMFILAS];
    int tamanhoPista;
    Apontadores Frente, Tras;
} FilaAterrissar;
//----------------------------------------------------------

//--------------------- TIPO DADOS PARA FILA DECOLAGEM ----------------------------------------------------------


typedef struct {
    int ID;
} aeronaveDecolar;//TIPO AVIAO DECOLANDO

typedef struct {
    aeronaveDecolar Aviao[MAXTAMFILAS];
    Apontadores Frente, Tras;
} FilaDecolar;
//----------------------------------------------------------

//funçoes para controledo aeroporto77 ----------------------------------------

void esperaAterrissar(aeronaveAterrissar *aviaoATERRISSAR, int SORTEIO_ATERRISSAR,
                      FilaAterrissar *Pista_1_espera_1, FilaAterrissar *Pista_1_espera_2,
                      FilaAterrissar *Pista_2_espera_1, FilaAterrissar *Pista_2_espera_2,
                      int *p_controleEspera);

void aterrissar(FilaAterrissar *p_ATERRISSAR1, FilaAterrissar *p_ATERRISSAR2,
                FilaAterrissar *filaEspera);

void emergencia(FilaAterrissar *PISTA_ATERRISSAR3, FilaAterrissar *filaEspera);

void decolar();

//sortear dados de aviao aterrissando
void criarAviaoAterrissando(aeronaveAterrissar *aviaoATERRISSAR, int SORTEIO, int *p_ID_aterrissagem);

//sortear dados de aviao decolando
void criarAviaoDecolando(aeronaveDecolar *aviaoDECOLAR, int SORTEIO, int *p_ID_decolagem);



//Tipos de dados ------------------------------------------------------------



// Tipo de dados e funçoes das filas


//FUNÇOES PARA FILAS DE ATERRISSAGEM

void CriarFilaAterrissar(FilaAterrissar *Fila);

int VaziaAterrissar(FilaAterrissar Fila);

void EnfileiraAterrissar(aeronaveAterrissar *aviaoATERRISSAR, int pos, FilaAterrissar *Fila);

void DesenfileiraAterrissar(FilaAterrissar *Fila, aeronaveAterrissar *Item);

void ImprimirAterrissagem(FilaAterrissar *fila);

//FUNÇOES PARA FILAS DE DECOLAGEM

void CriarFilaDecolar(FilaDecolar *fila);

int VaziaDecolar(FilaDecolar Fila);

void EnfileiraDecolar(aeronaveDecolar *aviaoDecolar, int pos, FilaDecolar *Fila);

void DesenfileiraDecolar(FilaDecolar *Fila, aeronaveDecolar *Item);

void ImprimirDecolagem(FilaDecolar *fila);


#endif //TRABALHO___SIMULADOR_DE_AEROPORTO_TRABALHO_SIMULADOR_DE_AEROPORTO_H
