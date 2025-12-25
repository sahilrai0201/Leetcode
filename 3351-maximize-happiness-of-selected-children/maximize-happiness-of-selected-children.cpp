//corrected version : 

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

        long long sum = 0;
        
        //sorted the happiness array in decreasing order
        sort(happiness.begin(), happiness.end(), greater<int>());

        //pick top k elements
        for(int i=0; i<k; i++){
            long long curr = happiness[i] - i;
            if(curr > 0){
                sum = sum + curr;
            }
        }
        return sum;
    }
};


//trial version : 
// class Solution {
// public:
//     long long maximumHappinessSum(vector<int>& happiness, int k) {

//         long long sum = 0;
        
//         sort(happiness.begin(), happiness.end(), greater<int>());

//         for(int j=0; j<k; j++){
//             sum = sum + happiness[j];
//             happiness[j] = happiness[j] - j;
//         }
//         return sum;
//     }
// };