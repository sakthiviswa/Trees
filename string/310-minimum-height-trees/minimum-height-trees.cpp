class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        vector<int>indegree(n);

        if(n == 1) return {0};

        for(auto i:edges){
            
            int u,v;
            u = i[0];
            v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            indegree[u]++;
            indegree[v]++;
        }

        queue<int>que;

        for(int i=0;i<n;i++){
            if(indegree[i] == 1){
                que.push(i);
            }
        }



        int remaningleaves = n;

        while(remaningleaves > 2){
            int leaves = que.size();

            remaningleaves = remaningleaves - leaves;


            for(int i=0;i<leaves;i++){

                int node = que.front();
                que.pop();

                //indegree[node]--;

                for(int nei:adj[node]){
                    indegree[nei]--;

                    if(indegree[nei] == 1){
                        que.push(nei);
                    }
                }
            }

        }


        vector<int>res;

        while(!que.empty()){
            res.push_back(que.front());
            que.pop();
        }

        return res;
    }
};