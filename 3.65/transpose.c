#define M 15

void transpose(long A[M][M]) {
    long i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < i; j++) {
            long t = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = t;
        }
    }
}

// A. 
// A[i][j] in %rdx, j++ = addq $8, %rdx
// B.
// A[j][i] in %rax, j++ = addq $120, %rax
// C.
// M = 15, 120/8 = 15, M = 15