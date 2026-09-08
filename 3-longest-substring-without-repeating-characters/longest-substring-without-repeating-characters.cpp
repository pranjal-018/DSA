class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Array to track character frequency in current window (ASCII characters)
        int charFrequency[128] = {0};
      
        // Initialize result and string length
        int maxLength = 0;
        int stringLength = s.size();
      
        // Sliding window approach with two pointers
        int left = 0;
        for (int right = 0; right < stringLength; ++right) {
            // Add current character to window
            ++charFrequency[s[right]];
          
            // Shrink window from left while duplicate exists
            while (charFrequency[s[right]] > 1) {
                // Remove leftmost character and move left pointer
                --charFrequency[s[left]];
                ++left;
            }
          
            // Update maximum length found so far
            // Current window size is (right - left + 1)
            maxLength = max(maxLength, right - left + 1);
        }
      
        return maxLength;
    }
};
