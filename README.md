# SHAD_Preparation_Algorithms

IN ENGLISH: 
`map_4_the_most_mind_blowing_greedy_algorithm.cpp` solves (for the least time I know) the following problem.

---

## Finding the Three Most Frequent Elements in an Array

**Time limit:** 1 second  
**Memory limit:** 256 MB  

---

## Problem Statement

An array $a$ consisting of $n$ numbers is given.

Find three **distinct** elements of this array  
$x_1, x_2, x_3$  
such that the **total number of their occurrences** in the array is maximized.

If there are several suitable triples $(x_1, x_2, x_3)$, output the triple with the **minimum sum**
$$x_1 + x_2 + x_3.$$

It is guaranteed that the array contains at least three distinct elements.

---

## Input Format

The first line contains a single integer $n$, the number of elements in the array.

The second line contains $n$ integers  
$$a_1, a_2, \dots, a_n,$$
where $a_i$ is the element at position $i$ in the array $a$.

---

## Constraints

$$1 \le n \le 10^5$$

$$1 \le a_i \le 10^5 \quad \text{for all } 1 \le i \le n$$

---

## Output Format

Output three integers  
$x_1, x_2, x_3$  
separated by spaces and printed in **increasing order**.

---

## Examples

### Example 1

**Input**

6

1 2 3 2 1 1

**Output**

1 2 3

---

### Example 2

**Input**

6

3 1 1 2 3 3

**Output**

1 2 3

---

### Example 3

**Input**

8

11 21 31 41 31 41 11 21

**Output**

11 21 31


