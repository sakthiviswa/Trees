class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        

        vector<vector<pair<int,double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        priority_queue<pair<double,int>>q;

        q.push({1.0,start_node});

        vector<double> best(n,0.0);

        best[start_node] = 1.0;

        while(!q.empty()){

            double dis = q.top().first;
            int node = q.top().second;

            q.pop();

            if(node == end_node){
                return dis;
            }

            if(dis < best[node]){
                continue;
            }

            for(auto& [nei,w]:adj[node]){

                if(dis * w > best[nei]){
                    best[nei] = dis * w;
                    q.push({best[nei],nei});
                }
            }
        }

        return 0.0;



        
    }
};