class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        if(str1+str2 !=str2+str1)
        {
            return "";
        }

        return str1.substr(0,gcd(str1.length(),str2.length()));
        // brute force
        // int len1 = str1.length(),len2 = str2.length();
        // string res;
        // if(len1>len2)
        // {
        //     res = str2;
        // }
        // else
        // {
        //     res = str1;
        // }

        // while(res!="")
        // {
        //     string temp1="",temp2="";
        //     for(int i=0;i<(len1/res.length());i++)
        //     {
        //        temp1+=res;
        //     }
        //     for(int i=0;i<(len2/res.length());i++)
        //     {
        //         temp2+=res;
        //     }
        //     if(temp2==str2 and temp1==str1)
        //     {
        //         return res;
        //     }
        //         res.pop_back();
        // }

        // return "";
        
    }
};