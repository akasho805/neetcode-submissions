class Solution {
public:
    vector<int> countBits(int n) {

        // Create result array of size n+1
        // res[i] will store number of set bits in i
        vector<int> res(n+1);

        // We start from 1 because res[0] = 0 by default
        for(int i = 1; i <= n; i++)
        {
            /*
            Core DP relation:

            res[i] = res[i >> 1] + (i & 1)

            Explanation:
            -------------------------
            1. i >> 1 → removes the last bit of i
               Example:
               i = 5 → 101
               i >> 1 = 2 → 10

            2. res[i >> 1] → already computed (DP reuse)

            3. (i & 1) → checks last bit:
               - 1 if last bit is 1
               - 0 if last bit is 0

            So:
            number of set bits in i =
            number of set bits in (i >> 1) + last bit

            This avoids recomputation → makes it O(n)
            */

            res[i] = res[i >> 1] + (i & 1);
        }

        return res;
    }

    // -------------------------------
    // Sub-optimal approach (for reference)
    // -------------------------------

    /*
    Idea:
    Count bits for each number independently using:
    n = n & (n-1)

    This removes the lowest set bit each time.

    Example:
    101100 → 101000 → 100000 → 000000

    Time Complexity:
    ----------------
    O(n log n) (worst case)

    Why worse?
    Because for each i, we may loop over its bits.

    Compared to DP solution:
    DP = O(n) → optimal
    */

    // int hammingWeight(int n) {
    //     int count = 0;
    //     while(n)
    //     {
    //         n = n & (n-1); // removes lowest set bit
    //         count++;
    //     }
    //     return count;
    // }

    // vector<int> countBits(int n) {
    //     vector<int> res(n+1);
    //     for(int i =1;i<=n;i++)
    //     {
    //         res[i]=hammingWeight(i);
    //     }
    //     return res;
    // }
};