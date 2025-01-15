#include <iostream>
#include <vector>

int searchInsert(std::vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target) {
            return i;
        } else if (target < nums[i]) {
            return i;
        }
    }
    return nums.size();
}

int main() {
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 7;
    int result = searchInsert(nums, target);
    std::cout << result << std::endl;
    return 0;
}