class Solution {
public:
    vector<int> sumZero(int n) {
        int even = false;
        if(n%2==0){
            even = true;
        }   
        vector<int> ans;
        if(even){
            int num = n/2;
            for(int i=1; i<=num; i++)
            {
                ans.push_back(i);
                ans.push_back(-1*i);
            }
        }
        else{
            int num = (n-1)/2;
            for(int i=-num; i <= num; i++){
                ans.push_back(i);
            }
        }
        return ans;
    }
};