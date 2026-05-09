class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);

        for(auto& i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;

        pq.push({0,k});

        vector<int> dis(n+1,INT_MAX);

        dis[k] = 0;

        while(!pq.empty())
        {

            int curdis = pq.top().first;
            int node = pq.top().second;

            pq.pop();


            if(dis[node] < curdis){
                continue;
            }

            for(auto& [nei,w] : adj[node]){

                if(curdis+w < dis[nei]){

                    dis[nei] = curdis+w;

                    pq.push({dis[nei],nei});
                }
            }
        }

       

        
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX) return -1;
            res = max(res, dis[i]);
        }

        return res;

        
    }
};