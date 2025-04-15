#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void setBoardShip(int board[10][10], int shipOrEvent[3][2]){
  for (int i = 0; i < 3; i++) {
    int x = shipOrEvent[i][0];
    int y = shipOrEvent[i][1];

    if (x >= 0 && x < 10 && y >= 0 && y < 10 && board[x][y] == 0) {
      board[x][y] = 3; //marca o navio na posição
    }
  }
}

void setBoardAttack(int board[10][10], int centerAttack[1][2], int pattern[3][5]) {
  int centerX = centerAttack[0][0]; //posição central do ataque eixoX
  int centerY = centerAttack[0][1]; //posição central do ataque eixoY

  for (int row = 0; row < 5; row++) {   
      for (int col = 0; col < 3; col++) {
          int offsetX = row - 1;  //obtendo o mais próximo do centro possível
          int offsetY = col - 2;  //obtendo o mais próximo do centro possível

          int x = centerX + offsetX;
          int y = centerY + offsetY;

          if(pattern[col][row] == 1) {  //marca se somente fizer parte do desenho da habilidade
            if (x >= 0 && x < 10 && y >= 0 && y < 10) {//verifica se esta dentro no board
                board[x][y] = pattern[col][row]; //marca a posição da habilidade
            }
          }
      }
  }
}

int main()
{
  // Nível Novato - Posicionamento dos Navios
  // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
  // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
  // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

  int board[10][10] = {0};
  int shipX[3][2] = {{3, 3}, {4, 4}, {5, 5}};
  int shipY[3][2] = {{0, 0}, {1, 1}, {2, 2}};

  setBoardShip(board, shipX);
  setBoardShip(board, shipY);

  // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
  // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
  // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
  // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

  int shipXY1[3][2] = {{6, 6}, {7, 7},{8, 8}};
  int shipXY2[3][2] = {{9, 0}, {8, 1},{7, 2}};
  setBoardShip(board, shipXY1);
  setBoardShip(board, shipXY2);

  // Nível Mestre - Habilidades Especiais com Matrizes
  // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
  // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
  // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

  // Exemplos de exibição das habilidades:
  // Exemplo para habilidade em cone:
  // 0 0 1 0 0
  // 0 1 1 1 0
  // 1 1 1 1 1
  int coneAttack[1][2] = {{1, 9}};
  int coneAttackPattern [3][5] = {
    {0,0,1,0,0},
    {0,1,1,1,0},
    {1,1,1,1,1}
  };
  setBoardAttack(board, coneAttack, coneAttackPattern);
  
  // Exemplo para habilidade em cruz:
  // 0 0 1 0 0
  // 1 1 1 1 1
  // 0 0 1 0 0
  
  int crossAttack [1][2] = {{1, 5}};
  int crossAttackPattern [3][5] = {
    {0,0,1,0,0},
    {1,1,1,1,1},
    {0,0,1,0,0}
  };
  setBoardAttack(board, crossAttack, crossAttackPattern);
  // Exemplo para habilidade em octaedro:
  // 0 0 1 0 0
  // 0 1 1 1 0
  // 0 0 1 0 0
  int octahedronAttack [1][2] = {{5,6}};
  int octahedronAttackPattern [3][5] = {
    {0,0,1,0,0},
    {0,1,1,1,0},
    {0,0,1,0,0}
  };
  setBoardAttack(board, octahedronAttack, octahedronAttackPattern);

  for (int y = 0; y < 10; y++) {
    for (int x = 0; x < 10; x++)
      printf("%s ", (board[x][y] == 0 ? "0 " : (board[x][y] == 3 ? "3 " : (board[x][y] == 1 ? "5 " : "! "))));
    printf("\n");
  }
  return 0;
}
