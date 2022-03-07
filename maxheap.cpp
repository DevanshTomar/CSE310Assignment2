//
// Created by devansh tomar on 3/4/22.
//


#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include "maxheap.h"

using namespace std;

// C++ program for building Heap from Array


string insertComma(int n)
{
    stringstream ss;
    ss << n;
    string s = ss.str();
    int len = s.length();
    for (int i = len - 3; i > 0; i -= 3)
        s.insert(i, ",");
    return s;
}

//maxheapify For SOC array
void maxheapifyTotal(SOC arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l].total > arr[largest].total)
        largest = l;

    if (r < n && arr[r].total > arr[largest].total)
        largest = r;

    if (largest != i)
    {
        SOC temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxheapifyTotal(arr, n, largest);
    }
}
void maxheapifyMen(SOC arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l].male > arr[largest].male)
        largest = l;

    if (r < n && arr[r].male > arr[largest].male)
        largest = r;

    if (largest != i)
    {
        SOC temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxheapifyMen(arr, n, largest);
    }
}
void maxheapifyWomen(SOC arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l].female > arr[largest].female)
        largest = l;

    if (r < n && arr[r].female > arr[largest].female)
        largest = r;

    if (largest != i)
    {
        SOC temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxheapifyWomen(arr, n, largest);
    }
}

//Build MaxHeap For SOC array
void buildMaxHeap(SOC arr[], int n, string keyword)
{
    if (keyword == "total")
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            maxheapifyTotal(arr, n, i);
    }
    else if (keyword == "male"){
        for (int i = n / 2 - 1; i >= 0; i--)
            maxheapifyMen(arr, n, i);
    }
    else{
        for (int i = n / 2 - 1; i >= 0; i--)
            maxheapifyWomen(arr, n, i);
    }
}

void extractMaxTotal(SOC arr[], int size, int numberOfOccupations)
{
    int i = 0;
    string res = "";
    while(i < numberOfOccupations){
        if (size == 0) {
            return;
        }
        if (size == 1) {
            size--;
            res = res + to_string(arr[0].total) + "\n";
            cout << res;
        }
        SOC temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;
        size--;
        buildMaxHeap(arr, size, "total");
        i++;
        res = res + "\t    " + arr[size].occupation + ": " + insertComma(arr[size].total) + "\n";
    }
    cout << res;
}

void extractMaxMen(SOC arr[], int size, int numberOfOccupations)
{
    int i = 0;
    string res = "";
    while(i < numberOfOccupations){
        if (size == 0) {
            return;
        }
        if (size == 1) {
            size--;
            res = res + to_string(arr[0].male) + "\n";
            cout << res;
        }
        SOC temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;
        size--;
        buildMaxHeap(arr, size, "male");
        i++;
        res = res + "\t    " + arr[size].occupation + ": " + insertComma(arr[size].male) + "\n";
    }
    cout << res;
}

void extractMaxWomen(SOC arr[], int size, int numberOfOccupations)
{
    int i = 0;
    string res = "";
    while(i < numberOfOccupations){
        if (size == 0) {
            return;
        }
        if (size == 1) {
            size--;
            res = res + to_string(arr[0].female) + "\n";
            cout << res;
        }
        SOC temp = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = temp;
        size--;
        buildMaxHeap(arr, size, "female");
        i++;
        res = res + "" + arr[size].occupation + ": " + insertComma(arr[size].female) + "\n";
    }
    cout << res;
}



