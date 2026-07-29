class Solution {
public:
    static const int LIMIT = 1000001;

    long long C(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);
        long long ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans >= LIMIT) return LIMIT;
        }
        return ans;
    }

    long long countWays(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt) total += x;

        long long ans = 1;
        int rem = total;
        for (int x : cnt) {
            if (x == 0) continue;
            ans *= C(rem, x);
            if (ans >= LIMIT) return LIMIT;
            rem -= x;
        }
        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        vector<int> half(26, 0);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] & 1)
                mid = char('a' + i);
        }

        if (countWays(half) < k)
            return "";

        string left;
        int len = 0;
        for (int x : half) len += x;

        while ((int)left.size() < len) {
            for (int i = 0; i < 26; i++) {
                if (half[i] == 0) continue;

                half[i]--;
                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back('a' + i);
                    break;
                } else {
                    k -= ways;
                    half[i]++;
                }
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};
