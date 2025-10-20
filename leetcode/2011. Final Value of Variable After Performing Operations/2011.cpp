class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;

        for (const auto& ope : operations) {
            res = res + (ope[1] == '+' ? 1 : -1);
        }

        return res;
    }
};