class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int missMatch = 0;
        vector<int> freq(26, 0);
        for(int i = 0; i < s1.length(); ++i) {
            if(s1[i] != s2[i]) {
                missMatch++;
                freq[s1[i]-'a']++;
                freq[s2[i]-'a']--;
            } 
        }

        for(int i : freq) {
            if(i != 0) return false;
        }

        return missMatch == 0 || missMatch == 2;
    }
};