class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        // base cases


        int ans = 0;
        int hr=(stoi(endTime.substr(0, 2)) - stoi(startTime.substr(0, 2)))*3600;
        int min=(stoi(endTime.substr(3, 2)) - stoi(startTime.substr(3, 2)))*60;
        int sec=stoi(endTime.substr(6, 2)) - stoi(startTime.substr(6, 2));
        ans = (hr + min + sec);
        return ans;
    }
};