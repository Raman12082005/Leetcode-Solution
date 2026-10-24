class Solution {
public:
    int countDaysTogether(string aa, string al, string ba, string bl) {
        // case 1
        if(al < ba || bl < aa) return 0;
        if(al.substr(0, 2) == ba.substr(0, 2) && al.substr(3, 2) < ba.substr(3, 2)) return 0;
        if(bl.substr(0, 2) == aa.substr(0, 2) && bl.substr(3, 2) < aa.substr(3, 2)) return 0;

        // case 2
        vector<int> days = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int maxMA = max(stoi(aa.substr(0, 2)), stoi(ba.substr(0, 2)));
        int maxDA = INT_MIN;
        if(maxMA == stoi(aa.substr(0, 2))) maxDA = max(maxDA, stoi(aa.substr(3, 2)));
        if(maxMA == stoi(ba.substr(0, 2))) maxDA = max(maxDA, stoi(ba.substr(3, 2)));

        int minML = min(stoi(al.substr(0, 2)), stoi(bl.substr(0, 2)));
        int minDL = INT_MAX;
        if(minML == stoi(al.substr(0, 2))) minDL = min(minDL, stoi(al.substr(3, 2)));
        if(minML == stoi(bl.substr(0, 2))) minDL = min(minDL, stoi(bl.substr(3, 2)));

        if(maxMA == minML) return minDL - maxDA + 1;
        int day = 0;
        day += (days[maxMA] - maxDA + 1);
        int temp = maxMA+1;
        while(temp != minML){
            day += days[temp];
            temp++;
        }
        day += minDL;
        return day;
    }
};