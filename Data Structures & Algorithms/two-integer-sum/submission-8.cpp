class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        //o(n)    
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) 
        {
            int need = target - nums[i];
            if (mp.count(need)) //check if the 2nd element is present
            {
                return {mp[need], i}; //return (2nd element,1st element)
            }
            mp[nums[i]] = i; //add 1st element to the map
        }
    }
};
