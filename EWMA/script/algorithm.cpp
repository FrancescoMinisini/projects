#include"libraries/definitions.h"
#define GAMMA 0.97
#define starting_capital 100
#define starting_stocks 0
#define sigma_threshold 0.40
#define investing_percentage 0.1


int main() {
    string directory = "data/history.csv"; 
    //string directory_market = "data/market.csv";
    string filename = "data/EWMA.csv";
    int n_stock = 0 ; 
    int error_code = 0;
    weighted_avg* average_values;
    stock* stocks = initialize_stock_values(directory, n_stock, error_code);
    portfolio port;
    //print_data(stocks, n_stock , error_code);
    average_values = initialize_weighted_avgs( stocks , n_stock , GAMMA );
    port.value = new double[n_stock]; 
    port.n_stocks = new double[n_stock];
    port.value[0] = starting_capital;
    port.n_stocks[0] = starting_stocks;
    //print_weighted_avgs (average_values , n_stock );
    simulate_portfolio( port , stocks , average_values , sigma_threshold, investing_percentage , n_stock );
    save_data_to_file(stocks , average_values, port ,  n_stock ,  filename);
    delete[] stocks;
    delete[] average_values;
    delete[] port.value;
    delete[] port.n_stocks;
    return 0;
}

