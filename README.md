# ExampleFunction
## [**Boost::hawick_circuits**](https://www.boost.org/doc/libs/1_78_0/libs/graph/doc/hawick_circuits.html)
### Requirements
* C++ Compiler - GNU g++/gcc
* Boost Graph library

### Build & Run
```
g++ -o BoostExample BoostExample.cpp
./BoostExample

```

### Example 1 
#### Input Graph
![boost_example](https://github.com/nitishchauhan0022/ExampleFunction/blob/main/images/1.png)

#### Output
```
1 2 3 4 1
1 2 4 1

```
Adding parallel edge 2->3

![boost_example](https://github.com/nitishchauhan0022/ExampleFunction/blob/main/images/2.png)
#### Output
```
1 2 3 4 1
1 2 4 1
1 2 3 4 1

```
If we want only the unique circuits then hawick_unique_circuits can be used.

#### Output of parallel edge graph using hawick_unique_circuits
```
1 2 3 4 1
1 2 4 1
```
