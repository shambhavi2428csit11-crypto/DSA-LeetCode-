class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end()){
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        int step=1;

        while(!q.empty()){
            int size=q.size();

            for(int j=0;j<size;j++){
                string p=q.front();
                q.pop();
                if(p==endWord){
                    return step;
                }
                for(int i=0;i<p.length();i++){
                    string p1=p;
                    for(char ch='a';ch<='z';ch++){
                        p1[i]=ch;
                        if(st.find(p1)!=st.end()){
                            q.push(p1);
                            st.erase(p1); 
                        }
                    }

                }
                
            }
            step++;
        }
        return 0;
     }
};