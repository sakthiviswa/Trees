class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int totcost = 0,totgas = 0;

        int n = gas.size();

        for(int i=0;i<n;i++){

            totgas += gas[i];
            totcost += cost[i];
        }

        if(totgas < totcost){
            return -1;
        }

        int cursum = 0,startInd = 0;

        for(int i=0;i<n;i++){

            cursum += (gas[i]-cost[i]);

            if(cursum < 0){

                startInd = i+1;
                cursum = 0;

            }
        }

        return startInd;
        
    }
};