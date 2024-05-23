import yfinance as yf

def print_stock_history(ticker_symbol, period='1y', interval='1h'):
    # Scarica i dati storici della stock
    stock = yf.Ticker(ticker_symbol)
    history = stock.history(period=period, interval=interval)
#    file_name = f"{ticker_symbol}_history.csv"
    file_name = "data/history.csv"
    history.to_csv(file_name)
#    print(f"History for {ticker_symbol}:")
#    print(history)

ticker_symbol = 'ISP.MI'  
print_stock_history(ticker_symbol)
