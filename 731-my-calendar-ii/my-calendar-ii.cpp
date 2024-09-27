class MyCalendarTwo {
public:
    vector<pair<int,int>> vp,vpd;
    MyCalendarTwo() {
        vp.clear();
        vpd.clear();
    }
    
    bool book(int s, int e) {
        e--;
        if(vpd.size()){
            for(auto x:vpd){
                if(s>=x.first and s<=x.second){
                    return false;
                }else if(e>=x.first and e<=x.second){
                    return false;
                }else if(x.first>=s and x.second<=e){
                    return false;
                }
            }
        }
        for(auto x:vp){
            if(s>=x.first and s<=x.second){
                vpd.push_back({s,min(e,x.second)});
            }else if(e>=x.first and e<=x.second){
                vpd.push_back({max(x.first,s),e});
            }else if(x.first>=s and x.second<=e){
                vpd.push_back({x.first,x.second});
            }
        }
        vp.push_back({s,e});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */