class Solution {
public:
    // Function to count number of set bits (1s) in binary form
    int countBits(int n){
        int count = 0;
        while(n){
            count += (n & 1);
            n = n >> 1;
        }
        return count;
    }

    //custom comparator
    static bool compare(int a, int b){
        Solution obj;

        int countA = obj.countBits(a);
        int countB = obj.countBits(b);

        // First sort by number of set bits
        if(countA == countB){
            return a < b;           // If equal, sort by value
        }
        return countA < countB;
    }

    //original function
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};