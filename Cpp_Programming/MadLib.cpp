// Creates a story based on user input

#include <iostream>
#include <string>
using std::string;

//function declaration
string askText(string prompt);
int askNumber(string prompt);

void tellStory(string* pName, string* pNoun, int number, string* pBodyPart, string* pVerb);//declare pointers

int main()
{
	std::cout << "Welcome to Mad Lib.\n\n";
	std::cout << "Answer the following questions to help create a new story.\n";
	
	string name = askText("Please enter a name: ");
	string noun = askText("Please enter a plural noun: ");
	int number = askNumber("Please enter a number: ");
	string bodyPart = askText("Please enter a body part: ");
	string verb = askText("Please enter a verb: ");
		
	tellStory(&name, &noun, number, &bodyPart, &verb);//use contents of these addresses
		
	return 0;
}

string askText(string prompt)
{
	string text;
	std::cout << prompt;
	std::cin >> text;
	return text;
}

int askNumber(string prompt)
{
	int num;
	std::cout << prompt;
	std::cin >> num;
	return num;
}

void tellStory(string* pName, string* pNoun, int number, string* pBodyPart, string* pVerb)
{
	std::cout << "\nHere's your story:\nThe famous explorer ";
	std::cout << *pName;//reference pointer
	std::cout << " had nearly given up a life-long quest to find\n";
	std::cout << "The Lost City of ";
	std::cout << *pNoun;//reference pointer
	std::cout << " when one day, the ";
	std::cout << *pNoun;//reference pointer
	std::cout << " found the explorer.\nSurrounded by ";
	std::cout << number;
	std::cout << " " << *pNoun;//reference pointer
	std::cout << ", a tear came to ";
	std::cout << *pName << "'s ";//reference pointer
	std::cout << *pBodyPart << ".\n";//reference pointer
	std::cout << "After all this time, the quest was finally over. ";
	std::cout << "And then, the ";
	std::cout << *pNoun << "\n";//reference pointer
	std::cout << "promptly devoured ";
	std::cout << *pName << ". ";//reference pointer
	std::cout << "The moral of the story? Be careful what you ";
	std::cout << *pVerb;//reference pointer
	std::cout << " for.";
}
