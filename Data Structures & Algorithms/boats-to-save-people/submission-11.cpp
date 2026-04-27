class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        

        sort(people.begin(),people.end());

        int left = 0;
        int right  = people.size()-1;
        int boats = 0;

        // while(left<right)
        while(left<=right)
        {
            int sum = people[left] + people[right];
            if(sum <= limit)
            {
                // boats++; we are doing boats ++ anyways
                left++;
                // right--; same as above
            }
            // else if(sum>limit) //handles single element as well
            // {
                boats++;
                right--;
            // }
        }

        // if(left==right)
        // {
        //     boats++;
        // }

        return boats;

    }
};