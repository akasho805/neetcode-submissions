class Solution {
public:
    string addBinary(string a, string b) {

        int p1 = a.size() - 1;
        int p2 = b.size() - 1;

        int carry = 0;
        string res = "";

        while(p1 >= 0 || p2 >= 0 || carry)
        {
            int bitA = (p1 >= 0) ? a[p1--] - '0' : 0;
            int bitB = (p2 >= 0) ? b[p2--] - '0' : 0;

            // XOR gives result bit
            int sum = bitA ^ bitB ^ carry;

            // Carry logic (full adder)
            carry = (bitA & bitB) | (bitA & carry) | (bitB & carry);

            res += (sum + '0');
        }

        reverse(res.begin(), res.end());
        return res;
    }
};