//
//  main.cpp
//  HW4 #5
//
//  Created by Arthur on 10/11/19.
//  Copyright © 2019 Arthur. All rights reserved.
//

//Question #5
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
int EX = 0;
int COM = 0;
int QEX = 0;
int QCOM = 0;
int QEX2 = 0;
int QCOM2 = 0;
void selection_sort(vector<unsigned int>& vec);
void bubble_sort_improved(vector <unsigned int> &vec);
void insertion_sort(vector <unsigned int> &num);
void ShellSort(vector <unsigned int> &num);
void merge(vector<unsigned int>& array, vector<unsigned int>& result, int lowPointer, int highPointer, int upperBound);
void mergesort(vector<unsigned int>& array, vector<unsigned int>& result, int lowerBand, int upperBand);
void mergeSort(vector<unsigned int>& array);

int partition(int first, int last, vector<unsigned int>& arr);
void quick_sort(int first, int last, vector<unsigned int>& arr);
void quick_sort_wrapper(vector<unsigned int>& arr);

int partitionB(int first, int last, std::vector<unsigned int>& arr);
void middle_quick_sort(int first, int last, std::vector<unsigned int>& arr);
void middle_quick_sort_wrapper(vector<unsigned int>& arr);




int main()
{
    char op;
   // int comparisons = 0, exchanges = 0;
    
    //create a array that is sorted in ascending order
    vector<unsigned int>ascending;
    for (int i=0; i<10000; i++)
    {
        ascending.push_back(i);
    }
    
    //create a array that is sorted in descending order
    vector<unsigned int>descending;
    for (int i=9999; i>=0; i--)
    {
        descending.push_back(i);
    }
    
    //create a random array
    vector<unsigned int>randomlist;
    srand(time(0));
    for (int i=9999; i>=0; i--)
    {
        randomlist.push_back(rand()%10000);
    }
    
    cout << "Input A: selection sort; B: bubble sort; C: insertion sort; D: shell sort; F: merge sort; G: quick sort; H: quick sort(improved)" << endl;
    cin >> op;
  
switch(op){
    case ('A'):
        cout << "ascending: \n";
        selection_sort(ascending);
        cout << "descending: \n";
        selection_sort(descending);
        cout << "random: \n";
        selection_sort(randomlist);
        cout << endl << endl;
        break;
        
    case ('B'):
        cout << "ascending: \n";
        bubble_sort_improved(ascending);
        cout << "descending: \n";
        bubble_sort_improved(descending);
        cout << "random: \n";
        bubble_sort_improved(randomlist);
        cout << endl << endl;
        break;
        
    case ('C'):
        cout << "ascending: \n";
        insertion_sort(ascending);
        cout << "descending: \n";
        insertion_sort(descending);
        cout << "random: \n";
        insertion_sort(randomlist);
        cout << endl << endl;
        break;
        
    case('D'):
        cout << "ascending: \n";
        ShellSort(ascending);
        cout << "descending: \n";
        ShellSort(descending);
        cout << "random: \n";
        ShellSort(randomlist);
        cout << endl << endl;
        break;
        
    case('F'):
        cout << "ascending: \n";
        mergeSort(ascending);
        cout << "descending: \n";
        mergeSort(descending);
        cout << "random: \n";
        mergeSort(randomlist);
        cout << endl << endl;
        break;
        
    case('G'):
        cout << "ascending: \n";
        quick_sort_wrapper(ascending);
        cout << "descending: \n";
        quick_sort_wrapper(descending);
        cout << "random: \n";
        quick_sort_wrapper(randomlist);
        cout << endl << endl;
        break;
        
    case('H'):
        cout << "ascending: \n";
        middle_quick_sort_wrapper(ascending);
        cout << "descending: \n";
        middle_quick_sort_wrapper(descending);
        cout << "random: \n";
        middle_quick_sort_wrapper(randomlist);
        cout << endl << endl;
        break;

   
    }
    
    return 0;
}
   



