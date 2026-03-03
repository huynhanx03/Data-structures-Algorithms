/*
 Problem: 84. Largest Rectangle in Histogram
 Language: cpp
 Runtime: 110 ms (5.11%)
 Memory: 78.2 MB (100.00%)
 Tags: Array, Stack, Monotonic Stack
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<int> stack;
        stack.push(-1);
        int max_area = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (stack.top() != -1 && heights[i] <= heights[stack.top()]) {
                int height = heights[stack.top()];
                stack.pop();
                int width = i - stack.top() - 1;
                max_area = std::max(max_area, height * width);
            }
            stack.push(i);
        }

        while (stack.top() != -1) {
            int height = heights[stack.top()];
            stack.pop();
            int width = heights.size() - stack.top() - 1;
            max_area = std::max(max_area, height * width);
        }

        return max_area;        
    }
};