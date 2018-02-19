/*
 *  @file    labThree_Part1.cpp
 *  @author  Tony Xu (xuj16)
 *  @date    2/18/2018
 *  @version 10.6
 *
 *  This is a little program that split all the inputs into
 *  two vectors and print its size and value. Then merge two
 *  vectors into one vector according to alphabetical order.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<string> que1(100); // Vector que1
    vector<string> que2(100); // Vector que2
    vector<string> que_merge; // Vector que_merge
    string userInput; // Variable use to record input
    unsigned int counter1 = 0; // Count the size of que1
    unsigned int counter2 = 0; // Count the size of que2
    unsigned int index = 0;

    // Ask user to enter input
    cout << "Enter queues:" << endl;
    cin >> userInput;

    // While loop use to enter inputs into vector que1 until "ENDQ" appears
    while (userInput != "ENDQ"){
        que1.at(counter1) = userInput;
        counter1++;
        cin >> userInput;
    }

    // Resize que1
    que1.resize(counter1);

    // Print the size and values in vector que1
    cout << "que1: " << que1.size() << endl;

    for (unsigned int i = 0; i < que1.size(); ++i) {
        cout << que1.at(i) << endl;
    }

    cout << endl;

    // Repeat the same process in que1
    cin >> userInput;

    while (userInput != "ENDQ"){
        que2.at(counter2) = userInput;
        counter2++;
        cin >> userInput;
    }

    que2.resize(counter2);

    cout << "que2: " << que2.size() << endl;

    for (unsigned int i = 0; i < que2.size(); ++i) {
        cout << que2.at(i) << endl;
    }

    cout << endl;

    que_merge.resize(counter1 + counter2);

    // Go through both vector and compare their first value
    while (que_merge.size() > index){
        // First Determine whether que1 or que2 is empty, and enter the value left in the other vector
        if (que1.empty()){
            que_merge.at(index) = que2.front();
            que2.erase(que2.begin());
        }
        else if (que2.empty()) {
            que_merge.at(index) = que1.front();
            que1.erase(que1.begin());
        }
        // Compare the first value of both vectors and add the smaller one into que_merge
        else if (que1.front() < que2.front()){
            que_merge.at(index) = que1.front();
            que1.erase(que1.begin());
        }
        else if (que1.front() > que2.front()){
            que_merge.at(index) = que2.front();
            que2.erase(que2.begin());
        }
        // If there are same value, add both into que_merge
        else if (que1.front() == que2.front()){
            que_merge.at(index) = que1.front();
            que1.erase(que1.begin());
            index++;
            que_merge.at(index) = que2.front();
            que2.erase(que2.begin());
        }
        index++; // Move the index forward
    }

    // Print information for que_merge
    cout << "que_merge: " << que_merge.size() << endl;

    for (unsigned int i = 0; i < que_merge.size(); ++i) {
        cout << que_merge.at(i) << endl;
    }

    return 0;
}
