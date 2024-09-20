#include "bits/stdc++.h"

using namespace std;

void solve()
{
  int n;
  cin >> n;

  vector <int> v(n);

  for (int& x: v)
    cin >> x;

  vector <int> nv = v;

  sort(nv.begin(), nv.end());
  nv.erase(unique(nv.begin(), nv.end()), nv.end());

  for (int& x : v) {
    int pos = lower_bound(nv.begin(), nv.end(), x) - nv.begin();
    x = pos;  
  }

  for (int& x : v)
    cout << x << " ";
}

int32_t main()
{
  solve();

  return 0;
}