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
    ReviewNode* n = new ReviewNode {rating, comment, nullptr};
    if (!head) return n;

    ReviewNode* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
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
    head = addtoTail(head, 4.1, "Meh, movie was okay and I would rather sleep");

    for (ReviewNode* p = head; p != nullptr; p = p->next){
        cout << p->rating << " - " << p->comment << " \n";
    }

    delete head; head = nullptr;
    return 0;

}