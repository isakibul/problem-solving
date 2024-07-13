function reverseString(str) {
  let resultArray = [];
  for (let i = str.length - 1; i >= 0; i--) {
    resultArray.push(str[i]);
  }
  return resultArray.join("");
}

const result = reverseString("sakibul");
console.log(result);
