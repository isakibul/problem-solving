#include <iostream>
#include <vector>
#include <stdexcept>

std::vector<int> twoSum(const std::vector<int>& nums, int target) {
    for (size_t i = 0; i < nums.size(); ++i) {
        for (size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return {static_cast<int>(i), static_cast<int>(j)};
            }
        }
    }
    throw std::runtime_error("No solution found");
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = twoSum(nums, target);
    std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;

    return 0;
}
