#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

struct stock
{
    string date;
    double open;
    double high;
    double low;
    double close;
    double volume;
    double dividends;
    double stock_splits;
};

stock* initialize_stock_values(string directory, int& n_stock, int& error_code);
void print_data (stock* , int , int& ); 