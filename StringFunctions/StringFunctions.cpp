// StringFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int countLetters(char ph[500]);
int countWords(char ph[500]);


int main()
{
	char phrase[500];

	cout << "please enter a phrase or word: ";
	cin.getline(phrase, 500);

	cout << "Your phrase has " << countLetters(phrase) << " letters." << endl;
	cout << "Your phrase has " << countWords(phrase) << " words." << endl;

    return 0;
}

// Functions pass letters, expected to pass character array; character arrays always end in null
int countLetters(char ph[500])
{
	int i;
	int count = 0;

	for (i = 0; ph[i] != '\0'; i++)
	{
		if ((ph[i] >= 'a' && ph[i] <= 'z') || (ph[i] >= 'A' && ph[i] <= 'Z'))
			count++;
	}

	return count;
}

int countWords(char ph[500])
{
	int i;
	int count = 0;
	bool inWord = false;

	for (i = 0; i < strlen(ph); i++)
	{


		if ((ph[i] >= 'a' && ph[i] <= 'z') || (ph[i] >= 'A' && ph[i] <= 'Z'))
		{
			if (!inWord)
			{
				count++;
				inWord = true;
			}
		}
		else
		{
			inWord = false;
		}
	}
	return count;
}

