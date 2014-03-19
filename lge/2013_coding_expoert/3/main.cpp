#include <iostream>


enum {
    VALUE,
    OPERATOR,
    FUCNTION,
};

class Node {
public:
    Node(int type) : _value(0), _parent(0), _left(0), _right(0), _op(0) {_type = type;}
    ~Node() {}
private:
    int _value;     // result of evaluation
    int _type;
    Node *_parent;
    Node *_left;
    Node *_right;
    Node *_op;

public:
    virtual int evaluate() = 0;
}



