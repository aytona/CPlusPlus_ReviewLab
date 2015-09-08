// C++ Review Lab Exercises
// Class: Data Structures & Algorithms
// By: Christopher Aytona

#include <iostream>
#include <string>
using namespace std;

string PigLatinify(string word)
{
	string new_word;
	char firstLetter = word[0];
	char secondLetter = word[1];
	new_word = word;

	// Check to see if the first letter starts with a q
	if (firstLetter == 'q')
	{
		new_word.erase(new_word.begin(), new_word.begin()+2);
		new_word += firstLetter;
		new_word += secondLetter;
	}
	// Check to see if the first letter starts with a vowel
	else if (firstLetter != 'a' && firstLetter != 'e' && firstLetter != 'i' && firstLetter != 'o' && firstLetter != 'u')
	{
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