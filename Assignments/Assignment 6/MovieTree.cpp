# include "MovieTree.hpp"

using namespace std;

MovieTree::MovieTree(){
    // Intialize any member varibales of the class to defau;t
}

MovieTree::~MovieTree(){
    // Free all memory that was allocated
}

void MovieTree::printMovieInventory(){
    // print every node in the tree in alphabetical order of titles
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating){
    // A function to add a node IN the correct place based on its title. 
    // NOTE: No two movies have the same title
}

void MovieTree::findMovie(string title){
    // A function to find the movie with the given title and print its corresponding information
}

void MovieTree::queryMovies(float rating, int year){
    // A function to print all the moview with a rating of at least @rating and that were released before the year 
    // @year in the PREORDER traversal fashion.
}

void MovieTree::averageRating(){
    // A function to print the average rating for all movies in the tree. 
}