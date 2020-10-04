## PANCAKE SORTING CHALLENGE

### The idea behind this sorting technique is that we will be provided with a unsorted array and the challenge is to sort it using a single operation on array.
`flip(arr, i): Reverse array from 0 to i`

### Algo idea induction:
  1.0. Use a **curr** locator depicting the nth element in begining. Decrement the curr each time by 1 while it is greater than 1.
  
  2.0. For each curr, perform two steps
  
  2.1. `flip(arr, maxIndex)` where maxIndex is index of maximum element of array in indices 0 to curr-1.
  
  2.2. `flip(arr, curr-1)`
