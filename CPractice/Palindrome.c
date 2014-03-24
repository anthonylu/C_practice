//
//  Palindrome.c
//  C_practice
//
//  Created by ChangChun Lu on 3/20/14.
//  Copyright (c) 2014 ChangChun Lu. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int isPalindrome(int n) {
    int result = 0;
    if (n < 0) {
        return 0;
    }
    int digit = log10(n), i = 0, high = pow(10.0, digit);
    ++digit;
    for (i = 0; i < digit/2; ++i) {
        if ((int)(n/high)%10 == (int)(n/pow(10, i))%10) {
            high /= 10;
            continue;
        } else return result;
    }
    result = 1;
    return result;
}

int isPalindromeChar(char *start) {
    int result = 0;
    char *end;
    end = start;
    while (*end != '\0') {
        ++end;
    }
    --end;
    //printf("length: %d s: %c e: %c ",length, *s, *end);
    
    while (*end == *start) {
        --end;
        ++start;
        if (start >= end) {
            result = 1;
            break;
        }
    }
    return result;
}