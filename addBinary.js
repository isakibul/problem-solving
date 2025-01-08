/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function (a, b) {
  const num1 = BigInt(`0b${a}`);
  const num2 = BigInt(`0b${b}`);

  const sum = num1 + num2;

  return sum.toString(2);
};

const inputOne =
  "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101";
const inputTwo =
  "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";
const result = addBinary(inputOne, inputTwo);
console.log(result);
