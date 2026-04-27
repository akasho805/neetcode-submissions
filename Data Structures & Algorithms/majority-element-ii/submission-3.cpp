class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = n/3;
        int major_el_1 =0,major_el_2 =1 ; //Actual values get set when freq == 0 anyway
        int freq_1 = 0,freq_2 = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==major_el_1)
            {
                freq_1++;
            }
            else if(nums[i]==major_el_2)
            {
                freq_2++;
            }
            else if(freq_1==0)
            {
                major_el_1=nums[i];
                freq_1 = 1;
            }
            else if(freq_2==0)
            {
                major_el_2=nums[i];
                freq_2 = 1;
            }
            else
            {
                freq_1--;freq_2--;
            }
        }

        freq_1=0;freq_2=0;

        for(int x: nums)
        {
            if(x == major_el_1)
            {
                freq_1++;
            }
            else if(x == major_el_2)
            {
                freq_2++;
            }
        }

        vector<int> res;
        if(freq_1 > k)
        {
            res.push_back(major_el_1);
        }
        if(freq_2 > k)
        {
            res.push_back(major_el_2);
        }

        return res;
        
        //o(n) space
        // unordered_map<int,int> freq;

        // int n = nums.size();
        // int k = n/3;

        // for(int x: nums)
        // {
        //     freq[x]++;
        // }

        // vector<int> res;
        // for(auto x: freq)
        // {
        //     if(x.second > k)
        //     {
        //         res.push_back(x.first);
        //     }
        // }

        // return res;
    }
};