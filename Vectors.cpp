// Vectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

double summation(vector<int>&, int);
vector<int> bubbleSort(vector<int>&, int);
double calculateMean(double, double);
double findMedian(vector<int>&, int);
double calculateVariance(vector<int>&, double, int);
double calculateStandardDeviation(double);


vector<int> randomNumbers;

unsigned seed;
int number, max, min, maxOccurrence, minOccurrence, averageNumber;
double sum, length, mean, variance;
int main()
{
	seed = time(0);
	srand(seed);
	max = 0;
	min = 100;

	cout << "How long would you like the list to be: ";
	cin >> length;


	cout << "The unsorted list: " << '\n';
	//Attempting to encapsulate everything within this loop 
	//to make runtime faster
	for (int i = 0; i < length; i++){
		number = rand() % 101;
		randomNumbers.push_back(number);
		
		//This if statement block is for finding the
		//max and minimum value and their occurence rates
		if (number > max){
			max = number;
			maxOccurrence = 0;
		}
		if (number == max) {
			maxOccurrence++;
		}
		if (number < min) {
			min = number;
			minOccurrence = 0;
		}
		if (number == min) {
			minOccurrence++;
		}

		cout << number << '\n';
	
	}
	system("PAUSE");
	sum = summation(randomNumbers, length);
	mean = calculateMean(sum, length);


	randomNumbers = bubbleSort(randomNumbers, length);
	cout << "Sorted list: \n";
	for (int i = 0; i < length; i++) {
		cout << randomNumbers[i] << '\n';
	}
	cout << "The mean is: " << mean << '\n';
	cout << "The median is: " << findMedian(randomNumbers, length) << '\n';
	
	variance = calculateVariance(randomNumbers, mean, length);
	cout << "The variance is: " << variance << '\n';
	
	cout << "The standard deviation is: " << calculateStandardDeviation(variance);
	
	cout << "The maximum is: " << max << " and its occurrence is: " << maxOccurrence << '\n';
	cout << "The minimum is: " << min << " and its occurrence is: " << minOccurrence << '\n';
}

//I wanted to get fancy so I did some recursion, plus it should have a quick runtime
//Just a simple summation of all the values in a vector
double summation(vector<int>& randomNumbers, int position){
	
	if (position <= 0) {
		return 0;
	}

	return (summation(randomNumbers, position - 1) + randomNumbers[position - 1.0]);
}
//Calculating the mean
double calculateMean(double sum, double length) {
	double mean;
	mean = sum / length * 1.0;
	return mean;
}
//Find the middle positioned value, must sort first
double findMedian(vector<int>& randomNumbers, int length) {
	int median;
	if (length % 2 == 1) {
		median = randomNumbers[(length/2)];
	}
	else if (length % 2 == 0) {
		median = (randomNumbers[((length - 1) / 2)] + randomNumbers[(((length - 1) / 2) + 1)]) / 2.0;
	}
	return median;
}

//Bubble sort for organizing values into a ascending order within the vector
vector<int> bubbleSort(vector<int>& randomNumbers, int length) {
	int swapPlaceholder;
	for (int i = 0; i < length - 1; i++) {

		for (int j = 0; j < length - i - 1; j++) {
			if (randomNumbers[j] > randomNumbers[j + 1]) {
				swapPlaceholder = randomNumbers[j + 1];
				randomNumbers[j + 1] = randomNumbers[j];
				randomNumbers[j] = swapPlaceholder;
			}
		}
	}
	return randomNumbers;
}

double calculateVariance(vector<int>& randomNumbers, double mean, int length) {
	double variance = 0;


	for (int i = 0; i < length; i++) {
		variance = variance + pow((randomNumbers[i] - mean), 2);
	}
	variance = variance / length;
	return variance;

}
double calculateStandardDeviation(double variance) {
	double standardDeviation;
	standardDeviation = sqrt(variance);
	return standardDeviation;
}


