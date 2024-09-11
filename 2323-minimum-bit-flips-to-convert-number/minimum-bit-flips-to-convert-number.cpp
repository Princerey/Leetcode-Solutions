class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
        bitset<32> startBit(start), goalBit(goal);
        int ans = 0;
        for(int i = 0; i < 32; i++) 
            if(startBit[i] != goalBit[i]) ans += 1;
        return ans;
    }
};