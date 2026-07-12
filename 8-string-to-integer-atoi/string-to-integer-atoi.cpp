// TC = O(N) & SC = O(N) ---------------->
class Solution {
private :
    long long solve(string &s, int i, int sign, long long ans){
        if(i >= s.length() || !isdigit(s[i])){
            return ans * sign;
        }

        ans = ans * 10 + (s[i] - '0');

        if(ans * sign > INT_MAX) return INT_MAX;
        if(ans * sign < INT_MIN) return INT_MIN;

        return solve(s, i+1, sign, ans);
    }   

public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;

        while(i < n && s[i] == ' '){
            i++;
        }

        int sign = 1;
        if(i < n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-'){
                sign = -1;
            }
            i++;
        }

        return  solve(s, i, sign, 0);
    }
};





// Time Complexity: O(N) & Space Complexity: O(1) ------------------>
// class Solution {
// public:
//     int myAtoi(string s) {
//         int n = s.length();

//         // Pointer to traverse the string
//         int i = 0;

//         // Skip all leading whitespaces
//         while(i < n && s[i] == ' '){
//             i++;
//         }

//         // Determine the sign of the number
//         int sign = 1;
//         if(i < n && (s[i] == '+' || s[i] == '-')){
//             if(s[i] == '-'){
//                 sign = -1;
//             }
//             i++;
//         }

//         // Use long long to safely detect overflow
//         long long ans = 0;

//         // Process consecutive digits
//         while(i < n && isdigit(s[i])){
//             // Build the number digit by digit
//             ans = ans * 10 + (s[i] - '0');

//             // Handle positive overflow
//             if(sign * ans > INT_MAX) return INT_MAX;

//             // Handle negative overflow
//             if(sign * ans < INT_MIN) return INT_MIN;

//             i++;
//         }

//         // Apply sign and return the result
//         return sign * ans;
//     }
// };