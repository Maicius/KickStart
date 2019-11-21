#include<iostream>
#include<queue>
using namespace std;
#define N 1000005

int T,cas,a[N],n;
priority_queue<int, vector<int>, greater<int> > Q;
/**
 * It is important for researchers to write many high quality academic papers. Jorge has recently discovered a way to measure how impactful a researcher's papers are: the H-index.

The H-index score of a researcher is the largest integer h such that the researcher has h papers with at least h citations each.

Input Sample: 

Input
 	
2
3
5 1 2
6
1 3 3 2 2 15

Output

Case #1: 1 1 2
Case #2: 1 1 2 2 2 3
 */ 
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
			Q.push(a[i]);
			int top = Q.top();

			if (Q.size() > top)
			{
				Q.pop();
			}
			printf("%d",Q.size());
			if (i==n) printf("\n");
			else printf(" ");
		}
	}
}