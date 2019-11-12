#include <algorithm>
#include <cmath>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
using namespace std;
typedef long long ll;
ll n;
ll gcd(ll x, ll y) { return y == 0 ? x : gcd(y, x % y); }
ll modpow(ll x, ll y, int z)
{
	ll ret = 1;
	for (; y; y >>= 1, x = x * x % z)
		if (y & 1)
			ret = ret * x % z;
	return ret;
}
int a[1000];
int f[200][200];
int mode[200][200];
int occ[3001];

int main()
{
	int T;
	cin >> T;
	for (int cas = 1; cas <= T; cas++) {
		int n, K;
		cin >> n >> K;
		for (int i = 1; i <= n; i++)cin >> a[i];
		for (int i = 1; i <= n; i++) {
			memset(occ, 0, sizeof occ);
			int sel = a[i];
			for (int j = i; j <= n; j++) {
				occ[a[j]]++;
				if (occ[a[j]] > occ[sel])
					sel = a[j];
				mode[i][j] = occ[sel];
			}
		}

		for (int i = 1; i <= n; i++) {
			f[i][1] = i - mode[1][i];
			for (int j = 2; j <= i; j++) {
				f[i][j] = f[i - 1][j - 1];
				for (int k = j-1; k <i; k++) {
					f[i][j] = min(f[i][j], f[k][j - 1] + i - k - mode[k + 1][i]);
				}
			}
		}
		printf("Case #%d: %d\n", cas, f[n][K + 1]);
	}
}