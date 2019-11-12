#include<iostream>
using namespace std;

const int MAX = 1000;
int A[MAX];
int T, K, N;
int A_i, max_num = 0;

int main() {
    freopen("flattening.in", "r",stdin);
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d%d", &N, &K);
        for (int i = 0; i < N; i++) {
            scanf("%d", &A_i);
            A[A_i]++;
            if (A[A_i] > A[max_num]) max_num = A_i;
        }
        int op = N - A[max_num];
        int res = op <= K ? 0 : op - K;
        printf("Case #%d: %d\n",t+1, res);
        for (int i = 0; i < N; i++) A[i] = 0;
        max_num = 0;
    }
}