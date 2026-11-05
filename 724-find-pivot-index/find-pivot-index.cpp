class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        // left[i]  = sum of all elements strictly to the LEFT of index i
        // right[i] = sum of all elements strictly to the RIGHT of index i
        vector<int> left(n);
        vector<int> right(n);

        // nothing exists to the left of index 0, so the left sum is 0
        left[0] = 0;
        // nothing exists to the right of the last index, so the right sum is 0
        right[n-1] = 0;

        // build left sums, going from left to right
        // left sum of i = left sum of (i-1) + the element at (i-1)
        // we add nums[i-1] (not nums[i]) because index i itself is NOT included
        for(int i=1; i<n; i++) {
            left[i] = left[i-1] + nums[i-1];
        }

        // build right sums, going from right to left
        // right sum of i = right sum of (i+1) + the element at (i+1)
        // we start from n-2 because right[n-1] is already set to 0
        for(int i=n-2; i>=0; i--) {
            right[i] = right[i+1] + nums[i+1];
        }

        // the pivot is the index where left sum == right sum
        // we go from left to right, so the first match is the leftmost pivot
        // (the question asks for the leftmost one)
        for(int i=0; i<n; i++) {
            if(right[i] == left[i]) return i;
        }

        // no index had equal left and right sums
        return -1;
    }
};