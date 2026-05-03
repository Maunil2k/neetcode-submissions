class Solution {
public:
    bool isPalindrome(string s) {
        int start=0, end=s.size()-1;
        while (start<=end) {
            int sc = s[start];
            if (!((sc>=65 && sc<=90) || (sc>=97 && sc<=122) || (sc>=48 && sc<=57))) {
                start++;
                continue;
            }

            int ec = s[end];
            if (!((ec>=65 && ec<=90) || (ec>=97 && ec<=122) || (ec>=48 && ec<=57))) {
                end--;
                continue;
            }

            if (sc >= 65 && sc<=90) sc = sc - 65 + 97;
            if (ec >= 65 && ec<=90) ec = ec - 65 + 97; 
            char sc_char = sc, ec_char = ec;
            if (sc_char != ec_char) {
                return false;
            }
            else {
                start++;
                end--;
            }
        }

        return true;
    }
};
