class Solution {
public:
    // Encode: Convert vector<string> to one string
    string encode(vector<string>& strs) {
        string ret;
        for (string& s : strs) {
            ret += to_string(s.size()) + "#" + s;
        }
        return ret;
    }

    // Decode: Convert encoded string back to vector<string>
    vector<string> decode(string s) {
        vector<string> ret;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            // Find the position of '#'
            while (s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));
            ret.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return ret;
    }
};
