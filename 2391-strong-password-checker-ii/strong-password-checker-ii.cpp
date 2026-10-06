class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        int n = password.length();
        bool found = true;

        int lowerCase = 0, upperCase = 0, digits = 0, specialChar = 0;

        for(int i=0; i<n; i++){
            if(password[i] >= 'a' && password[i] <= 'z') lowerCase++;

            else if(password[i] >= 'A' && password[i] <= 'Z') upperCase++;

            else if(password[i] >= '0' && password[i] <= '9') digits++;

            else if(password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*' || password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '+') specialChar++;
        }

        for(int i=0; i<n-1; i++){
            if(password[i] == password[i+1]){
                found = false;
            }
        }

        if(n >= 8 && lowerCase > 0 && upperCase > 0 && digits > 0 && specialChar > 0 && found == true){
            return true;
        }

        return false;
    }
};