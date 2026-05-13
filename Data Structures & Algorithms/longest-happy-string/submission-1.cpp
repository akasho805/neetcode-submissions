class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int,char>> maxHeap;
        if(a > 0) maxHeap.push({a,'a'});
        if(b > 0) maxHeap.push({b,'b'});
        if(c > 0) maxHeap.push({c,'c'});

        string res = "";

        while(!maxHeap.empty())
        {
            //auto [freq1, ch1] = maxHeap.top();
            auto curr = maxHeap.top(); maxHeap.pop();

            if(res.length()>1 and res[res.length()-1] == curr.second and res[res.length()-2] == curr.second)
            {
                //if no alternative exist
                if(maxHeap.empty())
                {
                    break;
                }
                    
                auto next = maxHeap.top(); maxHeap.pop();
                res+=next.second;

                if(next.first-1 > 0)
                {
                    maxHeap.push({next.first-1,next.second});
                }

                //put curr back
                maxHeap.push(curr);
            }
            else
            {
                res+=curr.second;

                if(curr.first-1 > 0)
                {
                    maxHeap.push({curr.first-1,curr.second});
                }
            }    
        }

        return  res;
    }
};