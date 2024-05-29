#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
/*#include <TCanvas.h>
#include <TGraph.h>
#include <TAxis.h>
#include <TLegend.h>
#include <TApplication.h>*/
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

struct portfolio {
    double* value;
    double alpha;
    double beta;
    double* n_stocks;
};

stock* initialize_stock_values(string directory, int& n_stock, int& error_code);
void print_data (stock* , int , int& ); 
weighted_avg* initialize_weighted_avgs(stock* data, int n_dati, double beta);
void print_weighted_avgs(weighted_avg* weighted_avgs, int n_dati);
void save_data_to_file(stock* data, weighted_avg* weighted_avgs, portfolio, int n_dati, string filename);
void simulate_portfolio(portfolio& asset, stock* stocks, weighted_avg* weighted_avgs, float s_index, float percent, int n_stock); 




