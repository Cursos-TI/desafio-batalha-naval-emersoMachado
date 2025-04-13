#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main()
{
  // Nível Novato - Posicionamento dos Navios
  // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
  // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
  // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

  int board[10][10] = {0};
  int shipX[3] = {3, 4, 5};
  int shipY[3] = {0, 1, 2};
  int shipXY1[3][2] = {{6, 6}, {7, 7},{8, 8}};
  int shipXY2[3][2] = {{9, 0}, {8, 1},{7, 2}};

  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      int isShipFound = 0;

      for (int x = 0; x < 3; x++)
      {
        if (shipX[x] == j && i == 0)
          isShipFound = 1;
        else if (shipY[x] == i && j == 0)
          isShipFound = 1;
        else if(shipXY1[x][0] == j && shipXY1[x][1] == i)
          isShipFound = 1;
        else if(shipXY2[x][0] == j && shipXY2[x][1] == i)
          isShipFound = 1;
      }

      if (isShipFound == 0)
        printf("0s ");
      else
        printf("3s ");
    }
    printf("\n");
  }
  // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
  // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
  // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
  // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

  // Nível Mestre - Habilidades Especiais com Matrizes
  // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
  // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
  // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

  // Exemplos de exibição das habilidades:
  // Exemplo para habilidade em cone:
  // 0 0 1 0 0
  // 0 1 1 1 0
  // 1 1 1 1 1

  // Exemplo para habilidade em octaedro:
  // 0 0 1 0 0
  // 0 1 1 1 0
  // 0 0 1 0 0

  // Exemplo para habilidade em cruz:
  // 0 0 1 0 0
  // 1 1 1 1 1
  // 0 0 1 0 0

  return 0;
}
