/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represent communication paths between nations             */
/****************************************************************/

# include "CountryNetwork.hpp"
# include <string>


CountryNetwork::CountryNetwork(){
  CountryNetwork::head = NULL;
}


void CountryNetwork::insertCountry(Country* previous, string countryName){
  // A function to insert a new country with name @CountryNmae in the Linked List after the country pointed
  // by @previous. If @previous == NULL, then add to the begining of the list and print a message 
  
  if (head == nullptr){
    cout << "adding :" << countryName << "(HEAD) " << endl;
    // Country* countryName = new Country();
    // countryName->name = countryName;
    head = new Country();
    head->name = countryName;
    head->next = nullptr;
    head->numberMessages = 0;
  
  }
  else if(previous == nullptr){
    // this is a the ptr pointing to the head by adding a new node at the start of the list
    cout << "adding :" << countryName << "(HEAD) " << endl;
    Country * countryNode = new Country();
    countryNode->name = countryName;
    countryNode->next = head;
    head = countryNode;
    countryNode->numberMessages = 0;

  }
  else{
    cout << "adding: " << countryName << " (PREV: " << previous->name << ")" << endl; 
    // create a new node
    Country* countryNode = new Country();
    countryNode->name = countryName;
    // update the next of the new node and the previod ptr
    countryNode->next = previous -> next;
    // update the previous prt to point to this newly created node
    previous->next = countryNode;
    countryNode -> numberMessages = 0;
  }
}

void CountryNetwork::loadDefaultSetup(){
  // a function to add a default of countrie 

  insertCountry(nullptr, "United_States");
  insertCountry(searchNetwork("United States"), "Canada");
  insertCountry(searchNetwork("Canada"), "Brazil");
  insertCountry(searchNetwork("Brazil"), "India");
  insertCountry(searchNetwork("India"), "China");
  insertCountry(searchNetwork("China"), "Australia");
  searchNetwork("Australia")->next = nullptr;

}

Country* CountryNetwork::searchNetwork(string countryName){
  // A function that returns a pointer to the node with the name @countryName. If not found then return NULL

  Country* tmp_ptr = head;
  while(tmp_ptr != NULL && tmp_ptr->name != countryName){
    // traverse through the whole loop
    tmp_ptr  = tmp_ptr->next;
  }

  return tmp_ptr;
}

void CountryNetwork::transmitMsg(string receiver, string msg){
  Country *node = new Country();

  if (head = NULL){
    cout << "Empty list" << endl;
    return ;
  }

  bool find_flag = false;
  int counter = 0;
  while (node->next != nullptr && node->name == receiver){
    find_flag = true;
    node->message = msg;
    node->numberMessages = counter;
    counter++;
    node = node->next;
  }

  if (find_flag){
    cout << "Country not found" << endl;
  }
}

void CountryNetwork::printPath(){
  // A helper function to print the name of each node in the linked list.
  /* Sample Output should look like :

  == CURRENT PATH ==
  United States -> Canada, Brazil -> India -> China -> Australia -> Null
  ===
  */
 
 Country *node = head;
 cout << "== CURRENT PATH ==" << endl;
 
 if (head == NULL){
   cout << "nothing in path" << endl;
   return ;
 }

  while (node->next != NULL){
    cout << node->name << " -> ";
    node = node->next;
  }

  cout << node->name << " -> " << "NULL" << endl;

  cout << "===" << endl;
}
