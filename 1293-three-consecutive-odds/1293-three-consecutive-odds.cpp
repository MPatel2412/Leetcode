class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if(n <= 2)
            return false;
        
        if(n==3)
        {
            if((arr[0]%2 == 1) && (arr[1]%2==1) && (arr[2]%2==1))
                return true;
        }

        for(int i=0;i<=n-3;i++)
        {
            if((arr[i]%2==1) && (arr[i+1]%2==1) && (arr[i+2]%2==1))
                return true;
        }
        return false;
    }
};