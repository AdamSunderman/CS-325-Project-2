CoinChange:
	g++ -o CoinChange coin_change.cpp

run: CoinChange
	./ChangeSlow ${FILENAME}

default: CoinChange

clean:
	rm -f CoinChange