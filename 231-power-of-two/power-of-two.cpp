/*
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int i,ans;
        for (i=0; i<=30; i++){
        ans= pow(2,i);
        if (ans==n){
            return true;
        }
    }
        return false;
    }
};
*/ 
// 2 approach to solve a problem 
class Solution {
public:
    bool isPowerOfTwo(int n) {
        for (int i=0; i<=30; i++){
        int ans= pow(2,i);
        if (ans==n){
            return true;
        }
    }
        return false;
    }
};
