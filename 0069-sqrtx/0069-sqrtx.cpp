class Solution {
public:
    int mySqrt(int x) {
        long long n = 0;

        for(int i = 0 ; i-1 < x ; i++){
            if(x >= n && (x < (n + ((2*i) +1)))){
                return i;
            }
            n += ((2*i) + 1);
        }

        return 0;
    }
};