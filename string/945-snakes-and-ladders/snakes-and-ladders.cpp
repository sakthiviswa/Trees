class Solution {
public:

    pair<int,int> getCoordinates(int num, int n){
        int row = (num - 1) / n;
        int col = (num - 1) % n;
        
        row = n - 1 - row;
        
        if((n - 1 - row) % 2 == 1){
            col = n - 1 - col;
        }
        
        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();
        int final_pos = n*n;

        vector<bool>visited(final_pos+1,false);
        queue<pair<int,int>>que;
        que.push({1,0});
        visited[1] = true;

        while(!que.empty()){

            int steps = que.front().first;
            int roll = que.front().second;

            que.pop();


            if(steps == final_pos){
                return roll;
            }

            for(int i=1;i<=6;i++){

                int next = i+steps;

                if(next <= final_pos){

                    auto[r,c] = getCoordinates(next,n);
                    
                    if(board[r][c] != -1){
                        next = board[r][c];
                    }

                    if(!visited[next])
                    {

                        visited[next] = true;
                        que.push({next,roll+1});

                    }

                }

            }

        }

        return -1;
        
    }
};