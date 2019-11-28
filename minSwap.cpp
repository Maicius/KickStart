#include<iostream>
#include<vector>
using namespace std;

int count1 = 0;

void merge(int *data, int low, int upper) {
  int len = upper - low + 1;
  int temp[len];
  int mid = (low + upper) / 2;
  int i = 0;
  int p1 = low, p2 = mid + 1;
  while(p1 <= mid && p2 <= upper) {
    if (data[p1] < data[p2]) {
      temp[i++] = data[p1++];
    } else {
      temp[i++] = data[p2++];
      count1 += mid - p1 + 1;
    }

  }
  while (p1 <= mid) {
      temp[i++] = data[p1++];
  }
  while(p2 <= upper) {
      temp[i++] = data[p2++];
    }
    for(int i = 0; i < len; i++) {
      data[low + i] = temp[i];
    }
}

void merge_sort(int *data, int low, int upper) {
  if (low == upper) return;
  int mid = (low + upper) / 2;
  merge_sort(data, low, mid);
  merge_sort(data, mid + 1, upper);
  merge(data, low, upper);
}

int main(){
  int t, n, temp;
  freopen("minSwap.in", "r",stdin);
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    int data[n];
    for(int i = 0; i < n;i++) {
 	  scanf("%d", &temp);
      data[i] = temp;
    }
    merge_sort(data, 0, n - 1);
    cout << count1 << endl;
    count1 = 0;
  }
}