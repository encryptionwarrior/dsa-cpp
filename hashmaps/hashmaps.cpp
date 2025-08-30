#include<iostream>
#include<map>
using namespace std;

void unOrderedMap(){
    map<string, int> M;

    pair<string, int> pair1 = make_pair("white", 2);
    M.insert(pair1);

    pair<string, int> pair2("black", 3);
    M.insert(pair2);

    M["red"] = 4;

    cout << "Before updation : white = " << M["white"] << endl;
    
    M["white"] = 10;
    cout << "After updation : white = " << M.at("white") << endl;
    cout << "Value of non-existent key 'orange' using [] = " << M["orange"] << endl;

    cout << "Size : " << M.size() << endl;

    cout << "Is 'yellow' present? (0=NO, 1=Yes) : " << M.count("yellow") << endl;
    cout << "Is 'white' present? (0=NO, 1=Yes) : " << M.count("white") << endl;

    M.erase("white");

    cout << "SIze after erasing white : " << M.size() << endl;

    cout << "Elements in map after removal (sorted by keys) : " << endl;

    for(auto i : M){
        cout << i.first << " & " << i.second << endl;
    }



}

int main(){

    unOrderedMap();
    return 0;
}