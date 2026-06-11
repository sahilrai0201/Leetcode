//OPTIMISED APPROACH : O(N) -------------------------------->
class Solution {
public:
    bool rotateString(string s, string goal) {

        // Rotation is not possible if lengths differ
        if(s.length() != goal.length())
            return false;

        // Append string to itself
        string temp = s + s;

        // If goal is present in temp, it is a valid rotation
        return temp.find(goal) != string::npos;
    }
};





//UPDATED BRUTE FORCE : O(N*N) -------------------------------->
// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if(s.length() != goal.length())
//             return false;

//         for(int i = 0; i < s.length(); i++){
//             if(s == goal)
//                 return true;

//             // left rotate by 1
//             char first = s[0];
//             s = s.substr(1) + first;
//         }

//         return false;
//     }
// };






//BRUTE FORCE : O(N*N) ------------------------------------->
// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         if(s.length() == 0 && goal.length() == 0) return true;
//         else if(s.length() != goal.length()) return false;
//         else{
//             for(int k=0; k<s.length(); k++){     // try all rotations
//                 if(s == goal) return true;

//                 char first = s[0];
//                 for(int i=0; i<s.length()-1; i++){
//                     s[i] = s[i+1];
//                 }    
//                 s[s.length() - 1] = first;
//             }
//         }
//         return false;
//     }
// };
