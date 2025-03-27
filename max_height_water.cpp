#include <iostream>
#include <vector>
using namespace std;

void findMaxWaterContainer(int n, vector<int>& arr) {
    int left = 0, right = n - 1;
    int maxWater = 0, bestLeft = 0, bestRight = 0;

    while (left < right) {
        int height = min(arr[left], arr[right]);
        int width = right - left;
        int water = height * width;

        if (water > maxWater) {
            maxWater = water;
            bestLeft = left;
            bestRight = right;
        }

        // Move the pointer pointing to the smaller height
        if (arr[left] < arr[right]) 
            left++;
        else 
            right--;
    }

    cout << bestLeft << " " << bestRight << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) 
            cin >> arr[i];
        findMaxWaterContainer(n, arr);
    }
    return 0;
}
