class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> timeMap;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        timeMap[key].emplace_back(timestamp,value);
    }
    
    string get(string key, int timestamp) {
        int l=0,r = timeMap[key].size()-1;
        string ret ="";
        while(l <= r){
            int m = l + (r-l)/2;
            if(timeMap[key][m].first <= timestamp){
                ret = timeMap[key][m].second;
                l = m +1;
            }else r = m -1;
        }
        return ret;
    }
};
