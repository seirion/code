// 

#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
    #include <code/debug.h>
#else
    #define trace printf
#endif

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
    return 0;
}
