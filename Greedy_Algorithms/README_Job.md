# ⚡ C++ Lambda Functions

Lambda functions in C++ are **anonymous (unnamed) functions** you can define **inline**, often used for **short, quick tasks** without needing to create a full function.

---

## 🧠 Definition

> A **lambda function** is a convenient way to define a small function object (functor) directly in the place where it’s invoked or passed as an argument.

Syntax:
```cpp
[capture_list](parameter_list) -> return_type {
    // function body
};
```

---

## 🔍 Components Explained

- **`[capture_list]`** – Specifies which external variables are accessible inside the lambda.
- **`(parameter_list)`** – Function arguments.
- **`-> return_type`** – (Optional) Explicit return type.
- **`{ body }`** – Function logic.

---

## 🎯 Why Use Lambda Functions?

- Reduces boilerplate code for small tasks.
- Makes code cleaner and more readable.
- Perfect for one-time-use functions (no need to name them).
- Useful with STL algorithms like `sort()`, `count_if()`, `for_each()`.

---

## ⏱️ When to Use

- Writing short custom logic inside STL functions.
- Passing quick callbacks or filters.
- When the function is only needed once or in a local scope.
- Capturing local variables for temporary operations.

---

## 🎓 Capture List Explained

| Capture Syntax | Meaning                             |
|----------------|-------------------------------------|
| `[ ]`          | Capture nothing                     |
| `[=]`          | Capture all local variables by value |
| `[&]`          | Capture all local variables by reference |
| `[x]`          | Capture variable `x` by value        |
| `[&x]`         | Capture variable `x` by reference    |

> Use `mutable` keyword if you want to modify variables captured by value.

---

## ✅ Examples

### 1. Basic Lambda
```cpp
auto sayHello = []() {
    std::cout << "Hello, Lambda!" << std::endl;
};
sayHello();
```

### 2. With Parameters and Return
```cpp
auto multiply = [](int a, int b) -> int {
    return a * b;
};
std::cout << multiply(3, 4); // Output: 12
```

### 3. Capture by Value and Reference
```cpp
int x = 10, y = 5;

// By value
auto sum = [x, y]() {
    return x + y;
};

// By reference
auto increment = [&x, &y]() {
    x++; y++;
};
```

### 4. Lambda in STL (Sorting)
```cpp
std::vector<int> v = {4, 1, 3, 2};
std::sort(v.begin(), v.end(), [](int a, int b) {
    return a > b; // Descending order
});
```

### 5. Count Using Condition
```cpp
std::vector<int> nums = {1, 5, 7, 3, 2};
int count = std::count_if(nums.begin(), nums.end(), [](int n) {
    return n > 3;
});
std::cout << count; // Output: 3
```

### 6. Mutable Lambda
```cpp
int a = 5;
auto change = [a]() mutable {
    a++;
    std::cout << a; // Output: 6 (but `a` outside remains 5)
};
```

---

## 🛠 Use Cases

- Custom sort logic using `sort()`.
- Filtering using `count_if()`, `remove_if()`.
- Performing actions in `for_each()`.
- GUI or system callbacks.
- Short one-off logic blocks.

---

# 🚀 Difference Between `push_back()` and `emplace_back()` in C++

When adding elements to a `std::vector` (or other STL containers), both `push_back()` and `emplace_back()` are used — but they work differently in how they construct and insert objects.

---

## ✅ `push_back()`

```cpp
jobs.push_back(Job(i, d, p));
```

- Constructs a **temporary object** `Job(i, d, p)`.
- Then **copies or moves** it into the vector.
- Slightly **less efficient**, especially for complex objects.

---

## ✅ `emplace_back()`

```cpp
jobs.emplace_back(i, d, p);
```

- Constructs the `Job` **directly inside** the vector's memory.
- **No temporary object** is created.
- Generally **faster and more memory-efficient**.
- Perfect when working with **custom classes or large objects**.

---

## ⚡ Summary

| Feature          | `push_back()`                    | `emplace_back()`                         |
|------------------|----------------------------------|-------------------------------------------|
| Object creation  | Outside (temporary)              | Directly in-place                         |
| Performance      | May involve copy/move            | Avoids extra copy/move                    |
| Use case         | When object is already created   | When constructing object on the spot      |
| Syntax           | Needs full object or initializer | Pass constructor arguments directly       |

---

✅ Use `emplace_back()` when:
- You're constructing the object inside the method.
- You want maximum performance and efficiency.

✅ Use `push_back()` when:
- You're pushing an already constructed object.
