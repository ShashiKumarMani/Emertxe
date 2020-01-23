#include<stdio.h>

int main()
{
    int i = 0;
    char ph;
    FILE *ptr = NULL, *str = NULL;
    long sptr, sstr;

    ptr = fopen("green.bmp", "rb");
    str = fopen("output1.bmp", "wb");

    fseek(ptr, 0L, SEEK_END);
    sptr = ftell(ptr);

    fseek(ptr, 0L, SEEK_SET);

    printf("%ld\n", sptr);

    char ch;

    for(int i = 0;i < sptr;i++)
    {
	fread(&ch, 1, 1, ptr);
	fwrite(&ch, 1, 1, str);
    }

    fseek(str, 0L, SEEK_END);

    sstr = ftell(str);

    fseek(str, 0L, SEEK_SET);

    printf("%ld\n", sstr);

    fclose(ptr);
    fclose(str);
}
