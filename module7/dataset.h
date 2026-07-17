#ifndef DATASET_H
#define DATASET_H

#include <iostream>
#include <string>
using namespace std;

class Sale {
private:
    string saleID;
    string saleDate;
    string gpuModel;
    string region;
    string unitsSold;
    string revenue;

public:
    Sale(string id, string date, string model,
        string reg, string units, string rev);

    void display();
};

#endif
