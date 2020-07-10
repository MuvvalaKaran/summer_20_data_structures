# include "MovieTree.hpp"
# include <iostream>

using namespace std;

void inOrder(MovieNode* node);
bool findMovieTraversal(MovieNode* root, string title);
float averageTraversal(MovieNode* root, float sum, int count);
void queryMoviesTraversal(MovieNode* root, float rating , int year);
void addNodeTraversal(MovieNode* root,MovieNode* node);

MovieTree::MovieTree(){
    // Intialize any member varibales of the class to defau;t
    root = nullptr;
}

MovieTree::~MovieTree(){
    // Free all memory that was allocated
}

void MovieTree::printMovieInventory(){
    // print every node in the tree in alphabetical order of titles
    if (root == nullptr){
        cout << "Tree is Empty, Cannot print" << endl;
    }
    else{
        // we have to perform inorder traversal as we print Left sub tree first, the currrent root 
        // and then the right sub-tree
        inOrder(root);
    }
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating){
    // A function to add a node IN the correct place based on its title. 
    // NOTE: No two movies have the same title
    MovieNode *node = new MovieNode(ranking, title, year, rating);

    // compare the this node with the root and go to left is < and right if > 
    if (root == nullptr){
        root = node;
    }else{
        addNodeTraversal(root, node);
    }
    
    
}

void MovieTree::findMovie(string title){
    // A function to find the movie with the given title and print its corresponding information
    // bool found = findMovieTraversal(root, title); 
    if (!findMovieTraversal(root, title)){
        cout << "Movie not found." << endl;
    }
}

void MovieTree::queryMovies(float rating, int year){
    // A function to print all the moview with a rating of at least @rating and that were released before the year 
    // @year in the PREORDER traversal fashion.
    cout << "Movies that came out after " << year << " with rating at least " << rating 
    << ":" << endl;
    queryMoviesTraversal(root, rating, year);
}

void MovieTree::averageRating(){
    // A function to print the average rating for all movies in the tree. 
    float average = averageTraversal(root, 0, 0);
    cout << "Average rating:" << average << endl;
}

void inOrder(MovieNode* node){

    if (node != nullptr){
        inOrder(node->left);
        cout << "Movie: " << node->title << " " << node->rating << endl;
        inOrder(node->right);
    }
}

void addNodeTraversal(MovieNode* root, MovieNode* node){
    if (root != nullptr){
        if (node->title <= root->title){
            if (root->left != nullptr){
                addNodeTraversal(root->left, node);
            }
            else{
                root->left = node;
            }
            
        }
        else if (node->title[0] >= root->title[0])
        {
            if (root->right != nullptr){
                addNodeTraversal(root->right, node);
            }
            else{
                root->right = node;
            }
        }
    }
}

bool findMovieTraversal(MovieNode* root, string title){
    if (root != nullptr){
        if (root->title != title){
            if (root->left){
                findMovieTraversal(root->left, title);
            }
            if (root->right){
                findMovieTraversal(root->right, title);
            }
        }
        else{
            cout << "Movie Info:" << endl;
            cout << "=====================" << endl;
            cout << "Ranking:"  << root->ranking << endl;
            cout << "Title:"  << root->title << endl;
            cout << "Year:"  << root->year << endl;
            cout << "rating:"  << root->rating << endl;
            return true;
        }
    } 
    // return false;
}

void queryMoviesTraversal(MovieNode* root, float rating , int year){
    if (root != nullptr){
        if ((root->rating >= rating) && (root->year > year)){
            cout << root->title << "(" << root->year << ")" << root->rating << endl;
        }
    }
    else{
        cout << "Tree is Empty. Cannot query Movies" << endl;
    }
}

float averageTraversal(MovieNode* root, float sum, int count){

    if (root == nullptr){
        return 0.0;
    }
    else{
        sum += root->rating;
        count++;
        averageTraversal(root->left, sum, count);
        averageTraversal(root->right, sum , count);    
    }

    return sum/count;
}