void readingCSV(string line, SOC &arr){
    int count = 1;
    string occupation;
    int total;
    int male;
    int female;
    string soc;
    stringstream ss(line);
    while (ss >> std::ws) {
        std::string csvElement;

        if (ss.peek() == '"') {
            ss >> quoted(csvElement);
            if(count == 1){
                for(int i = 0; i < csvElement.length(); i++){
                    arr.occupation[i] = csvElement[i];
                }
                occupation = csvElement;
                count++;
            }
            else if(count == 2){
                for(int i = 0; i < csvElement.length(); i++){
                    arr.SOC_code[i] = csvElement[i];
                }
                soc = csvElement;
                count++;
            }
            else if(count == 3){
                csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                arr.total = stoi(csvElement);
                total = stoi(csvElement);
                count++;
            }
            else if(count == 4){
                csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                arr.female = stoi(csvElement);
                female = stoi(csvElement);
                count++;
            }
            else{
                csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                arr.male = stoi(csvElement);
                male = stoi(csvElement);
                count = 1;
            }
            std::string discard;
            std::getline(ss, discard, ',');
        } else {
            std::getline(ss, csvElement, ',');
            if(count == 1){
                for(int i = 0; i < csvElement.length(); i++){
                    arr.occupation[i] = csvElement[i];
                }
                occupation = csvElement;
                count++;
            }
            else if(count == 2){
                for(int i = 0; i < csvElement.length(); i++){
                    arr.SOC_code[i] = csvElement[i];
                }
                soc = csvElement;
                count++;
            }
            else if(count == 3){
                csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                arr.total = stoi(csvElement);
                total = stoi(csvElement);
                count++;
            }
            else if(count == 4){
                csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                arr.female = stoi(csvElement);
                female = stoi(csvElement);
                count++;
            }
            else{
                csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                arr.male = stoi(csvElement);
                male = stoi(csvElement);
                count = 1;
            }
        }
    }
}


void readingCSVRatio1(string line, earnings &arr) {
    int count = 1;
    stringstream s(line);
    while (s >> std::ws) {
        std::string csvElement;
        if (s.peek() == '"') {
            s >> quoted(csvElement);
            if (count == 1) {
                arr.year = stoi(csvElement);
                count++;
            } else if (count == 2) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.male_total = stoi(csvElement);
                    count++;
                } else {
                    arr.male_total = 0;
                    count++;
                }

            } else if (count == 3) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.male_with_earnings = stoi(csvElement);
                    count++;
                } else {
                    arr.male_with_earnings = 0;
                    count++;
                }
            } else if (count == 4) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.male_earnings = stoi(csvElement);
                    count++;
                } else {
                    arr.male_earnings = 0;
                    count++;
                }
            } else if (count == 5) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.male_earnings_moe = stoi(csvElement);
                    count++;
                } else {
                    arr.male_earnings_moe = 0;
                    count++;
                }
            } else if (count == 6) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.female_total = stoi(csvElement);
                    count++;
                } else {
                    arr.female_total = 0;
                    count++;
                }
            } else if (count == 7) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.female_with_earnings = stoi(csvElement);
                    count++;
                } else {
                    arr.female_with_earnings = 0;
                    count++;
                }
            } else if (count == 8) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.female_earnings = stoi(csvElement);
                    count++;
                } else {
                    arr.female_earnings = 0;
                    count++;
                }
            } else if (count == 9) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.female_earnings_moe = stoi(csvElement);
                } else {
                    arr.female_earnings_moe = 0;
                }
            }
            std::string discard;
            std::getline(s, discard, ',');
        } else {
            std::getline(s, csvElement, ',');
            if (count == 1) {
                arr.year = stoi(csvElement);
                count++;
            } else if (count == 2) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.male_total = stoi(csvElement);
                    count++;
                } else {
                    arr.male_total = 0;
                    count++;
                }
            } else if (count == 3) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.male_with_earnings = stoi(csvElement);
                    count++;
                } else {
                    arr.male_with_earnings = 0;
                    count++;
                }
            } else if (count == 4) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.male_earnings = stoi(csvElement);
                    count++;
                } else {
                    arr.male_earnings = 0;
                    count++;
                }
            } else if (count == 5) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.male_earnings_moe = stoi(csvElement);
                    count++;
                } else {
                    arr.male_earnings_moe = 0;
                    count++;
                }
            } else if (count == 6) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.female_total = stoi(csvElement);
                    count++;
                } else {
                    arr.female_total = 0;
                    count++;
                }
            } else if (count == 7) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.female_with_earnings = stoi(csvElement);
                    count++;
                } else {
                    arr.female_with_earnings = 0;
                    count++;
                }
            } else if (count == 8) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.female_earnings = stoi(csvElement);
                    count++;
                } else {
                    arr.female_earnings = 0;
                    count++;
                }
            } else if (count == 9) {
                csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                arr.female_earnings_moe = stoi(csvElement);
                count++;
            }
        }
    }
}

