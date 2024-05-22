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

struct weighted_avg {
    double value;
    double sigma;
};

stock* initialize_stock_values(string directory, int& n_stock, int& error_code);
void print_data (stock* , int , int& ); 
weighted_avg* initialize_weighted_avgs(stock* data, int n_dati, double beta);
void print_weighted_avgs(weighted_avg* weighted_avgs, int n_dati);
void save_data_to_file(stock* data, weighted_avg* weighted_avgs, int n_dati, string filename);