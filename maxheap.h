//
// Created by devansh tomar on 3/4/22.
//

#ifndef DEFNS_H
#define DEFNS_H
#include "defns.h"
#endif

#include <iostream>
#include <string>
using namespace std;

string insertComma(int n);
void maxheapifyTotal(SOC arr[], int n, int i);
void maxheapifyMen(SOC arr[], int n, int i);
void maxheapifyWomen(SOC arr[], int n, int i);
void buildMaxHeap(SOC arr[], int n, string keyword);
void  extractMaxTotal(SOC arr[], int size, int numberOfOccupations);
void  extractMaxMen(SOC arr[], int size, int numberOfOccupations);
void  extractMaxWomen(SOC arr[], int size, int numberOfOccupations);
void readingCSV(string line, SOC &arr);
void initialize(SOC arr[], int size);
void readingCSVRatio1(string line, earnings &arr);
void readingCSVRatio2(string line, earnings &arr);
double getAverage(int maleSum, int femaleSum);
void printArray(earnings *arr, int n, int first, int second);
int searchArray(earnings *arr, int searched,  int n);



