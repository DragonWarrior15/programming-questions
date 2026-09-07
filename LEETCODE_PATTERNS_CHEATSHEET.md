# LeetCode Patterns Cheat Sheet

Use this sheet to recognize common problem types, recall their standard approach, and revise Python templates quickly.

## Interview checklist

Before coding, answer:

1. What are the inputs, outputs, and constraints?
2. What edge cases matter?
3. What is the brute-force solution and its complexity?
4. What work is repeated, and can it be avoided?
5. What invariant will the optimized solution maintain?
6. What are the final time and space complexities?

Common constraint hints:

| Maximum `n` | Complexity usually expected |
|---:|---|
| `10–20` | Exponential/backtracking may work |
| `100` | `O(n³)` may work |
| `1,000` | Usually `O(n²)` or better |
| `10⁴–10⁵` | Usually `O(n log n)` or `O(n)` |
| `10⁶` | Usually close to `O(n)` |

---

## 1. Hash maps and sets

### Recognition cues

- Need fast lookup, duplicate detection, counting, grouping, or complements.
- Wording such as “have we seen this?”, “frequency”, or “pair summing to target”.

### Core idea

Trade extra memory for average `O(1)` lookup.

```python
seen = set()
for value in nums:
    if value in seen:
        return True
    seen.add(value)
```

Frequency map:

```python
frequency = {}
for value in nums:
    frequency[value] = frequency.get(value, 0) + 1
```

### Remember

- Dictionary/set operations are average `O(1)`, not guaranteed worst-case `O(1)`.
- Ask whether sorting could replace the extra memory.

### Practice

- 1 Two Sum
- 49 Group Anagrams
- 128 Longest Consecutive Sequence
- [560 Subarray Sum Equals K](hashmap/subarray_sum_equals_k.py)

---

## 2. Two pointers

### Recognition cues

- Sorted array, palindrome, pair search, in-place compaction, or comparison from both ends.

### Opposite-direction template

```python
left, right = 0, len(nums) - 1

while left < right:
    current = nums[left] + nums[right]
    if current == target:
        return [left, right]
    if current < target:
        left += 1
    else:
        right -= 1
```

### Same-direction template

```python
write = 0
for read in range(len(nums)):
    if should_keep(nums[read]):
        nums[write] = nums[read]
        write += 1
```

### Complexity

Usually `O(n)` time and `O(1)` extra space.

### Practice

- 125 Valid Palindrome
- 167 Two Sum II
- 283 Move Zeroes
- 15 3Sum

---

## 3. Sliding window

### Recognition cues

- Longest/shortest valid **contiguous** substring or subarray.
- Add items on the right; remove items on the left when invalid.

### Variable-size window

```python
left = 0
answer = 0

for right in range(len(nums)):
    add(nums[right])

    while window_is_invalid():
        remove(nums[left])
        left += 1

    answer = max(answer, right - left + 1)
```

### Fixed-size window

```python
window_sum = sum(nums[:k])
answer = window_sum

for right in range(k, len(nums)):
    window_sum += nums[right] - nums[right - k]
    answer = max(answer, window_sum)
```

### Pitfall

Sliding window usually needs a monotonic condition. With arbitrary negative numbers, growing the window may not predictably increase a sum.

### Practice

- 3 Longest Substring Without Repeating Characters
- 209 Minimum Size Subarray Sum
- 424 Longest Repeating Character Replacement
- 567 Permutation in String

---

## 4. Prefix sums

### Recognition cues

- Many range-sum queries.
- Count subarrays with a given sum.
- Repeatedly computing sums of contiguous ranges.

### Range sum

```python
prefix = [0]
for value in nums:
    prefix.append(prefix[-1] + value)

# Inclusive range [left, right]
range_sum = prefix[right + 1] - prefix[left]
```

### Count subarrays whose sum equals `k`

```python
counts = {0: 1}
current = 0
answer = 0

for value in nums:
    current += value
    answer += counts.get(current - k, 0)
    counts[current] = counts.get(current, 0) + 1
```

