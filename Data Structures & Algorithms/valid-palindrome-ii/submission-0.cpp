class Solution {
public:

    bool isPall(string s, int l,int r, bool flag)
    {
        if(l>r)
        {
            return true;
        }

        if(s[l]!=s[r])
        {
            if(flag == false)
            {
                flag = true;
                return isPall(s,l,r-1,flag) or isPall(s,l+1,r,flag);
            }
            return false; 
        }
        else
        {
            return isPall(s,l+1,r-1,flag);
        }

    }
    bool validPalindrome(string s) {
        int l = 0, r = s.length()-1;
        bool flag = false;
        return isPall(s,l,r,flag);

    }
};