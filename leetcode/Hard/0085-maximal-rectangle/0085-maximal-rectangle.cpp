/*
 Problem: 85. Maximal Rectangle
 Language: cpp
 Runtime: 3 ms (86.93%)
 Memory: 17.5 MB (74.36%)
 Tags: Array, Dynamic Programming, Stack, Matrix, Monotonic Stack
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            stack<int> st;
            for (int j = 0; j <= cols; j++) {
                int currHeight = (j == cols) ? 0 : heights[j];

                while (!st.empty() && currHeight < heights[st.top()]) {
                    int h = heights[st.top()];
                    st.pop();
                    int width = st.empty() ? j : j - st.top() - 1;
                    maxArea = max(maxArea, h * width);
                }
                st.push(j);
            }
        }

        return maxArea;
    }
};
