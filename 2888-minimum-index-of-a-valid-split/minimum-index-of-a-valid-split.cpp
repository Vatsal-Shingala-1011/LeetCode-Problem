class Solution {
public:
int findDominantElement(vector<int>& nums) {//work because ele occur more than n/2 times
        int candidate = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == candidate) count++;
            else {
                count--;
                if (count == 0) {
                    candidate = nums[i];
                    count = 1;
                }
            }
        }
        return candidate;
    }
    
int findMinimumIndex(vector<int>& nums, int dominantElement) {
        int n = nums.size();
        int leftCount = 0, rightCount = 0,total=0;
        for(int i=0;i<n;i++){
            if(nums[i] == dominantElement) total++;
        }
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == dominantElement) leftCount++;
            rightCount=total-leftCount;
            if (leftCount * 2 > i + 1 && rightCount * 2 > n - i - 1) return i;
        }
        return -1;
    }
int minimumIndex(vector<int>& nums) {
        int dominantElement = findDominantElement(nums);
        return findMinimumIndex(nums, dominantElement);
    }
};

