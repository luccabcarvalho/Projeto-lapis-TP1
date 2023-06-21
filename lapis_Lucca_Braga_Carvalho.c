#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

void trocaValor (int valorN, int matriz[valorN][valorN])
{
    int cor = 0;

    for (cor = 0; cor < 10; cor++)
    {
        for(int linha = 0; linha < valorN; linha++)
        {
            for(int coluna = 0; coluna < valorN; coluna++)
            {
                if (matriz[linha][coluna] == cor && matriz[linha][coluna] != 9)
                {
                    if (matriz[linha][coluna + 1] == -1) {
                        matriz[linha][coluna + 1] = cor + 1;
                    }

                    if (matriz[linha][coluna - 1] == -1) {
                        matriz[linha][coluna - 1] = cor + 1;
                    }

                    if (matriz[linha + 1][coluna] == -1) {
                        matriz[linha + 1][coluna] = cor + 1;
                    }

                    if (matriz[linha - 1][coluna] == -1) {
                        matriz[linha - 1][coluna] = cor + 1;
                    }

                }
            }
        }
    }

    for(int linha = 0; linha < valorN; linha++)
        {
            for(int coluna = 0; coluna < valorN; coluna++)
            {
                if (matriz[linha][coluna] == -1) {
                    matriz[linha][coluna] = 9;
                }

            }
        }

        printf("\nFolha quadriculada: \n");
        for(int linha = 0; linha < valorN; linha++)
        {
            for(int coluna = 0; coluna < valorN; coluna++)
            {
                printf("%d ", matriz[linha][coluna]);
            }
            printf("\n");
        }
        return 0;
}
int main()
{
    setlocale(LC_ALL, "Portuguese");

    int n, i, j, contador1 = 1, contador2 = 1;
    char val[2];

    printf("\nProblema Lápis de Cor\n");

    printf("\nA folha quadriculada tem dimensão N x N.\nN deve ser maior que 3 e menor que 50.\n");

    printf("\nInsira o valor de N: ");
    scanf("%d", &n);
    if (n < 3 || n > 50)
    {
        printf("\nERRO.");
        return 0;
    }

    char tabela[n][n];
    int tabelaInt[n][n];
    printf("\nInsira os valores da folha. Valores permitidos:\n0 para quadrados coloridos / * para quadrados não coloridos\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            fflush(stdin);
            printf("\nlinha %d / coluna %d: ", contador1, contador2);
            printf("\nInsira o caractere: ");
            gets(val);
            if (val[0] != '*' && val[0] != '0')
            {
                printf("\nERRO.");
                return 0;
            }
            tabela[i][j] = val[0];
            contador2++;
        }
        contador1++;
        contador2 = 1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (tabela[i][j] == '*')
                tabelaInt[i][j] = -1;
            else
                tabelaInt[i][j] = 0;
        }
    }

    trocaValor(n, tabelaInt);

    return 0;
}
