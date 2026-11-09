class MinStack:

    def __init__(self):
        self.backing_array = []
        self.seen_min = float("inf")

    def push(self, val: int) -> None:
        if val < self.seen_min:
            self.seen_min = val
        self.backing_array.append((val, self.seen_min))

    def pop(self) -> None:
        item = self.backing_array.pop()
        if len(self.backing_array)>=1:
            self.seen_min = self.backing_array[-1][1]
        else:
            self.seen_min=float("inf")


    def top(self) -> int:
        return self.backing_array[-1][0]

    def getMin(self) -> int:
        return self.seen_min
        
        
