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

/*
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
*/

// 3 approach to solve a problem which is efficient approach the first two is brute force approach

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int ans=1;
        for (int i=0; i<=30; i++){
        if (ans==n){
            return true;
        }
        if(ans<INT_MAX/2){
        ans= ans * 2;
        }
    }
        return false;
    }
};

