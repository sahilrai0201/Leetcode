class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> nums3;
        int i = 0;
        int j = 0;

        while(i < n && j < m){
            if(nums1[i] <= nums2[j]){
                nums3.push_back(nums1[i++]);
            }
            else{
                nums3.push_back(nums2[j++]);
            }
        }

        while(i < n) nums3.push_back(nums1[i++]);
        while(j < m) nums3.push_back(nums2[j++]);

        
        int size = nums3.size();
        if(size % 2 == 1){
            return nums3[size / 2];
        }
        else{
            return (nums3[size/2 - 1] + nums3[size/2]) / 2.0;
        }

        // double sum = 0;
        // for(int k=0; k<nums3.size(); k++){
        //     sum = sum + nums3[k];
        // }
        // double mean = sum / nums3.size();

        // return mean;
    }
};