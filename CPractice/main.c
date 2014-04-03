//
//  main.c
//  C_practice
//
//  Created by ChangChun Lu on 3/18/14.
//  Copyright (c) 2014 ChangChun Lu. All rights reserved.
//

#include <stdio.h>
#include "ArithmetricSequence.h"
#include "GeometricSequence.h"
#include "FibonacciSequence.h"
#include "Palindrome.h"
#include "Search.h"
#include "sort.h"
#include "Compare.h"
#include "Stack.h"
#include "Queue.h"

int main(int argc, const char * argv[])
{

    // Testing
    /*printf("Testing arithmetic sequence\n");
    printf("sum(1,10,1): %d\n", sum(1,10,1));
    printf("product(1,5,2): %d\n", product(1,5,2));
    printf("factorial(10): %d\n", factorial(10));
    
    printf("Testing arithmetic sequence\n");
    printf("sum(1,16,2): %lf\n", geoSum(1.0,16.0,2.0));
    printf("sum(1,16,2): %lf\n", geoProduct(1.0,16.0,2.0));
    
    printf("getFibonaciiNumber(0): %d\n", getFibonacciNumber(0));
    printf("getFibonaciiNumber(1): %d\n", getFibonacciNumber(1));
    printf("getFibonaciiNumber(2): %d\n", getFibonacciNumber(2));
    printf("getFibonaciiNumber(3): %d\n", getFibonacciNumber(3));
    printf("getFibonaciiNumber(7): %d\n", getFibonacciNumber(7));
    printf("fibonaciiSum(0): %d\n", fibonacciSum(0));
    printf("fibonaciiSum(1): %d\n", fibonacciSum(1));
    printf("fibonaciiSum(2): %d\n", fibonacciSum(2));
    printf("fibonaciiSum(3): %d\n", fibonacciSum(3));
    printf("fibonaciiSum(4): %d\n", fibonacciSum(4));
    printf("fibonaciiSum(7): %d\n", fibonacciSum(7));
    
    printf("isPalindrome(121): %d\n", isPalindrome(121));
    printf("isPalindrome(31213): %d\n", isPalindrome(31213));
    printf("isPalindrome(1221): %d\n", isPalindrome(1221));
    printf("isPalindrome(12231): %d\n", isPalindrome(12231));
    printf("isPalindromeChar(12231): %d\n", isPalindromeChar("12231"));
    printf("isPalindromeChar(12321): %d\n", isPalindromeChar("12321"));
    printf("isPalindromeChar(1221): %d\n", isPalindromeChar("1221"));
    printf("isPalindromeChar(1): %d\n", isPalindromeChar("1"));*/
    
    /*int input[5] = {3,11,2,9,13}, input2[7] = {11,15,18,19,32,33,47}, input3[7] = {4,3,3,3,3,3,3};
    printf("search min(3,11,2,9,13): %d\n", min(input, 5));
    printf("search max(3,11,2,9,13): %d\n", max(input, 5));
    printf("search 2thMin(3,11,2,9,13): %d\n", kthMin(input, 5, 0, 2));
    printf("search 3thMin(3,11,2,9,13): %d\n", kthMin(input, 5, 0, 3));
    printf("search 3thMin(11,15,18,19,32,33,47): %d\n", kthMin(input2, 7, 0, 3));
    printf("search 5thMin(11,15,18,19,32,33,47): %d\n", kthMin(input2, 7, 0, 5));
    printf("search 3thMin(3,3,3,3,3,3,4): %d\n", kthMin(input3, 7, 0, 3));*/
    
    // testing swap
    int a = 3, b = 4;
    /*swapInt(&a, &b);
    printf("swap(a=3,b=4)= (a=%d,b=%d)\n", a, b);
    a = 3;
    b = 3;
    swapInt(&a, &b);
    printf("swap(a=3,b=3)= (a=%d,b=%d)\n", a, b);
    swapInt(&a, &a);
    printf("swap(a=3,a=3)= (a=%d,b=%d)\n", a, b);*/
    
    // testing quickSort
    /*printf("quickSort(");
    for (a=0; a<5; ++a) {
        printf("%d ",input[a]);
    }
    printf("): ");
    quickSort(input, 0, 4);
    for (a=0; a<5; ++a) {
        printf("%d ",input[a]);
    }
    printf("\n");
    printf("quickSort(");
    for (a=0; a<7; ++a) {
        printf("%d ",input2[a]);
    }
    printf("): ");
    quickSort(input2, 0, 6);
    for (a=0; a<7; ++a) {
        printf("%d ",input2[a]);
    }
    printf("\n");
    printf("quickSort(");
    for (a=0; a<7; ++a) {
        printf("%d ",input3[a]);
    }
    printf("): ");
    quickSort(input3, 0, 6);
    for (a=0; a<7; ++a) {
        printf("%d ",input3[a]);
    }
    printf("\n");
    
    a = 3;
    b = 4;
    printf("max(3,4)=%d compare(3,4)=%d\n", findMax(a, b), compareInt(a, b));
    printf("max(4,3)=%d compare(4,3)=%d\n", findMax(b, a), compareInt(b, a));
    printf("max(4,4)=%d compare(4,4)=%d\n", findMax(b, b), compareInt(b, b));*/
    
    //testing stack
    /*Stack* s = getStackInstant();
    for (b = 0; b < 10; ++b)
        push(s, b);
    for (b = 0; b < 10; ++b)
        printf("pop stack: %d\n", pop(s));
    push(s, 14);
    printf("pop stack: %d\n", pop(s));*/
    
    //testing queue
    /*Queue* q = getQueueInstance();
    for (a=0; a<5; ++a)
        enqueue(q,a);
    for (a = 0; a < 5; ++a)
        printf("dequeue: %d\n", dequeue(q));
    for (a=0; a<9; ++a)
        enqueue(q,a);
    for (a = 0; a < 10; ++a)
        printf("dequeue: %d\n", dequeue(q));
    for (a=0; a<10; ++a)
        enqueue(q,a);
    for (b = 0; b < 10; ++b)
        printf("dequeue: %d\n", dequeue(q));*/
    
    //testing binary search
    int sorted[10] = {5, 11, 23, 31, 41, 53, 61, 73, 89, 97};
    printf("binary search 97: %d\n", sorted[binarySearch(sorted, 10, 97)]);
    printf("binary search 41: %d\n", sorted[binarySearch(sorted, 10, 41)]);
    printf("binary search 5: %d\n", sorted[binarySearch(sorted, 10, 5)]);
    return 0;
}

