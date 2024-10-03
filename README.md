# hull2d-startup: Tom Han

## (0) Usage

```bash
$ make
>>> ...
$ ./hull2d 500
```

Replace 500 with the number of points you want to generate. Once in the program, you can press `q` to quit, `i` to change the color of the points.

## (0) Description

This project is an implementation of the 2D convex hull algorithm. The algorithm is based on the Graham scan algorithm. The algorithm first sorts the points by their polar angle with respect to the lowest point. Then, it iterates through the points and checks if the current point is a left turn or a right turn with respect to the last two points in the convex hull. If it is a left turn, the point is added to the convex hull. If it is a right turn, the last point is removed from the convex hull until the current point is a left turn with respect to the last two points in the convex hull. The algorithm runs in $O(n \log n)$ time, where $n$ is the number of points.

## (1) brief description of what sort of inputs constitute degeneracies for the algorithm and how you handled these degeneracies

The colinear case constitutes a degeneracy for the algorithm. I handled this by sorting the points by their polar angle with respect to the lowest point. If two points have the same polar angle, I remove the one that is further away from the lowest point. In addition, for the rate case of the first three points being colinear, I remove the middle point. (See `geom.cpp:110`)

> All pictures are generated with 500 points (e.g. `./hull2d 500`) unless otherwise specified.

## (2) pictures of the two initializers you created

### `initializer1`:

![initializer1](init1.png)

### `initializer2`:

![initializer2](init2.png)

## (2) pictures of the other initializers you used

### `initialize_points_two_vertical` from Ziyou

![initialize_points_two_vertical](init_2vl.png)

### `initialize_points_wave` from Manny and Jack

![initialize_points_wave](init_wave.png)

## (3) pictures of the convex hulls computed for each initial configuration of points — for all these choose a reasonable value of $n$

### `circle`:

![circle](circle.png)

### `cross`:

![cross](cross.png)

### `line`:

![line](line.png)

### `random`:

![random](random.png)

## (6) Time you spent in: Thinking; Programming; Testing; Documenting; Total

I choose to start writing the code after reading the project for around an hour. As I am writing the code, I am also testing it by constantly recompiling and run the test cases. I spent around 2 hours writing the code and 1 hour testing it. I spent around 30 minutes documenting the code. After making sure my code passes all four defalut case, I spend around 2 hours to make my two initializers (1 and 2). In total, I spent around 6 hours on this project.
