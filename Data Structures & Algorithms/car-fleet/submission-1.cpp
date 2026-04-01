class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        int n = position.size();
        for(int i=0;i<n;i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.rbegin(),cars.rend());
        stack<double> stack;
        for(auto c : cars){
            double time = (double)(target-c.first) / c.second;
            if(!stack.empty() && time <= stack.top()){
                continue;
            }else {
                stack.push(time);
            }
        }
        return stack.size();
    }
};
