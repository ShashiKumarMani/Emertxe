
#include <stdlib.h>
#include <unistd.h>

int main()
{
    system("PS1='my_new_shell>' bash");
    system("echo $PS1");
    sleep(1);
    return 0;
}
