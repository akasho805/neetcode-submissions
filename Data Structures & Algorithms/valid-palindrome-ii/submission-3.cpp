class Solution {
public:

// dont usae this recursion
    // Recursive approach (commented out)
    // The idea here was to allow at most one deletion using a flag.
    // If characters mismatch and deletion hasn't been used yet,
    // try skipping either the left or the right character.
    // However, recursion is unnecessary here and adds overhead.
    // The iterative two-pointer solution below is simpler and optimal.

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

    // Helper function to check if a substring is a palindrome.
    // It checks the characters between indices l and r using two pointers.
    // If any mismatch is found, it returns false.
    // Otherwise, if the entire substring is symmetric, it returns true.
    bool isPall(const string& s, int l,int r)
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

// | Approach                   | Time            | Space    |
// | -------------------------- | --------------- | -------- |
// | Recursive (first approach) | **O(n²)** worst | **O(n)** |
// | Two-pointer + helper       | **O(n)**        | **O(1)** |


    }
};