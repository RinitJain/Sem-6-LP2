# Selection Sort Algorithm 

## 📌 Overview

This program implements the **Selection Sort** algorithm in C++. It sorts an array of integers by repeatedly finding the minimum element from the unsorted portion and placing it at the beginning.

---

## 🧠 How It Works

- The array is divided into a sorted and unsorted section.
- For each position in the array, the smallest unsorted element is selected and swapped with the element at the current position.
- The process is repeated until the array is fully sorted.

---

## 🕒 Time & Space Complexity

- **Time Complexity:** O(n²)
- **Space Complexity:** O(1) — in-place sorting

---

## Sample Input - Output

```cpp
Original array:
64 25 12 22 11
Sorted array:
11 12 22 25 64
```