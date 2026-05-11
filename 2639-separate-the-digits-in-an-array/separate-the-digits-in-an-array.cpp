//TC = O(D) & SC = O(D) : where D = total digits across all numbers ------------------------>
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;

        for(int num : nums){
            vector<int> temp;

            // Extract digits in reverse order
            while(num > 0){
                int digit = num % 10;
                temp.push_back(digit);
                num = num / 10;
            }

            // Restore original order
            reverse(temp.begin(), temp.end());

            // Add digits to result
            for(int x : temp){
                result.push_back(x);
            }
        }

        return result;
    }
};