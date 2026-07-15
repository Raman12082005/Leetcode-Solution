class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddsum = n * n;
        int evensum = n*(n+1);
        while(oddsum != 0){
            int rem = evensum %oddsum;
            evensum = oddsum;
            oddsum = rem;
        }
        return evensum;
    }
};