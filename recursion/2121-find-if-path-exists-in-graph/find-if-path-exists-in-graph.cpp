class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        vector<vector<int>>graphs(n);

        for(auto &e: edges){

            graphs[e[0]].push_back(e[1]);
            graphs[e[1]].push_back(e[0]);

        }

        queue<int>q;
        q.push(source);



        vector<bool>visited(n,false);
        visited[source] = true;

        
        while(!q.empty()){

            int node = q.front();
            q.pop();

            if(node == destination){
                return true;
            }
                    for(int neighbour : graphs[node]){

                        if(!visited[neighbour]){
                            visited[neighbour] = true;
                            q.push(neighbour);
                        }
                    }    
            
        }

        return false;


        
        
    }
};