class SQL {
struct Table{
    int cols;
    int nextid = 1;
    map<int,vector<string>>rows;
};
public:
    unordered_map<string,Table> db;
    SQL(vector<string>& names, vector<int>& columns) {
        int n=names.size();
        for(int i=0;i<n;i++){
            db[names[i]].cols=columns[i];
        }
    }
    
    bool ins(string name, vector<string> row) {
        int s=row.size();
        if(db.count(name) == 0 || db[name].cols != s) return false;
        db[name].rows[db[name].nextid] = row;
        db[name].nextid++;
        return true;
    }
    
    void rmv(string name, int rowId) {
        if(db.count(name)==0 || db[name].rows.count(rowId)==0)return;
        db[name].rows.erase(rowId);
        
    }
    
    string sel(string name, int rowId, int columnId) {
        if(db.count(name) == 0 || columnId > db[name].cols || db[name].rows.count(rowId) == 0) return "<null>";
        return db[name].rows[rowId][columnId-1];
        
    }
    
    vector<string> exp(string name) {
        if(db.count(name)==0) return {};
        vector<string>ans;
        string curstring;
        for(auto&p : db[name].rows){
            curstring = to_string(p.first);
            for(string s : db[name].rows[p.first]){
                curstring += ","+s;
            }
            ans.push_back(curstring);
        }
        return ans;

        
    }
};

/**
 * Your SQL object will be instantiated and called as such:
 * SQL* obj = new SQL(names, columns);
 * bool param_1 = obj->ins(name,row);
 * obj->rmv(name,rowId);
 * string param_3 = obj->sel(name,rowId,columnId);
 * vector<string> param_4 = obj->exp(name);
 */