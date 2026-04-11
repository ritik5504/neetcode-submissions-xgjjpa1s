class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end()) return 0;

        queue<string> q;
        q.push(beginWord);

        int step=1;

        while(!q.empty()){
            int size=q.size();

            for(int i=0;i<size;i++){
                string word=q.front();
                q.pop();

                if(word==endWord) return step;

                for(int i=0;i<word.length();i++){
                    char ori=word[i];

                    for(char ch='a'; ch<='z';ch++){
                        word[i]=ch;

                        if(st.find(word) != st.end()){
                            q.push(word);
                            st.erase(word);
                        }
                    }
                    word[i]=ori;

                }
            }
            step++;
        }
        return 0;
        
    }
};
