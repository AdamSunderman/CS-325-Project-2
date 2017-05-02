#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

class ResultPair{
public:
	std::vector<int> array;
	int sum;

};


ResultPair changedp(vector<int> V, int amount);
void printVector(std::vector<int> vec, std::ofstream & outfile);
int runAlgorithms(string fileName);
ResultPair changeSlow(ResultPair coin_pair);

int main(int argc, char * argv[]) {

	string fileName;

	if (argv[1] != NULL)
		fileName = argv[1];
	//cout << "What file should I read?" << endl;
	//cin >> fileName;

	int results = runAlgorithms(fileName);


	if (results == 1) {
		cout << "Bad file read attempt" << endl;
	}

	return 0;
}



//Print Vector Contents
void printVector(std::vector<int> vec, std::ofstream & outfile) {
	for (int i = 0; i<vec.size(); i++) {
		outfile << vec[i];
		if ((i + 1) == vec.size()) {
			outfile << endl;
		}
		else {
			outfile << ", ";
		}

	}
}

//Function to read input file and run all algorithms and tests
int runAlgorithms(string fileName) {

	//The vector with the problem
	ResultPair problem;

	//Open the input file and verify it opened
	const char* file = (fileName + ".txt").c_str();
	std::ifstream input;
	input.open(file, std::ifstream::in);
	if (input.fail()) {
		cout << "File does not exist, Exiting" << endl;
		return 1;
	}

	//Open the output file
	std::ofstream output;
	output.open(fileName + "_change.txt");

	//Variables for file parsing
	string line;
	string delimiter = " ";
	size_t pos = 0;
	string token;
	int problemNumber = 0;

	//1. Get/Parse one problem store it in vector<int> problem.
	//2. Run all four algorithms on the vector, time and print the results.
	//3. Repeat for all lines in problem file.
	while (!input.eof()) {

		getline(input, line);

		//Find the index of the delimiter, save the number and
		//then remove the value from the line.
		while ((pos = line.find(delimiter)) != std::string::npos) {
			token = line.substr(0, pos);
			//cout << token << endl;
			problem.array.push_back(std::atoi(token.c_str()));
			line.erase(0, pos + delimiter.length());
		}

		//Due to formatting sometimes the last number won't get read by the
		//above while loop. This checks if there is still a number left in
		//the line and parses it if needed.
		if (line.length() > 0 && (isdigit(line[0]))){
			pos = 0;
			while (isdigit(line[pos])) {
				pos = pos + 1;
			}
			pos = pos + 1;
			token = line.substr(0, pos);
			//cout << token << endl;
			problem.array.push_back(std::atoi(token.c_str()));
		}
		problemNumber++;

		getline(input, line);

		//Find the index of the delimiter, save the number and
		//then remove the value from the line.
		while ((pos = line.find(delimiter)) != std::string::npos) {
			token = line.substr(0, pos);
			//cout << token << endl;
			problem.sum = std::atoi(token.c_str());
			line.erase(0, pos + delimiter.length());
		}

		//Due to formatting sometimes the last number won't get read by the
		//above while loop. This checks if there is still a number left in
		//the line and parses it if needed.
		if (line.length() > 0 && (isdigit(line[0]))){
			pos = 0;
			while (isdigit(line[pos])) {
				pos = pos + 1;
			}
			pos = pos + 1;
			token = line.substr(0, pos);
			//cout << token << endl;
			problem.sum = std::atoi(token.c_str());
		}

		//Print the final vector/problem contents
		output << "Problem " << problemNumber << endl << "Coins: ";
		printVector(problem.array, output);
		output << "Change To Make: " << problem.sum << endl;
		output << endl;

		/**
		We should be able to just run our algorithms here. We can each
		make a run through the current problem using the array "problem[]".
		The variable problemLength has the current number of items in problem[].
		We can each make a run with our algorithm, time them, then save the results
		as we go to a file or data structure. This should be a good skeleton to work from.
		**/

		//**************************Algorithm 1 Run Area************************

		output << "Algorithm 1 Problem " << problemNumber << endl;
		clock_t timeStart = clock();
		ResultPair alg1Results = changeSlow(problem);
		float alg1_elapsed = (float)(clock() - timeStart) / CLOCKS_PER_SEC;
		output << "Denoms used: ";
		printVector(alg1Results.array, output);
		output << "Num coins used: " << alg1Results.sum << endl
			<< "ChangeSlow Time: " << fixed << setprecision(10) << alg1_elapsed << endl << endl;


		//**************************Algorithm 1 Run Area************************


		//**************************Algorithm 2 Run Area************************
		/*
		output << "Algorithm 2 Problem " << problemNumber << endl;
		clock_t tStart = clock();
		ResultPair alg2Results = BetterEnum(problem, problemLength);
		float alg2_elapsed = (float)(clock() - tStart) / CLOCKS_PER_SEC;
		printVector(alg2Results.array, alg2Results.array.size(), output);
		output << "MSS Sum: " << alg2Results.sum << endl
		<< "MSS Time: " << fixed << setprecision(10) << alg2_elapsed << endl << endl;
		*/
		//**************************Algorithm 2 Run Area************************


		//**************************Algorithm 3 Run Area************************

		output << "Algorithm 3 Problem " << problemNumber << endl;
		clock_t alg3_begin = clock();
		ResultPair alg3Results = changedp(problem.array, problem.sum);
		clock_t alg3_end = clock();
		float alg3_elapsed = (float)(alg3_end - alg3_begin) / CLOCKS_PER_SEC;
		printVector(alg3Results.array, output);
		output << "Num coins used: " << alg3Results.sum << endl
			<< "ChangeDP Time: " << fixed << setprecision(10) << alg3_elapsed << endl << endl;

		//**************************Algorithm 3 Run Area************************


		//**************************Algorithm 4 (Linear) Run Area************************
		/*
		output << "Algorithm 4 Problem " << problemNumber << endl;
		clock_t alg4_begin = clock();
		ResultPair alg4Results = mssLinear(problem, problemLength);
		clock_t alg4_end = clock();
		float alg4_elapsed = (float)(alg4_end - alg4_begin) / CLOCKS_PER_SEC;
		printVector(alg4Results.array, alg4Results.array.size(), output);
		output << "MSS Sum: " << alg4Results.sum << endl
		<< "MSS Time: " << fixed << setprecision(10) << alg4_elapsed << endl << endl;
		cout << fixed << setprecision(10) << alg4_elapsed << endl;
		*/
		//**************************Algorithm 4 (Linear) Run Area************************


		//clear the vector
		problem.array.clear();
		problem.sum = 0;
	}
	input.close();
	output.close();
	return 0;
}


