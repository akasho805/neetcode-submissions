class Solution {
public:
    string simplifyPath(string path) {
        
        vector<string> tokens;

        string token="";

        for(char x: path)
        {
            if(x=='/')
            {
                if(token.length()!=0)
                {
                    tokens.push_back(token);
                    token="";
                }
            }
            else
            {
                token+=x;
            }
        }

        if(token.length()!=0)
        {
            tokens.push_back(token);
        }

        vector<string> filtered_tokens;

        for(string token: tokens)
        {
            if(token==".")
            {
                ;
            }
            else if(token=="..")
            {
                if(!filtered_tokens.empty())
                {
                    filtered_tokens.pop_back();
                }
            }
            else
            {
                filtered_tokens.push_back(token);
            }
        }

        string res="/";
        
        for(string token: filtered_tokens)
        {
            res+=token+"/";
        }

        if(res.length()!=1)
        {
            res.pop_back();
        }

        return res;

    }
};