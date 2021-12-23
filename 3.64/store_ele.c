#define R 7
#define S 5
#define T 13

long A[R][S][T];

long store_ele(long i, long j, long k, long *dest)
{
    *dest = A[i][j][k];
    return sizeof(A);
}

// A.
// A[i][j][k] = A + (k + j * T + i * S * T) * 8

// B.
// R = 7, S = 5, T = 13
// see store_ele.s