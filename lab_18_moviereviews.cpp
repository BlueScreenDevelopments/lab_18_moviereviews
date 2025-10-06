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

//structs -- each for movie review.
struct ReviewNode{
    double rating;
    string comment;
    ReviewNode* next;
};

//Linked-List Operations
// add to head -- add to the beginning of the list
ReviewNode* addtoHead(ReviewNode* head, double rating, const string& comment){
    ReviewNode* n = new ReviewNode{rating, comment, head};
    return n;
}
// add to tail -- end of list
ReviewNode* addtoTail(ReviewNode* head, double rating, const string& comment){
    ReviewNode* n = new ReviewNode {rating, comment, nullptr};
    if (!head) return n;

    ReviewNode* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
    return head;
}

// Outputs all reviews, and computes average
void    outputAllAndAverage(ReviewNode* head){
    cout << "All Reviews: \n";

    int count = 0;
    double sum = 0.0;

    for (ReviewNode* p = head; p !=nullptr; p = p->next){
        count++;
        cout << "  > Review #" << count <<": "
             << p->rating << ": " << p->comment << endl;
             sum += p->rating;
    }

    if (count ==0){
        cout << "  > No Reviews entered.\n";
    } else {
        double average = sum / count;
        cout << fixed << setprecision(3);
        cout << "   > Average: " << average << endl;
    }
}

//updated memory cleanup
    void deleteList(ReviewNode*& head){
        while (head){
            ReviewNode* temp = head;
            head = head->next;
            delete temp;
        }
}

int main (){
    ReviewNode* head = nullptr;

    // prompt for building the linked list
    cout << "Which linked list method should we use?\n";
    cout << "  [1] New Nodes are added at the head of the linked list\n";
    cout << "  [2] New Nodes are added to the tail of the linked list\n";
    cout << "  Choice:  ";

    int choice;
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char again = 'y';
    while (again == 'y' || again =='Y'){
        double rating;
        string comment;

        // user info
        cout << "Enter review rating 0-5: ";
        cin >> rating;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter review comments: ";
        getline(cin, comment);

        if (choice ==1)
            head = addtoHead(head, rating, comment);
        else
            head = addtoTail(head, rating, comment);

        cout << "Enter another review? Y/N: ";
        cin >> again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    outputAllAndAverage(head);
    deleteList(head);
    return 0;

}