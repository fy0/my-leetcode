class Solution {
public:
    void work(vector<string> &buf, string prefix, int lpn, int cur, int n) {
        if (prefix.length() == n*2) {
            if (!lpn) buf.push_back(prefix);
            return;
        }
        if (lpn < n) work(buf, prefix + '(', lpn+1, cur+1, n);
        if (lpn > 0) work(buf, prefix + ')', lpn-1, cur+1, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> buf;
        
        // lpn == left parenthesis number
        this->work(buf, "", 0, 0, n);
        return buf;
    }
};
