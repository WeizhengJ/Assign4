#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
#include <string>


/*  Weizheng Jiang
 *  z1861817
 *  CSCI 340 Section 2
 *
 *
 *  I certify that this is my own work and where appropriate an extension
    of the starter code provided for the assignment.
*/



using namespace std;

//declare the const integer for output format
const int ITEM_W = 16;
const int NO_ITEM = 3;

void get_words(map <string, int>&);
void print_words(const map<string, int>);
void clear_entry(const string&, string&);
void lower(char&);

//if the char is a number, return true, else return false
bool isnum(char c){return isalnum(c);}

//if the number is not a number, return true, else return false
bool isnnum(char c){return !isalnum(c);}

//read the input and insert the words into map m if the length is not 0
void get_words(map <string,int>& m)
{
	string first;
	string s;

	while(cin >> first)
	{
		clear_entry(first,s);

		if(s.length() != 0)
		{
			m[s]++;
		}
	}
}

void clear_entry(const string& first, string& s)
{
	auto i = first.begin();//initialize the first index to indicate the first char in the word

	auto j = first.begin();//initialize the second index to for another position

	i = find_if(first.begin(),first.end(),isnum);//find the number char in a word

	j = find_if(first.begin(),first.end(),isnnum);//find the char that is not a number

	s = first.substr(i - first.begin(), j - i);//copy the word from the position i to j

	for_each(s.begin(), s.end(),lower);//put them into lower case
}

void print_words(const map <string,int> m)
{
	//print the output in a correct format
	int words = 0, Line = 1;
	for(auto i = m.begin(); i != m.end(); i++)
		{
		cout << setw(ITEM_W) << left << i->first << " : " << i->second << "\t";
		if(Line == NO_ITEM)
			{
			cout << endl;
			Line = 0;
			}

		Line++;
		words+=i->second;
		}

	cout << "\nTotal words: " << words << endl;
	cout << "Displayed words: " << m.size() << endl;
}

	
void lower(char& c)
{
	c = tolower(c);//convert the char c into lower case
}


int main()
{
	map <string,int> m;

	get_words(m);

	print_words(m);

	return 0;
}
