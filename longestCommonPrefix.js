/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
  strs.sort();

  const first = strs[0];
  const last = strs[strs.length - 1];

  let prefix = "";

  for (let i = 0; i < first.length; i++) {
    if (first[i] === last[i]) {
      prefix += first[i];
    } else {
      break;
    }
  }

  return prefix;
};

const strs = ["dog", "racecar", "car"];
const result = longestCommonPrefix(strs);
console.log(result);
