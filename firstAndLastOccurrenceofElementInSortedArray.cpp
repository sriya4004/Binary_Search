class Solution {
public:
    // Find first occurrence of target
    int firstOcu(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int first = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return first;
    }

    // Find last occurrence of target
    int lastOcu(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int last = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                last = mid;
                low = mid + 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return last;
    }

    // Return first and last index of target
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOcu(nums, target);
        if (first == -1) {
            return {-1, -1};
        }
        int last = lastOcu(nums, target);
        return {first, last};
    }
};
