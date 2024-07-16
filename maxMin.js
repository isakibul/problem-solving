function maxMin(arr) {
  for (let i = 0; i < arr.length - 1; i++) {
    for (let j = 0; j < arr.length - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  const firstElement = arr[0];
  const lastElement = arr[arr.length - 1];
  return [firstElement, lastElement];
}

const inputArray = [1, 4, 2, 5, 9, 6, 7, 8];
const result = maxMin(inputArray);
console.log(result);
