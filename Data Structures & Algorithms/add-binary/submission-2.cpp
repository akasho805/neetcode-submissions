class Solution {
public:
    string addBinary(string a, string b) {
        //easier to implement
        int p1 = a.length() - 1;
        int p2 = b.length() - 1;
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

        // both are
        // Time: O(n)
        // Space: O(n)

        // | Factor                | Arithmetic | Bitwise |
        // | --------------------- | ---------- | ------- |
        // | Readability           | ⭐⭐⭐⭐ | ⭐⭐   |
        // | Difficulty            | Easy       | Medium  |
        // | Interview expectation | ⭐⭐⭐⭐ | ⭐⭐⭐ |
        // | Bug risk              | Low        | Higher  |
        // | Concept depth         | Medium     | High    |
        // | Real-world usage      | Common     | Rare    |


        //only to show bit manip depth
        // int p1 = a.size() - 1;
        // int p2 = b.size() - 1;

        // int carry = 0;
        // string res = "";

        // while(p1 >= 0 || p2 >= 0 || carry)
        // {
        //     int bitA = (p1 >= 0) ? a[p1--] - '0' : 0;
        //     int bitB = (p2 >= 0) ? b[p2--] - '0' : 0;

        //     // XOR gives result bit
        //     int sum = bitA ^ bitB ^ carry;

        //     // Carry logic (full adder)
        //     carry = (bitA & bitB) | (bitA & carry) | (bitB & carry);

        //     res += (sum + '0');
        // }

        // reverse(res.begin(), res.end());
        // return res;
    }
};