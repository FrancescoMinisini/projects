data_download: script/data_download.py
	python3 script/data_download.py

script/compiled/functions.o: script/libraries/functions.cpp script/libraries/definitions.h
	g++ -c script/libraries/functions.cpp -o script/compiled/functions.o

script/compiled/algorithm.o: script/algorithm.cpp 
	g++ -c script/algorithm.cpp -o script/compiled/algorithm.o

script/compiled/algorithm.x: script/compiled/algorithm.o  script/compiled/functions.o
	g++ script/algorithm.cpp script/compiled/functions.o -o script/compiled/algorithm.x

run: script/compiled/algorithm.x data_download 
	./script/compiled/algorithm.x

graph: script/graph.py run
	python3 script/graph.py