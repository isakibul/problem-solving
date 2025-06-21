/**
 * Brute force approach
 *
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  for (let i = 0; i < nums.length; i++) {
    for (let j = i + 1; j < nums.length; j++) {
      if (nums[i] + nums[j] == target) {
        return [i, j];
      }
    }
  }
};

/**
 * Two pointers approach
 *
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  let indexedNums = nums.map((value, index) => ({ value, index }));

  indexedNums.sort((a, b) => a.value - b.value);

  let left = 0;
  let right = indexedNums.length - 1;

  while (left < right) {
    let sum = indexedNums[left].value + indexedNums[right].value;

    if (sum === target) {
      return [indexedNums[left].index, indexedNums[right].index];
    } else if (sum < target) {
      left++;
    } else {
      right--;
    }
  }
};

/**
 * Hash map approach
 *
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  const hash = {};
  for (let i = 0; i < nums.length; i++) {
    let val = nums[i];
    hash[val] = i;
  }

  for (let i = 0; i < nums.length; i++) {
    const potKey = target - nums[i];
    if (hash[potKey] && hash[potKey] !== i) {
      return [i, hash[potKey]];
    }
  }
};

const result = twoSum([2, 7, 11, 15], 9);
console.log(result);
