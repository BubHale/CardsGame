/*
Sorting Playing Cards

This program reads a list of playing cards from the input file,
creates an array of Card type objects, then sorts them with the help
of a custom comparison function.

*/

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <list>
#include <tuple>

using namespace std;

// Utility functions
void loadFile(string fname, fstream& file)
{
    file.open(fname.c_str());
    if (file.fail())
    {
        cout << "Cannot open file " << fname << endl;
    }
}

// converts string to lowercase
string lowercase(string s)
{
    for (unsigned int i = 0; i < s.length(); i++)
    {
        s[i] = std::tolower(s[i]);
    }
    return s;
}


// Class representing a playing card
class Card
{
public:
    string value; // 2, 3, 4, ..., Queen, King, Ace
    string suit; // Clubs, Diamonds, Hearts, Spades
    // constructor
    // no input validation here!
    Card(string v, string s) : value(v), suit(s) {}

    bool operator < (Card& c) const;
    void print() const;

    int cardFaceInt() const;
    int cardSuitInt() const;
};

// helper functions for comparison
int
Card::cardFaceInt() const
{
    int result = 0;
    if (this->value == "2")
    {
        result = 0;
    }
    if (this->value == "3")
    {
        result = 1;
    }
    if (this->value == "4")
    {
        result = 2;
    }
    if (this->value == "5")
    {
        result = 3;
    }
    if (this->value == "6")
    {
        result = 4;
    }
    if (this->value == "7")
    {
        result = 5;
    }
    if (this->value == "8")
    {
        result = 6;
    }
    if (this->value == "9")
    {
        result = 7;
    }
    if (this->value == "10")
    {
        result = 8;
    }
    if (this->value == "Jack")
    {
        result = 9;
    }
    if (this->value == "Queen")
    {
        result = 10;
    }
    if (this->value == "King")
    {
        result = 11;
    }
    if (this->value == "Ace")
    {
        result = 12;
    }

    return result;
}
int
Card::cardSuitInt() const
{
    int result = 0;
    if (this->suit == "Clubs")
    {
        result = 0;
    }
    if (this->suit == "Diamonds")
    {
        result = 1;
    }
    if (this->suit == "Hearts")
    {
        result = 2;
    }
    if (this->suit == "Spades")
    {
        result = 3;
    }
    return result;

}

// Less than comparison operator overload
// INPUT: a Card c
// OUTPUT: True if 'this' Card is less than Card c, False otherwise
bool
Card::operator < (Card& c) const
{
    int thisResult = this->cardFaceInt() + this->cardSuitInt();
    int cResult = c.cardFaceInt() + c.cardSuitInt();
    if (thisResult < cResult) return true;
    else return false;
}

// prints out a string representation of the Card
void
Card::print() const
{
    cout << this->value << " " << this->suit << endl;
}

// INPUT: a list of Cards
// OUTPUT: a sorted list of Cards (descending order)
list<Card> 
mergeSort(list<Card> cards)
{
    list<Card> A;
    list<Card> B;
    int aPart, bPart;
    aPart = ceil(cards.size() / 2);
    bPart = floor(cards.size() / 2);
    if (cards.size() > 1) {
        //A = partition(cards.begin(),cards.end(), cards.size() / 2);
    }
    while (A.empty() && B.empty()) {
        if (A.front() < B.front()) {
            cards.push_back(A.front());
            A.pop_front();
        }
        else {
            cards.push_back(B.front());
            B.pop_front();
        }
    }
    while (A.empty()) {
        cards.push_back(A.front());
        A.pop_front();
    }
    while (B.empty()) {
        cards.push_back(A.front());
        B.pop_front();
    }
    return cards;
}

// INPUT: a list of (int, Card) tuples
// OUTPUT: a sorted list of (int, Card) tuples in descending order
list<tuple<int, Card> >
bucketSort(list<tuple<int, Card> > cards, int numBuckets)
{
    // Your code here
}

// INPUT: a list of Cards
// OUTPUT: a sorted list of Cards (descending order)
list<Card> 
lexSort(list<Card> cards)
{
    for (int i = 0; i < cards.size(); i++) {
        
    }
}

int main()
{
    string inputFilename = "input.txt";
    string line;
    bool echo = true;

    list<Card> cards = list<Card>();
    // open input file
    fstream inputFile;
    loadFile(inputFilename, inputFile);
    while (getline(inputFile, line))
    {
        // echo input
        if (echo) cout << line << endl;
        // parse input using a stringstream
        stringstream lineSS(line);
        string token;
        string command;
        // store tokens in a vector
        vector<string> tokens;
        while (getline(lineSS, token, ' '))
        {
            // trim whitespace
            token.erase(token.find_last_not_of(" \n\r\t") + 1);
            tokens.push_back(token);
        }

        if (tokens.size() > 0)
        {
            command = tokens[0]; // first token is the command
        }
        else
        {
            command = "";
        }

        if (command == "card")
        {
            cards.push_back(Card(tokens[1], tokens[2]));
        }
        if (command == "merge_sort")
        {
            cards = mergeSort(cards);
        }
        if (command == "lex_sort")
        {
            cards = lexSort(cards);
        }
        if (command == "print")
        {
            for (Card c : cards)
            {
                c.print();
            }
        }
        if (command == "noecho")
        {
            echo = false;
        }


    }
    inputFile.close();
    return EXIT_SUCCESS;
}