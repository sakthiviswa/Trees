class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        int n = score.size();
        vector<string>res(n);

       
        vector<pair<int,int>>temp;

        for(int i=0;i<n;i++){

            temp.push_back({score[i],i});

        }

        sort(temp.rbegin(),temp.rend());

        
        for(int i = 0; i < n; i++) {
            int idx = temp[i].second;

            if(i == 0) res[idx] = "Gold Medal";
            else if(i == 1) res[idx] = "Silver Medal";
            else if(i == 2) res[idx] = "Bronze Medal";
            else res[idx] = to_string(i + 1);
        }

        return res;

        
    }
};