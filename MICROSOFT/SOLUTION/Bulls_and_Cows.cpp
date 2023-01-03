class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> secrets(10, 0);
        vector<int> guesss(10, 0);

        int bulls=0, cows=0;
        for (int i=0; i<secret.size(); ++i) {
           
            if (secret[i]==guess[i]) bulls++;
            else {
                
               secrets[secret[i]-'0']++;
                 guesss[guess[i]-'0']++;
            }
        }

        for (int i=0; i<guesss.size(); ++i) {
            cows+=min(guesss[i], secrets[i]);
        }

        return to_string(bulls)+'A'+to_string(cows)+'B';

    }
};