class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        vector<int> frequencies;
        for (auto it : mp) 
        {
            frequencies.push_back(it.second);
        }
        sort(frequencies.begin(), frequencies.end());
        int elementsRemoved = 0;
        for (int i = 0; i < frequencies.size(); i++) 
        {
            elementsRemoved += frequencies[i];
            if (elementsRemoved > k) 
            {
                return frequencies.size() - i;
            }
        }
        return 0;
    }
};