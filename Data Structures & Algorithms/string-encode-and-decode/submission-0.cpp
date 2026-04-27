class Solution {
public:

    // ❗ First mistake to avoid
    // Don’t do: join with ',' or '#'

    // 👉 Why?

    // Strings can contain ANY characters (including your separator)

    // Example:

    // ["ab#c", "d"] → ambiguous if you split by '#'
    // 🧠 Core idea (KEY INSIGHT)
    // Store length of each string + delimiter + actual string

    // 👉 So decoding becomes deterministic

    // Encode
    string encode(vector<string>& strs) {
        string res = "";

        for(string &s : strs) {
            res += to_string(s.length()) + "#" + s;
        }

        return res;
    }

    // Decode
    vector<string> decode(string s) {
        vector<string> res;

        int i = 0;
        while(i < s.length()) {
            
            int j = i;
            // find '#'
            while(s[j] != '#') j++;

            int len = stoi(s.substr(i, j - i));

            j++; // move past '#'
            string word = s.substr(j, len);

            res.push_back(word);

            i = j + len;
        }

        return res;
    }
};
