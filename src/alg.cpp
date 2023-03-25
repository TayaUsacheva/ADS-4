// Copyright 2021 NNTU-CS
#include <iostream>

using namespace std;
int countPairs1(int *arr, int len, int value) {
    int count1 = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++){
            if (arr[i] >= 0 && arr[j] >= 0 && (arr[i] + arr[j]) == value)
                count1++;
        }
    }
  return count1;
}
int countPairs2(int *arr, int len, int value) {
    int count1 = 0;
    int l = 0;
    int r = len - 1;
    while (l != r)
    {
        int sum = arr[l] + arr[r];
        if (sum < value)
            l++;
        else if (sum > value)
            r--;
        else
        {
            count1++;
            l++;
        }
    }
  return count1;
}
int countPairs3(int *arr, int len, int value) {
    int count1 = 0;
    int right = len - 1;
    int left = 0;
    while (left < right - 1) {
        int center = (left + right) / 2;
    if (arr[center] > value)
        right = center;
    else
        left = center;
    }
    len = right - 1;
    for (int i = 0; i < len; i++) {
        left = i + 1;
        right = len - 1;
        int count2 = 0;
        while (left < right) {
            int center2 = (left + right) / 2;
            if (arr[center2] < (value - arr[i]))
                left = center2 + 1;
            else
                right = center2;
        }
        while (arr[left] == (value - arr[i])) {
            count2++;
            left++;
        }
        count1 += count2;
    }
    return count1;
}
