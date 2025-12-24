class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        //calculate total apples 
        int totalapples = 0;
        for(int a : apple){
            totalapples = totalapples + a;
        }

        //sort boxes capacities in descreasing order
        sort(capacity.begin(), capacity.end(), greater<int>());

        //use boxes until all apples are stored
        int boxused = 0;
        for(int cap : capacity){
            if(totalapples <= 0) break;
            totalapples = totalapples - cap;
            boxused++;
        }
        return boxused;
    }
};