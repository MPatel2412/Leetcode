class Solution {
public:
    bool check(long l,long r,long x)
    {
        if(l > r)
            return false;
        long mid = l + (r-l)/2;
        if(mid*mid == x)
            return true;
        if(mid*mid > x)
            return check(l,mid-1,x);
        
        return check(mid+1,r,x);
    }
public:
    bool judgeSquareSum(int c) {
        for(long long a = 0; a*a <= c; a++)
        {
            int b = c - (int)(a*a);
            if(check(0,b,b))
                return true;
        }
        return false;
    }
    
};