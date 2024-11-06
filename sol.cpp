class Solution {
public:

    int getPivotIndex(vector<int>&nums){
        int n = nums.size();
        int start = 0, end = n-1, mid = start + (end-start)/2;

        while(start<=end){
            if(mid+1<n && nums[mid] > nums[mid+1]){
                return mid;
            }
            else if(mid-1>=0 && nums[mid] < nums[mid-1]){
                return mid-1;
            }
            else if(nums[start] > nums[mid]){
                end = mid-1;
            }
            else if(start == end){
                return start;
            }
            else{
                start = mid+1;
            }
            mid = start + (end-start)/2;
        }
        return -1;
    }

    int binarySearch(int start, int end, int target, vector<int>arr){
        int mid = start+(end-start)/2;
        while (start <= end) {
            if (target == arr[mid]) {
                return mid;
            } else if (target > arr[mid]) {
                start = mid + 1;
            } else {
                end =  mid - 1;
            }
            mid = (start + end) / 2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivotIndex = getPivotIndex(nums);
        int n = nums.size();
        if(target>=nums[0] && target <= nums[pivotIndex]){
            // BS
            int ans = binarySearch(0, pivotIndex, target, nums);
            return ans;
        }
        else{
            // BS
            int ans = binarySearch(pivotIndex+1, n-1, target, nums);
            return ans;
        }

        return -1;
    }

    // line A -> index = 0 -> pivotIndex;
    // line B -> index = pivotIndex+1 -> n-1;

    // if target is in line A then search there
    // else search in line B
};
