#include<iostream>
#include<queue>

typedef long long ll;
using namespace std;

vector<ll> score;

int main() {
    freopen("/Users/maicius/CLionProjects/leetcodeExe/1.txt", "r", stdin);
    int T, N;
    scanf("%d", &T);
    char temp;
    for (int t = 0; t < T; t++) {
        scanf("%d", &N);
        bool square[N][N];
        vector<vector<int> > index;
        printf("Case #%d: ", t + 1);
        for (int i = 0; i < N;i++) {
            for (int j = 0; j < N; j++) {
                scanf("%c", &temp);
                if (temp == '#') {
                    square[i][j] = true;
                } else {
                    square[i][j] = false;
                    vector<int> in;
                    in.push_back(i);
                    in.push_back(j);
                    index.push_back(in);
                }
            }
        }
        if (index.empty()) {
            printf("0\n");
        }
        while (!index.empty()) {
            int i = 0, j = 0;
            while (i < N && j < N) {
                if (!square[i][j]) {
                    int l = i, r = j;
                    while (l < N && r < N) {
                        
                    }
                }
            }
        }
    }
}