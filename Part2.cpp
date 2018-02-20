/*
 *  @file    labThree_Part2.cpp
 *  @author  Tony Xu (xuj16)
 *  @date    2/19/2018
 *  @version 8.3
 *
 *  This is a little program that add one to Part 1 of Lab 3.
 *  Adding two new vectors into part 1: que_merge_no_dup and
 *  que_count that removing duplicates and add count numbers
 *  to each appeared string.
 *
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<string> que1(100); // Vector que1
    vector<string> que2(100); // Vector que2
    vector<string> que_merge; // Vector que_merge
    vector<string> que_merge_no_dup; // Vector that remove the duplicates from que_merge
    vector<int> que_count; // Vector record counts for each different string

    string userInput; // Variable use to record input
    unsigned int counter1 = 0; // Count the size of que1
    unsigned int counter2 = 0; // Count the size of que2
    unsigned int counter3 = 0; // Track the que_merge_no_dup
    unsigned int index = 0;

    // Ask user to enter input
    cout << "Enter queues:" << endl;
    cin >> userInput;

    // While loop use to enter inputs into vector que1 until "ENDQ" appears
    while (userInput != "ENDQ") {
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

    while (userInput != "ENDQ") {
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
    while (que_merge.size() > index) {
        // First Determine whether que1 or que2 is empty, and enter the value left in the other vector
        if (que1.empty()) {
            que_merge.at(index) = que2.front();
            que2.erase(que2.begin());
        } else if (que2.empty()) {
            que_merge.at(index) = que1.front();
            que1.erase(que1.begin());
        }
            // Compare the first value of both vectors and add the smaller one into que_merge
        else if (que1.front() < que2.front()) {
            que_merge.at(index) = que1.front();
            que1.erase(que1.begin());
        } else if (que1.front() > que2.front()) {
            que_merge.at(index) = que2.front();
            que2.erase(que2.begin());
        }
            // If there are same value, add both into que_merge
        else if (que1.front() == que2.front()) {
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

    que_merge_no_dup = que_merge;
    que_count.resize(que_merge_no_dup.size());

    while (counter3 < que_count.size()){
        que_count.at(counter3) = 1;
        ++counter3;
    }

    counter3 = 0;

    if (que_merge_no_dup.size() > 0) {
        while (counter3 < que_count.size() - 1) {
            if (que_merge_no_dup.at(counter3) == que_merge_no_dup.at(counter3 + 1)) {
                que_count.pop_back();
                que_merge_no_dup.erase(que_merge_no_dup.begin() + counter3);
                que_count.at(counter3)++;
                continue;
            }
            counter3++;
        }
    }
    
    cout << "que_no_dups: " << que_merge_no_dup.size() << endl;

    for (unsigned int i = 0; i < que_merge_no_dup.size(); ++i){
        cout << que_merge_no_dup.at(i) << " " << que_count.at(i) << endl;
    }

    return 0;
}