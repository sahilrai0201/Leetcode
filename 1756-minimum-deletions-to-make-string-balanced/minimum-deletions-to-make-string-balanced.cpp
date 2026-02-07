class Solution {
public:
    int minimumDeletions(string s) {
        int bCount = 0;
        int deletions = 0;

        for(char c : s){
            if(c == 'b'){
                bCount++;
            }
            else{   //c == 'a'
                if(bCount > 0){
                    deletions++;
                    bCount--;     // delete one previous 'b'
                }
            }
        }
        return deletions;
    }
};