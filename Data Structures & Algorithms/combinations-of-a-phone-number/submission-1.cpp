class Solution {
public:
    vector<string> res;
    vector<string> digitToChar = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(int i, string& curStr, string& digits)
    {
        if (i == digits.size())
        {
            res.push_back(curStr);
            return;
        }

        string& chars = digitToChar[digits[i] - '0'];

        for (char c : chars)
        {
            curStr.push_back(c);           // Choose

            backtrack(i + 1, curStr, digits); // Recurse

            curStr.pop_back();             // Undo
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};

        string curStr;

        backtrack(0, curStr, digits);

        return res;
    }
};