// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count1 = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
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
    while (l != r) {
        int sum = arr[l] + arr[r];
        if (sum < value) {
            l++;
        } else if (sum > value) {
            r--;
        } else {
            count1++;
            l++;
        }
    }
  return count1;
}
int countPairs3(int *arr, int len, int value) {
    int count1 = 0;
    for (int i = 0; i < (len - 1); i++) {
        int left = i, right = len;
        while (left < right - 1) {
            int center = (left + right) / 2;
            if (i != center && arr[i] + arr[center] == value) {
                count1 += 1;
                for (int j = center + 1; j < right
                    && arr[i] + arr[j] == value
                    && center != i; ++j) {
                    count1 += 1;
                }
                for (int j = center - 1; j > left
                    && arr[i] + arr[j] == value
                    && center != i; --j) {
                    count1 += 1;
                }
                break;
            }
            if (arr[i] + arr[center] > value)
                right = center;
            else
                left = center;
        }
    }
    return count1;
}
