class Solution {
public:

    vector<vector<int>> constructadj(int v,vector<vector<int>> &edges){

        vector<vector<int>>adj(v);

        for(auto &i:edges){
            adj[i[1]].push_back(i[0]);
        }   

        return adj;
    }

    vector<int> findOrder(int v, vector<vector<int>>& edges) {

        vector<vector<int>>adj = constructadj(v,edges);

        vector<int>indegree(v);

        for(int i=0;i<v;i++){
            for(int nei:adj[i]){
                indegree[nei]++;
            }
        }

        queue<int>que;

        for(int i=0;i<v;i++){

            if(indegree[i] == 0){
                que.push(i);
            }
        }

        vector<int>res;

        while(!que.empty()){

            int node = que.front();
            que.pop();

            res.push_back(node);

            for(int nei:adj[node]){
                indegree[nei]--;

                if(indegree[nei] == 0){
                    que.push(nei);
                }
            }
        }


        if(res.size() != v){
            return {};
        }

        return res;
        
    }
};