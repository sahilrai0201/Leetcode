class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> st;
        int n = digits.size();

        for(int i = 0; i < n; i++) {
            // Last digit must be even
            if(digits[i] % 2 != 0) continue;

            for(int j = 0; j < n; j++) {
                if(j == i) continue;

                // Hundreds digit cannot be 0
                if(digits[j] == 0) continue;

                for(int k = 0; k < n; k++) {
                    if(k == i || k == j) continue;

                    int num = digits[j] * 100 
                            + digits[k] * 10 
                            + digits[i];

                    st.insert(num);
                }
            }
        }

        return st.size();
    }
};