Why it works: if `prefix[j] - prefix[i] == k`, then `prefix[i] == prefix[j] - k`.

### Practice

- 303 Range Sum Query
- 560 Subarray Sum Equals K
- 525 Contiguous Array
- 974 Subarray Sums Divisible by K

---

## 5. Binary search

### Recognition cues

- Sorted search space.
- Need first/last valid position.
- “Minimum possible maximum” or “maximum possible minimum”.
- A yes/no feasibility condition changes only once.

### Exact search

```python
left, right = 0, len(nums) - 1

while left <= right:
    middle = (left + right) // 2
    if nums[middle] == target:
        return middle
    if nums[middle] < target:
        left = middle + 1
    else:
        right = middle - 1

return -1
```

### First valid answer

```python
left, right = minimum_answer, maximum_answer

while left < right:
    middle = (left + right) // 2
    if feasible(middle):
        right = middle
    else:
        left = middle + 1

return left
```

### Pitfalls

- Define precisely what `left` and `right` represent.
- Know whether the interval is closed `[left, right]` or half-open `[left, right)`.

### Practice

- 704 Binary Search
- 33 Search in Rotated Sorted Array
- 153 Find Minimum in Rotated Sorted Array
- 875 Koko Eating Bananas

---

## 6. Stack and monotonic stack

### Recognition cues

- Nested structures or matching brackets.
- Nearest/next greater or smaller element.
- Undoing or evaluating expressions.

### Bracket stack

```python
pairs = {')': '(', ']': '[', '}': '{'}
stack = []

for char in s:
    if char in pairs:
        if not stack or stack.pop() != pairs[char]:
            return False
    else:
        stack.append(char)

return not stack
```

### Monotonic decreasing stack

```python
answer = [-1] * len(nums)
stack = []  # indexes whose next greater value is unknown

for i, value in enumerate(nums):
    while stack and nums[stack[-1]] < value:
        previous = stack.pop()
        answer[previous] = value
    stack.append(i)
```

Each index is pushed and popped at most once: `O(n)`.

### Practice

- 20 Valid Parentheses
- 155 Min Stack
- 739 Daily Temperatures
- 84 Largest Rectangle in Histogram

---

## 7. Linked-list pointers

### Recognition cues

- Reverse links, find a middle/cycle, merge lists, or remove nodes.

### Reverse a list

```python
previous = None
current = head

while current:
    following = current.next
    current.next = previous
    previous = current
    current = following

return previous
```

### Fast and slow pointers

```python
slow = fast = head

while fast and fast.next:
    slow = slow.next
    fast = fast.next.next
```

- When `fast` finishes, `slow` is near the middle.
- If `slow == fast` after movement, there is a cycle.

### Dummy node

Use a dummy node when the head might be removed or changed. It eliminates special handling for the first node.

### Practice

- 206 Reverse Linked List
- 21 Merge Two Sorted Lists
- 141 Linked List Cycle
- 19 Remove Nth Node From End

---

## 8. Trees: DFS and BFS

### Recognition cues

- Parent-child hierarchy, subtree calculations, paths, levels, or ancestors.

### Recursive DFS

```python
def dfs(node):
    if node is None:
        return base_value

    left = dfs(node.left)
    right = dfs(node.right)
    return combine(node.val, left, right)
```

Ask: what information must each child return to its parent?

### Level-order BFS

```python
from collections import deque

queue = deque([root])

while queue:
    level_size = len(queue)
    for _ in range(level_size):
        node = queue.popleft()
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
```

### Complexity

Usually `O(n)` time. Space is `O(h)` for DFS recursion or `O(w)` for BFS, where `h` is height and `w` is maximum width.

### Practice

- 104 Maximum Depth of Binary Tree
- 226 Invert Binary Tree
- 102 Binary Tree Level Order Traversal
- 543 Diameter of Binary Tree
- 98 Validate Binary Search Tree

---

## 9. Graphs

### Recognition cues

- Entities connected by relationships.
- Grids with movement between neighboring cells.
- Components, reachability, cycles, dependencies, or shortest unweighted paths.

