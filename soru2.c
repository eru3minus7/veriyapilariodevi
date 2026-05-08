void customSort(int arr[], int n) {
    // Önce küçükten büyüğe sırala
    insertionSort(arr, n);

    int result[n];
    int left = 0, right = n-1, idx = 0;

    while (left <= right) {
        result[idx++] = arr[right--]; // büyük
        if (left <= right)
            result[idx++] = arr[left++]; // küçük
    }

    // Sonucu geri kopyala
    for (int i = 0; i < n; i++)
        arr[i] = result[i];
}
