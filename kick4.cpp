#include<iostream>
#include<queue>
#include <algorithm>
typedef long long ll;
using namespace std;
vector<int> digits;
bool cal_digit(int *data, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0)
            sum += data[i];
        if (i % 2 != 0)
            sum -= data[i];
    }
    return sum % 11 == 0;
}
int main() {
    freopen("/Users/maicius/CLionProjects/leetcodeExe/1.txt", "r", stdin);
    int T, N;
    scanf("%d", &T);
    int temp;
    bool flag = true;
    for (int t = 0; t < T; t++) {
        printf("Case #%d:", t + 1);
        flag = true;
        for (int i = 0; i < 9;i++) {
            scanf("%d", &temp);
            for (int j =0; j < temp; j++) {
                digits.push_back(i + 1);
            }
        }
        int size = digits.size();
        int arr[digits.size()];
        for (int i = 0; i < size; i++) {
            arr[i] = digits[i];

        }
        if (cal_digit(arr, size)) printf(" YES\n");
        else {
            while (next_permutation(arr, arr + size)) {
                if (cal_digit(arr, size)){
                    printf(" YES\n");
                    flag = false;
                    break;
                }
            }
            if (flag) {
                printf(" NO\n");
            }
        }
        digits.clear();

    }
}

