#include <iostream>
#include <vector>
using namespace std;

void findElements();
bool solveString(string const target, string &tempString, const vector <string> allElements, vector <int> &keyElements);
bool checkString(string currentString, string const target, string const currentElement);


void findElements(){
  //Get the target string 
  cout << "Please enter your target string: ";
  string targetString;
  cin >> targetString;

  //Get the size of the element string set
  cout << "How many strings are in your element string set? ";
  int numberOfElements;
  cin >> numberOfElements;

  //Store the string elements in a vector
  vector <string> elementSet;
  for (int i=0; i < numberOfElements; i++){
    cout << "Enter element string in index " << i << ": ";
    string element;
    cin >> element;
    elementSet.push_back(element);
  }

  //Stores the sequence of elements that make up the target string
  vector <int> orderOfKey;

  //Stores a temporary result of the string as more matching elements are appended to it
  string stringResult = "";

  //Runs the recursion and prints out the sequence that is stored in orderOfKey
  if (solveString(targetString, stringResult, elementSet, orderOfKey)){
    cout << "The sequence of elements that make up the target string is: ";
    for (int j= 0; j < orderOfKey.size(); j++)
      cout << orderOfKey[j] << " ";
    cout << endl;
  }
  else
    cout << "There is no solution for this key with the given elements" << endl;
}

bool solveString(string const target, string &tempString, const vector <string> allElements, vector <int> &elementsKey){
  //Saves an original copy of the string in case it needs to backtrack 
  string originalString = tempString;

  //Base case: if the temporary string matches the target, then a solution has been found
  if (tempString == target)
    return true;

  //Adds each element to the temporary string to check if it matches the target string
  //If true, the temporary string updates and the element index is stored in elementsKey (the sequence solution)
  for (int i=0; i < allElements.size(); i++){
    if (checkString(tempString, target, allElements[i])){
      tempString += allElements[i];
      elementsKey.push_back(i);
      if (solveString(target, tempString, allElements, elementsKey))
	return true;

      //Backtracking if the result is false.
      //The temporary string is back to the original string and the element is no longer in the sequence solution
      tempString = originalString;
      elementsKey.pop_back(); 
    }
  }
  return false;
}
    

bool checkString(string currentString, string const target, string const currentElement){
  //Appends the element that the function is checking to the temporary string
  currentString += currentElement;
  
  //Stores the target string in a temporary target string to the size of the temporary string
  string currentTarget = ""; 
  for (int i=0; i < currentString.size(); i++){
    currentTarget +=  target[i];
  }
  if (currentString == currentTarget){
    return true;
    }
  return false;
}
    

int main(){
  findElements();
  return 0;
}
