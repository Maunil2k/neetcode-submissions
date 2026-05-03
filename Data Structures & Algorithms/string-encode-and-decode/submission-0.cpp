class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (auto& str: strs) {
            char l = str.length();
            l += '0';
            encoded += l;
            encoded += str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while (i < s.length()) {
            int l = s[i] - '0';
            decoded.push_back(s.substr(i+1, l));
            i += l+1; 
        }
        return decoded;
    }
};
