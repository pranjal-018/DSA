class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n!=0) {

            //check karega last bit ko
            if(n&1) {
                count++;
            }
            n= n>>1;
        }
            return count;
    } 
};