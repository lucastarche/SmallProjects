# Random Walk

Simulates a random walk, in which every direction (up, down, left and right) is equally likely.

It then plots the amount of walks that ended with a manhattan distance of x.

There is a Python version (walk.py), as well as a C++ version (walk.cpp).

Both versions write the results to res.txt, which then can be plotted by running plot_file.py. 

Asymptotic complexity: O(n*m), where n is the amount of iterations, and m is the amount of steps.