#include<iostream>
#include<string>
#include<cctype> 
using namespace std;

// Node class.
class node {
public:
    string data;
    node* next;

    node(string value) {
        data = value;
        next = NULL;
    }
};

void display(node* head) {
    node* temp = head;

    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void deleteList(node* &head) {
    node* temp = head;
    node* nextNode;

    while (temp != NULL) {
        nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    head = NULL;
}

// Function to convert a string to lowercase
string toLower(string str) {
    for (char &c : str) {
        c = tolower(c);
    }
    return str;
}

// Function to convert a string to uppercase
string toUpper(string str) {
    for (char &c : str) {
        c = toupper(c);
    }
    return str;
}

// Alphabet checking function.
void latterChake(node* &head, string value, int point) {
    node* lastNode = head->next;
    node* secondLastNode = head;
    node* newnode = new node(value);

    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
        secondLastNode = secondLastNode->next;
    }

    if (head == NULL) {
        head = newnode;
        return;
    }

    if (head->next == NULL) {
        head = NULL;
    }

    if (toLower(secondLastNode->data).back() == toLower(lastNode->data).front()) {
        cout << "Correct!!!" << endl;
    }
    else {
        cout << "Wrong Name!!! Error!!!" << endl;
        if (point % 2 == 0) {
            cout << "Person 2 win" << endl;
        }
        else {
            cout << "Person 1 win" << endl;
        }
        display(head);
        cout<<"LinkedList is deleted"<<endl;
        deleteList(head);
        display(head);
        exit(0);
    }
}

// Same name checking function.
void check(node* &head, string value, int point) {
    node* temp = head;

    while (temp != NULL) {
        if (toLower(temp->data) == toLower(value)) {
            cout << "Same value entered!!!" << endl;
            if (point % 2 == 0) {
                cout << "Person 2 win" << endl;
            }
            else {
                cout << "Person 1 win" << endl;
            }
            display(head);
            cout<<"linkedList is deleted"<<endl;
            deleteList(head);
            display(head);
            exit(0);
        }
        temp = temp->next;
    }
}

// Adding value at the end of the node.
void addAtLast(node* &head, string value) {
    node* newNode = new node(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Main Function.
int main() {
    node* head = NULL;
    string value;

    cout << "Welcome to our Project:'Atlas Game' made by 'Rushi' " << endl
         << "There are some Rules to maintain." << endl;
    cout << "Rule 1: Make sure that first alphabet of new Country or state or city name must be same as last alphabet of previous Country or state or city name ." << endl;
    cout << "Rule 2: Make sure that the same name should not repeat." << endl;
    cout << "Enter 'exit' to manually exit the game." << endl;
    cout << "There is an example." << endl;

    addAtLast(head, "india");
    addAtLast(head, "australia");
    display(head);
    cout << "Now continue with above example i.e. 'a'." << endl;

    int point = 0;
    do {
        if (point % 2 == 0) {
            cout << "Turn for person 1" << endl;
        }
        else {
            cout << "Turn for person 2" << endl;
        }

        cout << "Add name: ";
        cin >> value;

        // Convert input to lowercase
        value = toLower(value);

        if (value == "exit") {
            cout << "Congratulations! You completed the game without any error." << endl;
            break;
        }

        check(head, value, point);
        addAtLast(head, value);
        latterChake(head, value, point);

        point++;
    } while (true);

    display(head);

    cout << "You completed the game. If you want to delete the list of words." << endl;
    cout << "Enter 'yes': ";
    cin >> value;

    if (toLower(value) == "yes") {
        deleteList(head);
        cout << "Now Link list is empty." << endl;
    }

    cout << "The line print 'List is empty' is the proof of the empty LinkList" << endl;
    display(head);

    return 0;
}