ResultPair changeSlow(ResultPair coin_pair){
	ResultPair results;
	ResultPair left;
	ResultPair right;
	results.array = std::vector<int>(coin_pair.array.size(), 0);
	results.sum = coin_pair.sum;

	for (int j = 0; j<coin_pair.array.size(); j++){
		if (coin_pair.sum == coin_pair.array[j]){
			results.array[j] = 1;
			results.sum = 1;
			return results;
		}
	}
	for (int k = 0; k<coin_pair.array.size(); k++){
		if (coin_pair.array[k] <= coin_pair.sum){
			ResultPair l_temp;
			ResultPair r_temp;
			l_temp.array = coin_pair.array;
			r_temp.array = coin_pair.array;
			l_temp.sum = coin_pair.array[k];
			r_temp.sum = coin_pair.sum - coin_pair.array[k];
			left = changeSlow(l_temp);
			right = changeSlow(r_temp);
		}
		if ((left.sum + right.sum) < results.sum){
			results.sum = (left.sum + right.sum);
			for (int l = 0; l<coin_pair.array.size(); l++) {
				results.array[l] = (left.array[l] + right.array[l]);
			}
		}
	}
	return results;
}

ResultPair changedp(std::vector<int> V, int amount){

	//T[p] Contains the minumum number of coins required for p cents
	vector<int> T(amount + 1);

	//L[p] Contains location of the first coin in an optimal solution for p cents
	vector<int> L(amount + 1);

	//Initialize T[0], as an amount of zero shoudl yield zero coin combos
	T[0] = 0;

	//Result storage
	ResultPair R;

	int min, coinIndex = 0;

	//Iterate up to the change amount
	for (int i = 1; i <= amount; i++){

		min = INT_MAX;

		//Minimize 1 + T[i-V[j]]
		for (int j = 0; j < V.size(); j++){

			//Only valid if the current denomination is less than
			//the current change amount
			if (V[j] <= i)

				//Record start index of optimal solution + reassign min 
			if (1 + T[i - V[j]] < min){
				min = 1 + T[i - V[j]];
				coinIndex = j;
			}
		}

		T[i] = min;
		L[i] = coinIndex;
	}

	//To generate the result vector, add the first element
	//of increasingly smaller subproblems 
	for (int i = amount; i > 0; i -= V[L[i]])
		R.array.push_back(L[i]);


	R.sum = T[amount];
	return R;
}











