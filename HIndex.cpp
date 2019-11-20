#include<iostream>
#include<queue>
using namespace std;
#define N 1000005

int T,cas,a[N],n;
priority_queue<int, vector<int>, greater<int> > Q;

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		while (!Q.empty()) Q.pop();
		printf("Case #%d: ",++cas);
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++)
		{
			Q.push(-a[i]);
			int top=-Q.top();
			if (Q.size()>top)
			{
				Q.pop();
			}
			printf("%d",Q.size());
			if (i==n) printf("\n");
			else printf(" ");
		}
	}
}