void selection_sort(vector<unsigned int>& vec)
{
    int exchanges = 0, comparisons = 0;
    for (int fill = 0; fill < vec.size(); ++fill)
    {
        int pos_min = fill;
        for (int next = fill + 1; next < vec.size(); ++next)
        {
            comparisons++;
            if (vec[next] < vec[pos_min])
                pos_min = next;
            
        }
            if (fill != pos_min)
            {
                //make an exchange
                exchanges++;
                int temp = vec[pos_min];
                vec[pos_min] = vec[fill];
                vec[fill] = temp;
            }
    }
    cout << "comparisons: " << comparisons << " exchanges: " << exchanges << endl;
    
}


void bubble_sort_improved(vector <unsigned int> &vec)
{
    int Exchanges = 0, Comparisons = 0;
    
    bool exchanges = false;
    for (int i = 1; i <= vec.size(); i++)
    {
        exchanges = false;
        for (int j = 0; j < vec.size() - i; j++)
        {
            Comparisons++;
            if (vec[j + 1] < vec[j])
            {
                swap(vec[j], vec[j + 1]);
                exchanges = true;
                //an exchange happened
                Exchanges++;
            }
        }// stop sorting if no exchanges happened
        if (!exchanges){
        cout << "comparisons: " << Comparisons << " exchanges: " << Exchanges << endl;
        break;
        }
    }
}

void insertion_sort(vector <unsigned int> &num)
{
    int exchanges = 0, comparisons = 0;
    
    int i, j, key;
    bool insertionNeeded = false;
    for (j = 1; j < num.size(); j++)
    {
        key = num[j];
        insertionNeeded = false;
        for (i = j - 1; i >= 0; i--)
        {
            comparisons++;
            // larger values move right
            if (key < num[i])
            {
                exchanges++;
                num[i + 1] = num[i];
                insertionNeeded = true;
            }
            else
            {
                break;
            }
        }
        if (insertionNeeded)
            exchanges++;
            num[i + 1] = key;
        //Put key into its proper location
    }
     cout << "comparisons: " << comparisons << " exchanges: " << exchanges << endl;
}


void ShellSort(vector <unsigned int> &num){
    int exchanges = 0, comparisons = 0;
    
    int i, temp, flag = 1, numLength = num.size();
    int gap = numLength;
    bool insertionNeeded = false;
    int swapPos = 0;
    int key;
    while (true)
    {
        // boolean flag (true when not equal to 0)
        gap = (gap - 1) / 2;
        if (gap == 0){
            cout << "comparisons: " << comparisons << " exchanges: " << exchanges << endl;
            break;
        }
            
        for (int k = 0; k < gap; k++) {
            for (int j = gap + k; j < numLength; j += gap)
            {
                key = num[j];
                insertionNeeded = false;
                for (i = j - gap; i >= 0; i -= gap) {
                    comparisons++;
                    // Smaller values move right
                    if (key < num[i]) {
                        swapPos = i;
                        num[i + gap] = num[i];
                        insertionNeeded = true;
                        exchanges++;
                        
                    }
                    else
                        break;
                    
                }
                if (insertionNeeded) {
                    exchanges++;
                    num[swapPos] = key;
                    //Put key into its proper location
                    
                }
                
            }
            
        }
        
    }
    return;
}

