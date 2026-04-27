class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res="";

        // columnNumber--;
        while(columnNumber>0)
        {
            columnNumber--;
            int rem = columnNumber % 26;
            res+=char('A'+(rem));
            columnNumber/=26;
        }

        reverse(res.begin(),res.end());
        return res;
    }
};