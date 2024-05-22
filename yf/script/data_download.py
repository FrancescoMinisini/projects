import yfinance as yf

def print_stock_history(ticker_symbol, period='1y', interval='1d'):
    # Scarica i dati storici della stock
    stock = yf.Ticker(ticker_symbol)
    history = stock.history(period=period, interval=interval)
    
    # Stampa la history
#    file_name = f"{ticker_symbol}_history.csv"
    file_name = "data/history.csv"
    history.to_csv(file_name)
#    print(f"History for {ticker_symbol}:")
#    print(history)

# Esempio di utilizzo
ticker_symbol = 'AAPL'  # Sostituisci con il simbolo della stock desiderata
print_stock_history(ticker_symbol)
