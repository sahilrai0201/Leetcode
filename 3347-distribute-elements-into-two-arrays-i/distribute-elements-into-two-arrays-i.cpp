class Solution { 
public: 
    vector<int> resultArray(vector<int>& nums) { 
        // Initialize first two elements in separate arrays
        vector<int> a = {nums[0]}; 
        vector<int> b = {nums[1]}; 
 
        // Process remaining elements
        for(int i = 2; i < nums.size(); i++){ 
            
            // Add to 'a' if its last element is greater
            if(a.back() > b.back()){ 
                a.push_back(nums[i]); 
            } 
            else{ 
                // Otherwise, add to 'b'
                b.push_back(nums[i]); 
            } 
        } 
 
        // Append all elements of 'b' after 'a'
        a.insert(a.end(), b.begin(), b.end()); 
 
        // Return the final combined array
        return a; 
    } 
};