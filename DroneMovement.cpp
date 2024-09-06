#include<bits/stdc++.h>
using namespace std;
// Function to find the position and distance based on the drone movement instructions
vector<int> findPositionandDistance(string t) {
    stack<int> sx, sy, sz, s_; // stacks for X, Y, Z, and multipliers
    sx.push(0), sy.push(0), sz.push(0); // initial positions
    int n = 1, d = 0, i = 0;

    while (i < t.length()) {
        if (isdigit(t[i])) { // when t[i] is a number
            string m = "";
            while (i < t.length() && isdigit(t[i])) { // extracting full number
                m += t[i];
                i++;
            }
            s_.push(stoi(m)); // store multiplier
            n *= s_.top();    // multiply the current n
            i--; // adjust for outer loop increment
        } 
        else if (t[i] == ')') { // if closing bracket, pop multiplier
            n /= s_.top(); 
            s_.pop();
        } 
        else if (t[i] == '+') {
            if (t[i+1] == 'X') {
                d += n;
                int newX = sx.top() + n;
                sx.pop();
                sx.push(newX);
            } 
            else if (t[i+1] == 'Y') {
                d += n;
                int newY = sy.top() + n;
                sy.pop();
                sy.push(newY);
            } 
            else if (t[i+1] == 'Z') {
                d += n;
                int newZ = sz.top() + n;
                sz.pop();
                sz.push(newZ);
            }
            i++; // skip the axis letter
        } 
        else if (t[i] == '-') {
            if (t[i+1] == 'X') {
                d += n;
                int newX = sx.top() - n;
                sx.pop();
                sx.push(newX);
            } 
            else if (t[i+1] == 'Y') {
                d += n;
                int newY = sy.top() - n;
                sy.pop();
                sy.push(newY);
            } 
            else if (t[i+1] == 'Z') {
                d += n;
                int newZ = sz.top() - n;
                sz.pop();
                sz.push(newZ);
            }
            i++; // skip the axis letter
        }
        i++; // move to next character
    }

    return {sx.top(), sy.top(), sz.top(), d}; // return final position and distance
}

int main() {
    string t;
    cout << "Enter the drone program: ";
    cin >> t;

    // Find the final position and distance
    vector<int> result = findPositionandDistance(t);

    // Output the final position and total distance
    cout << "Final Position: (" << result[0] << ", " << result[1] << ", " << result[2] << ")" << endl;
    cout << "Total Distance: " << result[3] << endl;

    return 0;
}
