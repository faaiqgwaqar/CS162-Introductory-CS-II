#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void count_letters(ifstream& infile, int* letters){
	char c;
	int i;
	while(infile>> c){
		if(c >= 'a' && c <= 'z'){
			i = c - 'a';
			letters[i]++;
		}
		
		else if(c >='A' && c <= 'Z'){
			i = c - 'A';
			letters[i]++;
		}
	}
}

void write_counts(ofstream& outfile, int* letters){
	char c = 'A';
	for(int i = 0;i < 26;i++){
		outfile << "Frequency of " << c << ": " << letters[i] << "\n";
		c++;
	}
}
			
int main(int argc,char **argv){
	
	int letters[26];
	
	for (int i = 0;i < 26;i++)
		letters[i] = 0;

	ifstream infile(argv[1]);
	if (infile.fail()){
		cout << "INVALID ... FAILED\n";
		return 1;
	}
	
	count_letters(infile,letters);
	infile.close();
	ofstream outfile(argv[2]);
	write_counts(outfile, letters);
	outfile.close();

	return 0;
//	write_counts(outfile,letters);
}
