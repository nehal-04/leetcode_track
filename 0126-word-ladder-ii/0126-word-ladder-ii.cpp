class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string word, string beginWord, vector<string>& path)
    {
        if(word == beginWord)
        {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for(string p : parent[word])
        {
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord,
                                       string endWord,
                                       vector<string>& wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if(!dict.count(endWord))
            return {};

        queue<string> q;
        unordered_set<string> visited;

        q.push(beginWord);
        visited.insert(beginWord);

        bool found=false;

        while(!q.empty() && !found)
        {
            int sz=q.size();

            unordered_set<string> levelVisited;

            while(sz--)
            {
                string word=q.front();
                q.pop();

                for(int i=0;i<word.size();i++)
                {
                    string next=word;

                    for(char c='a';c<='z';c++)
                    {
                        next[i]=c;

                        if(!dict.count(next))
                            continue;

                        if(visited.count(next))
                            continue;

                        if(!levelVisited.count(next))
                        {
                            levelVisited.insert(next);
                            q.push(next);
                        }

                        parent[next].push_back(word);

                        if(next==endWord)
                            found=true;
                    }
                }
            }

            for(auto &x:levelVisited)
                visited.insert(x);
        }

        if(!found)
            return {};

        vector<string> path;
        path.push_back(endWord);

        dfs(endWord, beginWord, path);

        return ans;
    }
};