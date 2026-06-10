class Solution {
public:
    string longestPalindrome(string s) {

        int resLen = 0, resIdx = 0;
    
        for (int i = 0; i < s.size(); i++) 
        {
            // odd length
            int left = i,right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) 
            {
                if (right - left + 1 > resLen) {
                    resIdx = left;
                    resLen = right - left + 1;
                }
                left--;
                right++;
            }

            // even length
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() &&s[left] == s[right]) 
            {
                if (right - left + 1 > resLen) {
                    resIdx = left;
                    resLen = right - left + 1;
                }
                left--;
                right++;
            }
        }

        return s.substr(resIdx,resLen);


    }
};
