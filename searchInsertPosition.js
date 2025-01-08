/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function (nums, target) {
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === target) {
      return i;
    } else if (target < nums[i]) {
      return i;
    }
  }
  return nums.length;
};

const nums = [1, 3, 5, 6];
const target = 2;
const result = searchInsert(nums, target);
console.log(result);
