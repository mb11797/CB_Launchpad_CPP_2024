class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;

        for(char ch: t){
            m2[ch]++;
        }

        int matchedCount = 0;
        int desiredMatchedCount = t.length();

        int beg = -1, en = -1;
        int ansBeg = -1, ansEn = -1;

        while(true){

            bool loop1Executed = false;
            bool loop2Executed = false;

            while(en+1 < n && matchedCount < desiredMatchedCount){
                // expand window in right direction
                en++;
                char ch = s[en];
                m1[ch] = (m1.count(ch) > 0 ? m1[ch] + 1 : 1);

                if(m1[ch] <= (m2.count(ch) > 0 ? m2[ch] : 0)){
                    matchedCount++;
                }
                loop1Executed = true;
            }

            while(beg < en && matchedCount == desiredMatchedCount){
                // beg < en check bcz substring is from beg + 1 to en
                if((ansBeg == -1 && ansEn == -1) || (en - beg) < (ansEn - ansBeg)){
                    ansBeg = beg;
                    ansEn = en;
                }
                // Shrink from left side
                beg++;
                char ch = s[beg];
                m1[ch]--;
                if(m1[ch] == 0){
                    m1.erase(ch);
                }

                if((m1.count(ch) > 0 ? m1[ch] : 0) < (m2.count(ch) > 0 ? m2[ch] : 0)){
                    matchedCount--;
                }
                loop2Executed = true;
            }

            if(!loop1Executed && !loop2Executed)
                break;
        }

        if(ansBeg != -1 || ansEn != -1){
            // str.substr(begIdx, lenOfSubstringToCut)
            return s.substr(ansBeg+1, (ansEn - ansBeg));
        }

        return "";
    }
};