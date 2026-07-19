class Solution {
private:
    void solve(int index, int k, int n, vector<int> &curr, vector<vector<int>> &ans){
        vector<int> num = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        if(k < 0 || n < 0){
            return;
        }

        if(n == 0 && k == 0){
            ans.push_back(curr);
            return;
        }

        for(int i=index; i<9; i++){
            int element = num[i];
            curr.push_back(element);

            solve(i + 1, k - 1, n - num[i], curr, ans);

            curr.pop_back();
        }
    }    

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, k, n, curr, ans);

        return ans;
    }
};



// PICK, NOT PICK APPROACH
// class Solution {
// private:
//     void solve(int num, int k, int target,
//                vector<int>& curr,
//                vector<vector<int>>& ans) {

//         // Valid combination
//         if (k == 0 && target == 0) {
//             ans.push_back(curr);
//             return;
//         }

//         // Invalid cases
//         if (num > 9 || k < 0 || target < 0) {
//             return;
//         }

//         // PICK
//         curr.push_back(num);
//         solve(num + 1, k - 1, target - num, curr, ans);
//         curr.pop_back();

//         // NOT PICK
//         solve(num + 1, k, target, curr, ans);
//     }

// public:
//     vector<vector<int>> combinationSum3(int k, int n) {
//         vector<vector<int>> ans;
//         vector<int> curr;

//         solve(1, k, n, curr, ans);

//         return ans;
//     }
// };