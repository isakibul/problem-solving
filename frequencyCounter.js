function frequencyCounter(arr) {
  return arr.reduce((freqMap, num) => {
    if (freqMap[num]) {
      freqMap[num]++;
    } else {
      freqMap[num] = 1;
    }
    return freqMap;
  }, {});
}

console.log(frequencyCounter([10, 10, 20, 20, 20]));
