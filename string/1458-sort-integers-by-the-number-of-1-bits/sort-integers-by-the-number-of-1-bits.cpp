class Solution {
public:
            int countOnes(int n){

                int count = 0;

                while(n > 0) {
                    count += n % 2;
                    n /= 2;
                }

                return count;
            }
    vector<int> sortByBits(vector<int>& arr) {


        sort(arr.begin(),arr.end(),[&](int a,int b){

            int bita = countOnes(a);
            int bitb = countOnes(b);

            if(bita == bitb){
                return a < b;
            }

            return bita < bitb;


        });

        return arr;
        
    }
};