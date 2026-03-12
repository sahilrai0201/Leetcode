//Optimesd approach -> KMP approach
//Tc = O(n+m) and Sc = O(m) :




//Nested loops ->
//Tc = O(n*m) and Sc = O(1) ->
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        for(int i=0; i<=n-m; i++){
            int j;
            for(j=0; j<m; j++){
                if(haystack[i+j] != needle[j]){
                    break;
                }
            }
            if(j == m) return i;
        }
        return -1;
    }
};


//substr() approach :
//TC = O(n*m) and SC = O(m) ->
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int n=haystack.size();
//         int m=needle.size();

//         for(int i=0; i<=n-m; i++){
//             if(haystack.substr(i,m)==needle){
//                 return i;
//             }
//         }
//         return -1;
//     }
// };





//Built-in function of cpp ->  find() function
//Tc = O(n*m) and Sc = O(1) ->
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         return haystack.find(needle);
//     }
// };