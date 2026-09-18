class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) return s.length();
        set<char> m;
        int l=0, r=1, ans=1;
        m.insert(s[0]);
        while(r<s.length()) {
            // cout<<"processing "<<s[r]<<", ";
            if (m.find(s[r]) != m.end()) {
                // element exists, we now need to recursively shrink the window by incrementing 
                // by increasing the left pointer until, all the elements are unqiue in the substring
                // cout<<"Found in the set!! ";
                while (m.find(s[r]) != m.end()) {
                    m.erase(s[l]);
                    l++;
                }
                m.insert(s[r]);
                // cout<<"New left pointer points to "<<"s["<<l<<"]: "<<s[l]<<endl;
                // cout << "Current elements in the set"<<endl;
                // for (auto c : m) cout << c << " ";;
                // cout <<endl;
            }

            else {
                m.insert(s[r]);
                if (ans < m.size()) ans = m.size();
                // cout << "Ans: " <<ans<<endl;
            }
            r++;
        }
        return ans;
    }
};
