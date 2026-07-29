class Solution {
private:
    vector<pair<int,int>>serves = {{100,0} , {75,25} ,{50,50} ,{25,75} };
    vector<vector<double>>help;
    double solve(double a , double b){
        if(a<=0  && b<=0) return 0.5;
        if(a<=0) return 1;
        if(b<=0) return 0;
        
        if(help[a][b] != -1.0) return help[a][b];
        double prob = 0.0;
        for(auto& p : serves){
            int a_taken = p.first;
            int b_taken = p.second;


            prob += solve(a-a_taken , b-b_taken);
        }

        return help[a][b] = 0.25 * prob;

    }
public:
    double soupServings(int n) {
        if(n>=5000) return 1;
        help.resize(n+1,vector<double>(n+1,-1.0));    
        return solve(n,n);
    }
};