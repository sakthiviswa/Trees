class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();

        int k = p.length();

        vector<int> res;

        unordered_map<char, int> mp;

        for (int i = 0; i < k; i++) {
            mp[p[i]]++;
        }

        int left = 0;
        for (int right = 0; right < n; right++) {

            mp[s[right]]--;

            if (mp[s[right]] == 0) {
                mp.erase(s[right]);
            }

            if (right - left + 1 == k) {

                if (mp.empty()) {
                    res.push_back(left);
                }

                mp[s[left]]++;

                if (mp[s[left]] == 0) {
                    mp.erase(s[left]);
                }

                left++;
            }
        }

        return res;
    }
};