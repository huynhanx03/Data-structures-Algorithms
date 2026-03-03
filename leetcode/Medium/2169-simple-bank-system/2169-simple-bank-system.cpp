/*
 Problem: 2169. Simple Bank System
 Language: cpp
 Runtime: 11 ms (67.01%)
 Memory: 123.8 MB (29.28%)
 Tags: Array, Hash Table, Design, Simulation
*/
class Bank {
    vector<long long> bal;
public:
    Bank(vector<long long>& balance) {
        bal = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 < 1 || account1 > bal.size() || account2 < 1 || account2 > bal.size())
            return false;
        if(bal[account1-1] < money)
            return false;
        bal[account1-1] -= money;
        bal[account2-1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account < 1 || account > bal.size())
            return false;
        bal[account-1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account < 1 || account > bal.size())
            return false;
        if(bal[account-1] < money)
            return false;
        bal[account-1] -= money;
        return true;
    }
};
