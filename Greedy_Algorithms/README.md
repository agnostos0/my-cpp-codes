# ✅ Activity Selection Problem – Greedy Algorithm Proof (Exchange Argument)

## 📌 Problem Statement

Given `n` activities with start times `s[]` and finish times `f[]`, select the **maximum number of non-overlapping activities**. Each activity `i` has:
- Start time: `s[i]`
- End time: `f[i]`

Assume activities are **sorted by end time** (i.e., `f[0] <= f[1] <= ... <= f[n-1]`).

---

## ✅ Goal

Prove that the **greedy algorithm**, which always selects the next activity that finishes earliest, produces an **optimal solution**.

---

## ✅ Greedy Strategy

1. Select the first activity (smallest end time).
2. For each subsequent activity, select it **only if** its start time is ≥ end time of last selected activity.

Let:
- **G** = `{g₁, g₂, ..., g_k}` be the activities selected by **greedy**
- **O** = `{o₁, o₂, ..., o_m}` be the activities in an **optimal** solution

---

## ✅ Proof by Exchange Argument

### Step 1: Transform Optimal into Greedy

We prove:  
> The optimal solution **O** can be transformed into a new solution **O′** that includes all of greedy's activities **G**, without reducing the number of selected activities.

This is done by **replacing** some activities in O with the corresponding greedy selections.

---

### Step 2: What We Get by Replacement

By replacing:
- \( o_1 \) with \( g_1 \)
- \( o_2 \) with \( g_2 \)
- ...
- \( o_k \) with \( g_k \)

We get:
- A new solution **O′** of size **m**, where the **first k activities match greedy’s picks**
- **O′** is still valid (no overlaps), because greedy always chooses the earliest-ending valid activity

---

### Step 3: Contradiction Argument

Suppose \( k < m \): greedy selected **fewer** activities than optimal.

But:
- Greedy **always** picks the activity that ends earliest and leaves maximum room
- So if there was space for more, greedy **would have picked it**

Thus, if \( m > k \), greedy **missed** a possible activity ⇒ **Contradiction**

---

## ✅ Therefore:

\[
k = m
\]

- Greedy picks **same number** of activities as optimal
- So **greedy is optimal**

---

## ✅ Summary Table

| Step | Explanation |
|------|-------------|
| ✅ Greedy picks non-overlapping activities by earliest finish time | Valid |
| 🔁 Replacing optimal with greedy keeps feasibility | Valid |
| ❌ Assuming greedy picked fewer leads to contradiction | Invalid |
| ✅ Greedy picks maximum number of activities | Proven |

---

## ✅ Conclusion

The greedy algorithm gives an **optimal solution** to the activity selection problem when activities are sorted by end time.

> 📌 **Greedy is not just fast — it's provably correct.**

---
