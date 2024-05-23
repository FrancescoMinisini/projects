#include"libraries/definitions.h"
#define BETA 0.94

int main() {
    string directory = "data/history.csv"; 
    string filename = "data/output.csv";
    int n_stock = 0;
    int error_code = 0;
    weighted_avg* average_values;
    stock* stocks = initialize_stock_values(directory, n_stock, error_code);
    //print_data(stocks, n_stock , error_code);
    average_values = initialize_weighted_avgs( stocks , n_stock , BETA );
    //print_weighted_avgs (average_values , n_stock );
    save_data_to_file(stocks , average_values ,  n_stock ,  filename);
    delete[] stocks;
    delete[] average_values; 
    return 0;
}

