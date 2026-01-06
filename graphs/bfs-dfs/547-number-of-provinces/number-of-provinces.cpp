class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n=isConnected.size();

        int provisince = 0;

        vector<bool>visited(n,false);

        for(int i=0;i<n;i++){

            if(!visited[i]){

                provisince++;
                visited[i] = true;

                queue<int>q;
                q.push(i);

                while(!q.empty()){
                    int node = q.front();
                    q.pop();

                    for(int neighbour = 0;neighbour<n;neighbour++){

                        if(isConnected[node][neighbour] == 1 && !visited[neighbour]){
                            visited[neighbour] = true;
                            q.push(neighbour);
                        }
                    }
                }
            }
        }


        return provisince;
        
    }
};