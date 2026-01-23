class Solution {
public:

    pair<int,int> find_Ind(int next, int n)
    {
        int row = (next-1)/n;
        int col = (next-1)%n;

        int rowind = n-1-row;
        int colind = (row%2 == 0) ? col :n-1-col;


        return {rowind,colind};
    }
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();
        int final_pos = n*n;

        queue<pair<int,int>> q;
        q.push({1,0});

        vector<bool> visited(final_pos+1,false);

        visited[1] = true;
        

        while(!q.empty()){

            auto [position,step] = q.front();
            q.pop();

            if(position == final_pos){
                return step;
            }

            for(int i=1;i<=6;i++){


                 int next = position+i;

                 if(next>final_pos ){
                    continue;
                 }

                 auto[x,y] = find_Ind(next,n);


                  if(board[x][y] != -1){
                    next = board[x][y];
                }

                 if(!visited[next]){
                    visited[next] = true;
                    q.push({next,step+1});
                 }


            }
        }
        return -1;
    }
};