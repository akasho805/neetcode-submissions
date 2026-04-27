class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left= 0,right=0,n =s.length();
        int maxLen = 0;
        vector<int> freq(26);

        for(int right = 0;right<n;right++)
        {
            freq[s[right] - 'A']++;

            int maxFreq=0;
            for(auto num: freq)
            {
                maxFreq=(max(maxFreq,num));
            }

            int windowLen = right-left+1;
            if(windowLen - maxFreq <= k)
            {
                // right++;
                maxLen = max(maxLen,windowLen);
            }
            else
            {
                freq[s[left]-'A']--;
                // freq[s[right]-'A']--;
                left++;
            } 
        }

        return maxLen;
    }
};
