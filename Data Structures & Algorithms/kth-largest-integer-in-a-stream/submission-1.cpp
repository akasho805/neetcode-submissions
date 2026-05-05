class KthLargest {
public:

    priority_queue<int,vector<int>,greater<int>> pq;

    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int x:nums)
        {
            if(pq.size()==k)
            {
                if(x >= pq.top())
                {
                    pq.pop();
                    pq.push(x);
                }
                else
                {
                    continue;
                }
            }
            else
            {
                pq.push(x);
            }
        }
    }
    
    int add(int x) {

        if(pq.size()==k)
        {
            if(x >= pq.top())
            {
                pq.pop();
                pq.push(x);
            }
        }
        else
        {
            pq.push(x);
        }

        return pq.top();
    }
};
