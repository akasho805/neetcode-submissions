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
    bool isHappy(int n) {
        int a[10];
        int flag=1;

        while(sumOfDigits(n)!=1 and flag)
        {
            int sum=sumOfDigits(n);
            if(sum<10)
            {
                if(!a[sum-1])
                {
                    a[sum-1]=1;
                }
                else
                {
                    return false;
                }
            }
            n=sum;
        }

        return true;
    }
};
