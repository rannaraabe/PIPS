/*
Difficulty: Medium;

Comparators are used to compare two objects. In this challenge, you'll create a comparator and use it to sort an array. The Player class is provided in the editor below. It has two fields:
name: a string.
score: an integer.

Given an array of n Player objects, write a comparator that sorts them in order of decreasing score. If 2 or more players have the same score, sort those players alphabetically ascending by name. To do this, you must create a Checker class that implements the Comparator interface, then write an int compare(Player a, Player b) method implementing the Comparator.compare(T o1, T o2) method. In short, when sorting in ascending order, a comparator function returns -1 if a<b, 0 if a=b, and 1 if a>b.
Declare a Checker class that implements the comparator method as described. It should sort first descending by score, then ascending by name. The code stub reads the input, creates a list of Player objects, uses your method to sort the data, and prints it out properly.

Constraints:
0 <= score <= 1000
Two or more players can have the same name.
Player names consist of lowercase English alphabetic letters.
*/

#include <bits/stdc++.h>
using namespace std; 

struct Player {
    int score;
    string name;
};

class Checker{
public:
    static int comparator(Player a, Player b) {
        if(a.score < b.score) return -1;
        else if(a.score > b.score) return 1;
        else {
            if(a.name == b.name) return 0;
            else if(a.name < b.name) return 1;
            else return -1;
        }
    }
};

bool compare(Player a, Player b) {
    if(Checker::comparator(a,b) == -1)
        return false;
    return true;
}

int main() {
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;

    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player player;
        player.name = name, player.score = score;
        players.push_back(player);
    }

    sort(players.begin(), players.end(), compare);
    for(int i = 0; i < players.size(); i++) {
        cout << players[i].name << " " << players[i].score << endl;
    }

    return 0;
}