### DFS

```python
def dfs(node):
    if node in visited:
        return
    visited.add(node)

    for neighbor in graph[node]:
        dfs(neighbor)
```

### BFS

```python
from collections import deque

queue = deque([start])
visited = {start}

while queue:
    node = queue.popleft()
    for neighbor in graph[node]:
        if neighbor not in visited:
            visited.add(neighbor)
            queue.append(neighbor)
```

Use BFS for shortest paths in an unweighted graph. Mark nodes visited when enqueuing them, not when removing them.

### Topological sort

Use for directed dependencies/prerequisites. Kahn's algorithm repeatedly processes nodes with indegree zero. If fewer than `n` nodes are processed, a cycle exists.

### Practice

- 200 Number of Islands
- 133 Clone Graph
- 207 Course Schedule
- 994 Rotting Oranges

---

## 10. Heap / priority queue

### Recognition cues

- Repeatedly need the minimum/maximum.
- Need top `k`, merge sorted streams, or schedule by priority.

Python's `heapq` is a min-heap:

```python
import heapq

heap = []
heapq.heappush(heap, value)
smallest = heapq.heappop(heap)
```

Maintain the `k` largest values with a min-heap of size `k`:

```python
heap = []

for value in nums:
    heapq.heappush(heap, value)
    if len(heap) > k:
        heapq.heappop(heap)
```

Complexity: inserting/removing is `O(log k)`; reading the minimum is `O(1)`.

### Practice

- 215 Kth Largest Element in an Array
- 347 Top K Frequent Elements
- 973 K Closest Points to Origin
- 295 Find Median from Data Stream

---

## 11. Backtracking

### Recognition cues

- Generate all combinations, permutations, subsets, or valid arrangements.
- Small input size and exponential output/search space.

### Choose → explore → undo

```python
answer = []

def backtrack(start, path):
    if is_solution(path):
        answer.append(path.copy())
        return

    for i in range(start, len(options)):
        if not is_valid(options[i], path):
            continue

        path.append(options[i])
        backtrack(i + 1, path)
        path.pop()
```

### Important distinctions

- Subsets/combinations: usually advance a `start` index.
- Permutations: usually track which elements are used.
- Pruning: stop a branch as soon as it cannot lead to a valid answer.

### Practice

- 78 Subsets
- 46 Permutations
- 39 Combination Sum
- 79 Word Search

---

## 12. Greedy algorithms

### Recognition cues

- Need an optimum but a local choice may permanently simplify the remaining problem.
- Intervals, jumps, scheduling, or resource allocation.

### How to justify a greedy solution

Do not rely only on intuition. State:

1. The choice made at each step.
2. The invariant preserved.
3. Why replacing any optimal solution's choice with yours cannot make it worse (exchange argument).

### Interval example

To keep the maximum number of non-overlapping intervals, sort by ending time and repeatedly choose the interval that ends earliest.

### Practice

- 55 Jump Game
- 45 Jump Game II
- 134 Gas Station
- 435 Non-overlapping Intervals

---

## 13. Dynamic programming

### Recognition cues

- Count ways, find min/max cost, or decide possibility.
- The solution can be expressed using answers to smaller overlapping subproblems.

### DP recipe

1. Define the state in one sentence.
2. Write the recurrence.
3. Set base cases.
4. Decide the evaluation order.
5. Identify the final state.
6. Consider reducing memory.

### One-dimensional template

```python
dp = [0] * (n + 1)
dp[0] = base_case

for i in range(1, n + 1):
    dp[i] = transition_using_previous_states

return dp[n]
```

### Memoized recursion

```python
from functools import cache

@cache
def solve(state):
    if is_base_case(state):
        return base_value
    return combine(solve(next_state) for next_state in choices(state))
```

### Common state shapes

- `dp[i]`: answer using the first `i` items.
- `dp[i][j]`: answer for two positions, capacities, or string prefixes.
- `dp[index][remaining]`: answer from an index with a remaining target/resource.

