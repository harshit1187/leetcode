class Solution {
public:
    int lowerbound(vector<int>& arr, int size, int target) {
        int left = 0;
        int right = size - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        return right;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left=0;
        int right=m-1;
        while(left<right){
            int mid = left + (right - left) / 2;
            if (matrix[mid][0] >= target)
                right = mid;
            else
                left = mid + 1;
        }
        int index=left;
        if (matrix[index][0] == target)
            return true;

        if (matrix[index][0] > target)
            index--;

        if (index < 0)
            return false;
        int ans = lowerbound(matrix[index], n, target);
        if (matrix[index][ans] == target)
            return true;
        else
            return false;
    }
};