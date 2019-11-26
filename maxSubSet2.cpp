#include<iostream>
#include<vector>
using namespace std;

int dp[1024]; 

// Function to create mask for every number 
int get_binary(int u) 
{ 
	int ans = 0; 
	while (u) { 
		int rem = u % 10; 
		ans |= (1 << rem); 
		u /= 10; 
	} 

	return ans; 
} 

// Recursion for Filling DP array 
int recur(int u, vector<int> &array, int n) 
{ 
	// Base Condition 
	if (u == 0) 
		return 0; 
	if (dp[u] != -1) 
		return dp[u]; 

	int temp = 0; 
	for (int i = 0; i < n; i++) { 
		int mask = get_binary(array[i]); 
		// Recurrence Relation 
		if ((mask | u) == u) { 
			dp[u] = max(max(0, 
					dp[u ^ mask]) + array[i], dp[u]); 
		} 
	} 

	return dp[u]; 
} 

// Function to find Maximum Subset Sum 
int solve(vector<int> &array, int n) 
{ 
	// Initialize DP array 
	for (int i = 0; i < (1 << 10); i++) { 
		dp[i] = -1; 
	} 

	int ans = 0; 

	// Iterate over all possible masks of 10 bit number 
	for (int i = 0; i < (1 << 10); i++) { 
		ans = max(ans, recur(i, array, n)); 
	} 

	return ans; 
}

int main() {
   freopen("maxSubSet.txt", "r",stdin);
   int T, N, temp;
   vector<int> res;
   scanf("%d", &T);
   while(T--) {
    scanf("%d", &N);
    for(int i = 0; i <N;i++) {
       scanf("%d", &temp);
       res.push_back(temp);
    }
    int ans = solve(res, res.size());
    printf("%d\n", ans);
    res.clear();
  }
}