#ifndef TRABALHO___SIMULADOR_DE_AEROPORTO_TRABALHO_SIMULADOR_DE_AEROPORTO_H
#define TRABALHO___SIMULADOR_DE_AEROPORTO_TRABALHO_SIMULADOR_DE_AEROPORTO_H

#define MAXTAMFILAS 100000 //TAMANHO MAXIMO PARA FILAS

typedef int Apontadores;

//************************    TIPO DADOS PARA FILA ATERRISSAR  ***********************************************

typedef struct {
    int ID, quantidadeTempo;
} aeronaveAterrissar;//TIPO PARA AVIAO ATERRISANDO


typedef struct {
    aeronaveAterrissar Aviao[MAXTAMFILAS];
    int tamanhoPista;
    Apontadores Frente, Tras;
} FilaAterrissar;

//************************    TIPO DADOS PARA FILA DECOLAGEM  ***********************************************


typedef struct {
    int ID;
} aeronaveDecolar;//TIPO AVIAO DECOLANDO

typedef struct {
    aeronaveDecolar Aviao[MAXTAMFILAS];
    Apontadores Frente, Tras;
} FilaDecolar;


//************************    FUNÇOES PARA FILAS DE ATERRISSAGEM  ***********************************************

//sortear dados de aviao aterrissando
void criarAviaoAterrissando(aeronaveAterrissar *aviaoATERRISSAR, int SORTEIO, int *p_ID_aterrissagem);

void CriarFilaAterrissar(FilaAterrissar *Fila);

int VaziaAterrissar(FilaAterrissar Fila);

void EnfileiraAterrissar(aeronaveAterrissar *aviaoATERRISSAR, int pos, FilaAterrissar *Fila);

void DesenfileiraAterrissar(FilaAterrissar *Fila, aeronaveAterrissar *Item);

void ImprimirAterrissagem(FilaAterrissar *fila);

void esperaAterrissar(aeronaveAterrissar *aviaoATERRISSAR, int SORTEIO_ATERRISSAR,
                      FilaAterrissar *Pista_1_espera_1, FilaAterrissar *Pista_1_espera_2,
                      FilaAterrissar *Pista_2_espera_1, FilaAterrissar *Pista_2_espera_2,
                      int *p_controleAterrisagem);

void aterrissar(FilaAterrissar *p_ATERRISSAR1, FilaAterrissar *p_ATERRISSAR2,
                FilaAterrissar *filaEspera);

void emergencia(FilaAterrissar *PISTA_ATERRISSAR3, FilaAterrissar *filaEspera);


//************************    FUNÇOES PARA FILAS DE DECOLAGEM  ***********************************************

//sortear dados de aviao decolando
void criarAviaoDecolando(aeronaveDecolar *aviaoDECOLAR, int SORTEIO, int *p_ID_decolagem);

void CriarFilaDecolar(FilaDecolar *fila);

int VaziaDecolar(FilaDecolar Fila);

void EnfileiraDecolar(aeronaveDecolar *aviaoDecolar, int pos, FilaDecolar *Fila);

void DesenfileiraDecolar(FilaDecolar *Fila, aeronaveDecolar *Item);

void ImprimirDecolagem(FilaDecolar *fila);

void decolar(aeronaveDecolar *aviaoDECOLAR, int SORTEIO_DECOLAR,
             FilaDecolar *PistaDecolar1, FilaDecolar *PistaDecolar2, FilaDecolar *PistaDecolar3,
             int *p_controleDecolar);

#endif //TRABALHO___SIMULADOR_DE_AEROPORTO_TRABALHO_SIMULADOR_DE_AEROPORTO_H
