/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  const stack = [];
  const parens = "()[]{}";

  let i = 0;
  while (i < s.length) {
    stack.push(s[i]);
    i++;

    const open = stack[stack.length - 2];
    const close = stack[stack.length - 1];

    const potParens = open + close;

    if (parens.includes(potParens)) {
      stack.pop();
      stack.pop();
    }
  }

  return stack.length === 0;
};

const result = isValid("()[]{}");
console.log(result);
