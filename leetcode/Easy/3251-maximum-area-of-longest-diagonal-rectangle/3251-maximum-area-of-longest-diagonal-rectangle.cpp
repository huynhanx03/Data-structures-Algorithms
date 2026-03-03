/*
 Problem: 3251. Maximum Area of Longest Diagonal Rectangle
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 29.3 MB (75.51%)
 Tags: Array
*/
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonalSquare = 0, maxArea = 0;

        for (const auto& rectangle : dimensions) {
            int length = rectangle[0], width = rectangle[1];
            int diagonalSquare = length * length + width * width;
            int area = length * width;

            if (diagonalSquare > maxDiagonalSquare || 
                (diagonalSquare == maxDiagonalSquare && area > maxArea)) {
                maxDiagonalSquare = diagonalSquare;
                maxArea = area;
            }
        }

        return maxArea;
    }
};