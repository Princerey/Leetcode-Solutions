class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> numbers(n);
        numbers[0]=1;
        int power2=0;
        int power3=0;
        int power5=0;
        for(int i=1;i<n;i++){
            numbers[i]=min(numbers[power2]*2, min(numbers[power3]*3,numbers[power5]*5));
            if(numbers[i]==numbers[power2]*2){
                power2++;
            }
            if(numbers[i]==numbers[power3]*3){
                power3++;
            }
            if(numbers[i]==numbers[power5]*5){
                power5++;
            }
        }
        return numbers[n-1];
    }
};