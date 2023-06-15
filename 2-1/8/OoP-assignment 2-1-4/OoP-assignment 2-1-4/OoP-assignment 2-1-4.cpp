#include <iostream>
#include <fstream>
#include <cstring> // Required for using strlen

using namespace std;

class Binary_alphbet_Decoder
{
private:
	char binaryline[20000];
	char output[100];
	int zero_count;
	int idx;// current index in the output array

public:
	Binary_alphbet_Decoder() : zero_count(0), idx(0) {} // initialize
	ifstream input_file;
	ofstream output_file;

	void decode() {
		if (!input_file || !output_file) { // If the file streams are not open
			cout << "error occurred" << endl; // Print an error message
			return; // Exit the function
		}

		input_file.getline(binaryline, 20000);
		int len = strlen(binaryline);

		for (int i = 0; i < len; i++) { // Traverse the string one character at a time
			if (binaryline[i] == '0') { // If the current character is '0'
				if (zero_count != 25) { // If zero_count is not 25
					zero_count++; // Increment zero_count by 1
				}
			}
			if (zero_count == 25) { // If zero_count is 25 (z is handled separately because 1 does not come out)
				output[idx++] = 'z'; // Add 'z' to the output array and increment idx
				zero_count = 0; // Reset zero_count to 0
			}
			else if (binaryline[i] == '1') { // If the current character is '1'(zero_count ==> a=0, b=1, ..., y=24)
				output[idx++] = zero_count + 'a'; // Add the corresponding alphabet to the output array and increment idx
				zero_count = 0; // Reset zero_count to 0
			}
		}

		for (int i = 0; i < idx; i++) { // Write the output array to the output file
			output_file << output[i];
		}
	}
};

int main(void) {
	Binary_alphbet_Decoder BaD;// Create an instance of the Binary_alphbet_Decoder class
	BaD.input_file.open("binary.txt");
	BaD.output_file.open("alphabet.txt");
	BaD.decode(); // Call the decode function

	BaD.input_file.close();
	BaD.output_file.close();

	return 0;
}
