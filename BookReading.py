# round G 2019 - Kick Start 2019
import sys
sys.stdin = open('BookReading.in', 'r')

# 算法复杂度 nlogn
def main():
    num = int(input())
    for i in range(num):
        M_N_Q = list(map(int, input().split(' ')))
        M = set(map(int, input().split(' ')))
        Q = list(map(int, input().split(' ')))
        res = 0
        for reader in range(M_N_Q[2]):
            for page in range(Q[reader], M_N_Q[0] + 1, Q[reader]):
                if page not in M:
                    res += 1
        print("Case #" + str(i + 1) + ":", res)

if __name__ =='__main__':
    main()