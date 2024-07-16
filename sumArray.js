function sumArray(arr) {
  let sum = 0;
  for (let i = 0; i < arr.length; i++) {
    if (typeof arr[i] === "number") {
      sum += arr[i];
    }
  }
  return sum;
}

const inputArray = [1, 2, "a", 3, null, 4];
const result = sumArray(inputArray);
console.log(result);
