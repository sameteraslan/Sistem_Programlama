#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
    int c, p[2], i;
    char rec[5];
    char snd[] = "HELLO";

    if (pipe(p) < 0) printf("Cannot create a pipe\n");

    if ((c=fork()) < 0) printf("Cannot fork\n");
    else if (c > 0)
    {
        close(p[0]);

        for (i = 0; i < 2; i++)
        {
            if (write(p[1], snd, 5) < 0)
            {
                printf("M: Cannot write %d\n", i+1);
            }
            printf("C: I read \"%s"\"\n", rec);

        }
        wait(NULL);
    }
    else
    {
        sleep(1);
        close(p[1]);
        for (i = 0; i < 2; i++)
        {
            if (read(p[0], rec, 5) < 0)
            {
                printf("C: Cannot read %d\n", i+1);
            }
            printf("C: I read \"%s"\"\n", rec);
        }
    }
    
}