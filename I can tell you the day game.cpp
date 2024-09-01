#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;  

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

Node* createCircularDoublyLinkedList() {
    Node* head = new Node(0);
    Node* current = head;
    
    for (int i = 1; i <= 6; ++i) {
        current->next = new Node(i);
        current->next->prev = current;  
        current = current->next;
    }
    
    current->next = head; 
    head->prev = current;  
    return head;
}

Node* findUpdatedDay(Node* head, int updatedDay) {
    Node* current = head;
    do {
        if (current->data == updatedDay) {
            return current;
        }
        current = current->next;
    } while (current != head);
    
    return head; 
}

int main() {
    map<int, string> dayNames;
    dayNames[0] = "Sunday";
    dayNames[1] = "Monday";
    dayNames[2] = "Tuesday";
    dayNames[3] = "Wednesday";
    dayNames[4] = "Thursday";
    dayNames[5] = "Friday";
    dayNames[6] = "Saturday";
    
    int day, month, year;
    cout << "day: " << endl;
    cin >> day;
    cout << "month: " << endl;
    cin >> month;
    cout << "year: " << endl;
    cin >> year;
    
    int FirstStep = (year % 100) / 4;

    int SecondStep = FirstStep + (year % 100);

    int ThirdStep = SecondStep % 7;

    int DDay_century = (9 - ((year / 100) % 4) * 2) % 7;

    int updatedDay = (DDay_century + ThirdStep) % 7;
    
    int DDay_month;
    if (month == 1)
        DDay_month = 31;
    else if (month == 2)
        DDay_month = 28;
    else if (month == 3)
        DDay_month = 14;
    else if (month == 4)
        DDay_month = 4;
    else if (month == 5)
        DDay_month = 9;
    else if (month == 6)
        DDay_month = 6;
    else if (month == 7)
        DDay_month = 11;    
    else if (month == 8)
        DDay_month = 8;
    else if (month == 9)
        DDay_month = 5;
    else if (month == 10)
        DDay_month = 10;
    else if (month == 11)
        DDay_month = 7;
    else
        DDay_month = 12;
    
    int diff = day - DDay_month;
    
    Node* head = createCircularDoublyLinkedList();
    
    
    Node* startNode = findUpdatedDay(head, updatedDay);
    
    Node* current;
    
    if (diff >= 0) {
        
        current = startNode;
        for (int i = 0; i < abs(diff); ++i) {
            current = current->next;
        }
    } else {
        
        current = startNode;
        for (int i = 0; i < abs(diff); ++i) {
            current = current->prev;
        }
    }
    
    cout << endl;
    cout << "The day is: " << dayNames[current->data]<< endl;

    return 0;
}

