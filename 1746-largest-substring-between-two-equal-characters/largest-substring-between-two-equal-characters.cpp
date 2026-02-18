class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        int maxLen = -1;

        for(int i = 0; i < n; i++){
            for(int j = n - 1; j > i; j--){
                if(s[i] == s[j]){
                    maxLen = max(maxLen, j - i - 1);
                    break;  // no need to check smaller end for same start
                }
            }
        }
        return maxLen;
    }
};




// class Solution {
// public:
//     int maxLengthBetweenEqualCharacters(string s) {
//         int n = s.length();

//         int start = 0;
//         int end = n-1;

//         while(start <= end){
//             if(s[start] == s[end]){
//                 start++; end--;
//                 return end - start + 1;
//             }
//             else{
//                 return -1;
//             }
//         }
//         return {};
//     }
// };