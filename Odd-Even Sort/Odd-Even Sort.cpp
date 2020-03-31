// Odd-Even Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <ios>
#include <iterator>
#include <chrono>
#include "Odd-Even Sort.h"
using namespace std;

void printArray(int arr[], int n)
{
	ofstream fout("output.txt");
	for (int i = 0; i < n; i++)
		fout << arr[i] << " ";
	fout << "\n";
}

void secvSort(int arr[], int n) {
	bool isSorted = false; // Initially array is unsorted 

	while (!isSorted) {
		isSorted = true;

		// Perform Bubble sort on odd indexed element 
		for (int i = 1; i <= n - 2; i = i + 2) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}

		// Perform Bubble sort on even indexed element 
		for (int i = 0; i <= n - 2; i = i + 2) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}
	}
}

void readFromFile(int& n, int*& a)
{
	ifstream fin("input.txt");
	fin >> n;

	a = new int[n];
	int x;
	for (int i = 0; i < n; i++) {
		fin >> x;
		a[i] = x;
	}
}

int main()
{
	int n;
	int* a;
	readFromFile(n, a);

	auto startTime = chrono::steady_clock::now();
	secvSort(a, n);
	printArray(a, n);
	auto endTime = std::chrono::steady_clock::now();
	std::cout << "Secvential time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count() << std::endl;
	
	return 0;
}
