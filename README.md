*This project has been created as part of the 42 curriculum by estmoren and lumacko.*

## Description
Push_swap is a project in which students tackle sorting algorithms and collaborative work.

The goal of the project is to sort stack of integers using only two stacks ( "a" and "b"). Number of total operations is limited and so are the types of operations:

- `sa`, `sb`, `ss`
- `pa`, `pb`
- `ra`, `rb`, `rr`
- `rra`, `rrb`, `rrr`

The result is an output of operations required to sort the input stack in an ascending order, minimizing the number of moves.

### Features
* **Algorithm Efficiency**: Finding the optimized path to sort integers.
* **Stack Manipulation**: Using two stacks (Stack A and Stack B) of single linked lists and predefined operations.
* **Memory Leaks**: Make sure there are no memory leaks, even when displaying error.
* **Flags**: Simple, Medium, Complex, Adaptive(uses disorder to choose the right strategy) and Benchmark mode (provides statistics)
* **Performance Targets**: For 100 random numbers under 2000 operations (minimum requirement), for 500 random numbers use under 12 000 operations (minimum requirement)

### Compilation
To compile the project, run the following command in your terminal:
```bash
make
```
This generates the `push_swap` executable.

Remove object files:

```bash
make clean
```

Remove object files and executable:

```bash
make fclean
```

Rebuild the project:

```bash
make re
```

### Instructions
Run the executable by passing a list of integers as arguments:
```bash
./push_swap 2 1 3 6 5 8
```
or also as as string:

```bash
./push_swap "2 1 3 6 5 8"
```

We can choose which algorithm we want to test by using specific flags. We can use a mix of flags + bench, but never the same flag twice
```bash
./push_swap --simple 8 3 21 6 100 or --bench --simple 8 3 21 6 100
./push_swap --medium 8 3 21 6 100 or --bench --medium 8 3 21 6 100
./push_swap --complex 8 3 21 6 100 or --bench --complex 8 3 21 6 100
./push_swap --adaptive 8 3 21 6 100 or --bench --complex 8 3 21 6 100
```

Example with --bench:

-[bench] disorder: 49.67%
-[bench] strategy: Adaptive -> Medium / O(n*sqrt(n))
-[bench] total_operations: 780
-[bench] sa: 0     sb: 0       ss: 0     pa: 100     pb: 100
-[bench] ra: 88    rb: 169     rr: 0     rra: 165    rrb: 158     rrr: 0


The flags will trigger these algorithms

| `--simple` | Simple Sort |

| `--medium` | Chunk Sort |

| `--complex` | Radix Sort |

| `--adaptive` | Adaptive Selection |

If no flag is used, adaptive mode will be executed as a default one.
---

## Metrics

- Selected algorithm
- Disorder
- Complexity
- Total number of operations/ steps
- Per operation stats

## Structure of the Single Linked List

typedef struct s_stack_node
{
	int					value;
	int					rank;
	struct s_stack_node	*next;
} 						t_stack_node;

### Disorder
Disorder gets calculated before the sorting happens and is used in Adaptive mode. It looks at pair of numbers and compares them.

Example: 8 9 7 6

8 < 9				= no disorder ( result is 0.0)
9 > 7 and 7 > 6 	= disorder (between 0.0 and 1.0)

## Algorithms implemented
The following algorithms were selected and implemented. The decision was purely strategic, taking into consideration the time frame and availability of the programmers.
* **Insertion sort adaptation**
* **Chunk-based sorting**
* **Radix**
* **Adaptive**

| Disorder Index | Strategy | Complexity |
|----------------|----------|------------|
| < 0.20 | Simple Sort | O(n) / Near-sorted optimization |
| 0.20 - 0.49 | Chunk Sort | O(n√n) |
| ≥ 0.50 | Radix Sort | O(n log n) |

## Errors

Invalid characters, integer overflow, duplicated values, fail to allocate memory will trigger:

```text
Error
```

```bash
./push_swap 1 2 2
```
or
```bash
./push_swap hello
```

## Team Contributions
Both students participated in the creation of the project, testing and debugging

## estmoren
- Parsing and imput validation
- Error handling
- Stack operations
- Simple and complex algorithms
- Testing

## lumacko
- Stack data structure implementation
- Medium and Adaptive algorithms
- Benchmark mode
- Testing

## team work
- Tracking and updating process via Trello
- Managing Github and branches
- Final testing

## Resources
- Linux Man Pages
- AI for guidance purposes and debugging
- 42 Documentation
- peer advice
