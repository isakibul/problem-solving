function filterPositive(arr) {
  let result = [];
  for (let i = 0; i < arr.length; i++) {
    if (typeof arr[i] === "number" && arr[i] > 0) {
      result.push(arr[i]);
    }
  }
}

const inputArray = [1, "a", -2, null, 3, "b", -4];
const result = filterPositive(inputArray);
console.log(result);
