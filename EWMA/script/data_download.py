import yfinance as yf

def print_stock_history(ticker_symbol, period='1y', interval='1h'):
    stock = yf.Ticker(ticker_symbol)
    history = stock.history(period=period, interval=interval)
#    file_name = f"{ticker_symbol}_history.csv"
    file_name = "data/history.csv"
    history.to_csv(file_name)
#    print(f"History for {ticker_symbol}:")
#    print(history)
def print_market_history(ticker_symbol, period='1y', interval='1h'):
    stock = yf.Ticker(ticker_symbol)
    history = stock.history(period=period, interval=interval)
#    file_name = f"{ticker_symbol}_history.csv"
    file_name = "data/market.csv"
    history.to_csv(file_name)

#ticker_symbol = "^GSPC" 
#print_market_history(ticker_symbol)
ticker_symbol = "GPRO"  
print_stock_history(ticker_symbol)


