class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int length = s.size();
        letter * map_1 = new letter[length];
        letter * map_2 = new letter[length];
        for(int i=0; i<length; i++)
        {   
            for(int j=0;j<i;j++){
                if(s[i]==map_1[j].value){
                    if (map_1[j].next -> value != t[i]){
                        return false;
                    }
                }
                if(t[i]==map_2[j].value){
                    if (map_2[j].next -> value != s[i]){
                        return false;
                    }
                }

            }
            map_1[i].value = s[i];
            map_2[i].value = t[i];
            circle(map_1[i],map_2[i]);
        }
        return true;
    }
    class letter
    {
        public:
        char value;
        letter* next;
    };
    void circle(letter& x, letter& y)
    {
        x.next = &y;
        y.next = &x;
    }
};