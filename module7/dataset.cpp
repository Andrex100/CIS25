#include "dataset.h"

Sale::Sale(string id, string date, string model,
    string reg, string units, string rev)
{
    saleID = id;
    saleDate = date;
    gpuModel = model;
    region = reg;
    unitsSold = units;
    revenue = rev;
}

void Sale::display()
{
    cout << "Sale ID: " << saleID << endl;
    cout << "Date: " << saleDate << endl;
    cout << "GPU Model: " << gpuModel << endl;
    cout << "Region: " << region << endl;
    cout << "Units Sold: " << unitsSold << endl;
    cout << "Revenue: $" << revenue << endl;
    cout << "---" << endl;
}
