/*
 Problem: 3797. Design Spreadsheet
 Language: cpp
 Runtime: 55 ms (86.19%)
 Memory: 123.3 MB (89.01%)
 Tags: Array, Hash Table, String, Design, Matrix
*/
class Spreadsheet {
private:
    unordered_map<string, int> cells;
    int rows;

int getCellValue(string str) {
        if (isdigit(str[0])) 
            return stoi(str);
        if (cells.find(str) != cells.end()) 
            return cells[str];
        return 0;
    }
public:
    Spreadsheet(int rows) {
        this->rows = rows;
    }

    void setCell(string cell, int value) {
        cells[cell] = value;
    }

    void resetCell(string cell) {
        cells[cell] = 0;
    }

    int getValue(string formula) {
        if (formula[0] != '=') 
            return stoi(formula);

        string X, Y;
        int plusPos = formula.find('+');
        X = formula.substr(1, plusPos - 1);
        Y = formula.substr(plusPos + 1);

        return getCellValue(X) + getCellValue(Y);
    }
};


/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */