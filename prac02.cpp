#include<iostream>
#include"Time.h"
using namespace std;
int main() {
    int numberOfVisits(0), totalWaitingTime(0);
    char answer;
    do {
        bool errorFlag; // arrival, seenByDoctor are instances of Time class
        Time arrival, seenByDoctor;
        cout << "Enter arrival time:";
        arrival.readTime(errorFlag);
        while (errorFlag) {
            cout << "Arrival time was incorrectly formatted; try again: ";
            arrival.readTime(errorFlag);
        }
        cout << "Enter time seen by doctor:";
        seenByDoctor.readTime(errorFlag);
        while (errorFlag) {
            cout << "Seen by doctor time was incorrectly formatted; try again: ";
            seenByDoctor.readTime(errorFlag);
        }
        numberOfVisits++;
        // assume that subtracting one Time from another yields the
      // difference in minutes as an int
        totalWaitingTime += seenByDoctor.subtractTimes(arrival);
        cout << "Done? Enter 'y' to quit, anything else to continue: ";
        cin >> answer;
    } while (answer != 'y');
    cout << "Number of visits: " << numberOfVisits << "\n";
    cout << "Total waiting time: " << totalWaitingTime << " minutes.\n";
    cout << "Average wait is " << totalWaitingTime / numberOfVisits
        << " minutes.\n";

    Time arrival;
    bool errFlag;
    int aver = totalWaitingTime / numberOfVisits;
    cout << "Enter arrival time:";
    arrival.readTime(errFlag);
    int predic_waiting = arrival.addtime(aver);
    cout << "���� ��� �ð�: " << predic_waiting/60 << "�� " <<predic_waiting %60 <<"��"<< endl;

    return 0;
}
