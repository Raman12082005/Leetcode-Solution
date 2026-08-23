class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        // base cases


        int leftsum = 0, leftq = 0;
        int half = n/2;
        for(int i=0; i<half; i++){
            if(num[i] == '?') leftq++;
            else leftsum += num[i] - '0';
        }

        int rightsum = 0, rightq = 0;
        for(int i=half; i<n; i++){
            if(num[i] == '?') rightq++;
            else rightsum += num[i] - '0';
        }

        int qdiff = leftq - rightq;
        int sumdiff = leftsum - rightsum;
        if(abs(qdiff)%2 == 1) return true;

        return sumdiff != 9 * (rightq-leftq) / 2;
    }
};