### Practice

- 70 Climbing Stairs
- 198 House Robber
- 322 Coin Change
- 300 Longest Increasing Subsequence
- 1143 Longest Common Subsequence

---

## 14. Union-Find / Disjoint Set Union

### Recognition cues

- Repeatedly connect items and ask whether they belong to the same component.
- Undirected cycle detection or merging accounts/groups.

```python
class DSU:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, a, b):
        root_a = self.find(a)
        root_b = self.find(b)

        if root_a == root_b:
            return False

        if self.size[root_a] < self.size[root_b]:
            root_a, root_b = root_b, root_a

        self.parent[root_b] = root_a
        self.size[root_a] += self.size[root_b]
        return True
```

With path compression and union by size, operations are effectively constant amortized time.

### Practice

- 547 Number of Provinces
- 684 Redundant Connection
- 721 Accounts Merge

---

## 15. String algorithms

### KMP and the LPS array

Use KMP when matching a pattern efficiently or reasoning about prefix/suffix overlap.

`lps[i]` is the length of the longest **proper prefix** of `pattern[:i + 1]` that is also its suffix.

```python
def build_lps(pattern):
    lps = [0] * len(pattern)
    prefix_len = 0
    i = 1

    while i < len(pattern):
        if pattern[i] == pattern[prefix_len]:
            prefix_len += 1
            lps[i] = prefix_len
            i += 1
        elif prefix_len > 0:
            prefix_len = lps[prefix_len - 1]
        else:
            i += 1

    return lps
```

On a mismatch:

- If `prefix_len > 0`, fall back to the next possible border and retry the same `i`.
- If `prefix_len == 0`, no prefix works; advance `i`.

### LeetCode 459: Repeated Substring Pattern

```python
def repeatedSubstringPattern(s):
    lps = build_lps(s)
    border_length = lps[-1]
    unit_length = len(s) - border_length

    return border_length > 0 and len(s) % unit_length == 0
```

Why: a border of length `n - unit_length` means the string has period `unit_length`. Divisibility confirms that complete copies fill the string.

Complexity: `O(n)` time and `O(n)` space.

### Trie recognition cues

- Many prefix queries, autocomplete, or dictionary word search.
- Operations are proportional to word length rather than number of stored words.

### Practice

- 28 Find the Index of the First Occurrence in a String
- 459 Repeated Substring Pattern
- 208 Implement Trie
- 1392 Longest Happy Prefix

---

## Pattern selection map

```text
Need fast existence/counting?              Hash map / set
Sorted array with pair/range behavior?     Two pointers
Contiguous range that grows and shrinks?   Sliding window
Repeated range sums?                       Prefix sum
Monotonic yes/no answer space?             Binary search
Next greater/smaller element?              Monotonic stack
Hierarchy or subtree information?          Tree DFS
Shortest unweighted path?                  BFS
Dependencies/order?                        Topological sort
Repeated minimum/maximum or top k?         Heap
Generate every valid choice?               Backtracking
Overlapping optimization subproblems?      Dynamic programming
Repeatedly merge components?               Union-Find
Pattern/prefix/suffix matching?             KMP / trie / string algorithms
```

## Complexity reminders

| Operation/algorithm | Typical complexity |
|---|---:|
| Hash lookup | `O(1)` average |
| Sorting | `O(n log n)` |
| Binary search | `O(log n)` |
| Heap push/pop | `O(log n)` |
| DFS/BFS | `O(V + E)` |
| KMP | `O(n + m)` |
| Generate all subsets | `O(2ⁿ)` |
| Generate all permutations | `O(n!)` |

## Revision method

For each pattern:

1. Solve one easy problem without notes.
2. Explain the invariant aloud.
3. Write the reusable template from memory.
4. Solve one medium problem where the pattern is not explicitly named.
5. Revisit it after 1 day, 1 week, and 1 month.

When reviewing a failed problem, record:

```text
Recognition cue I missed:
Brute-force bottleneck:
Key invariant:
Edge case I missed:
Time and space complexity:
```
