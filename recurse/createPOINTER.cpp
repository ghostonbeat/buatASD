#include <iostream>
using namespace std;

int main() {
    string mrkrabs = "Krabby Patty";
    string* plankton = &mrkrabs;

    cout << "Mr. Krabs punya " << mrkrabs << endl;
    cout << "Plankton telah mencuri " << *plankton << endl;
}