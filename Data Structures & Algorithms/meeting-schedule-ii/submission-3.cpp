/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        vector<int> st,en;

        int n =intervals.size();

        for(int i=0;i<n;i++)
        {
            st.push_back(intervals[i].start);
            en.push_back(intervals[i].end);
        }

        sort(st.begin(),st.end());
        sort(en.begin(),en.end());

        int i =0,j=0;

        int count = 0;

        int maxCount = 0;

        while(i<n && j<n)
        {
            if(st[i]<en[j])
            {
                i++;count++;
            }
            else
            {
                j++;count--;
            }
            maxCount= max(count,maxCount);
        }

        return maxCount;
    }
};
