# Asymptotic Analysis Cheat Sheet

*This cheat sheet is a little different than most in that it doesn't show algorithms and their run times, but instead estimates for and while loop constructs.*

*This is a work in progress, and will be updated periodically.*

## Single Loop Constructs

```cpp
for (int i = 0; i < N; i++) {...}
```
$$O(N)$$

-

```cpp
for (int i = 0; i < N; i+=k) {...}
```
$$O(\dfrac{N}{k})$$

The inverse is also true.

```cpp
for (int i = (N - 1); i > 0; i-=k) {...}
```
$$O(\dfrac{N}{k})$$

-

```cpp
for (int i = 0; i < N; i*=k) {...}
```

$$O(log_{k}(N))$$

The inverse of the above is also $$O(log_{k}(N))$$.

```cpp
for (int i = N - 1; i > 0; i/=k) {...}
```

-

Lastly, for something like:

```cpp
for (i = 2; i < N; i*=i)
```

Note that here unless `i` starts at some integer greater than $$1$$, then the loop will never end. This one was a little tricky, but it only took a few minutes to figure out. I think I just got lucky with a guess. Anyway, the above can be also be more generally expressed as `for (i = a; i < N; i = i^k)`. My conjecture is that the exact runtime can be expressed as:

$$\lceil log_{k}(log_{a}((N) \rceil$$

in big O notation this would just become $$O(log(log(N)))$$. I think an iterated log is interesting in that for numbers that humans deal with this really is almost constant in runtime. But for astronomically large numbers the difference between constant time and one of an iterated log can become apparent.

Here is a table of results:
*i is the starting i value (for large N it needed to be a long)*

`i` | `N` | Count | Hypothesis | 
--- | --- | --- | --- |
2 | 10 | 2 | 2
2 | 100 | 3 | 3
2 | 1000 | 4 | 4
2 | 10000 | 4 | 4
2 | 100000 | 5 | 5
2 | 1e+06 | 5 | 5
2 | 1e+07 | 5 | 5
3 | 10 | 2 | 2
3 | 100 | 3 | 3
3 | 1000 | 3 | 3
3 | 10000 | 4 | 4
3 | 100000 | 4 | 4
3 | 1e+06 | 4 | 4
3 | 1e+07 | 4 | 4
4 | 10 | 1 | 1
4 | 100 | 2 | 2
4 | 1000 | 3 | 3
4 | 10000 | 3 | 3
4 | 100000 | 4 | 4
4 | 1e+06 | 4 | 4
4 | 1e+07 | 4 | 4
5 | 10 | 1 | 1
5 | 100 | 2 | 2
5 | 1000 | 3 | 3
5 | 10000 | 3 | 3
5 | 100000 | 3 | 3
5 | 1e+06 | 4 | 4
5 | 1e+07 | 4 | 4
6 | 10 | 1 | 1
6 | 100 | 2 | 2
6 | 1000 | 2 | 2
6 | 10000 | 3 | 3
6 | 100000 | 3 | 3
6 | 1e+06 | 3 | 3
6 | 1e+07 | 4 | 4
7 | 10 | 1 | 1
7 | 100 | 2 | 2
7 | 1000 | 2 | 2
7 | 10000 | 3 | 3
7 | 100000 | 3 | 3
7 | 1e+06 | 3 | 3
7 | 1e+07 | 4 | 4
8 | 10 | 1 | 1
8 | 100 | 2 | 2
8 | 1000 | 2 | 2
8 | 10000 | 3 | 3
8 | 100000 | 3 | 3
8 | 1e+06 | 3 | 3
8 | 1e+07 | 3 | 3
9 | 10 | 1 | 1
9 | 100 | 2 | 2
9 | 1000 | 2 | 2
9 | 10000 | 3 | 3
9 | 100000 | 3 | 3
9 | 1e+06 | 3 | 3
9 | 1e+07 | 3 | 3

Seems to be right so far. If your interested take a look at the code, change it around to run more tests, and let me know your results!