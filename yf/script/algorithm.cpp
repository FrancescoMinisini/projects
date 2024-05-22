#include"libraries/definitions.h"

int main() {
    string directory = "data/history.csv"; 
    int n_stock = 0;
    int error_code = 0;
    stock* stocks = initialize_stock_values(directory, n_stock, error_code);
    //print_data(stocks, n_stock , error_code);
    delete[] stocks;
    return 0;
}

