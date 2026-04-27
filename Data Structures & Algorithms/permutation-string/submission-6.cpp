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

        int matches = 0;

        for(int i = 0;i<26;i++)
        {
            if(freq1[i] == freq2[i])
            {
                matches++;
            }
        }

        if(matches == 26)
        {
            return true;
        }

        for(int i = len1; i < len2; i++)
        {
            int addCh = s2[i]-'a';
            // add new char

            //check if before were equal
            if(freq2[addCh] == freq1[addCh])
            {
                matches--;
            }

            freq2[s2[i]-'a']++;

            //check if after were equal
            if(freq2[addCh] == freq1[addCh])
            {
                matches++;
            }

            // remove left char
            int remCh = s2[i-len1]-'a';
            //check if before were equal
            if(freq2[remCh] == freq1[remCh])
            {
                matches--;
            }

            freq2[remCh]--;

            //check if after were equal
            if(freq2[remCh] == freq1[remCh])
            {
                matches++;
            }

            if(matches == 26)
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
