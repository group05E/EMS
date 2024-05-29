#include <iostream>
#include <string>

using namespace std;

class Attendee {
public:
    string name;

public:
    Attendee(){}
    Attendee(string name) : name(name) {}

    string getName() const { return name; }

    void display() const {
        cout  << "Name: " << name << endl;
    }
};

class Venue {
private:
    string name;

public:
    Venue(){}
    Venue(string name) : name(name) {}

    string getName() const { return name; }

    void display() const {
        cout << "Venue Name: " << name << endl;
    }
};

class Schedule {
private:
    string date;
    string time;

public:
    Schedule(){}
    Schedule(string date, string time) : date(date), time(time) {}

    string getDate(){ return date; }
    string getTime(){ return time; }

    void display() const {
        cout << "Date: " << date << ", Time: " << time << endl;
    }
};

class Event {
private:
    int id;
    string name;
    Venue venue;
    Schedule schedule;
    Attendee attendees[20];
    int noOfAttendee;
    string category;

public:
    Event(){}
    Event(int id, string name, string cat, Venue venue, Schedule schedule)
        : id(id), name(name), category(cat), venue(venue), schedule(schedule), noOfAttendee(0) {}

    int getId() const { return id; }
    string getName() const { return name; }

    void countAttendee(){
        cout << "Enter no. of attendees for this Event: ";
        cin >> noOfAttendee;
    }

    void inputAttendee(){
        cin.ignore(); // To ignore the newline character left in the input buffer
        for(int i = 0; i < noOfAttendee; i++){
            cout << "Enter Name[" << i+1 << "]: ";
            getline(cin, attendees[i].name);
        }
    }

    string getCategory(){
        return category;
    }

    void display() const {
        cout << "Event ID: " << id << ", Name: " << name << endl;
        venue.display();
        schedule.display();
        cout << "Attendees: " << endl;
    
        for(int i = 0; i < noOfAttendee; i++){
            cout << i+1 << ". " << attendees[i].name << "   ";
        }
        cout << endl;
    }
};

class EventManagementSystem {
private:
    Event events[50];

    int i_con = 0, i_work = 0, i_sem = 0;

public:
    void addconferences() {
        int eventId; string eventName, venueName, scheduleDate, scheduleTime, cat;
        cout << "Enter Event ID: ";
        cin >> eventId;

        cout << "Enter Event Name: ";
        cin.ignore(); // To ignore the newline character left in the input buffer
        getline(cin, eventName);

        cout << "Enter Event Category(Conference/Workshop/Seminar): ";
        getline(cin, cat);

        cout << "Enter Venue Name: ";
        getline(cin, venueName);

        cout << "Enter Schedule Date: ";
        getline(cin, scheduleDate);

        cout << "Enter Schedule Time: ";
        getline(cin, scheduleTime);

        Venue ven(venueName);
        Schedule sch(scheduleDate, scheduleTime);
        Event newEvent(eventId, eventName, cat, ven, sch);

        // Add the new event to the conferences array
        events[i_con] = newEvent;

        // Set the number of attendees and their names for the newly added event
        events[i_con].countAttendee();
        events[i_con].inputAttendee();

        // Move to the next slot in the array
        i_con++;
    }

    void display(){
        // Display all the conferences
        for(int i = 0; i < i_con; i++){
            cout << endl << "============================\nEvent: " << i+1 << " (" << events[i].getCategory() << ")" << endl;
            cout << "============================\n";
            events[i].display(); cout << endl;
        }
    }
};

int main() {
    EventManagementSystem ems;
    
    int choice;
    do {
        cout << "\nEvent Management System Menu:\n";
        cout << "1. Add Event\n";
        cout << "2. Display Events\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ems.addconferences();
                break;

            case 2:
                ems.display();
                break;

            case 10:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while(choice != 0);


       return 0;
}
