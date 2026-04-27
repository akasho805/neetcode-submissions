class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        vector<int> record;
        int idx=0;
        
        for(int i =0;i<ops.size();i++)
        {
            if(ops[i]=="+")
            {
                record.push_back(record[idx-1]+record[idx-2]);idx++;
            }
            else if(ops[i]=="D")
            {
                record.push_back(2*record[idx-1]);
                idx++;
            }
            else if(ops[i]=="C")
            {
                record.pop_back();idx--;
            }
            else
            {
                record.push_back(stoi(ops[i]));
                idx++;
            }
        }

        int sum=0;
        for(int x:record)
        {
            sum+=x;
        }
        return sum;
    }
};