`This project has been created as part of the 42 curriculum by akkaraka, almecani.`

# Push_swap

## Description

Push_swap is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using two stacks (a and b) and a limited set of operations. The program must output the sequence of operations needed to sort stack a in ascending order.

### Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack a |
| `sb` | Swap the first two elements of stack b |
| `ss` | sa and sb at the same time |
| `pa` | Push the top of stack b onto stack a |
| `pb` | Push the top of stack a onto stack b |
| `ra` | Rotate stack a upward (first becomes last) |
| `rb` | Rotate stack b upward (first becomes last) |
| `rr` | ra and rb at the same time |
| `rra` | Reverse rotate stack a (last becomes first) |
| `rrb` | Reverse rotate stack b (last becomes first) |
| `rrr` | rra and rrb at the same time |

---

## Instructions

### Compilation

```bash
make
```

### Execution

```bash
# Basic usage
./push_swap 3 1 2 5 4

# With algorithm flag
./push_swap --simple 3 1 2 5 4
./push_swap --medium 3 1 2 5 4
./push_swap --complex 3 1 2 5 4
./push_swap --adaptive 3 1 2 5 4

# With benchmark mode
./push_swap --bench 3 1 2 5 4
./push_swap --bench --simple 3 1 2 5 4

# With checker
./push_swap 3 1 2 5 4 | ./checker_linux 3 1 2 5 4

# With quoted input
./push_swap "3 1 2" "5 4"
```

### Cleanup

```bash
make clean   # remove object files
make fclean  # remove object files and binary
make re      # recompile everything
```

---

## Algorithms

### Disorder Metric

Before sorting, the program computes a disorder value between 0 and 1:
- **0** = already sorted
- **1** = completely reversed

```
disorder = number of inversions / total pairs
```

To check the disorder value of your input, add these two lines in `main.c`:

```c
	data.a = parse_input(argc - first, argv + first);
	disorder = compute_disorder(data.a);
	ft_printf("disorder: %f\n", disorder);
run_sort(&data, algo);
```

Then recompile with `make re` and run:
```bash
./push_swap 3 1 2 5 4
```

The disorder value (0.00 to 1.00) will be printed before the operations.
### 1. Simple Algorithm – Selection Sort O(n²)

**How it works:**
For each pass, find the minimum element in stack a and rotate it to the top, then push it to stack b. Once all elements are in b, push them all back to a.

**Why O(n²):**
For each of the n elements, we scan the entire stack (n steps) to find the minimum → n × n = n² operations.

**Best for:** Small inputs (≤ 20 elements) or low disorder (< 0.2).

---

### 2. Medium Algorithm – Chunk Sort O(n√n)

**How it works:**
Divide the elements into chunks of size √n based on their rank. Push each chunk from a to b, then push back from b to a in descending order by always finding the largest remaining element.

**Optimization:** When pushing to b, elements in the upper half of the chunk are immediately rotated down with `rb` so that larger elements sit at the bottom of b, reducing the cost of the push-back phase.

**Why O(n√n):**
There are √n chunks, and each chunk requires O(n) operations to process → √n × n = n√n operations.

**Best for:** Medium inputs (20–200 elements) or medium disorder (0.2 ≤ disorder < 0.5).

---

### 3. Complex Algorithm – Radix Sort O(n log n)

**How it works:**
Assign each element a rank (0 to n-1). Then sort by bits from least significant to most significant. For each bit position:
- If the bit is 0 → push to b
- If the bit is 1 → rotate in a
- After each round → push all back from b to a

**Why O(n log n):**
There are log₂(n) bit positions, and each pass processes all n elements → n × log(n) operations.

**Best for:** Large inputs (≥ 200 elements) or high disorder (≥ 0.5).

---

### 4. Adaptive Algorithm

The adaptive algorithm measures disorder before sorting and selects the best strategy:

| Disorder | Strategy | Complexity |
|----------|----------|------------|
| < 0.2 | Selection Sort | O(n²) |
| 0.2 – 0.5 | Chunk Sort | O(n√n) |
| ≥ 0.5 | Radix Sort | O(n log n) |

**Threshold justification:**
- **0.2**: At low disorder, the stack is nearly sorted. Selection sort is simple and efficient for small numbers of inversions, as it requires few rotations to find the minimum.
- **0.5**: At medium disorder, chunk sort outperforms selection sort because it processes elements in groups, reducing redundant comparisons. Above 0.5, the disorder is high enough that radix sort's consistent O(n log n) behavior becomes more efficient than chunk sort's variable performance.

---

## Benchmark Mode

When run with `--bench`, the program outputs sorting statistics to stderr:

```
Disorder: 0.65 (65.00%)
Strategy: Radix Sort
Complexity: O(n log n)
Total operations: 4782
sa: 0   sb: 0   ss: 0
pa: 2284 pb: 2284 rr: 0
ra: 214  rb: 0   rr: 0
rra: 0  rrb: 0  rrr: 0
```

---

## Performance

| Input size | Algorithm | Operations |
|------------|-----------|------------|
| 5 numbers | Selection Sort | ~ 12 |
| 100 numbers | Chunk Sort | ~ 700 |
| 500 numbers | Chunk/Radix | ~ 5500 |

---

## Resources

- [Sorting Algorithms Visualizer](https://visualgo.net/en/sorting)
- [Radix Sort Explained](https://en.wikipedia.org/wiki/Radix_sort)
- [Push_swap Medium Article](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
- [Chunk Sort Strategy](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

### AI Usage

Claude (Anthropic) was used throughout this project for:
- **Algorithm design**: Understanding and implementing Selection Sort, Chunk Sort, Radix Sort and the Adaptive algorithm in the Push_swap operation model.
- **Debugging**: Identifying logic errors in stack operations, rotation direction, and rank assignment.
- **Code structure**: Organizing files, splitting functions to comply with the 42 Norm, and designing the `t_data` and `t_bench` structs.
- **Optimization**: Tuning chunk sizes for different input sizes to minimize operation counts.

All code was written, understood, and validated by the project authors.