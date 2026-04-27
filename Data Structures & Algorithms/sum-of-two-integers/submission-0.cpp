class Solution {
public:
    int getSum(int a, int b) {
    while(b != 0) {
        int carry = (a & b) << 1; // common bits → carry
        a = a ^ b;                // sum without carry
        b = carry;                // carry becomes next addition
    }
    return a;
}
};
