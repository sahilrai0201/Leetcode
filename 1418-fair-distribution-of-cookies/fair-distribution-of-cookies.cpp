class Solution {
public:
    int solve(vector<int>& cookies, int i, vector<int>& a){
        if(i == cookies.size()){
            int ans = 0;
            for(auto it : a) ans = max(ans, it);
            return ans;
        }
        int mn = INT_MAX;
        for(int j=0; j<a.size(); j++){
            a[j] = a[j] + cookies[i];
            mn = min(mn, solve(cookies, i+1, a));
            a[j] = a[j] - cookies[i];
        }
        return mn;
    }    
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int i, n = cookies.size();
        vector<int> a(k);
        return solve(cookies, 0, a);
    }
};