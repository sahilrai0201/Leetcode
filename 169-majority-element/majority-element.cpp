class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int candidate = nums[0], vote = 1;
        for(int i=1; i<nums.size(); i++){
            if(vote == 0) {
                candidate = nums[i];
                vote = 1;
            }
            else if(nums[i] == candidate) {
                vote++;
            }
            else{
                vote--;
            }
        }
        return candidate;
    }
};