#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define pll pair<ll, ll>

const ll p1 = 31;
const ll m1 = (ll)1e9 + 7;
vector<ll> pow1;
const ll p2 = 53;
const ll m2 = (ll)1e9 + 9;
vector<ll> pow2;
// const ll ma = 1e6; // max string size
ll ma; 


struct pairhash 
{
public:
	template <typename T, typename U>
	std::size_t operator()(const std::pair<T, U>& x) const
	{
		return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
	}
};
 
class DoubleHash
{
private:
	ll n; // String Size
	//Hash 1
	vector<ll> h1;
	//Hash 2
	vector<ll> h2;
public:
	pll get(ll l, ll r)
	{
		//GET HASH 1
		ll fi = h1[r];
		if (l >= 1)
			fi = (fi - h1[l - 1] + m1) % m1;
		fi = (fi * pow1[ma - r - 1]) % m1;
		//GET HASH 2 
		ll se = h2[r];
		if (l >= 1)
            se = (se - h2[l - 1] + m2) % m2;
		se = (se * pow2[ma - r - 1]) % m2;
 
		return { fi,se };
	}
	DoubleHash(ll si, string& s)
	{
		n = si;
		//Init Pow
 
		// Create Hash
		h1.resize(n + 1);
		h2.resize(n + 1);
		h1[0] = ((s[0] - 'a' + 1) * pow1[0]) % m1;
		h2[0] = ((s[0] - 'a' + 1) * pow2[0]) % m2;
		for (ll i = 1; i <= n - 1; i++)
		{
			h1[i] = (h1[i - 1] + pow1[i] * (s[i] - 'a' + 1)) % m1;
			h2[i] = (h2[i - 1] + pow2[i] * (s[i] - 'a' + 1)) % m2;
		}
	}
};

bool check(DoubleHash hs, int len) {
    if (len == 0) return 1;

    pll cur;
    set <pll> kt;

    for (int i = 0; i < ma - len + 1; ++i) {
        cur = hs.get(i, i + len - 1);
        if (kt.count(cur)) return 1;
        kt.insert(cur); 
    }

    return 0;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    getline(cin, s);
    ma = s.size();

	pow1.resize(ma + 1);
	pow2.resize(ma + 1);
	pow1[0] = 1;
	pow2[0] = 1;
	for (ll i = 1; i <= ma; i++)
	{
		pow1[i] = (pow1[i - 1] * p1) % m1;
		pow2[i] = (pow2[i - 1] * p2) % m2;
	}

    DoubleHash hs(ma, s);

    int l = 1, r = ma - 1, ans;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }  else { r = mid - 1; }
    }

    cout << ans;
	return 0;
}
