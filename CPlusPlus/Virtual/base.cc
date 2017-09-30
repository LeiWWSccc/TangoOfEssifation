#include<iostream>
using namespace std;

class A {
public:
    
    virtual void printWithVitual(){
        cout << "A->vitual!" << endl;
    }
    
    void printWithoutVitual(){
        cout << "A->printWithoutVitual!" << endl;
    }

};

class SubA : public A {
public:

    virtual void printWithVitual(){
        cout << "SubA->vitual!" << endl;
    }
    void printWithoutVitual(){
        cout << "SubA->printWithoutVitual!" << endl;
    }
    
};

void print1(A &a) {
    a.printWithVitual();
}


void print2(A a) {
    a.printWithVitual();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    cout<< "===Stage 1==="<<endl<<endl;
    
    A a;
    SubA sa;
    a.printWithVitual();
    sa.printWithVitual();
    ((A)sa).printWithVitual();//something interesting coming up,sa is casted to A,then the output was't SubA's print method
    
    cout<< "===Stage 2==="<<endl<<endl;
    A *ap = &a;
    SubA* sap = &sa;
    A * ap1 = &sa;
    ap->printWithVitual();
    ap->printWithoutVitual();
    
    sap->printWithVitual();
    sap->printWithoutVitual();
    
    ap1->printWithVitual();
    ap1->printWithoutVitual();
    
    cout<< "===Stage 3==="<<endl<<endl;

    A & aRef = sa;
    aRef.printWithVitual();
    aRef.printWithoutVitual();
    print1(aRef);
    print2(aRef);
    
    cout<< "===Stage 4==="<<endl<<endl;
    
    print1(sa);
    print2(sa); // same as stage 1

    
    return 0;
}


