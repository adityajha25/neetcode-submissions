class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        price=prices[0]
        best=0
        for item in prices[1:]:
            best = max(best, item-price)
            price = min(price, item)
        return best
        