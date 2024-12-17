#include <iostream>
#include <memory>
#include "WordCounter.h"






using namespace std;

ostream& operator<<(ostream& os, WordCounter& objekt) {
    for (const auto &word: objekt.countMap) {
        os << word.first << " " << word.second << endl;

    }
    return os;
}

int main() {
    WordCounter test;
    test.count("das ist ein Beispielstring mit dem ich das ganze mal teste");
    test.print();
    try{
        test.remove("ist");
    }
    catch(invalid_argument &e){
        cout << e.what() << endl;
    }
    //test.reset();
    //print try catch
    try{
        test.print();
    }
    catch(invalid_argument &e){
        cout << e.what() << endl;
    }

    //get count try catch
    try{
        cout << test.getCount("ist") << endl;
    }
    catch(invalid_argument &e){
        cout << e.what() << endl;
    }

    try{
        cout << test("das") << endl;
    }
    catch(invalid_argument &e){
        cout << e.what() << endl;
    }
    try{
    cout << endl;
    cout << test << endl;
}
    catch(invalid_argument &e){
        cout << e.what() << endl;
    }

    shared_ptr<WordCounter> tm = shared_ptr<WordCounter>(new WordCounter());
    shared_ptr<WordCounter> tmt = make_shared<WordCounter>();
    tmt->count("greizkrutzefix du hund");
    tmt->print();
    tm->count("sdfwsdf2ej sdfsdf sdf");
    tm->print();

    return 0;
}
