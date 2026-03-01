class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> res(n, n);  // initialize with large value
        
        int pos = -n;

        // Left to right pass
        for (int i = 0; i < n; i++) {
            if (s[i] == c) pos = i;
            res[i] = i - pos;
        }

        pos = 2 * n;

        // Right to left pass
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) pos = i;
            res[i] = min(res[i], pos - i);
        }

        return res;
    }
};