void readingCSVRatio2(string line, earnings &arr) {
    int count = 1;
    stringstream s(line);
    while (s >> std::ws) {
        std::string csvElement;
        if (s.peek() == '"') {
            s >> quoted(csvElement);
            if (count == 1) {
                arr.year = stoi(csvElement);
                count++;
            } else if (count == 2) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.male_total = stoi(csvElement);
                    count++;
                } else {
                    arr.male_total = 0;
                    count++;
                }

            } else if (count == 3) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.male_with_earnings = stoi(csvElement);
                    count++;
                } else {
                    arr.male_with_earnings = 0;
                    count++;
                }
            } else if (count == 4) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.male_earnings = stoi(csvElement);
                    count++;
                } else {
                    arr.male_earnings = 0;
                    count++;
                }
            } else if (count == 5) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.male_earnings_moe = stoi(csvElement);
                    count++;
                } else {
                    arr.male_earnings_moe = 0;
                    count++;
                }
            } else if (count == 6) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.female_total = stoi(csvElement);
                    count++;
                } else {
                    arr.female_total = 0;
                    count++;
                }
            } else if (count == 7) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.female_with_earnings = stoi(csvElement);
                    count++;
                } else {
                    arr.female_with_earnings = 0;
                    count++;
                }
            } else if (count == 8) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.female_earnings = stoi(csvElement);
                    count++;
                } else {
                    arr.female_earnings = 0;
                    count++;
                }
            } else if (count == 9) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.female_earnings_moe = stoi(csvElement);
                } else {
                    arr.female_earnings_moe = 0;
                }
            }
            std::string discard;
            std::getline(s, discard, ',');
        } else {
            std::getline(s, csvElement, ',');
            if (count == 1) {
                arr.year = stoi(csvElement);
                count++;
            } else if (count == 2) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.male_total = stoi(csvElement);
                    count++;
                } else {
                    arr.male_total = 0;
                    count++;
                }
            } else if (count == 3) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.male_with_earnings = stoi(csvElement);
                    count++;
                } else {
                    arr.male_with_earnings = 0;
                    count++;
                }
            } else if (count == 4) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.male_earnings = stoi(csvElement);
                    count++;
                } else {
                    arr.male_earnings = 0;
                    count++;
                }
            } else if (count == 5) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.male_earnings_moe = stoi(csvElement);
                    count++;
                } else {
                    arr.male_earnings_moe = 0;
                    count++;
                }
            } else if (count == 6) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.female_total = stoi(csvElement);
                    count++;
                } else {
                    arr.female_total = 0;
                    count++;
                }
            } else if (count == 7) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.female_with_earnings = stoi(csvElement);
                    count++;
                } else {
                    arr.female_with_earnings = 0;
                    count++;
                }
            } else if (count == 8) {
                if (csvElement != "N") {
                    csvElement.erase(remove(csvElement.begin(), csvElement.end(), ','), csvElement.end()); // imp
                    arr.female_earnings = stoi(csvElement);
                    count++;
                } else {
                    arr.female_earnings = 0;
                    count++;
                }
            } else if (count == 9) {
                arr.female_earnings_moe = 0;
            }
        }
    }
} //used to read the ones with the last section as N

double getAverage(int maleSum, int femaleSum)
{
    return ((double)femaleSum/(double)maleSum) * 100;
}

void printArray(earnings *arr, int n, int first, int second)
{
    for (int i = first; i >= second; i--) {
        double d = getAverage(arr[i].male_earnings, arr[i].female_earnings);
        int tmp = d * 10;
        d = tmp / 10.0;
        printf("%d: %.1f%s\n", arr[i].year, d, "%");
    }
}

int searchArray(earnings *arr,int searched,  int n)
{
    for (int i = 0; i < n; i++) {
        if (arr[i].year == searched) {
            return i;
        }
    }
}