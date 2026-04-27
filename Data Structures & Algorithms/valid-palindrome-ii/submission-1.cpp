class Solution {
public:
// dont usae this recursion
    // bool isPall(string s, int l,int r, bool flag)
    // {
    //     if(l>r)
    //     {
    //         return true;
    //     }

    //     if(s[l]!=s[r])
    //     {
    //         if(flag == false)
    //         {
    //             flag = true;
    //             return isPall(s,l,r-1,flag) or isPall(s,l+1,r,flag);
    //         }
    //         return false; 
    //     }
    //     else
    //     {
    //         return isPall(s,l+1,r-1,flag);
    //     }

    // }

    bool isPall(string s, int l,int r)
    {
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                return false;
            }
            l++;r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0, r = s.length()-1;
        
        while(l<r)
        {
            if(s[l]!=s[r])
            {
                return isPall(s,l,r-1) || isPall(s,l+1,r);
            }
            l++;r--;
        }
        return true;

    }
};