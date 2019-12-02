#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
struct points
{
    int x;
    int y;
};
// 平面中任意两个点，满足曼哈顿距离与欧式距离相等
int total(points a[], int len)
{
    unordered_map<int,unordered_set<int> > m;
    unordered_map<int,unordered_set<int> > m2;
    for(int i=0;i<len;i++)
    {
        int pos = a[i].x;
        m[pos].insert(a[i].y);
        pos = a[i].y;
        m2[pos].insert(a[i].x);
    }
    int ans=0;
    for(auto x : m)
    {
        int n = (x.second).size();
        if(n>1)
        {
            ans += ((n-1)*n)/2;
        }
    }
    for(auto x : m2)
    {
        int n = (x.second).size();
        if(n>1)
        {
            ans += ((n-1)*n)/2;
        }
    }
    return ans;
}
int main()
 {
	//code
	int testcases;
    freopen("CoincidingPoints.in", "r",stdin);
	cin>>testcases;
	vector<int> ans;
	for(int i=0;i<testcases;i++)
	{
	    int n;
	    cin>>n;
	    points a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i].x>>a[i].y;
	    ans.push_back(total(a,n));
	}
	for(auto x : ans)
	    cout<<x<<endl;
	return 0;
}