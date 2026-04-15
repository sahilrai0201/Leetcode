//TC = O(N) & SC = O(N)----------------------------->
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n, 0);

        int count = 0, ops = 0;

        // Left → Right
        for(int i = 0; i < n; i++) {
            result[i] += ops;
            if(boxes[i] == '1') count++;
            ops += count;
        }

        // Reset
        count = 0;
        ops = 0;

        // Right → Left
        for(int i = n - 1; i >= 0; i--) {
            result[i] += ops;
            if(boxes[i] == '1') count++;
            ops += count;
        }

        return result;
    }
};




//TC = O(N*N) & SC = O(N)----------------------------->
// class Solution {
// public:
//     vector<int> minOperations(string boxes) {
//         int n = boxes.size();
//         vector<int> result(n, 0);

//         for(int i=0; i<n; i++){
//             int ops = 0;

//             for(int j=0; j<n; j++){
//                 if(boxes[j] == '1'){
//                     ops = ops + abs(i-j);
//                 }
//             }
//             result[i] = ops;
//         }
//         return result;
//     }
// };