class Solution {
public:

    int resLen = 0, start = 0 ,count = 0;

    //to avoid copying string every fn call
    void expand(const string& s,int left,int right)
    // void expand(string s,int left,int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right]) 
        {
            count++;
            if (right - left + 1 > resLen) 
            {
                start = left;
                resLen = right - left + 1;
            }
            left--;
            right++;
        }
    }
    
    int countSubstrings(string s) {

        for (int i = 0; i < s.size(); i++) 
        {
            // odd length
            expand(s,i,i);
            // even length
            expand(s,i,i+1);
        }

        return count;

    }
    
};
