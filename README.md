# TrabalhosDeProg1
Todos os trabalhos realizados por mim na disciplina de programação

Copas
Enunciado do programa:
Esse programa realiza uma simulação do jogo Copas, um jogo de baralho com cinquenta e duas cartas é dividido igualmente entre quatro jogadores (treze cartas para cada).
Cada turno começa com um jogador descartando uma de suas cartas na mesa e em seguida os outros jogadores devem descartar uma de suas cartas com o mesmo naipe da carta que iniciou o turno. Por exemplo, se o primeiro jogador descartou o 8 de Ouros, os demais devem descartar uma carta de Ouros. Só é permitido descartar uma carta de outro naipe quando o jogador não tiver cartas daquele naipe.

Após os quatro jogadores descartarem uma carta, aquele que jogou a maior carta do naipe correto vai:

Ganhar as quatro cartas descartadas; e
Iniciar o turno seguinte.
Ao final de treze turnos, os pontos de cada jogador são contabilizados de acordo com as cartas ganhas ao longo dos turnos:

Cada carta de Copas vale 1 ponto;
A Dama de Espadas vale 13 pontos; e
Se um jogador ganhou as treze cartas de Copas mais a Dama de Espadas, ele recebe 0 pontos enquanto os demais jogadores recebem 26.
Após a contabilização o baralho é redistribuído e uma rodada de treze turnos começa novamente até que um dos jogadores acumule 100 pontos ou mais. Vence o jogador com menos pontos.

Neste trabalho você deve escrever um programa que leia a sequência de cartas ganhas por cada jogador ao final de cada rodada. Por exemplo, as sequências de uma rodada seguem o formato abaixo:

4 16 28 4
5-P 11-P 1-C 11-O
7-E 8-O 1-P 10-C 11-E 4-E 13-C 3-C 7-P 12-O 12-P 5-C 6-O 12-C 6-P 7-C
2-E 9-O 7-O 10-O 1-E 9-E 13-O 5-E 4-O 3-O 12-E 8-P 5-O 9-C 13-E 3-P 10-E 6-C 13-P 6-E 10-P 2-C 4-P 1-O 9-P 8-C 4-C 8-E
2-P 11-C 3-E 2-O
A primeira linha possui quatro números que correspondem à quantidade de cartas em cada uma das quatro linhas seguintes (uma linha para cada jogador). Cada carta é um par de número e letra separados por hífen. Os números representam o ranque da carta, sendo 1, 11, 12 e 13 equivalentes a Ás, Valete, Damas e Reis, respectivamente. Já as letras representam os naipes, sendo O, P, C e E iguais a Ouros, Paus, Copas e Espadas.

Após ler as sequências de uma rodada, imprima o placar com as pontuações acumuladas de cada jogador no seguinte formato:

A: 1 B: 6 C: 18 D: 1
As letras A, B, C e D representam cada jogador na ordem das respectivas quatro linhas de entrada; e os números são as pontuações calculadas de acordo com as cartas ganhas pelo respectivo jogador, ou seja, nesse exemplo o jogador A ganhou uma carta de Copas, o jogador B ganhou seis cartas de Copas, o jogador C ganhou cinco cartas de Copas mais a Rainha de Espadas, e o jogador D ganhou uma carta de Copas.

O programa deve continuar lendo rodadas e imprimindo o placar atualizado (pontuação atual somada à pontuação da rodada anterior) até o fim do jogo. Quando o jogo acabar, imprima qual jogador venceu o jogo e qual estourou 100 pontos no formato "Vencedor: jogador X; Ultimo Lugar: jogador Y", sendo X e Y a letra do respectivo jogador. Não haverá empates ou mais de um jogador estourando 100 pontos.

Exemplo de execução:

