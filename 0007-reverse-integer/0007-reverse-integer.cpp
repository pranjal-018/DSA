class Solution {
public:
    int reverse(int x) {
        int reversedNumber = 0;
      
        // Process each digit of the input number
        while (x != 0) {
            // Check for potential overflow before multiplying by 10
            // INT_MAX = 2147483647, INT_MIN = -2147483648
            // If reversedNumber > INT_MAX/10, then reversedNumber * 10 will overflow
            // If reversedNumber < INT_MIN/10, then reversedNumber * 10 will underflow
            if (reversedNumber > INT_MAX / 10 || reversedNumber < INT_MIN / 10) {
                return 0;
            }
          
            // Extract the last digit and append it to the reversed number
            int lastDigit = x % 10;
            reversedNumber = reversedNumber * 10 + lastDigit;
          
            // Remove the last digit from the original number
            x /= 10;
        }
      
        return reversedNumber;
    }
};