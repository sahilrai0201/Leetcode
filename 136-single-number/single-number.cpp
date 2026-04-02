class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        // Map to store frequency of each number
        map<int, int> mp;

        // Traverse the array and count occurrences of each element
        for(int x : nums){
            mp[x]++;   // increment count of element x
        }

        // Iterate through the map to find the element with frequency 1
        for(auto i : mp){
            // i.first  -> element
            // i.second -> frequency of that element
            if(i.second == 1){
                return i.first;   // return the element that appears only once
            }
        }

        // In case no unique element is found (though problem guarantees one)
        return -1; 
    }
};