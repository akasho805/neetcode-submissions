class Solution {
public:

    int sumOfDigits(int n)
    {
        int sum=0;
        while(n)
        {
            int digit = n%10;
            sum+=digit*digit;
            n/=10;
        }
        return sum;
    }

    bool isHappy(int n) 
    {
        int slow = n;
        int fast = n;

        do {
            slow = sumOfDigits(slow);
            fast = sumOfDigits(sumOfDigits(fast));
        }while (slow != fast);

        return slow == 1;
    }
    
    //better impoementaion using hashset
    // bool isHappy(int n) {
    //     unordered_set<int> seen;

    //     while (n != 1) {
    //         if (seen.count(n)) return false; // cycle detected
    //         seen.insert(n);
    //         n = sumOfDigits(n);
    //     }

    //     return true;
    // }
    //cycle of sumbers can be 2 or more dgits, inthis case it will take too much time to compute
    // bool isHappy(int n) {
    //     int a[10] = {0};

    //     while(sumOfDigits(n)!=1)
    //     {
    //         int sum=sumOfDigits(n);
    //         if(sum<10)
    //         {
    //             if(!a[sum-1])
    //             {
    //                 a[sum-1]=1;
    //             }
    //             else
    //             {
    //                 return false;
    //             }
    //         }
    //         n=sum;
    //     }

    //     return true;
    // }
};
