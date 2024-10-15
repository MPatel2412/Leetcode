class Solution {
public:
    long long minimumSteps(string s) {
        int whitePosition = 0;
        long long totalSwaps = 0;

        // Iterate through each ball (character) in the string
        for (int currentPos = 0; currentPos < s.length(); currentPos++) {
            if (s[currentPos] == '0') {
                
                totalSwaps += currentPos - whitePosition;

                whitePosition++;
            }
        }

        return totalSwaps;
    }
};