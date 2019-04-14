# Quick Sort and Parallel Quick Sort Comparison

## Introduction 
This repository contains comparison between a quick sort without a parallel omp and with parallel omp. This is for educational purposes in order to complete the Operating System class' assignment that was given. The comparisson itself will be based on how much time that both quick sort and parallel quick sort took to complete the sorting with certain set of numbers. 

## Requirements

### Programming Language
C++ 11 

### IDE
Code:Blocks

## Comparison
In this comparison, there are 2 important feature that effected the sorting time, which is `n` (Set of Numbers) and also `range`(range of random number). It ranged from 1 until 1000 random numbers for this test. After I ran both of the test, these are what I got : 

| 'n' (Set Of Numbers)  | Quick Sort (s)    | Parallel Quick Sort (s)|
| ----------------------| ------------------| -----------------------|
| 5000                  | 0.000999891       | 0.0449999              |
| 10000                 | 0.002             | 0.064                  |
| 50000                 | 0.0170001         | 0.302                  |
| 100000                | 0.053             | 0.426                  |
| 500000                | 1.009             | 2.411                  |


![Time Comparisson](https://github.com/kayleenp/QuickSortTaskOS/blob/master/time%20comparisson%20qs.JPG)
    

## Conclusion 
From the data, we can conclude that Parallel Quick Sort took more time to sort than a regular (without parallel omp) quick sort. So, in terms of the efficiency of time, regular quick sort is better. 
