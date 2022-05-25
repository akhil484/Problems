class Solution {
public:
    int totalStrength(vector<int>& str) {
        int mod=1000000007;
        int n = str.size();
        vector<int> prev (n);
        vector<int> next (n);
        
        stack<int> s;
        for (int j = 0; j < n; j ++) {
            while (!s.empty() && str[s.top()] > str[j]) s.pop();
            prev[j] = s.empty()? -1 : s.top();
            s.push(j);
        }
        
        while (!s.empty()) s.pop();
        for (int j = n-1; j >= 0; j --) {
            while (!s.empty() && str[s.top()] >= str[j]) s.pop();
            next[j] = s.empty()? n : s.top();
            s.push(j);
        }
        
        vector<long long int> pref(n+2);
        for (int j = 1; j <= n; j ++) {
            pref[j] = (pref[j-1] + str[j-1]) % mod;
        }
        vector<long long int> pref_pref (n+2);
        for (int j = 1; j <= n; j ++) {
            pref_pref[j] = (pref_pref[j-1] + pref[j]) % mod;
        } 
        
        long long int ans = 0;
        for (int j = 1; j <= n; j ++) {
            int prv = prev[j-1]+1, nxt = next[j-1]+1;
            
            long long int minus = (pref_pref[j-1] - (prv == 0? 0 : pref_pref[prv-1]) + mod) % mod;
            long long int plus = (pref_pref[nxt-1] - pref_pref[j-1] + mod) % mod;
            
            long long int before = j - prv;
            long long int after = nxt - j;
            long long int total = ((plus * before) % mod - (minus * after) % mod  + mod) % mod;
            
            // cout << j << " " << str[j-1] << " --> " << prv << " " << nxt << ": " << total << " " << minus << " " << plus << endl;
            
            ans = (ans + (total * str[j-1]) % mod) % mod;
        }
        
        return ans;
    }
};