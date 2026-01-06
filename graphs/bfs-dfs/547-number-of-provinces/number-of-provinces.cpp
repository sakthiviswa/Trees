class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();


        vector<bool>visited(n,false);
        
        int provisions = 0;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                provisions++;

                queue<int>q;
                q.push(i);
                visited[i] = true;


                while(!q.empty()){

                    int node = q.front();
                    q.pop();

                    for(int neighbour = 0;neighbour < n;neighbour++){
                        if(isConnected[node][neighbour] == 1 && !visited[neighbour]){
                            visited[neighbour] = true;
                            q.push(neighbour);
                        }
                    }
                }
            }
        }


        return provisions;
        
    }
};