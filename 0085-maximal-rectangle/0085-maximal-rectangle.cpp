class Solution {
public:
    int helper(vector<int>& arr){
        int n = arr.size();
        // base cases


        vector<int> nse(n, 0), pse(n, 0);
        stack<int> st1, st2;
        st1.push(0);
        for(int i=1; i<n; i++){
            while(!st1.empty() && arr[st1.top()] >= arr[i]) st1.pop();
            if(st1.empty()) pse[i] = 0;
            else pse[i] = st1.top() + 1;
            st1.push(i);
        }

        nse[n-1] = n;
        st2.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(!st2.empty() && arr[st2.top()] >= arr[i]) st2.pop();
            if(st2.empty()) nse[i] = n;
            else nse[i] = st2.top();
            st2.push(i);
        }

        int maxarea = INT_MIN;
        for(int i=0; i<n; i++){
            maxarea = max(maxarea, (nse[i]-pse[i])*arr[i]);
        }    
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // base cases


        int maxarea= INT_MIN;
        vector<int> arr(m, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == '1'){
                    if(arr[j] == 0){
                        arr[j] = 1;
                    }
                    else arr[j]++;
                }
                else{
                    arr[j] = 0;
                }
            }
            maxarea = max(maxarea, helper(arr));
        }
        return maxarea;
    }
};