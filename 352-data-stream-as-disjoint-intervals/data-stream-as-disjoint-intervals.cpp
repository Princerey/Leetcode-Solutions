class SummaryRanges {
    set<int> iInt;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        iInt.insert(value);
        
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        if (iInt.size() == 0) return res;

        int start=-1, end=-1;
        for (auto val:iInt){
            if (start == -1) start = end = val;
            else if(end+1 == val) end = val;
            else {
                res.push_back({start,end});
                start = end = val;
            }
        }
        res.push_back({start,end});
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */