/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

# include "CountryNetwork.hpp"
# include <string>


CountryNetwork::CountryNetwork(){
  CountryNetwork::head = NULL;
}


void CountryNetwork::insertCountry(Country* previous, string countryName){
  // A function to insert a new country with name @CountryNmae in the Linked List after the country pointed
  // by @previous. If @previous == NULL, then add to the begining of the list and print a message 
  
  if (previous == NULL){
    cout << "adding :" << countryName << "(HEAD) " << endl;
  }
  else{
    cout << "adding: " << countryName << " (PREV: " << previous->name << ")" << endl; 
  }
}

void CountryNetwork::loadDefaultSetup(){
  // a function to add a default of countrie 

  string default_countries[6] = {"United States", "Canada", "BRazil", "India", "China", "Australia"};

}

Country* CountryNetwork::searchNetwork(string countryName){
  // A function that returns a pointer to the node with the name @countryName. If not found then return NULL

  return NULL;
}

void CountryNetwork::transmitMsg(string receiver, string msg){

}

void CountryNetwork::printPath(){
  // A helper function to print the name of each node in the linked list.
  /* Sample Output should look like :

  == CURRENT PATH ==
  United States -> Canada, Brazil -> India -> China -> Australia -> Null
  ===
  */
}
