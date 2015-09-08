// C++ Review Lab Exercises
// Class: Data Structures & Algorithms
// By: Christopher Aytona

#include <iostream>
#include <string>
using namespace std;

string PigLatinify(string &word)
{
	string new_word;
	char firstLetter;
	new_word = word;

	if (word[0] == 'q')
	{
		firstLetter = word[0];
		new_word.erase(new_word.begin());
		new_word.erase(new_word.begin());
		new_word += firstLetter;
		new_word += "u";
	}

	else if (word[0] != 'a' || 'e' || 'i' || 'o' || 'u')
	{
		firstLetter = word[0];
		new_word.erase(new_word.begin());
		new_word += firstLetter;
	}
	
	new_word += "ay";
	return new_word;
}

int main()
{
	string word;
	cout << "Input word: ";
	cin >> word;
	cout << PigLatinify(word) << endl;
	return 0;
}