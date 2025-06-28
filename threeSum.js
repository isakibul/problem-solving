/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
  const result = new Set();

  for (let i = 0; i < nums.length; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      for (let k = j + 1; k < nums.length; k++) {
        if (nums[i] + nums[j] + nums[k] === 0) {
          const triplet = [nums[i], nums[j], nums[k]].sort((a, b) => a - b);
          result.add(triplet.toString());
        }
      }
    }
  }
  return Array.from(result).map((str) => str.split(",").map(Number));
};

const nums = [-1, 0, 1, 2, -1, -4];
const result = threeSum(nums);
console.log(result);

/**
 * If we use this brute force approach, the time complexity is O(n^3) because we have three nested loops. This is not efficient for large arrays. We can optimize this solution using sorting and two pointers technique, which will reduce the time complexity to O(n^2).
 */
