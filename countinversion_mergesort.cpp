#include <iostream>
#include <cstdio>

using namespace std;

long long ans = 0;
void mergei(int a[], int st, int ed) {
  int mid = (st + ed) >> 1;
  int i = st;
  int *arr = new int[ed - st + 1];
  //int s = st;
  int j = mid + 1;
  int k = 0;
  while (i <= mid && j <= ed) {
    if (a[i] <= a[j]) {
      arr[k++] = a[i++];

    } else {
      arr[k++] = a[j++];
      ans += ((mid + 1) - i);
    }
  }
  for (; i <= mid;)
    arr[k++] = a[i++];
  for (; j <= ed;)
    arr[k++] = a[j++];
  for (int k = 0, s = st; s <= ed;)
    a[s++] = arr[k++];
  delete[] arr;
}

void m_sort(int a[], int st, int ed) {
  if (st < ed) {
    int mid = (st + ed) >> 1;
    m_sort(a, st, mid);
    m_sort(a, mid + 1, ed);
    mergei(a, st, ed);
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    ans = 0;
    scanf("%d", &n);
    int *a = new int[n];
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    m_sort(a, 0, n - 1);
    cout << ans << endl;
  }
  return 0;
}