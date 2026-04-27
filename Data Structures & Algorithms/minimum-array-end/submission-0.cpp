class Solution {
public:
    long long minEnd(int n, int x) {
        
        /*
        We know that if the AND of all elements is x,
        then in binary form, all bits that are 1 in x
        must remain 1 in every number.

        Example:
        x = 3 → binary = 11

        So the last 2 bits of every number must be "11".

        Now we use numbers from 0 to n-1 to construct the array.

        For n = 5:
        we use values: 0 to n-1 → 0,1,2,3,4

        i (0 to n-1) | x (11) | append both | decimal value
        ---------------------------------------------------
        0   (000)    | 11     | 00011        | 3
        1   (001)    | 11     | 00111        | 7
        2   (010)    | 11     | 01011        | 11
        3   (011)    | 11     | 01111        | 15
        4   (100)    | 11     | 10011        | 19

        So the constructed array is:
        [3, 7, 11, 15, 19]

        But we only need the (n-1)th element:
        n-1 = 4 → answer = 19
        */

        // return only (n-1)th term
        long long res = x;
        long long k = n - 1;  // we only care about last index

        int bitPos = 0;

        while(k > 0)
        {
            if((x & (1LL << bitPos)) == 0)
            {
                if(k & 1)
                {
                    res |= (1LL << bitPos);
                }
                k >>= 1;
            }
            bitPos++;
        }

        return res;

    }
};

// to return the full nums array
// class Solution {
// public:

//     long long buildNumber(long long x, long long k)
//     {
//         long long res = x;
//         int bitPos = 0;

//         while(k > 0)
//         {
//             // if bit in x is 0 → we can fill
//             if((x & (1LL << bitPos)) == 0)
//             {
//                 if(k & 1)
//                 {
//                     res |= (1LL << bitPos);
//                 }
//                 k >>= 1;
//             }
//             bitPos++;
//         }

//         return res;
//     }

//     vector<long long> buildArray(int n, int x) {
//         vector<long long> nums;

//         for(int i = 0; i < n; i++)
//         {
//             nums.push_back(buildNumber(x, i));
//         }

//         return nums;
//     }
// };