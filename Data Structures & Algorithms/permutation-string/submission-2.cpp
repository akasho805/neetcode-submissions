class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        // O(n) soln
        int len1 =s1.length(),len2 =s2.length();

        if(len1>len2)
        {
            return false;
        }

        
        vector<int> freq1(26,0),freq2(26,0);

        for(int i=0;i<len1;i++)
        {
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }

        if(freq1 == freq2)
        {
            return true;
        }


        for(int i = len1; i < len2; i++)
        {
            // add new char
            freq2[s2[i]-'a']++;
            // remove left char
            freq2[s2[i-len1]-'a']--;

            if(freq1 == freq2)
            {
                return true;
            }
        }

        return false;

        // O(23.n) soln
        // int len1 =s1.length(),len2 =s2.length();

        // if(len1>len2)
        // {
        //     return false;
        // }

        
        // vector<int> freq1(26,0),freq2(26,0);

        // for(int i=0;i<len1;i++)
        // {
        //     freq1[s1[i]-'a']++;
        //     freq2[s2[i]-'a']++;
        // }

        // if(freq1 == freq2)
        // {
        //     return true;
        // }


        // for(int i = len1; i < len2; i++)
        // {
        //     // add new char
        //     freq2[s2[i]-'a']++;
        //     // remove left char
        //     freq2[s2[i-len1]-'a']--;

        //     if(freq1 == freq2)
        //     {
        //         return true;
        //     }
        // }

        // return false;

    }
};
