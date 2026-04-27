class Solution {
public:
    string multiply(string num1, string num2) {
        
        if(num1 == "0" || num2 == "0") return "0";

        int len1 = num1.length(), len2 = num2.length();
        vector<int> temp(len1 + len2, 0);

        for(int i = len1 - 1; i >= 0; i--) {
            for(int j = len2 - 1; j >= 0; j--) {

                int mul = (num1[i] - '0') * (num2[j] - '0');
                
                int pos1 = i + j;       // carry position
                int pos2 = i + j + 1;   // current digit position

                int sum = mul + temp[pos2];

                temp[pos2] = sum % 10;
                temp[pos1] += sum / 10;
            }
        }

        // build result (skip leading zeros)
        string ans = "";
        for(int x : temp) {
            if(!(ans.empty() && x == 0)) {
                ans += (x + '0');
            }
        }

        return ans.empty() ? "0" : ans;
    }
};