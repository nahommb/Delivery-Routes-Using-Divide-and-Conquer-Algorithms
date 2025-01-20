Delivery Routes Optimization

This repository contains C++ code that implements the Divide and Conquer algorithm to find the shortest distance between two points in a given set of points.
Algorithm:

Divide and Conquer:
Divide the set of points into two halves recursively.
Recursively find the shortest distance within each half.
Combine the results from both halves.
Find the shortest distance among points that are close to the dividing line.
Brute Force (Base Case):
For a small number of points, use brute force to calculate the distances between all pairs.
Implementation:

The code uses a Point struct to represent points in a 2D plane.
Functions are provided for:
Calculating the Euclidean distance between two points.
Implementing the brute-force algorithm.
Implementing the Divide and Conquer algorithm.
Finding the shortest distance between all points in the given set.
