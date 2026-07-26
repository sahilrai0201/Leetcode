// TC = O(N)
// SC = O(N)

class Solution {
private:
    // Find index of Next Smaller Element
    vector<int> nextSmallerElement(vector<int> arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = n - 1; i >= 0; i--){
            int curr = arr[i];

            // Remove elements >= current
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }

            // Store next smaller index
            ans[i] = s.top();

            // Push current index
            s.push(i);
        }
        return ans;
    }

    // Find index of Previous Smaller Element
    vector<int> prevSmallerElement(vector<int> arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            int curr = arr[i];

            // Remove elements >= current
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }

            // Store previous smaller index
            ans[i] = s.top();

            // Push current index
            s.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // Next Smaller Index
        vector<int> next = nextSmallerElement(heights, n);

        // Previous Smaller Index
        vector<int> prev = prevSmallerElement(heights, n);

        int area = INT_MIN;

        for(int i = 0; i < n; i++){

            // Height of rectangle
            int l = heights[i];

            // No smaller on right -> extend till end
            if(next[i] == -1){
                next[i] = n;
            }

            // Width = right boundary - left boundary - 1
            int b = next[i] - prev[i] - 1;

            // Area using current bar as minimum height
            int newArea = l * b;

            // Update maximum area
            area = max(area, newArea);
        }

        return area;
    }
};