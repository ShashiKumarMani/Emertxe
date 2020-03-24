/*

*/

#define _XOPEN_SOURCE
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>

int gettime(char **argv)
{
    struct tm tm;
//    char *string = malloc(sizeof(argv[1]));
//    strcpy(string, argv[1]);

    printf("gettime\n");

    tm.tm_hour = atoi(strtok(argv[1], ":"));
    tm.tm_min = atoi(strtok(NULL, ":"));
    
    printf("get date\n");

    tm.tm_mday = atoi(strtok(argv[2], "/"));
    tm.tm_mon = atoi(strtok(NULL, "/"));
    tm.tm_year = atoi(strtok(NULL, "/"));

    printf("Hour- %d, Min : %d , Day : %d , Mon : %d , year : %d\n", tm.tm_hour, tm.tm_min, tm.tm_mday, tm.tm_mon, tm.tm_year);

}

int main(int argc, char **argv)
{

    /* Seconds -> string */
    struct tm ltm = {0};
    char buf[] = "17/02/20";
    puts(buf);
    strptime(buf, "%d/%m/%y", &ltm);
    
    printf("%d %d %d\n", ltm.tm_mday, ltm.tm_mon, ltm.tm_year);

    /**/
//    mktime(&ltm);
//    strftime(buf, sizeof(buf), "%Y/%m/%d", &ltm);
//    puts(buf);
    return 0;
}
