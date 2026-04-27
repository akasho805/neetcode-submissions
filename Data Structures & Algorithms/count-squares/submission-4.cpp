
class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> mp;

    CountSquares() {}

    void add(vector<int> point) {
        mp[point[0]][point[1]]++;
    }

    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int res = 0;

        // If no points with same x → no square possible
        if (!mp.count(x)) return 0;

        for (auto &[y2, freq] : mp[x]) {
            if (y2 == y) continue;

            int d = y2 - y;

            // RIGHT square (x + d)
            if (mp.count(x + d)) {
                res += freq *
                       mp[x + d][y] *
                       mp[x + d][y2];
            }

            // LEFT square (x - d)
            if (mp.count(x - d)) {
                res += freq *
                       mp[x - d][y] *
                       mp[x - d][y2];
            }
        }

        return res;
    }
};

