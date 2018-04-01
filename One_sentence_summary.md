# One sentence summary of solution ideas

For review purpose. Not strictly one sentence, but I will try to keep it less than 50 words.

## 001-100

1. Two Sum: use hashmap to get O(n).

2. Add two numbers: keep an eye on the carry and corner cases.

3. Longest substring without repeating characters: sliding window, use a hashmap to keep char last appearing index.

4. Median of two sorted array: try to write a "get kth number" helper function (recursive); calculate median index in merged array (but do not need really merge); key idea is still binary search.

5. Longest palindromic substring: expand around center; Manacher's Algorithm - ref. 647, 214; may also try dp.

6. ZigZag conversion: create an array of strings; n == 0, step = 1; n == sz - 1, step = -1; row += step; concatenate the array of strings.

7. Reverse integer: ret = 0; while (x / 10); remember check overflow.

8. String to integer (atoi): wierd test cases, don't spend too much time on it.

9. Palindrome number: one int extra cost is necessary.

10. Regular expression matching: recursive, may have costs to create substring; or dp[i, j] == true means pattern.substr(0, j) matches teststr.substr(0, i).

11. Container with most water: two pointers; h[left] < h[right] ? ++left : --right.

12. Integer to Roman: prepare a value - Roman map; for each loop, num -= numval[i], ret += Roman[i].

13. Roman to integer: prepare a Roman - value map. m[s[i]] < m[s[i + 1]] ? ret -= m[s[i++]] : ret += m[s[i++]].

14. Longest common prefix: general scan works; may also try binary search and divide & conquer.

15. 3 sum: general n-sum question, sort and then use 2 pointers for each loop; remember to bypass same elements to avoid duplicate triplets.

## 101-200

## 201-300

222. Count Complete Tree Nodes: Calculate height of left and right subtree.

## 301-400

309. Best Time to Buy and Sell Stock with Cooldown: DP, finite state machine.

389. Find the Difference: counter or XOR all.

## 401-500

## 501-600

## 601-700

## 701-800