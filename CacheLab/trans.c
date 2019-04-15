/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 

/*
 * parameter s = 5 E = 1 b = 5
 * so it has 2 ^ 5 cache groups
 * each group has 1 line
 * so it's 32 lines in total
 * each lines have 2 ^ 5 bytes => 8 ints
 * so one cache can accommodate 256 ints
 */

#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    //attention : A[N][M] B[M][N]
    //12个int变量，4个用来循环，其余8个用来存A中块的一行
    int a, b, c, d;
    int temp0, temp1, temp2, temp3, temp4, temp5, temp6, temp7;
    if (M == 61 && N == 67)
    {
        for (a = 0; a < N; a += 23)
        {
            for (b = 0; b < M; b += 23)
            {
                for (c = a; (c < a + 23) && c < N; c++)
                {
                    for (d = b; (d < b + 23) && d < M; d++)
                    {
                        B[d][c] = A[c][d];
                    }
                }
            }
        }
    }
    else if (M == 32 && N == 32)
    {
        for (a = 0; a < N; a += 8)
        {
            for (b = 0; b < M; b += 8)
            {
                for (c = a; c < a + 8; c++)
                {
                    temp0 = A[c][b + 0];
                    temp1 = A[c][b + 1];
                    temp2 = A[c][b + 2];
                    temp3 = A[c][b + 3];
                    temp4 = A[c][b + 4];
                    temp5 = A[c][b + 5];
                    temp6 = A[c][b + 6];
                    temp7 = A[c][b + 7];
                    B[b + 0][c] = temp0;
                    B[b + 1][c] = temp1;
                    B[b + 2][c] = temp2;
                    B[b + 3][c] = temp3;
                    B[b + 4][c] = temp4;
                    B[b + 5][c] = temp5;
                    B[b + 6][c] = temp6;
                    B[b + 7][c] = temp7; 
                }
            }
        }
    }
    else if (M == 64 && N == 64)
    {
        for (a = 0; a < 32; a += 8)
        {
            for (b = 0; b < 32; b += 8)
            {
                for (c = a; c < a + 8; c++)
                {
                    temp0 = A[c][b + 0];
                    temp1 = A[c][b + 1];
                    temp2 = A[c][b + 2];
                    temp3 = A[c][b + 3];
                    temp4 = A[c][b + 4];
                    temp5 = A[c][b + 5];
                    temp6 = A[c][b + 6];
                    temp7 = A[c][b + 7];
                    B[b + 0][c] = temp0;
                    B[b + 1][c] = temp1;
                    B[b + 2][c] = temp2;
                    B[b + 3][c] = temp3;
                    B[b + 4][c] = temp4;
                    B[b + 5][c] = temp5;
                    B[b + 6][c] = temp6;
                    B[b + 7][c] = temp7;
                }
            }
        }
        for (a = 32; a < 64; a += 8)
        {
            for (b = 32; b < 64; b += 8)
            {
                for (c = a; c < a + 8; c++)
                {
                    temp0 = A[c][b + 0];
                    temp1 = A[c][b + 1];
                    temp2 = A[c][b + 2];
                    temp3 = A[c][b + 3];
                    temp4 = A[c][b + 4];
                    temp5 = A[c][b + 5];
                    temp6 = A[c][b + 6];
                    temp7 = A[c][b + 7];
                    B[b + 0][c] = temp0;
                    B[b + 1][c] = temp1;
                    B[b + 2][c] = temp2;
                    B[b + 3][c] = temp3;
                    B[b + 4][c] = temp4;
                    B[b + 5][c] = temp5;
                    B[b + 6][c] = temp6;
                    B[b + 7][c] = temp7;
                }
            }
        }
        for (a = 32; a < 64; a += 8)
        {
            for (b = 0; b < 32; b += 8)
            {
                for (c = a; c < a + 8; c++)
                {
                    temp0 = A[c][b + 0];
                    temp1 = A[c][b + 1];
                    temp2 = A[c][b + 2];
                    temp3 = A[c][b + 3];
                    temp4 = A[c][b + 4];
                    temp5 = A[c][b + 5];
                    temp6 = A[c][b + 6];
                    temp7 = A[c][b + 7];
                    B[b + 0][c] = temp0;
                    B[b + 1][c] = temp1;
                    B[b + 2][c] = temp2;
                    B[b + 3][c] = temp3;
                    B[b + 4][c] = temp4;
                    B[b + 5][c] = temp5;
                    B[b + 6][c] = temp6;
                    B[b + 7][c] = temp7;
                }
            }
        }
        for (a = 0; a < 32; a += 8)
        {
            for (b = 32; b < 64; b += 8)
            {
                for (c = a; c < a + 8; c++)
                {
                    temp0 = A[c][b + 0];
                    temp1 = A[c][b + 1];
                    temp2 = A[c][b + 2];
                    temp3 = A[c][b + 3];
                    temp4 = A[c][b + 4];
                    temp5 = A[c][b + 5];
                    temp6 = A[c][b + 6];
                    temp7 = A[c][b + 7];
                    B[b + 0][c] = temp0;
                    B[b + 1][c] = temp1;
                    B[b + 2][c] = temp2;
                    B[b + 3][c] = temp3;
                    B[b + 4][c] = temp4;
                    B[b + 5][c] = temp5;
                    B[b + 6][c] = temp6;
                    B[b + 7][c] = temp7;
                }
            }
        }
    }
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */

char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc);

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

