class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26);

        if(s.length()!=t.length())
        {
            return false;
        }

        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        for(int x:freq)
        {
            if(x!=0)
            {
                return false;
            }
        }
        return true;

    }
};
