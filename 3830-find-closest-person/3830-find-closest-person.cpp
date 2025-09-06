class Solution {
public:
    int findClosest(int x, int y, int z) {
        int distX = abs(z-x);
        int distY = abs(z-y);

        if(distY > distX){
            return 1;
        } else if(distX > distY){
            return 2;
        }
        
        if(distX == 0 && distY != 0){
            return 1;
        }
        else if(distX !=0 && distY == 0){
            return 2;
        }

        return 0;
    }
};