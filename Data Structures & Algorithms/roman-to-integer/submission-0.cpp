class Solution {
public:
    int value(char c) {
        switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {

        // unordered_map<char, int> val = {{'I', 1},   {'V', 5},   {'X', 10},
        //                                 {'L', 50},  {'C', 100}, {'D', 500},
        //                                 {'M', 1000}};
        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i < s.length() - 1 and value(s[i]) < value(s[i + 1])) {
                num -= value(s[i]);
            } else {
                num += value(s[i]);
            }
        }
        return num;
    }
};