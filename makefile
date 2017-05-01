ChangeSlow:
	g++ -o ChangeSlow changeslow.cpp

run: ChangeSlow
	./ChangeSlow ${FILENAME}

default: ChangeSlow
	./ChangeSlow ${FILENAME}

clean:
	rm -f ChangeSlow