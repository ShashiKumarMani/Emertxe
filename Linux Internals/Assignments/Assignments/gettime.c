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
    /* Get Seconds */ 
    time_t tm = time(NULL);
    char *str = NULL;

//    gettime(argv);

    printf("%lu\n", tm);

    /* Seconds -> structure tm*/
//    struct tm *ret_tm = gmtime(&tm);

//    printf("Result : %d %d %d %d %d %d %d %d %d\n", ret_tm->tm_sec, ret_tm->tm_min, ret_tm->tm_hour, ret_tm->tm_mday, ret_tm->tm_mon, ret_tm->tm_year, ret_tm->tm_wday, ret_tm->tm_yday, ret_tm->tm_isdst);

    struct tm stm;
    memset(&stm, 0, sizeof(stm));
    /* Seconds -> string */ 
    str = ctime(&tm);
    printf("->%s\n", str);

//    ret_tm->tm_mon = 2;
//    ret_tm->tm_hour = 5;
//    ret_tm->tm_min = 35;
//    ret_tm->tm_sec = 55;

    strptime("12", "%H", &stm);

    /* structure tm -> mktime -> seconds */
    time_t tim = mktime(&stm);

    printf("->Sec : %lu\n", tim);

    /* Seconds -> string */
    str = ctime(&tim);
    printf("%s", str);

    return 0;
}
