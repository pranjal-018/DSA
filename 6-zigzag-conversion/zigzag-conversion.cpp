class Solution {
public:
    string convert(string s, int numRows) {
       
        if (numRows == 1) {
            return s;
        }
      
        
        vector<string> rows(numRows);
      
        
        int currentRow = 0;
        int direction = -1;
      
        // Iterate through each character in the input string
        for (char ch : s) {
            // Add current character to the appropriate row
            rows[currentRow] += ch;
          
            // Change direction when reaching the top row (0) or bottom row (numRows - 1)
            if (currentRow == 0 || currentRow == numRows - 1) {
                direction = -direction;
            }
          
            // Move to the next row based on current direction
            currentRow += direction;
        }
      
        // Concatenate all rows to form the final result
        string result;
        for (const auto& row : rows) {
            result += row;
        }
      
        return result;
    }
};