4 16 28 4
5-P 11-P 1-C 11-O
7-E 8-O 1-P 10-C 11-E 4-E 13-C 3-C 7-P 12-O 12-P 5-C 6-O 12-C 6-P 7-C
2-E 9-O 7-O 10-O 1-E 9-E 13-O 5-E 4-O 3-O 12-E 8-P 5-O 9-C 13-E 3-P 10-E 6-C 13-P 6-E 10-P 2-C 4-P 1-O 9-P 8-C 4-C 8-E
2-P 11-C 3-E 2-O
A: 1 B: 6 C: 18 D: 1
4 4 32 12
13-E 6-E 4-C 11-E
8-P 13-P 8-C 1-O
5-C 9-P 4-P 11-O 2-C 1-C 2-E 5-O 3-O 11-P 9-E 3-P 5-P 12-C 11-C 4-E 2-P 1-E 7-O 8-O 3-C 10-C 5-E 1-P 13-O 9-C 4-O 12-P 6-O 7-C 3-E 6-P
10-O 10-E 12-O 9-O 7-P 10-P 6-C 8-E 2-O 13-C 12-E 7-E
A: 2 B: 7 C: 27 D: 16
12 8 16 16
3-C 13-E 5-P 10-O 2-O 3-O 7-P 6-P 11-C 13-C 8-C 6-O
4-O 11-E 13-P 12-O 7-E 6-C 9-P 9-E
9-O 8-O 10-E 12-C 2-E 1-P 6-E 9-C 4-C 3-E 13-O 4-P 12-E 5-O 7-C 1-C
12-P 3-P 2-C 10-C 5-E 1-O 5-C 8-P 2-P 11-P 11-O 1-E 4-E 8-E 10-P 7-O
A: 6 B: 8 C: 45 D: 19
20 8 4 20
13-E 5-O 9-P 5-P 4-P 2-O 11-E 10-O 2-P 7-P 8-P 13-P 1-P 2-C 2-E 3-E 4-C 8-E 11-C 10-C
10-E 1-E 6-P 12-P 8-C 4-E 12-O 11-O
12-C 3-P 7-E 9-O
10-P 11-P 1-O 13-C 12-E 9-E 8-O 1-C 3-O 6-E 6-C 13-O 5-E 6-O 4-O 7-O 9-C 5-C 3-C 7-C
A: 10 B: 9 C: 46 D: 39
12 12 20 8
11-P 5-P 6-C 11-E 9-P 4-P 10-P 4-E 12-O 10-E 8-E 8-C
2-C 6-O 10-O 4-C 12-E 1-E 9-O 3-P 2-O 1-C 3-C 6-E
6-P 4-O 2-E 11-C 5-E 13-C 13-P 7-C 7-P 12-P 3-O 2-P 7-O 10-C 9-C 1-P 7-E 9-E 13-E 8-P
1-O 8-O 3-E 5-O 12-C 13-O 5-C 11-O
A: 12 B: 26 C: 51 D: 41
12 4 16 20
9-P 8-E 3-C 13-P 11-E 7-P 2-P 7-E 12-E 5-O 13-E 1-O
5-E 8-C 11-C 4-E
9-O 11-P 2-C 1-P 3-O 7-O 9-C 4-P 5-P 9-E 3-E 10-C 1-E 13-C 6-C 11-O
12-C 10-E 8-P 10-O 12-P 8-O 4-O 7-C 4-C 3-P 13-O 2-O 1-C 6-E 5-C 12-O 6-P 10-P 2-E 6-O
A: 26 B: 28 C: 56 D: 46
4 20 24 4
11-P 3-O 1-E 4-E
8-E 3-C 11-C 10-P 13-E 8-P 6-P 9-P 5-O 5-E 1-P 6-E 1-O 6-O 12-O 4-O 9-O 13-C 7-P 8-O
4-C 13-O 11-E 5-P 4-P 12-C 10-C 13-P 2-O 6-C 5-C 10-O 10-E 3-E 2-P 1-C 9-C 12-E 2-E 7-O 3-P 9-E 7-E 12-P
8-C 7-C 11-O 2-C
A: 26 B: 31 C: 76 D: 49
8 28 4 12
8-P 1-E 10-C 13-P 8-C 2-C 8-E 13-E
9-C 4-E 7-O 5-E 4-P 4-O 1-P 11-P 11-O 6-E 9-O 8-O 9-E 1-O 3-C 6-P 7-E 5-O 9-P 4-C 3-P 6-O 10-P 10-E 11-E 2-P 3-E 10-O
1-C 12-O 6-C 12-C
5-P 11-C 13-C 5-C 3-O 12-E 2-E 7-C 7-P 13-O 2-O 12-P
A: 29 B: 34 C: 79 D: 66
12 28 8 4
2-C 7-P 12-C 13-E 4-O 3-C 9-E 2-E 13-P 1-P 12-E 6-P
4-C 9-O 6-O 1-O 13-O 3-O 9-P 6-E 11-P 1-C 12-P 3-E 4-E 9-C 11-O 13-C 5-P 7-C 5-O 8-O 8-P 8-E 3-P 10-P 2-P 5-C 6-C 7-O
10-O 10-C 11-E 11-C 1-E 5-E 12-O 7-E
10-E 4-P 8-C 2-O
A: 45 B: 41 C: 81 D: 67
12 16 12 12
8-C 5-P 4-O 11-P 12-O 1-E 3-C 6-O 1-P 9-P 2-O 3-P
2-E 4-E 4-P 13-O 9-E 2-C 9-O 3-E 7-P 1-C 9-C 5-E 8-E 11-O 12-E 3-O
7-O 10-E 4-C 2-P 1-O 8-P 10-O 10-C 6-E 12-C 7-E 8-O
10-P 5-O 11-C 11-E 13-C 5-C 13-P 12-P 6-P 6-C 7-C 13-E
A: 47 B: 57 C: 84 D: 72
16 16 8 12
6-C 6-E 1-O 9-C 7-E 11-E 8-E 13-C 9-P 5-P 4-P 7-O 8-P 3-P 10-C 10-O
11-C 6-P 6-O 1-E 12-P 3-O 3-E 12-E 5-E 10-P 1-P 1-C 9-E 13-E 7-C 4-E
12-C 11-P 10-E 9-O 5-C 2-C 11-O 2-O
2-P 3-C 8-C 4-O 4-C 13-P 7-P 8-O 12-O 2-E 13-O 5-O
A: 51 B: 73 C: 87 D: 75
16 16 12 8
8-O 13-O 5-C 2-O 1-O 1-E 9-C 6-E 12-O 2-E 9-O 5-E 4-E 12-C 10-C 8-E
11-O 13-P 11-E 13-C 3-C 9-E 6-C 8-C 3-P 6-O 2-C 10-P 7-P 1-C 11-P 3-E
8-P 5-O 10-O 11-C 7-O 7-E 9-P 4-C 12-E 10-E 13-E 4-P
6-P 12-P 2-P 7-C 5-P 4-O 1-P 3-O
A: 55 B: 79 C: 102 D: 76
Vencedor: jogador A; Ultimo Lugar: jogador C
Obs: as partes com A, B, C e D, e os vencedores são as saídas

Descrição do código:
Primeiro há o armazenamento do número de cartas de cada jogador, funcionando como o parâmetro para quantidade de loops de leitura da carta.
Dentro do loop, há a leitura do número da carta, '-' e seu naipe.
Depois, as validações de pontos sendo se for copas adicionar 1 ponto ao jogador, dama(12) de espadas(E) adicionar 13 pontos ao jogador, e 13 cartas de copas e uma dama de espadas adicionar 26 pontos aos outros jogadores. Pórem, par funcionar adequadamente são necessárias bandeiras ou flags para quantidade de cartas de copas e damas, para contar uma única vez o número de pontos, repetindo isso para cada jogador.
Para finalizar, há vários if-else para contagem de pontos, sendo a condição a pessoa possuir mais pontos que todos ou menos pontos que todos, imprimindo a letra da pessoa na tela. 