void merge(vector<unsigned int>& array, vector<unsigned int>& result, int lowPointer, int highPointer, int upperBound) {
    int j = 0;
    int lowerBound = lowPointer;
    int mid = highPointer - 1;
    int n = upperBound - lowerBound + 1;
    //number of items
    while (lowPointer <= mid && highPointer <= upperBound){
        COM++;
        if (array[lowPointer] < array[highPointer])
            result[j++] = array[lowPointer++];
        else{
            result[j++] = array[highPointer++];
            EX++;
        }
    }
    while (lowPointer <= mid)
        result[j++] = array[lowPointer++];
    while (highPointer <= upperBound)
        result[j++] = array[highPointer++];
    for (j = 0; j < n; j++)
        //copy the items from the temporary array to the original array
        array[lowerBound + j] = result[j];
    
}
void mergesort(vector<unsigned int>& array, vector<unsigned int>& result, int lowerBand, int upperBand) {
    int midpoint;
    if (lowerBand < upperBand) {
        midpoint = (lowerBand + upperBand) / 2;
        mergesort(array, result, lowerBand, midpoint);
        //merge sort the left half
        mergesort(array, result, midpoint + 1, upperBand);
        //merge sort the right half
        merge(array, result, lowerBand, midpoint + 1, upperBand);
        
    }
    
}
void mergeSort(vector<unsigned int>& array){
    vector<unsigned int> result = array;
    mergesort(array, result, 0, array.size() - 1);
    cout << "comparisons: " << COM << " exchanges: " << EX << endl;
    
}


int partition(int first, int last, vector<unsigned int>& arr) {
    // Start up and down at either end of the sequence.
    // The first table element is the pivot value.
    int up = first+1;
    int down = last-1;
    do {

        while ((up != last) && !(arr[first] < arr[up])) {
            ++up;
            QCOM++;
        }
        while (arr[first] < arr[down]) {
            --down;
            QCOM++;
        }
        if (up < down) {
            // if up is to the left of down,
            swap(arr[up], arr[down]);
            QEX++;
        }
    } while (up < down); // Repeat while up is left of down.

    swap(arr[down], arr[first]);
    QEX++;
    return down;
}

void quick_sort(int first, int last, vector<unsigned int>& arr) {
    if (last - first > 1) {
        // There is data to be sorted.
        // Partition the table.
        int pivot = partition(first, last, arr);

        // Sort the left subarray.
        quick_sort(first, pivot, arr);

        // Sort the right subarray.
        quick_sort(pivot + 1, last, arr);
    }
}

void quick_sort_wrapper(vector<unsigned int>& arr){
    quick_sort(0, arr.size(), arr);
    cout << "comparisons: " << QCOM << " exchanges: " << QEX << endl;
}

void sort_median(vector<unsigned int>& arr, int first, int last){

    bool exchanges = true;
    int middle = (first + last) / 2;
    if (arr[first]>arr[middle])
        swap(arr[first], arr[middle]);
    if (arr[middle] > arr[last])
        swap(arr[middle], arr[last]);
    if (arr[first] > arr[middle])
        swap(arr[first], arr[middle]);


    //swap the middle with the left
    swap(arr[middle], arr[first]);
}

int partitionB(int first, int last, vector<unsigned int>& arr) {
    // Start up and down at either end of the sequence.
    // The first table element is the pivot value.


    int up = first+1;
    int down = last-1;
    sort_median(arr, first, last-1);
    int mid = first;
    do {
        while ((up != last - 1) && !(arr[mid] < arr[up])) {
            ++up;
            QCOM2++;
        }
        while (arr[mid] < arr[down]) {
            --down;
            QCOM2++;
        }
        if (up < down) {
            // if up is to the left of down,
            swap(arr[up], arr[down]);
            QEX2++;
        }
    } while (up < down); // Repeat while up is left of down.

    swap(arr[mid], arr[down]);
    QEX2++;

    return down;
}

void middle_quick_sort(int first, int last, vector<unsigned int>& arr) {
    if (last - first > 1) {
        // There is data to be sorted.
        // Partition the table.
        int pivot = partitionB(first, last, arr);

        // Sort the left half.
        middle_quick_sort(first, pivot, arr);

        // Sort the right half.
        middle_quick_sort(pivot + 1, last, arr);
    }
}

void middle_quick_sort_wrapper(vector<unsigned int>& arr){
    middle_quick_sort(0, arr.size(), arr);
    cout << "comparisons: " << QCOM2 << " exchanges: " << QEX2 << endl;
}



