#include <iostream>
#include <fstream>
#include <sstream>
#include "maxheap.h"
#include "earnings.h"
#define EARNINGS_ARRAY_SIZE 60

using namespace std;

int main() {
    fstream infile("/Users/devanshtomar/Documents/SPRING 2022/CSE 310/untitledFinal/queries.txt");
    fstream heapfile;
    heapfile.open("/Users/devanshtomar/Documents/SPRING 2022/CSE 310/untitledFinal/Occupation-Dist-All-1999.csv",
                  ios::in);
    fstream earningsFile("/Users/devanshtomar/Documents/SPRING 2022/CSE 310/untitledFinal/Earnings-1960-2019.csv");
    earnings *findRatio = new earnings[EARNINGS_ARRAY_SIZE];
    string ratioLine;
    for (int lineno = 0; getline(earningsFile, ratioLine) && lineno < 8; lineno++) {
        if (lineno == 7) {
            break;
        }
    }
    if (earningsFile.is_open()) {
        for (int lineno = 0; lineno < EARNINGS_ARRAY_SIZE; lineno++) {
            if(lineno < 45) {
                getline(earningsFile, ratioLine);
                readingCSVRatio1(ratioLine, findRatio[lineno]);
            }
            else{
                getline(earningsFile, ratioLine);
                readingCSVRatio2(ratioLine, findRatio[lineno]);
            }
        }
    }
    string line; // used to store the values read form the file
    while(infile.good()){
        getline(infile, line);
        stringstream p(readInput(line));
        string word;
        string category;
        string value;
        p >> word;
        p >> category;
        p >> value;
        string query = "find " + word + " " + category + " " + value;
        if(word == "max"){
            SOC *findMax = new SOC[NUM_OCC];
            string maxLine;
            for (int lineno = 0; getline(heapfile, maxLine) && lineno < 5; lineno++) {
                if (lineno == 4) {
                    break;
                }
            }
            if (infile.is_open()) {
                for (int lineno = 0; getline(heapfile, maxLine); lineno++) {
                    readingCSV(maxLine, findMax[lineno]);
                }
            }
            buildMaxHeap(findMax, NUM_OCC, category);
            if(category == "total"){
                cout << "Query: " << query << endl;
                cout << endl;
                cout << "Top " << value <<" occupations in 1999 for total workers:" << endl;
                extractMaxTotal(findMax, NUM_OCC, stoi(value));
            }
            else if(category == "male"){
                cout << "Query: " << query << endl;
                cout << endl;
                cout << "Top " << value <<" occupations in 1999 for male workers:" << endl;
                extractMaxMen(findMax, NUM_OCC, stoi(value));
            }
            else{
                cout << "Query: " << query << endl;
                cout << endl;
                cout << "Top " << value <<" occupations in 1999 for female workers:" << endl;
                extractMaxWomen(findMax, NUM_OCC, stoi(value));
            }
            heapfile.close();
            delete[] findMax;
        }
        else if(word == "ratio"){
            cout << "Query: " << query << endl;
            cout << endl;
            cout << "The female-to-male earnings ration for " << category << "-" << value << ":" << endl;
            printArray(findRatio, EARNINGS_ARRAY_SIZE, searchArray(findRatio, stoi(category), EARNINGS_ARRAY_SIZE), searchArray(findRatio, stoi(value), EARNINGS_ARRAY_SIZE));
        }
        cout << endl;
    }
}

