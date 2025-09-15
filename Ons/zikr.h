#if !defined(ZIKR_H)
#define ZIKR_H


#include <string>
#include <vector>


using namespace std;


// Group of variables 
struct Zekr {
    string text;
    // int count;
};

class ZikrManaging {
private:
    
    vector<Zekr> list;
    int CurrentCount;

public:
    ZikrManaging();
    bool ImportZekrFromTxt();
    void displayAllGradually() const ; //Show the zikr in order
    void reset(); // for restart the loop 
    const vector<Zekr>& getList() const { return list; }
    

};


#endif // ZIKR_H
