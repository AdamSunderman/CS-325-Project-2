CoinChange:
	g++ -std=c++11 coin_change.cpp -o CoinChange 

run: CoinChange
	./ChangeSlow ${FILENAME}

default: CoinChange

clean:
	rm -f CoinChange