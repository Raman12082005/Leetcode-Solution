class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        // base cases
        if(n == 1) return 0;
        if(n == 2){
            string temp = s;
            sort(temp.begin(), temp.end());
            if(temp == s) return 0;
            return -1;
        }

        string temp = s;
        string sorted = s;
        sort(sorted.begin(), sorted.end());

        // case 0
        if(temp == sorted) return 0;
        
        // case 1
        sort(temp.begin(), temp.end()-1);
        if(temp == sorted) return 1;
        temp = s;
        sort(temp.begin()+1, temp.end());
        if(temp == sorted) return 1;
        
        // case 2
        temp = s;
        sort(temp.begin(), temp.end()-1);
        sort(temp.begin()+1, temp.end());
        if(temp == sorted) return 2;

        temp = s;
        sort(temp.begin()+1, temp.end());
        sort(temp.begin(), temp.end()-1);
        if(temp == sorted) return 2;

        return 3;
    }
};