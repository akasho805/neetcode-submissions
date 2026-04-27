class Solution {
public:

    int getBit(int num,int pos)
    {
        return num & (1 << pos) ? 1 : 0;
    }
    void updateBit(uint32_t &n,int pos,int val)
    {
        n = n & (~(1 << pos)); //clearbit
        n = n | (val << pos); //update bit
    }
    uint32_t reverseBits(uint32_t n) {
        uint32_t m= 0;
        for(int i = 0; i<32;i++)
        {
            updateBit(m,31-i,getBit(n,i));
        }
        return m;
    }

};
