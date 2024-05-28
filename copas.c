#include <stdio.h>
// Se um jogador ganhou as treze cartas de quantidadeCopas mais a Dama de Espadas, ele recebe 0 pontos enquanto os demais jogadores recebem 26.
int main()
{
    int numCartasJogador1, numCartasJogador2, numCartasJogador3, numCartasJogador4, pontosJogador1 = 0, pontosJogador2 = 0, pontosJogador3 = 0, pontosJogador4 = 0,
                                                                                    numCarta, quantidadeCopas, damaEspadas;
    char naipe, primeiroLugar, ultimoLugar;
    do
    {
        scanf("%d %d %d %d\n", &numCartasJogador1, &numCartasJogador2, &numCartasJogador3, &numCartasJogador4);
        for (quantidadeCopas = 0, damaEspadas = 0; numCartasJogador1 >= 1; numCartasJogador1--)
        {
            scanf("%d-%c", &numCarta, &naipe);
            // Cada carta de quantidadeCopas vale 1 ponto;
            if (naipe == 'C')
            {
                quantidadeCopas++;
                pontosJogador1 += 1;
            }
            // A Dama de Espadas vale 13 pontos
            else if (numCarta == 12 && naipe == 'E')
            {
                pontosJogador1 += 13;
                damaEspadas = 1;
            }
            // Se um jogador ganhou as treze cartas de quantidadeCopas mais a Dama de Espadas, ele recebe 0 pontos enquanto os demais jogadores recebem 26.
            if (quantidadeCopas == 13 && damaEspadas == 1)
            {
                pontosJogador1 -= 26;
                pontosJogador2 += 26;
                pontosJogador3 += 26;
                pontosJogador4 += 26;
                damaEspadas = 0;
            }
        }
        for (quantidadeCopas = 0, damaEspadas = 0; numCartasJogador2 >= 1; numCartasJogador2--)
        {
            scanf("%d-%c", &numCarta, &naipe);
            if (naipe == 'C')
            {
                quantidadeCopas++;
                pontosJogador2 += 1;
            }
            else if (numCarta == 12 && naipe == 'E')
            {
                pontosJogador2 += 13;
                damaEspadas = 1;
            }
            if (quantidadeCopas == 13 && damaEspadas == 1)
            {
                pontosJogador2 -= 26;
                pontosJogador1 += 26;
                pontosJogador3 += 26;
                pontosJogador4 += 26;
                damaEspadas = 0;
            }
        }
        for (quantidadeCopas = 0, damaEspadas = 0; numCartasJogador3 >= 1; numCartasJogador3--)
        {
            scanf("%d-%c", &numCarta, &naipe);
            if (naipe == 'C')
            {
                quantidadeCopas++;
                pontosJogador3 += 1;
            }
            else if (numCarta == 12 && naipe == 'E')
            {
                pontosJogador3 += 13;
                damaEspadas = 1;
            }
            if (quantidadeCopas == 13 && damaEspadas == 1)
            {
                pontosJogador3 -= 26;
                pontosJogador2 += 26;
                pontosJogador1 += 26;
                pontosJogador4 += 26;
                damaEspadas = 0;
            }
        }
        for (quantidadeCopas = 0, damaEspadas = 0; numCartasJogador4 >= 1; numCartasJogador4--)
        {
            scanf("%d-%c", &numCarta, &naipe);
            if (naipe == 'C')
            {
                quantidadeCopas++;
                pontosJogador4 += 1;
            }
            else if (numCarta == 12 && naipe == 'E')
            {
                pontosJogador4 += 13;
                damaEspadas = 1;
            }
            if (quantidadeCopas == 13 && damaEspadas == 1)
            {
                pontosJogador4 -= 26;
                pontosJogador2 += 26;
                pontosJogador3 += 26;
                pontosJogador1 += 26;
                damaEspadas = 0;
            }
        }
        printf("A: %d B: %d C: %d D: %d\n", pontosJogador1, pontosJogador2, pontosJogador3, pontosJogador4);
    } while (pontosJogador1 < 100 && pontosJogador2 < 100 && pontosJogador3 < 100 && pontosJogador4 < 100);

    // O programa deve continuar lendo rodadas e imprimindo o placar atualizado (pontuação atual somada à pontuação da rodada anterior) até o fim do jogo. Quando o jogo acabar, imprima qual jogador venceu o jogo e qual estourou 100 pontos no formato "Vencedor: jogador X; Ultimo Lugar: jogador Y", sendo X e Y a letra do respectivo jogador. Não haverá empates ou mais de um jogador estourando 100 pontos.

    if (pontosJogador1 > pontosJogador2 && pontosJogador1 > pontosJogador3 && pontosJogador1 > pontosJogador4)
    {
        ultimoLugar = 'A';
    }
    else if (pontosJogador2 > pontosJogador1 && pontosJogador2 > pontosJogador3 && pontosJogador2 > pontosJogador4)
    {
        ultimoLugar = 'B';
    }
    else if (pontosJogador3 > pontosJogador2 && pontosJogador3 > pontosJogador1 && pontosJogador3 > pontosJogador4)
    {
        ultimoLugar = 'C';
    }
    else
    {
        ultimoLugar = 'D';
    }

    if (pontosJogador1 < pontosJogador2 && pontosJogador1 < pontosJogador3 && pontosJogador1 < pontosJogador4)
    {
        primeiroLugar = 'A';
    }
    else if (pontosJogador2 < pontosJogador1 && pontosJogador2 < pontosJogador3 && pontosJogador2 < pontosJogador4)
    {
        primeiroLugar = 'B';
    }
    else if (pontosJogador3 < pontosJogador2 && pontosJogador3 < pontosJogador1 && pontosJogador3 < pontosJogador4)
    {
        primeiroLugar = 'C';
    }
    else if (pontosJogador4 < pontosJogador2 && pontosJogador4 < pontosJogador3 && pontosJogador4 < pontosJogador1)
    {
        primeiroLugar = 'D';
    }
    printf("Vencedor: jogador %c; Ultimo Lugar: jogador %c", primeiroLugar, ultimoLugar);
    return 0;
}