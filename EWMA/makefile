
TARGET = script/compiled/algorithm.x
FUNCTIONS_SRC = script/libraries/functions.cpp
FUNCTIONS_OBJ = script/compiled/functions.o
ALGORITHM_SRC = script/algorithm.cpp
ALGORITHM_OBJ = script/compiled/algorithm.o
DATA_DOWNLOAD_SCRIPT = script/data_download.py
GRAPH_STOCK_SCRIPT = script/graph/graph_stock.py
GRAPH_PORTFOLIO_SCRIPT = script/graph/graph_portfolio.py

all: $(TARGET)

data_download:
	python3 $(DATA_DOWNLOAD_SCRIPT)
$(FUNCTIONS_OBJ): $(FUNCTIONS_SRC) script/libraries/definitions.h
	g++ -c $< -o $@
$(ALGORITHM_OBJ): $(ALGORITHM_SRC)
	g++ -c $< -o $@
$(TARGET): $(ALGORITHM_OBJ) $(FUNCTIONS_OBJ)
	g++ $^ -o $@
run: $(TARGET) data_download
	./$<
graph_stock: run
	python3 $(GRAPH_STOCK_SCRIPT)
graph_portfolio: run 
	python3 $(GRAPH_PORTFOLIO_SCRIPT)
graph: run
	python3 $(GRAPH_STOCK_SCRIPT)
	python3 $(GRAPH_PORTFOLIO_SCRIPT)