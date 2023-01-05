class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rect) {
        map<pair<int,int>,int> tracker;
        for(auto x:rect){
            tracker[{x[0],x[1]}]++;
            tracker[{x[2],x[3]}]++;
            tracker[{x[0],x[3]}]--;
            tracker[{x[2],x[1]}]--;
        }
        int cornerSum=0;
        for(auto it=tracker.begin();it!=tracker.end();it++){
            if(it->second!=0){
                if(abs(it->second)!=1)return false;
                cornerSum++;
            }
        }
        return cornerSum==4;
    }
};