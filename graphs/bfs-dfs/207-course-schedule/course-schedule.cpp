class Solution {
public:

    vector<vector<int>> constructadj(int v,vector<vector<int>>& edges){

        vector<vector<int>>adj(v);

        for(auto& i:edges){

            adj[i[0]].push_back(i[1]);
        }

        return adj;
    }


    bool canFinish(int v, vector<vector<int>>& edges) {

        vector<vector<int>> adj = constructadj(v,edges); 

        vector<int> indegree(v);

        for(int i=0;i<v;i++){
            for(int neighbour:adj[i]){
                indegree[neighbour]++;
            }
        }


        queue<int> q;

        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> res;


        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);

            for(int neighbour:adj[node]){
                indegree[neighbour]--;

                if(indegree[neighbour] == 0){
                    q.push(neighbour);

                }
            }

        }

        if(res.size() == v){
            return true;
        }


        return false;
    }
};