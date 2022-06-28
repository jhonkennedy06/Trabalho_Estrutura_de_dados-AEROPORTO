#ifndef TRABALHO___SIMULADOR_DE_AEROPORTO_TRABALHO_SIMULADOR_DE_AEROPORTO_H
#define TRABALHO___SIMULADOR_DE_AEROPORTO_TRABALHO_SIMULADOR_DE_AEROPORTO_H

#define MAXTAMFILAS 100000 //TAMANHO MAXIMO PARA FILAS

typedef int Apontadores;

//************************    TIPO DADOS PARA FILAS  ***********************************************

typedef struct {
    int ID, quantidadeTempo;
} aeronave;//TIPO PARA AVIAO


typedef struct {
    aeronave Aviao[MAXTAMFILAS];
    int tamanhoPista;
    Apontadores Frente, Tras;
} Fila; //FILAS PARA AVIAO

//************************    FUNÇOES PARA FILAS DE ATERRISSAGEM  ***********************************************

//sortear dados de aviao aterrissando
void
criarAviao(aeronave *aviaoDECOLAR, aeronave *aviaoATERRISSAR, int SORTEIO_ATERRISSAR, int *p_ID_aterrissagem,
           int SORTEIO_DECOLAR, int *p_ID_decolagem);

void CriarFila(Fila *Fila);

int Vazia(Fila Fila);

void Enfileira(aeronave *aviaoATERRISSAR, int pos, Fila *Fila);

void Desenfileira(Fila *Fila, aeronave *Item);

void Imprimir(Fila *fila);

void esperaAterrissar(aeronave *aviaoATERRISSAR, int SORTEIO_ATERRISSAR, Fila *espera_1, Fila *espera_2,
                      Fila *espera_3, Fila *espera_4, int *p_controleAterrisagem);

void aterrissar(Fila *PISTA1, Fila *PISTA2, Fila *filaEspera);

void emergencia_e_decolar(Fila *PISTA3, Fila *filaEspera);

void Combustivel(Fila *espera);

void decolar(aeronave *aviaoDECOLAR, int SORTEIO_DECOLAR, Fila *fila_DECOLAR); //função para decolagem


#endif //TRABALHO___SIMULADOR_DE_AEROPORTO_TRABALHO_SIMULADOR_DE_AEROPORTO_H
