// see sum_col.s
#define NR(n) 3*n
#define NC(n) 4*n+1

long sum_col(long n, long A[NR(n)][NC(n)], long j) {
    long i;
    long result = 0;
    for (i = 0; i < NR(n); i++) {
        result += A[i][j];
    }
    return result;
}