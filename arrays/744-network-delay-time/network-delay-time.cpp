class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>>adj(n+1);

        for(auto& i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;

        vector<int>dis(n+1,INT_MAX);

        dis[k] = 0;

        pq.push({0,k});

        while(!pq.empty()){

            int curdis = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            if(curdis > dis[node]){

                continue;
            }

            for(auto& [v,w] : adj[node]){

                if(curdis + w < dis[v]){
                    dis[v] = curdis+w;
                    pq.push({dis[v],v});
                }
            }



        }

        int ans = 0;

        for(int i=1;i<=n;i++){
            if(dis[i] == INT_MAX){
                return -1;
            }
            ans = max(ans,dis[i]);
        }

        return ans;
    }
};