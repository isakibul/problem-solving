/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  if (prices.length < 2) return 0;

  let minPrice = prices[0];
  let maxProfit = 0;

  for (let i = 1; i < prices.length; i++) {
    const profit = prices[i] - minPrice;

    maxProfit = Math.max(maxProfit, profit);

    minPrice = Math.min(minPrice, prices[i]);
  }

  return maxProfit;
};

const prices = [7, 1, 5, 3, 6, 4];
const result = maxProfit(prices);
console.log(result);
