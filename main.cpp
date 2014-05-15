#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cerrno>
#include <vector>
/****
 * For each word in the input line, change the initial character to upper case if it is a lower case
 * letter. Print the modified line.
 * 
 * Take advantage of the fact that in ASCII upper case letters are contiguous and lower
 * case letters are contiguous and that they are separated by a decimal value of 32 (0x20).
 * 
 * Find the start of the next word in the input line by scanning for the first non-blank character.
 * If the rest of the line is blank, the scan of the line is finished.
 * 
 * Find the end of that word by scanning for the first blank character. If there are no more blanks, the 
 * scan of the line is finished.
 ****/
void processLine (std::string& line) {
	
	for(size_t i = 0; i != std::string::npos; ){
		i = line.find_first_not_of(' ',i);		// find beginning of word
		if(i == std::string::npos)	break;		// end of string: scan finished
		
		if(line[i] >= 'a' && line[i] <= 'z'){	// lower case letter found
			line[i]	-= 32;						// change to upper case
		}
		i	= line.find_first_of(' ',i);		// scan for end of word
	}
	
	std::cout << line << "\n";					// print modified line
}

int main(int argc, char **argv)
{
	std::ifstream file;
	std::string line;
	file.open (argv[1]);

	if(file.good()){
		while(std::getline(file,line)){
			processLine(line);
		}
	}else{
		std::cout << strerror(errno) << "\n";
		std::cout << "Could not open " << argv[1] << "\n";
	}

	return 0;
}
