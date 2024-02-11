// Copyright 2024 Aarsh Patel
#include<iostream>
using std::cout;
using std::endl;

// function to output the values in an integer array to the standard output
// device (using cout)
void OutputArray(int a[], int size);

void OutputArray(int a[], int size) {
    for ( int i = 0; i < size; ++i )
        cout << a[i] << " ";
    cout << endl;

}

// function that returns the average value in an array of integers
double AverageArray(const int nums[], int size);

double AverageArray(const int nums[], int size) {
    double sum = 0;
    for ( int i = 0; i < size; ++i )
        sum += nums[i];
    return sum / size;
}

int main() {
    const int kSize = 15;
    // We can initialize the values when the array is declared with a 
    // comma-separated list of values
    double some_reals[kSize] = {2.3, 6.7, -4.97};
    
    cout << some_reals << endl;
    cout << some_reals[1] << endl;
    cout << some_reals[10] << endl;
    cout << some_reals[30] << endl;
    cout << some_reals[-18] << endl;

    cout << sizeof(double) << endl;
    cout << some_reals + 1 << endl;

    for ( int i = 0; i < kSize; ++i )
        cout << "some_reals[" << i << "] = " << some_reals[i] << endl;

    int some_ints[kSize];
    cout << some_ints << " " << some_ints + 1 << endl;
    OutputArray(some_ints, kSize);
    cout << AverageArray(some_ints, kSize) << endl;
    return 0;
}