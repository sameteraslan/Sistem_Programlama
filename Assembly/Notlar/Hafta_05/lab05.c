#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main()
{
    int c, p1[2], p2[2], i;
    int avg;
    int snd[5];
    int rec[5];

    //pipe olusturma
    if (pipe(p1) < 0)
    {
        printf("Cannot create a pipe1\n");
    }
    if (pipe(p2) < 0)
    {
        printf("Cannot create a pipe2\n");
    }

    //kullanicidan deger alma
    for (i = 0; i < 5; i++)
    {
        printf("Sayi %d:", (i + 1));
        scanf("%d", &snd[i]);
    }


    if ((c=fork()) < 0)
    {
        printf("Cannot fork\n");
    } 
    else if (c > 0) //parent olustu
    {
        close(p1[0]);

        //pipe1 e yazma
        if (write(p1[1], &snd, 5 * sizeof(int)) < 0)
        {
            printf("M P1: Cannot write %d\n", i+1);
        }

        //wait(NULL);
        sleep(1);
        close(p2[1]);

        if (read(p2[0], &avg, sizeof(int)) < 0)
        {
            printf("P2 C: Cannot read %d\n", i+1);
        }
        printf("P2 M: I read %d\n", avg);
    }
    else  //child process
    {
        sleep(1);
        close(p1[1]);

        if (read(p1[0], rec, 5 * sizeof(int)) < 0)
        {
            printf("C: Cannot read %d\n", i+1);
        }
        avg = 0;
        for (i = 0 ; i < 5; i++)
        {
            avg += rec[i];
        }
        avg = avg / 5;
        printf("C: Average %d\n", avg);
        
        //avg yi gonderme

        close(p2[0]);
        if (write(p2[1], &avg, sizeof(int)) < 0)
        {
            printf("C P2: Cannot write %d\n", i+1);
        }

        wait(NULL);
    }
}