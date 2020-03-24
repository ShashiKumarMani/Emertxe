      #include <unistd.h>
       #include <stdlib.h>
       #include <stdio.h>

       int
       main(int argc, char *argv[])
       {
           int flags = 0, opt;// flags2 = 0, flags3 = 0, opt;
           int nsecs, tfnd, i = 0;

           nsecs = 0;
           tfnd = 0;
        
           while ((opt = getopt(argc, argv, "nt")) != -1) 
	   {
	       switch (opt) 
	       {
		   case 'n':
		       flags = 1;
		       break;
		   case 't':
		       tfnd = 1;
		       break;
		   default: /* '?' */
		       flags = 1;
	       }
//		break;
      	   }
           printf("flags=%d; tfnd=%d; nsecs=%d; optind=%d\n",
                   flags, tfnd, nsecs, optind);

           if (optind >= argc) {
               fprintf(stderr, "Expected argument after options\n");
               exit(EXIT_FAILURE);
           }

	    i = optind;

	   while(i < argc)
	   {
	    printf("name argument = %d:%s\n", optind, argv[i++]);
	    }
           /* Other code omitted */

	    i = 0;
	    while(i < argc)
	    {
		printf("argv - %s\n", argv[i]);
		i++;
	    }
    	   exit(EXIT_SUCCESS);
       }

