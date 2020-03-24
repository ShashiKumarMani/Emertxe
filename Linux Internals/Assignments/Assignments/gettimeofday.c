/*

*/

#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    char *str = NULL;
    
    struct tm result;
    memset(&result, 0, sizeof(result));
   
    /* Get Seconds */ 
    time_t tm = time(NULL);

    printf("%lu\n", tm);

    /* Seconds -> structure tm*/
    struct tm *ret_tm = gmtime(&tm);
 
    printf("Result : %d %d %d %d %d %d\n", ret_tm->tm_sec, ret_tm->tm_min, ret_tm->tm_hour, ret_tm->tm_mday, ret_tm->tm_mon, ret_tm->tm_year);
    
    /* Seconds -> string */ 
    str = ctime(&tm);
    printf("->%s\n", str);

    /* structure tm -> mktime -> seconds */
    time_t tim = mktime(ret_tm);

    printf("%lu\n", tim);

    /* Seconds -> string */
    str = ctime(&tim);
    printf("%s", str);
    
    return 0;
}
