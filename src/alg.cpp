// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count1 = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if ((arr[i] + arr[j]) == value)
                count1++;
        }
    }
  return count1;
}
int countPairs2(int *arr, int len, int value) {
    int count1 = 0, k = 0;
    for (int i = 1; i < len; i++)
        if (arr[0] + arr[i] <= value) k++;
        else
            break;
    for (int i = 0; i < k; i++)
        for (int j = i + 1; j <= k; j++)
            if (arr[i] + arr[j] == value)
                count1++;
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
