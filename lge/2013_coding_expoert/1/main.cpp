#include <iostream>
#include <list>

//#define _DEBUG

#ifdef _WIN32
    typedef unsigned __int64    uint64;
#elif defined (__linux__) || defined (__CYGWIN__)
    typedef unsigned long long  uint64;
#endif
typedef std::list<int> List;

using namespace std;

//////////////////////////////////////////////////////////
// function prototypes
void solve();
void setInput(List &list);
void findOptimal(List &list);
int getMultiOfList(List &list);
int getSumOfList(List &list);
uint64 getMaxFlag(List &list);
int getLeftValue(List &list, uint64 flag);
int getRightValue(List &list, uint64 flag);
int getValue(List &list, uint64 flag, int match);
void pushLeft(List &target, List &org, uint64 flag);
void pushRight(List &target, List &org, uint64 flag);
void push(List &target, List &org, uint64 flag, int match);


uint64 _cost = 0;

int main()
{
    int size;
    cin >> size;
    //cout << size << endl;
    for (int i = 0; i < size; i++)
        solve();
    return 0;
}


void solve()
{
    List list;
    setInput(list);

    findOptimal(list);
    cout << _cost << endl;
}

void setInput(List &list)
{
    int size;
    cin >> size;
    //cout << size << endl;
    int a;
    for (int i = 0; i < size; i++) {
        cin >> a;
        list.push_back(a);
    }
    list.sort();
}


/**
 *
 * finish condition : the size of list is less than 2
 */
void findOptimal(List &list)
{
    // 1. finish condition
    int size = list.size();
    if (size < 2) return;
    if (size == 2) {
        _cost += getMultiOfList(list);
        return;
    }

    // 2. front == 1
    int front = list.front();
    if (front == 1) { 
        list.pop_front();
        int next = list.front();
        _cost += next;
        findOptimal(list);
        return;
    }

    // 3. else : devide into 2 lists
    _cost += getMultiOfList(list);

    uint64 flag = 1;
    uint64 optimalFlag = flag;
    const uint64 MAX_FLAG = getMaxFlag(list);
#ifdef _DEBUG
    cout << "max : " << MAX_FLAG<< endl;
#endif
    List list1, list2;

    int currentCost = 0x7FFFFFFF;
    const int SUM_OF_LIST = getSumOfList(list);
    while (flag <= MAX_FLAG) {
        int leftValue = getLeftValue(list, flag);
        int rightValue = SUM_OF_LIST - leftValue;
        if (currentCost > abs(leftValue - rightValue)) {
            currentCost = abs(leftValue - rightValue);
            optimalFlag = flag;
        }
        flag++;
    }
#ifdef _DEBUG
    cout << "flag : " << optimalFlag<< endl;
#endif

    List ll, rl;
    pushLeft(ll, list, optimalFlag);
    pushRight(rl, list, optimalFlag);
    list.clear();

    findOptimal(ll);
    findOptimal(rl);
}


int getMultiOfList(List &list)
{
    int cost = 1;
    List::iterator it = list.begin();
    for (; it != list.end(); it++) {
        cost *= (*it);
    }
    return cost;
}

int getSumOfList(List &list)
{
    int sum = 0;
    List::iterator it = list.begin();
    for (; it != list.end(); it++) {
        sum += (*it);
    }
    return sum;
}

uint64 getMaxFlag(List &list) {
    int size = list.size();
    return (1 << size);
}

int getLeftValue(List &list, uint64 flag)
{
    return getValue(list, flag, 1);
}

int getRightValue(List &list, uint64 flag)
{
    return getValue(list, flag, 0);
}

int getValue(List &list, uint64 flag, int match)
{
    int value = 0;
    List::iterator it = list.begin();
    for (int i = 0; it != list.end(); it++, i++) {
        if (((flag >> i) & 1) == match) {
            value += (*it);
        }
    }
    return value;
}

void pushLeft(List &target, List &org, uint64 flag)
{
    push(target, org, flag, 1);
}

void pushRight(List &target, List &org, uint64 flag)
{
    push(target, org, flag, 0);
}

void push(List &target, List &org, uint64 flag, int match)
{
    List::iterator it = org.begin();
    for (int i = 0; it != org.end(); it++, i++) {
        if (((flag >> i) & 1) == match) {
            target.push_back(*it);
        }
    }
}
