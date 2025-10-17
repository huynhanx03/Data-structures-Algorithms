#include "bits/stdc++.h"

#define ll long long

using namespace std;
class heap
{
private:
    int n;
    vector <ll> h;
public:
    void init()
    {
        cin >> n;
        h.resize(n);
        for (int i = 0; i < n; ++i) cin >> h[i];
    }
    void min_heap(int i)
    {
        int smallest = i, l = 2*i + 1, r = 2*i + 2;
        if (l < h.size() && h[l] < h[smallest]) smallest = l;
        if (r < h.size() && h[r] < h[smallest]) smallest = r;
        if (smallest  != i)
        {
            swap(h[i], h[smallest]);
            min_heap(smallest);
        }
    }
    void build_heap()
    {
        for (int i = n/2 - 1 ; i >= 0; --i) min_heap(i);
    }
    ll top_heap()
    {
        return h[0];
    }
    void push_heap(ll value)
    {
        h.push_back(value);
        int i = h.size() - 1;
        while (i != 0 && h[(i - 1)/2] > h[i])
        {
            swap(h[i], h[(i - 1)/2]);
            i = (i - 1) / 2;
        }
    }
    void pop_heap()
    {
        int length = h.size();
        if (length == 0) return;
        h[0] = h[length-1];
        h.pop_back();
        min_heap(0);
    }
    void sol()
    {
        build_heap();
        while (h.size())
        {
            cout << top_heap() << ' ';
            pop_heap();
        }
    }
};
int32_t main() 
{
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    heap he;
    
    return 0;
}