// 
// author : hyungyu.jang@lge.com

#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
    #include <code/debug.h>
    #include <ctime>
#else
    #define trace printf
#endif

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

///////////////////////////////////////////////////////////////////////

#if defined _EXTERNAL_DEBUGGER && defined _DEBUG
int test_main(int argc, char *argv[])
#else
int main(int argc, char *argv[])
#endif
{
    return 0;
}

