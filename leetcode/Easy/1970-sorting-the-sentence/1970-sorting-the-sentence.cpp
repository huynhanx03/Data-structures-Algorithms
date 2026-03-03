/*
 Problem: 1970. Sorting the Sentence
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 6.4 MB (100.00%)
 Tags: String, Sorting
*/
class Solution {
public:
    string sortSentence(string s) {
        string c="";
        s+=' ';
        vector<pair<int,string>> a;
        for (int i=0;i<s.size();++i)
        {
            if (s[i]==' ' || i==s.size()-1)
            {
                int l=c.size();
                string k="";
                int num=c[l-1]-'0';
                for (int j=0; j<l-1;++j) k+=c[j];
                a.push_back({num,k});
                c="";
                continue;
            }
            c+=s[i];
        }
        sort(a.begin(), a.end());
        string ans="";
        for(int i=0; i<a.size()-1;++i) ans+=a[i].second+' ';
        ans+=a[a.size()-1].second;
        return ans;
    }
};