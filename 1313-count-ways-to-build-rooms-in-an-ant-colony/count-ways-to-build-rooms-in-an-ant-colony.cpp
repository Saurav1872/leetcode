class Solution {
public:
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
        vector<vector<int>> g(n);
        for (int i = 1; i < n; ++i) {
            g[prevRoom[i]].push_back(i);
        }

        fact.resize(n+1, 1);
        fact[0] = 1;
        for(int i=1; i <= n; ++i) {
            fact[i] = (fact[i-1] * i) % MOD;
        }

        invFact.resize(n+1, 1);
        invFact[n] = pow(fact[n], MOD - 2);
        for (int i = n - 1; i >= 1; --i) {
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
        }


        return dfs(g, 0).first;
    }

private:
    const long long MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    pair<long long, long long> dfs(const vector<vector<int>>& g, int curr) {
        if (g[curr].size() == 0) {
            return {1, 1}; // 1 topo sort soln, 1 elements in ans
        }

        long long ans = 1, l = 0;
        for (int node : g[curr]) {
            auto [temp, r] = dfs(g, node);
            ans = ((ans * temp % MOD) * nCr(l + r, r)) % MOD;
            l += r; // add elements in curr subtree
        }

        return {ans, l + 1};
    }

    long long nCr(int n, int r) {
        if (r > n)
            return 0;
        // long long res = 1;
        // for (int i = 0; i < r; i++) {
        //     res = res * (n - i) % MOD;
        //     res = res * pow(i + 1, MOD - 2) % MOD;
        // }
        // return res;

        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    long long pow(long long base, long long exp) {
        long long ans = 1;
        while (exp > 0) {
            if (exp % 2 == 1) 
                ans = (ans * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return ans;
    }
};