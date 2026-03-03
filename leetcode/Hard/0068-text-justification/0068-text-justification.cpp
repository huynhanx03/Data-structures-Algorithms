/*
 Problem: 68. Text Justification
 Language: cpp
 Runtime: 0 ms (100.00%)
 Memory: 9.4 MB (100.00%)
 Tags: Array, String, Simulation
*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        // initalize our variables
        vector<string> result;  // output vector
        int i = 0;  // index to loop through words
        int n = words.size();   // total number of words

        // loop through the words
        while (i < n) {
            int j = i;  // current word
            int line_length = 0; // length of the words in current line

            /* loop to  keep adding words until the line length with spaces (lineLength + (j - i)) exceeds maxWidth */ 
            while(j < n && line_length + words[j].size() + (j - i) <= maxWidth) {
                line_length += words[j].size(); // add this word to the size of our line;
                j++; // move to next word
            }

            // create justified line
            string line;
            int to_fill = maxWidth - line_length; // number of characters thats need to be ' '

            /* populate the line */
            // loop through all words on line
            for(int k = i; k < j; k++) {
                line += words[k]; // add the words

                /* Dealing with spaces*/
                if(to_fill > 0) {
                    int count;
                    // left aligmnet for last line
                    if(j == n) {
                        // if its last word in last line, add one space for normal spaces, add rest for final right space
                        count = (k == j - 1) ? to_fill : 1;   
                    }
                    // normal left and right justified lines
                    else {
                        // we are on last word of line, so all remaning spaces should be added
                        if(j - 1 - k == 0) count = to_fill;
                        // not last word of line, round up if cant distrubute evently since extra spaces should be on left
                        else {
                            count = ceil((double) to_fill / (j - 1 - k));
                        }
                    }
                    // add space of required size after the word
                    line += string(count, ' ');
                    to_fill -= count; // decrease number of spaces to fill
                }
            }
            result.push_back(line); // add the construced line to output
            i = j; // move i to next word to look at for next line, skipping all the words just added
        }
        return result;
    }
};