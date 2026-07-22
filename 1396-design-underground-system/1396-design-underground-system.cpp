class UndergroundSystem {
public:
    unordered_map<int , pair<string,int>> check_in;
    unordered_map<string,pair<int,int>>check_out;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        check_in[id] = {stationName , t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string start_st= check_in[id].first;
        int start_time = check_in[id].second;
        string route = start_st + "-" + stationName;
        check_out[route].first += t-start_time;
        check_out[route].second ++;

        check_in.erase(id);

    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "-" + endStation;
        return (double)check_out[route].first/check_out[route].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */