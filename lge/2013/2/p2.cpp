// 2. Smallest Delivery Box
// author : aaa

#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
    #include <code/debug.h>
    #include <ctime>
#else
    #define trace printf
#endif

#define MAX_BOX_SIZE 100
#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

#define LEFT 0
#define RIGHT 1

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

class Tree;
class Box;
///////////////////////////////////////////////////////////////////////
// function prototypes
void solve(const char *input_file_path);
void get_input(ifstream &in);
void shuffle_input();
void arrange();
void insert(Tree *tree, int id);
bool need_rotation(Tree *tree, int width, int height);
void fit_box(Tree *parent, Box &box);
Tree *find_optimal_tree_to_fit(int width, int height);
int get_cost_to_fit(Tree *tree, Tree **optimal, int width, int height);
void enlarge_big_box(Tree *box);
void save_optimal();
void print_result();
void release_all();
void release_tree();


struct Rectangle {
    Rectangle() : _left(-1), _top(-1), _width(0), _height(0) {}
    Rectangle(int left, int top, int width, int height) :
        _left(left), _top(top), _width(width), _height(height) {}
    int _left, _top, _width, _height;
};

class Box {
public:
    Box() : _id(0), _rotate(false) {}
    Box(int id, const Rectangle &rect) : 
        _id(id), _rect(rect), _rotate(false) {}
    ~Box() {}
private:
    int _id;    // index
    Rectangle _rect;
    bool _rotate;
public:
    int get_id() const {return _id;}
    void set_id(int id) {_id = id;}
    Rectangle &get_rect() {return _rect;}
public:
    bool is_used() const {return (_rect._left != -1 && _rect._top != -1);}
    bool reset() {_rect._left = _rect._top = -1;}
    void rotate() {
        int temp = _rect._width; _rect._width = _rect._height; _rect._height = temp;
        _rotate = (_rotate == true ? false : true);
    }
    bool is_rotate() const {return _rotate;}
    bool operator==(const Box& b) const {return _rect._width == b._rect._width && _rect._height == b._rect._height;}
    bool operator>(const Box& b) const {
        int max1 = max(_rect._width, _rect._height);
        int max2 = max(b._rect._width, b._rect._height);
        return max1 > max2;
        if (max1 == max2) {
            return min(_rect._width, _rect._height) > min(b._rect._width, b._rect._height);
        }
        else {
            return max1 > max2;
        }
    }
    bool operator<(const Box& b) const {
        if (*this == b) return false;
        return !operator>(b);
    }
};


class Tree {
public:
    Tree() {
        _child[LEFT] = _child[RIGHT] = 0;
        _id = -1;   // invalid id
    }
    ~Tree() {}
private:
    Tree *_child[2];   // binary tree
    Rectangle _rect;
    int _id;
public:
    int get_id() const {return _id;}
    void set_id(int id) {_id = id;}
    Tree *get_child(int index) {return _child[index];}
    void set_child(int index, Tree *child) {_child[index] = child;}
    Rectangle &get_rect() {return _rect;}
    int getId() {return _id;}

    bool is_leaf() const {return (_child[0] == 0 && _child[1] == 0);}
    bool can_fit(int width, int height);
};

inline bool Tree::can_fit(int width, int height) {
    if (_id >= 0) return false; // aleady occupied
    if (is_leaf()) {
        return ((width <= _rect._width && height <= _rect._height) ||
            (width <= _rect._height && height <= _rect._width));
    }

    if ((_child[LEFT] && _child[LEFT]->can_fit(width, height)) ||
        (_child[RIGHT] && _child[RIGHT]->can_fit(width, height))) return true;
    return false;
}


///////////////////////////////////////////////////////////////////////
// global variables
Tree _root;
vector<Box> _pool;
int _min_cost = 0;
int _total_length = 0;
int _max_length = 0;
int _current_width = 0;
int _current_height = 0;
vector<Box> _input;

int _current_optimal_width = 10000;
int _current_optimal_height = 10000;
vector<Box> _backup;


bool compare(const Box& box1, const Box& box2) {
    return box1 > box2;
}

bool compare2(const Box& box1, const Box& box2) {
    return box1 < box2;
}


#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
int test_main(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
    const char *INPUT = "kk.txt";
#else
    const char *INPUT = argv[1];
#endif
    srand(time(0));
    for (int i = 0; i < 16; i++) {
        solve(INPUT);
    }
    print_result();
    return 0;
}


void solve(const char *input_file_path)
{
    ifstream in(input_file_path);
    if (!in.is_open()) return;

    get_input(in);
    arrange();
    save_optimal();
    release_all();
    in.close();
}

void get_input(ifstream &in)
{
    int i, size = 0;
    in >> size;
    //trace("%d\n", size);
    for (i = 0; i < size; i++) {
        int w, h;
        in >> w >> h;
        Box box(i, Rectangle(-1, -1, w, h));
        _pool.push_back(box);
        _input.push_back(box);

        _min_cost += w * h;
        _total_length += max(w, h);
        _max_length = max(_max_length, max(w, h));
    }

    static int try_num = 0;
    if (try_num == 0) {
    }
    else if (try_num == 1) {
        sort(_input.begin(), _input.end(), compare);
    }
    else if (try_num == 2) {
        sort(_input.begin(), _input.end(), compare2);
    }
    else if (try_num > 2) shuffle_input();
    try_num++;

    Rectangle &rect = _root.get_rect();
    rect._left = rect._top = 0;
    rect._width = rect._height = _total_length;
}

void shuffle_input()
{
    const int SIZE = _input.size();
    for (int i = 0; i < SIZE; i++) {
        int index2 = rand() % SIZE;

        if (i != index2) {
            Box box = _input[i];
            _input[i] = _input[index2];
            _input[index2] = box;
        }
    }
}


void arrange()
{
    vector<Box>::const_iterator it = _input.begin();
    for (; it != _input.end(); it++) {
        int id = (*it).get_id();
        insert(&_root, id);
    }
}

void insert(Tree *tree, int id)
{
    Box &box = _pool[id];

    if (tree->is_leaf()) {
        if (tree->getId() == -1) {
            // determine rotation or not
            if (need_rotation(tree, box.get_rect()._width, box.get_rect()._height)) {
                box.rotate();
            }

            int width = box.get_rect()._width;
            int height = box.get_rect()._height;

            // 1. make left
            Tree *left = new Tree();
            Rectangle rect;
            rect = tree->get_rect();
            rect._height = height;
            left->get_rect() = rect;
            tree->set_child(LEFT, left);

            // 2. make right
            Tree *right = new Tree();
            rect._top = tree->get_rect()._top + height;
            rect._height = tree->get_rect()._height - rect._top;
            right->get_rect() = rect;
            tree->set_child(RIGHT, right);

            // 3. fit the box to optimal
            fit_box(left, box);
            
        }
        else {
            trace("something wrong\n");
        }
    }
    else {
        // which is better ? find optimal space and fit the box to it
        Tree *optimal = find_optimal_tree_to_fit(box.get_rect()._width, box.get_rect()._height);
        insert(optimal, id);
    }
}


bool need_rotation(Tree *tree, int width, int height)
{
    int big_box_width = tree->get_rect()._width;
    int big_box_height = tree->get_rect()._height;

    if (big_box_width < width || big_box_height < height) {
        return true;
    }
    else if (big_box_width < height || big_box_height < width) {
        return false;
    }

    int left = tree->get_rect()._left;
    int top = tree->get_rect()._top;
    
    int cost_of_not = max(_current_width, left+width) * max(_current_height, top + height);
    int cost_of_rotation = max(_current_width, left+height) * max(_current_height, top + width);

    if (cost_of_rotation == cost_of_not) {
        return (height > width);
    }

    return (cost_of_rotation < cost_of_not);
}

void fit_box(Tree *parent, Box &box)
{
    Rectangle rect;
    Tree *for_box = new Tree();
    rect = box.get_rect();
    rect._left = parent->get_rect()._left;
    rect._top = parent->get_rect()._top;
    for_box->set_id(box.get_id());

    box.get_rect()._left = rect._left;
    box.get_rect()._top = rect._top;
    for_box->get_rect() = rect;

    parent->set_child(LEFT, for_box);
    enlarge_big_box(parent->get_child(LEFT));

    // insert empty space into right
    Tree *empty = new Tree();
    rect = parent->get_rect();
    rect._left = parent->get_rect()._left + for_box->get_rect()._width;
    rect._width = parent->get_rect()._width - for_box->get_rect()._width;
    empty->get_rect() = rect;
    parent->set_child(RIGHT, empty);
}


/**
 * param optimal [OUT]
 */
int get_cost_to_fit(Tree *tree, Tree **optimal, int width, int height)
{
    if (tree->get_id() >= 0) return 0x7FFFFFFF; // occupied node

    if (tree->is_leaf()) {
        int top = tree->get_rect()._top;
        int left = tree->get_rect()._left;

        // cat fit ?
        int cost_of_not = 0x7FFFFFFF;
        int cost_of_rotation = 0x7FFFFFFF;

        int big_box_width = tree->get_rect()._width;
        int big_box_height = tree->get_rect()._height;
        if (big_box_width >= width && big_box_height >= height) {
            cost_of_not = max(_current_width, left + width) * max(_current_height, top + height);
        }
        if (big_box_height >= width && big_box_width >= height) {
            cost_of_rotation = max(_current_width, left +height) * max(_current_height, top + width);
        }

        *optimal = tree;
        return min(cost_of_not, cost_of_rotation);
    }

    Tree *optimal_left = 0, *optimal_right = 0;
    int cost_left = get_cost_to_fit(tree->get_child(LEFT), &optimal_left, width, height);
    int cost_right = get_cost_to_fit(tree->get_child(RIGHT), &optimal_right, width, height);

    if (cost_left < cost_right) {
        *optimal = optimal_left;
        return cost_left;
    }
    else {
        *optimal = optimal_right;
        return cost_right;
    }
}

/**
 * full search and find optimal
 */
Tree *find_optimal_tree_to_fit(int width, int height)
{
    int min_cost = 0x7FFFFFFF;
    Tree *min_tree = 0;
    Tree *tree = &_root;

    get_cost_to_fit(tree, &min_tree, width, height); 
    return min_tree;
}

void enlarge_big_box(Tree *box)
{
    Rectangle &rect = box->get_rect();
    _current_width = max(_current_width, rect._left + rect._width);
    _current_height = max(_current_height, rect._top + rect._height);
}

void print_result()
{
    bool reverse = (_current_optimal_width < _current_optimal_height);

    if (reverse) {
        trace("%d %d\n", _current_optimal_height, _current_optimal_width);
        //getchar();
        const int SIZE = _backup.size();
        for (int i = 0; i < SIZE; i++) {
            Box &box = _backup[i];
            trace("%d %d %d\n", box.get_rect()._top, box.get_rect()._left, box.is_rotate()?0:1);
        }
    }
    else {
        trace("%d %d\n", _current_optimal_width, _current_optimal_height);
        //getchar();
        const int SIZE = _backup.size();
        for (int i = 0; i < SIZE; i++) {
            Box &box = _backup[i];
            trace("%d %d %d\n", box.get_rect()._left, box.get_rect()._top, box.is_rotate()?1:0);
        }
    }
}

void release(Tree *tree)
{
    if (tree->is_leaf()) {
        delete tree;
        tree = 0;
        return;
    }

    release(tree->get_child(LEFT));
    release(tree->get_child(RIGHT));
}

void save_optimal()
{
    //trace("%d %d\n", _current_width, _current_height);
    if (_current_optimal_width * _current_optimal_height > _current_width * _current_height) {
        _current_optimal_width = _current_width;
        _current_optimal_height = _current_height;
        int size = _pool.size();
        _backup.resize(size);
        memcpy(&(_backup[0]), &(_pool[0]), sizeof(Box) * size);
    }
}

void release_all()
{
    _min_cost = 0;
    _total_length = 0;
    _max_length = 0;
    _current_width = 0;
    _current_height = 0;

    _pool.clear();
    _input.clear();
    release_tree();
}

void release_tree()
{
    release(_root.get_child(LEFT));
    release(_root.get_child(RIGHT));
    _root.set_child(LEFT, 0);
    _root.set_child(RIGHT, 0);
}
