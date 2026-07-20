class Solution {
private:
    int wordcount(string message){
        int ans=0;
        int i=0;
        while(i<message.size()){
            while(i<message.size() && message[i]!=' ')i++;
            ans++;
            i++;
        }
        return ans;

    }
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int>mp;
        int n = messages.size();
        for(int i=0;i<n;i++){
            string sender = senders[i];
            int ct= wordcount(messages[i]);
            mp[sender]+=ct;
        }
        vector<pair<int,string>>fin;
        for(pair<string,int>p : mp){
            fin.push_back({p.second , p.first});
        }

        sort(fin.begin(), fin.end() , [](pair<int,string>p1 , pair<int,string>p2){
            if(p1.first==p2.first) return p1.second>p2.second;
            return p1.first>p2.first;
        });

        return fin[0].second;
    }
};