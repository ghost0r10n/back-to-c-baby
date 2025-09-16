# AVL Balance Quiz

**Instructions:** Calculate heights and balance factors for each tree. Determine if balanced or unbalanced.

**Remember:**

- Height = longest path from node to any leaf
- Balance factor = right_height - left_height
- Unbalanced if balance factor is +2 or -2

---

## Tree 1:

```
      5
     / \
    3   8
   /   / \
  1   7   9
```

**Heights:**

- Node 1: _0_
- Node 3: _1_
- Node 7: _0_
- Node 8: _1_
- Node 9: _0_
- Node 5: _2_

**Balance Factors:**

- Node 1: _0_
- Node 3: -2\_
- Node 7: _0_
- Node 8: _0_
- Node 9: _0_
- Node 5: _0_

**Status:** Balanced / xUnbalanced

---

## Tree 2:

```
    4
   / \
  2   6
 /     \
1       8
       /
      7
```

**Heights:**

- Node 1: _0_
- Node 2: _1_
- Node 7: _0_
- Node 8: _1_
- Node 6: _2_
- Node 4: _3_

**Balance Factors:**

- Node 1: _0_
- Node 2: -2\_
- Node 7: _0_
- Node 8: -2\_
- Node 6: _0_
- Node 4: _1_

**Status:** Balanced / xUnbalanced

---

## Tree 3:

```
    10
   /
  5
 /
3
```

**Heights:**

- Node 3: _0_
- Node 5: _1_
- Node 10: _2_

**Balance Factors:**

- Node 3: _0_
- Node 5: -2\_
- Node 10: -3\_

**Status:** Balanced / Unbalanced

---

**When done, tell me to check your answers!**
