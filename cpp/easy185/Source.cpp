/*
	http://www.reddit.com/r/dailyprogrammer/comments/2jt4cx/10202014_challenge_185_easy_generated_twitter/

	The following program reads wordlist.txt and looks for word having 'at' in it
	If such word is found, then 'at' is replaced with '@'
	Finally it prints such 10 smallest words and 10 longest words

	Written by
	Suyash Mohan
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//http://www.reddit.com/r/dailyprogrammer/comments/2jt4cx/10202014_challenge_185_easy_generated_twitter/
void easy185()
{
	//Open the file for reading
	ifstream fin("wordlist.txt");
	if (!fin.is_open())
	{
		//File not found
		cout << "Error opening file."<<endl;
		return;
	}

	string line, orgLine;
	vector<string> list;
	int pos;

	//Check of end of file
	while (!fin.eof())
	{
		//read the line
		getline(fin, line);
		//make a copy of word
		orgLine = line;
		
		//Look for 'at'
		while ((pos = line.find("at")) != string::npos)
		{
			//'at' found
			//Replace 'at' with '@'
			line.replace(pos, 2, "@");
		}

		if (line != orgLine)
		{
			//Line has been modified i.e. 'at' has been replace with '@'
			//Insert it into the list
			list.push_back(line);
		}
	}

	//For comparing our list based on the size of elements
	struct compare
	{
		bool operator()(const string &first, const string &second)
		{
			return first.size() < second.size();
		}
	};
	compare c;
	
	//Sort the list
	sort(list.begin(), list.end(), c);

	//Print the Shortest Names
	cout << "==========Shortest Names==========" << endl;
	for (unsigned int i = 0; i < 10 && i < list.size(); i++)
		cout << list.at(i) << endl;
	
	//Print the Longest Names
	cout << "==========Longest Names==========" << endl;
	for (unsigned int j = list.size()-1; j >= list.size() - 10; j--)
		cout << list.at(j) << endl;
}

int main(char *argv[], int argc)
{
	easy185();
}