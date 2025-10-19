# CSI2372 — Week 7 Lab Handout  
**Topic:** Templates • Generic Programming • STL Containers • Resource Management • Iterator Design  
**Course:** Advanced Programming Concepts with C++ (Fall 2025, uOttawa)

---

## 1. Overview
In this lab, you will deepen your understanding of C++ templates, generic programming, and STL containers.  
You will implement multiple modular components that demonstrate type-independent logic, resource safety, and iterator design patterns.

The lab consists of **five graded tasks**:

1. **DataProcessor** – template-based data aggregation and transformation.  
2. **Box** – generic container with ownership and access semantics.  
3. **StorageManager** – layered resource management using RAII and smart pointers.  
4. **MapContainer** – associative container wrapper with custom iterators.  
5. **NumericPipeline** – functional numeric transformation pipeline with aggregation and safety guarantees.

All work is autograded via **CI/CTest**.  
When the GitHub Actions build is green, you earn full marks.

---

## 2. Learning Objectives
By the end of this lab, you should be able to:

- Implement and instantiate **class and function templates**.  
- Understand how template definitions must be visible at the point of instantiation.  
- Use **RAII** to guarantee correct resource lifetime.  
- Manage ownership via **unique_ptr** and **shared_ptr**.  
- Design and expose **iterators** for custom containers.  
- Apply **exception safety guarantees** (basic, strong, no-throw).  
- Use CMake and modular C++ project structures.

---

## 3. Task A — DataProcessor
You are given a template class `DataProcessor<T>` that performs computations on collections of data (e.g., averages, sums, filtering).

### Required Behavior
- Template parameter `T` represents the element type.  
- Implement `add(T)`, `size()`, `average()`, and `transform(Function)`.  
- `average()` should throw if the collection is empty.  
- `transform()` should apply a callable to all elements and return a new `DataProcessor<U>`.  
- Implementation should be header-only.

### Concepts Covered
Template design, callable usage, exception safety, and const-correctness.

---

## 4. Task B — Box
You are given a templated class `Box<T>` representing a small storage unit for a single value.

### Required Behavior
- Support construction, copy, and move.  
- Implement `set(const T&)`, `get() const`, and `reset()`.  
- Ensure proper ownership semantics and move behavior.  
- Include `bool has_value() const noexcept`.

### Concepts Covered
Value semantics, move semantics, and template encapsulation.

---

## 5. Task C — StorageManager
Implement a class `StorageManager<T>` that manages a collection of objects with automatic lifetime control.

### Required Behavior
- Internally use `std::unique_ptr<T>` or `std::shared_ptr<T>`.  
- Support `add(std::unique_ptr<T>)`, `get_all()`, and `clear()`.  
- `clear()` must follow the **no-throw guarantee**.  
- Add a method `count() const noexcept`.

### Concepts Covered
Resource management, RAII, ownership transfer, and exception guarantees.

---

## 6. Task D — MapContainer
Design a wrapper around `std::map<Key, Value>` that supports iteration and safe lookup.

### Required Behavior
- Provide custom iterator types compatible with range-based for loops.  
- Implement `insert(const Key&, const Value&)`, `find(const Key&)`, and `erase(const Key&)`.  
- Throw a `std::out_of_range` exception if `find` fails.  
- Add `size() const noexcept` and `empty() const noexcept`.

### Concepts Covered
Iterator interface design, associative container abstraction, and strong exception safety.

---

## 7. Task E — NumericPipeline
Implement a header-only class template `NumericPipeline<T>` that represents a configurable numeric computation pipeline.  
It allows sequential transformation of data using function stages and supports aggregation operations.

### Required Behavior
- Template parameter `T` must support basic arithmetic operations (`+`, `*`, `/`, etc.).  
- Provide the following member functions:
  - `add_stage(std::function<T(T)>)` — adds a new transformation stage.  
  - `run(const std::vector<T>&)` — executes all stages on the provided input data sequentially.  
  - `sum()` — returns the sum of the processed results.  
  - `average()` — returns the arithmetic mean; must throw `std::runtime_error` if the pipeline is empty or produces no output.  
  - `clear()` — removes all stages from the pipeline.  
- Must provide **basic** and **strong** exception safety guarantees where applicable.  
- Entire implementation must reside in the `.hpp` file (header-only design).  

### Concepts Covered
Template programming, functional composition, arithmetic transformation, and exception safety in generic code.

---

## 8. Building and Running
Recommended workflow :

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure

```
CI runs on GitHub automatically when you push.

## 9. Grading
100% autograded: your score = proportion of passing tests.

No manual grading.
