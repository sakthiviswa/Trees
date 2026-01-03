class Solution {
public:

    int recursion(int n){
        if(n==0 || n==1){
            return 1;
        }

        int count = 0;

        for(int i=0;i<n;i++){

            int l = recursion(i);
            int r = recursion(n-i-1);

            count += l*r;
        }

        return count;
    }
    int numTrees(int n) {

        return recursion(n);
        
    }
};