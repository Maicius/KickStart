#include<iostream>
using namespace std;
const int N=1e5+10;

int main() {
	freopen("BookReading.in", "r",stdin);
    int t, n, m ,q, r;
    int page[N], ans[N];
    long long res = 0;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++) {
        scanf("%d%d%d", &n, &m, &q);
        for (int j = 1; j <= n;j++) {
            page[j] = 1;
        }
        int torn;
        for (int j = 1; j <= m; j++) {
            scanf("%d", &torn);
            page[torn] = 0;
        }
        
		// for (int j = 1; j <= n; j++) {
        //     for (int k = j; k <= n; k += j) {
        //         ans[j] += page[k];
        //     } 
        // }
        // for (int j = 0; j < q; j++){
        //     scanf("%d", &r);
        //     res += ans[r];
        // }

		for(int i=1;i<=n;i++) for(int j=i;j<=n;j += i) ans[i]+=page[j];
		long long sum=0;
		for(int i=1;i<=q;i++) scanf("%d",&r),sum+=ans[r];
		
		printf("Case #%d: %lld\n", cas, sum);
		for (int j = 1; j <= n;j++) {
            page[j] = 0;
			ans[j] = 0;
        }
    }
}
            
