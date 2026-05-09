class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>>dis(m,vector<int>(n,INT_MAX));

        dis[0][0] = 0;

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        pq.push({0,0,0});

        vector<vector<int>>dir = {{0,-1},{0,1},{1,0},{-1,0}};


        while(!pq.empty()){
            auto  q = pq.top();
            pq.pop();

            int effort = q[0];
            int r = q[1];
            int c = q[2];


            if(r == m-1 && c == n-1){
                return effort;
            }

            if(effort > dis[r][c]){
                continue;
            }

            for(auto d:dir){

                int nr = r + d[0];
                int nc = c + d[1];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n){

                    int neweffort = max(effort,abs(heights[r][c]-heights[nr][nc]));

                    if(neweffort < dis[nr][nc]){
                        dis[nr][nc] = neweffort;
                        pq.push({neweffort,nr,nc});
                    }
                }
            }
        }

        return 0;
        
    }
};