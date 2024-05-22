#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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

int main() {
    string directory = "AAPL_history.csv"; // Replace with your file path
    int n_stock = 0;
    int error_code = 0;
    stock* stocks = initialize_stock_values(directory, n_stock, error_code);
/*
    if (error_code == 0) {
        // Process the stock data
        for (int i = 0; i < n_stock; i++) {
            cout << "Date: " << stocks[i].date << " Open: " << stocks[i].open << " High: " << stocks[i].high
                 << " Low: " << stocks[i].low << " Close: " << stocks[i].close << " Volume: " << stocks[i].volume
                 << " Dividends: " << stocks[i].dividends << " Stock Splits: " << stocks[i].stock_splits << endl;
        }
    } else {
        cout << "Error code: " << error_code << endl;
    }
*/
    // Don't forget to free the allocated memory
    delete[] stocks;

    return 0;
}

stock* initialize_stock_values(string directory, int& n_stock, int& error_code) {
    ifstream data(directory);

    if (!data.is_open()) {
        cout << "Failed to read file" << endl;
        error_code = -1;
        return nullptr;
    }

    // Skip the header
    string header;
    getline(data, header);

    // Count the number of lines
    n_stock = 0;
    string line;
    while (getline(data, line)) {
        n_stock++;
    }

    data.clear();  // Clear the EOF flag
    data.seekg(0); // Go back to the beginning of the file
    getline(data, header); // Skip the header again

    stock* vettore = new stock[n_stock];

    if (vettore == nullptr) {
        error_code = -2;
        return nullptr;
    }

    int index = 0;
    while (getline(data, line) && index < n_stock) {
        stringstream ss(line);
        string temp;
        
        getline(ss, vettore[index].date, ',');
        getline(ss, temp, ',');
        vettore[index].open = stod(temp);
        getline(ss, temp, ',');
        vettore[index].high = stod(temp);
        getline(ss, temp, ',');
        vettore[index].low = stod(temp);
        getline(ss, temp, ',');
        vettore[index].close = stod(temp);
        getline(ss, temp, ',');
        vettore[index].volume = stod(temp);
        getline(ss, temp, ',');
        vettore[index].dividends = stod(temp);
        getline(ss, temp, ',');
        vettore[index].stock_splits = stod(temp);

        index++;
    }

    data.close();
    error_code = 0;
    return vettore;
}


