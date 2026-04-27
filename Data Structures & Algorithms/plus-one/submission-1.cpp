class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        int n = digits.size();
        digits[n-1]++;
        if(digits[n-1]>9)
        {
            carry =1;
            digits[n-1]=0;
        }

        for(int i=n-2;i>=0;i--)
        {
            digits[i]+=carry;
            if(digits[i]>9)
            {
                carry = 1;
                digits[i]=0;
            }
            else{
                carry=0;
            }
        }
        if(carry)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
