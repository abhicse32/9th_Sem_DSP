#include <iostream>
using namespace std;

class Shape {
    public: 
        Shape(){
            cout <<"Shape constructor\n";
        }
        virtual void xc(){
            cout <<"this is Shape\n";
        }
};

class rect: public Shape{
    public:
        rect(){
            cout <<"rect constructor\n";
        }
        void xc(){
            cout << "this is rect\n";
        }
};

int main(){
    Shape shape;
    rect rec;
    shape= rec;
    shape.xc();
}


