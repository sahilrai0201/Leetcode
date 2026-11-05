class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();

        vector<int> altitude;
        altitude.push_back(0);
        for(int i=0; i<n; i++){
            altitude.push_back(gain[i]);
        }

        vector<int> prefix(n+1);
        prefix[0] = altitude[0];
        for(int i=1; i<n+1; i++){
            prefix[i] = prefix[i-1] + altitude[i];
        }

        int maxi = INT_MIN;
        for(int i=0; i<n+1; i++){
            maxi = max(maxi, prefix[i]);
        }

        return maxi;
    }
};