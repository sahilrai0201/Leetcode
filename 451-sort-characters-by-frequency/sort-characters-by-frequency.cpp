//TC = O(N + KlogK) & SC = O(N + K) --------------------------------------------->

class Solution {
public:
    // Comparator function to sort characters in descending order of frequency
    static bool cmp(pair<char, int> &a, pair<char, int> &b){
        return a.second > b.second;
    }

    string frequencySort(string s) {
        // Hash map to store frequency of each character
        unordered_map<char, int> mp;

        // String to store the final answer
        string st = "";

        // Count frequency of each character
        for(auto ch : s){
            mp[ch]++;
        }

        // Vector to store {character, frequency} pairs
        vector<pair<char, int>> vec;

        // Copy all map entries into the vector
        for(auto it : mp){
            vec.push_back(it);
        }

        // Sort the vector based on frequency in descending order
        sort(vec.begin(), vec.end(), cmp);

        // Append each character frequency number of times
        for(auto ans : vec){
            for(int i=0; i<ans.second; i++){
                st += ans.first;
            }
        }

        // Return the frequency sorted string
        return st;
    }
};