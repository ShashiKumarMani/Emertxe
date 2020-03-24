
#include <stdio.h>
#include <stdlib.h>

int main()
{

    if(!fork())
    {
	alarm(3);
    }
    else
    {

    }
}
