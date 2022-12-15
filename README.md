# Trabalho_Estrutura_de_dados-AEROPORTO

O trabalho deverá ser realizado individualmente e consiste na modelagem e implementação computacional sobre uma situação fictícia vivenciada em um
aeroporto.

## 2 Contexto

O objetivo do trabalho é simular os padrões de aterrissagem e decolagem em um aeroporto.
Suponha um aeroporto que possui três pistas, numeradas como 1, 2 e 3. Existem quatro “prateleiras” de espera para aterrissagem, duas para cada uma das pistas 1 e 2. Aeronaves que se aproximam do aeroporto devem integrar-se a uma das prateleiras (filas) de espera, sendo que estas filas devem procurar manter o mesmo tamanho. Assim que um avião entra em uma fila de aterrissagem, ele recebe um número de identificação ID e outro número inteiro que indica a quantidade de unidades de tempo que o avião pode permanecer na fila antes que ele tenha de descer (do contrário, seu combustível termina e ele cai).
Existem também filas para decolagem, uma para cada pista. Os aviões que chegam nessas filas também recebem uma identificação ID. Essas filas também devem procurar manter o mesmo tamanho.

## 3 Simulação   
O controle do simulador deverá ser realizado por UT (Unidade de Tempo) sendo que, a cada unidade de tempo:

• de zero a três aeronaves podem chegar nas filas de decolagem;
• de zero a três aeronaves podem chegar nas prateleiras;
• cada pista pode ser usada para um pouso ou uma decolagem, sendo que a pista 3 em geral só é usada para decolagens, a não ser que um dos aviões nas prateleiras esteja para aterrissar e fique sem combustível, quando então ela deve ser imediatamente usada para pouso.

OBS.: Se apenas uma aeronave está com falta de combustível, ela pousará na pista 3; se mais de um avião estiver nesta situação, as outras pistas poderão ser utilizadas (a cada unidade de tempo no máximo três aviões poderão estar nesta desagradável situação). Utilize inteiros pares (ímpares) sucessivos para a ID dos aviões chegando nas filas de decolagem (aterrissagem). A cada unidade de tempo, assuma que os aviões entram nas filas antes que aterrissagens ou decolagens ocorram. Tente projetar um algoritmo que não permita o crescimento excessivo das filas de aterrissagem ou decolagem. Coloque os aviões sempre no final das filas, que não devem ser reordenadas.

A saída do programa deverá indicar o que ocorre a cada unidade de tempo. Periodicamente imprima:
a) o conteúdo de cada fila;
b) o tempo médio de espera para decolagem;
c) o tempo médio de espera para aterrissagem;
d) o número de aviões que aterrissam sem reserva de combustível.

Os itens b e c acima devem ser calculados para os aviões que já decolaram ou pousaram, respectivamente. A saída do programa deve ser autoexplicativa e fácil de entender. 

A entrada poderia ser criada manualmente, mas o melhor é utilizar um gerador de números aleatórios. Para cada unidade de tempo, a entrada deve ter as seguintes informações:
a) número de aviões (zero a três) chegando nas filas de aterrissagem com respectivas reservas de combustível (de 1 a 20 unidades de tempo);
b) número de aviões (zero a três) chegando nas filas de decolagem;
