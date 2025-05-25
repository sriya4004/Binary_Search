int firstOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == k) {
            first = mid;
            high = mid - 1;  // search on the left
        }
        else if (arr[mid] < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return first;
}

// Function to find the last occurrence of k
int lastOccurrence(vector<int> &arr, int n, int k) {
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == k) {
            last = mid;
            low = mid + 1;  // search on the right
        }
        else if (arr[mid] < k) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return last;
}

// Function to return both first and last position of k
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k) {
    int first = firstOccurrence(arr, n, k);
    if (first == -1) return {-1, -1};
    int last = lastOccurrence(arr, n, k);
    return {first, last};
}

// Function to return count of occurrences of x
int count(vector<int>& arr, int n, int x) {
    pair<int, int> ans = firstAndLastPosition(arr, n, x);
    if (ans.first == -1) return 0;
    return (ans.second - ans.first + 1);
}
