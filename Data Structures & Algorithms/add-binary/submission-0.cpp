class Solution {
public:
    string addBinary(string a, string b) {
        int p1=a.length()-1,p2=b.length()-1;
        int carry = 0;
        string res = "";
         while(p1 >= 0 || p2 >= 0 || carry)
        {
            int sum = carry;

            if(p1 >= 0) sum += a[p1--] - '0';
            if(p2 >= 0) sum += b[p2--] - '0';

            res += (sum % 2) + '0';   // append result bit
            carry = sum / 2;          // update carry
        }

        reverse(res.begin(), res.end());
        
        return res;

    }
};