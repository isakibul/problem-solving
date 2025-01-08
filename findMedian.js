/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function (nums1, nums2) {
  const merged = [...nums1, ...nums2].sort((a, b) => a - b);

  const n = merged.length;

  if (n % 2 === 1) {
    return merged[Math.floor(n / 2)];
  } else {
    const mid1 = merged[n / 2 - 1];
    const mid2 = merged[n / 2];
    return (mid1 + mid2) / 2;
  }
};

const nums1 = [1, 2];
const nums2 = [3, 4];

const result = findMedianSortedArrays(nums1, nums2);
console.log(result);
