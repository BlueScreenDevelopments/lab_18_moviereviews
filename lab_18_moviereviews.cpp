#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
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
ReviewNode* addtoHead(ReviewNode* head, double rating, const string& comment){
    ReviewNode* n = new ReviewNode{rating, comment, head};
    return n;
}

ReviewNode* addtoTail(ReviewNode* head, double rating, const string& comment){
    void(rating); (void)comment;
    return head;
}

void    outputAllAndAverage(ReviewNode* head){
    (void)head;
}

void    deleteList(ReviewNode*& head){
    head = nullptr;
}


int main (){
    ReviewNode* head = nullptr;
    head = addtoHead(head, 4.8, "Terrible Movie -- would not recommend.");

    if (head){
        cout << "First Review: " << head->rating << " - " << head->comment << " \n";

    }

    delete head; head = nullptr;
    return 0;

}