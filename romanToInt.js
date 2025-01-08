/**
 * @param {string} s
 * @return {number}
 */
function romanToInt(s) {
  const romanValues = {
    M: 1000,
    D: 500,
    C: 100,
    L: 50,
    X: 10,
    V: 5,
    I: 1,
  };

  let result = 0;
  let len = s.length;

  for (let i = 0; i < len; i++) {
    let currentValue = romanValues[s[i]];
    let nextValue = romanValues[s[i + 1]];

    if (currentValue < nextValue) {
      result -= currentValue;
    } else {
      result += currentValue;
    }
  }

  return result;
}

const s = "MCMXCIV";
const result = romanToInt(s);
console.log(result);
