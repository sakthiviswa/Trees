class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();

        queue<int>q;
        q.push(0);

        vector<bool>visited(n,false);
        visited[0] = true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();


            for(int key:rooms[node]){

                if(!visited[key]){
                    visited[key] = true;
                    q.push(key);
                }
            }
        }


        for(bool i:visited){
            if(!i){
                return false;
            }
        }

        return true;
        
    }
};