#include<iostream>
#define X first
#define Y second
#define mid ((l+r)>>1)
#define PB push_back
#define LB lower_bound

using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=1e5+10, M=1<<20|10;
const int mod=1e9+7;

int T,n,m,q,x;
int a[N],ans[N];
int main(){
    freopen("BookReading.in", "r",stdin); //输入重定向，输入数据将从D盘根目录下的in.txt文件中读取 
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++) {
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++) a[i]=1;
		for(int i=1;i<=m;i++) scanf("%d",&x),a[x]=0;
		for(int i=1;i<=n;i++) for(int j=i;j<=n;j+=i) ans[i]+=a[j];
		ll sum=0;
		for(int i=1;i<=q;i++) scanf("%d",&x),sum+=ans[x];
		printf("Case #%d: %lld\n",cas,sum);
		for(int i=1;i<=n;i++) a[i]=ans[i]=0;
	}
}