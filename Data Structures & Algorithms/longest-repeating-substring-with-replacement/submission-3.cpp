class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left= 0,right=0,n =s.length();
        int maxLen = 0;
        unordered_map<char,int> freq;

        for(int right = 0;right<n;)
        {
            freq[s[right]]++;

            int maxFreq=0;
            for(auto &p: freq)
            {
                maxFreq=(max(maxFreq,p.second));
            }

            int windowLen = right-left+1;
            if(windowLen - maxFreq <= k)
            {
                right++;
                maxLen = max(maxLen,windowLen);
            }
            else
            {
                freq[s[left]]--;
                freq[s[right]]--;
                left++;
            } 
        }

        return maxLen;
    }
};
