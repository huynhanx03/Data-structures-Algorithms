#include <bits/stdc++.h>
using namespace std;

const string NAME = "main";
const int NTEST = 1000;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd
    
long long Rand(long long L, long long R)
{
    assert(L <= R);
    return L + rd() % (R - L + 1);
}

int main()
{
    int w = 0;
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());

        int n = Rand(1, 10);
        for (int i = 0; i < n; i++)
        {
            inp << (char)('A' + Rand(0, 1));
        }

        inp.close();

        system((NAME + ".exe").c_str());
        system((NAME + "_trau.exe").c_str());

        ifstream outFile((NAME + ".out").c_str());
        ifstream ansFile((NAME + ".ans").c_str());

        string outContent, ansContent;
        getline(outFile, outContent, '\0');
        getline(ansFile, ansContent, '\0');

        if (outContent != ansContent)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            ++w;
            return 0;
        } else {
            // cout << "Test " << iTest << ": CORRECT!\n";
        }
    }

    cout << "WRONG: " << w << "/" << NTEST << "\n";
    return 0;   
}