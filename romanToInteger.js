var romanToInt = function (s) {
  const romanMap = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000,
  };

  let total = 0;
  let previous = 0;

  for (let i = 0; i < s.length; i++) {
    let current = romanMap[s[i]];

    if (current > previous) {
      total += current - 2 * previous;
    } else {
      total += current;
    }

    previous = current;
  }

  return total;
};

const result = romanToInt("MCMXCIV");
console.log(result);
