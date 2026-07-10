class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b){ return nums[a] < nums[b]; });

        vector<int> sortedVal(n), pos(n); 
        for (int i = 0; i < n; i++) {
            sortedVal[i] = nums[idx[i]];
            pos[idx[i]] = i;
        }

       
        vector<int> comp(n);
        int c = 0;
        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            if (sortedVal[i] - sortedVal[i - 1] > maxDiff) c++;
            comp[i] = c;
        }

       
        vector<int> nxt(n);
        int r = 0;
        for (int i = 0; i < n; i++) {
            if (r < i) r = i;
            while (r + 1 < n && sortedVal[r + 1] - sortedVal[i] <= maxDiff) r++;
            nxt[i] = r;
        }

        
        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        LOG++;
        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = nxt;
        for (int k = 1; k < LOG; k++)
            for (int i = 0; i < n; i++)
                up[k][i] = up[k - 1][up[k - 1][i]];

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto &q : queries) {
            int u = q[0], v = q[1];
            int pu = pos[u], pv = pos[v];
            if (pu > pv) swap(pu, pv);

            if (comp[pu] != comp[pv]) { ans.push_back(-1); continue; }
            if (pu == pv) { ans.push_back(0); continue; }

            int cur = pu, steps = 0;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < pv) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }
            steps += 1; 
            ans.push_back(steps);
        }
        return ans;
    }
};