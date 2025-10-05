#include <iostream>
#include <string>
using namespace std;

/*
Brandon Julao
COMSC-210-5470
10.05.25
lab-18-movie reviews
*/

//structs
struct ReviewNode{
    double rating;
    string comment;
    ReviewNode* next;
};

//Linked-List Operations
ReviewNode* addtoHead(ReviewNode* head, double rating, const string& comment);
ReviewNode* addtoTail(ReviewNode* head, double rating, const string& comment);
void    outputAllAndAverage(ReviewNode* head);
void    deleteList(ReviewNode*& head);


int main (){
    cout << "Step 1: Nodes Complied \n";

    return 0;
}