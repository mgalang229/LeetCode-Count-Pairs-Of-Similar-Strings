class Solution {
    bool is_similar(string s1, string s2) {
        bool vis1[26], vis2[26];
        memset(vis1, false, sizeof(vis1));
        memset(vis2, false, sizeof(vis2));
        for (char& c : s1) {
            vis1[c-'a'] = true;
        }
        for (char& c : s2) {
            vis2[c-'a'] = true;
        }
        for (int i = 0; i < 26; i++) {
            if (vis1[i] != vis2[i]) {
                return false;
            }
        }
        return true;
    }
    
public:
    int similarPairs(vector<string>& words) {
        int cnt = 0;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                cnt += (is_similar(words[i], words[j]));
            }
        }
        return cnt;
    }
};
