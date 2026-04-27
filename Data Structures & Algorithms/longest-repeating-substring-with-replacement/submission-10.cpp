class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int left= 0,right=0,n =s.length();
        int maxLen = 0;
        vector<int> freq(26);
        int maxFreq = 0;

        for(int right = 0;right<n;right++)
        {
            freq[s[right] - 'A']++;

            //we just need max length which is maximizing the maxfreq
            // therefore we dont need to update maxfreq as the next answer will be at the
            // next greater frequency
            maxFreq=(max(maxFreq,freq[s[right] - 'A'])); 

            while((right-left+1) - maxFreq > k)
            {
                freq[s[left]-'A']--;
                left++;
            }
            maxLen = max(maxLen,right-left+1);
        }

        return maxLen;

        // o(26n) = 26 O(n) = O(n) soln
        // int left= 0,right=0,n =s.length();
        // int maxLen = 0;
        // vector<int> freq(26);

        // for(int right = 0;right<n;right++)
        // {
        //     freq[s[right] - 'A']++;

        //     int maxFreq=0;
        //     for(auto num: freq)
        //     {
        //         maxFreq=(max(maxFreq,num));
        //     }

        //     int windowLen = right-left+1;
        //     if(windowLen - maxFreq <= k)
        //     {
        //         // right++;
        //         maxLen = max(maxLen,windowLen);
        //     }
        //     else
        //     {
        //         freq[s[left]-'A']--;
        //         // freq[s[right]-'A']--;
        //         left++;
        //     } 
        // }

        // return maxLen;
    }
};
