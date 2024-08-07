const deepClone = (obj) => {
  return (newObj = JSON.parse(JSON.stringify(obj)));
};

const original = {
  a: 1,
  b: [2, 3],
  c: { d: 4 },
};

const clone = deepClone(original);
console.log(clone);
