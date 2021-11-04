#include<stdlib.h>
#include<stdio.h>
#include <string.h>

int main()
{
    char* option = NULL;//Save input from stdin
    const char* filename = "/proc/my_info";//File name
    char* contents = NULL;//Get input from file
    size_t len = 0;//Save string length

    //Open and close file at each question, since information may change automatically
    while(1)
    {
        int flag = 0;//Check position in file
        FILE *fp = fopen(filename, "r");//File pointer
        //Check we get file
        if(!fp)
        {
            puts("Proc file doesn't exist\n");
            exit(0);
        }
        //Ask operation
        printf("Which information do you want?\n");
        printf("Version(v),CPU(c),Memory(m),Time(t),All(a),Exit(e)?\n");
        //Get answer from stdin
        if(getline(&option, &len, stdin) == 1);
        printf("\n");
        /*
        Option judge
        Do action based on input.

        variable:
        option-
        Check what we want.
        ex. version (x), v (o), V (x), b (x)
        Incorrect input, print "Wrong input type."
        flag- Record how many title fp read
        contents- Get content. Print if we need it

        Repeated until we get input "e"
        */
        //Version
        if(strcmp(option, "v\n")==0)
        {
            while (getline(&contents, &len, fp) != -1)
            {
                if(*contents == '=')
                    flag++;
                else if(flag < 1)
                    continue;
                else
                {
                    printf("Version: %s", contents);
                    printf("------------------------------------------------------------\n");
                    break;
                }
            }
        }
        //Cpu information
        else if(strcmp(option, "c\n")==0)
        {
            while (getline(&contents, &len, fp) != -1)
            {
                if(*contents == '=')
                {
                    flag++;
                    if(flag == 2)
                    {
                        printf("Cpu information:\n");
                        continue;
                    }
                }
                if(flag < 2)
                    continue;
                else if(flag == 2)
                    printf("%s", contents);
                else
                {
                    printf("------------------------------------------------------------\n");
                    break;
                }
            }
        }
        //Memory information
        else if(strcmp(option, "m\n")==0)
        {
            while (getline(&contents, &len, fp) != -1)
            {
                if(*contents == '=')
                {
                    flag++;
                    if(flag == 3)
                    {
                        printf("Memory information:\n");
                        continue;
                    }
                }
                if(flag < 3)
                    continue;
                else if(flag == 3)
                    printf("%s", contents);
                else
                {
                    printf("------------------------------------------------------------\n");
                    break;
                }
            }
        }
        //Memory information
        else if(strcmp(option, "t\n")==0)
        {
            while (getline(&contents, &len, fp) != -1)
            {
                if(*contents == '=')
                {
                    flag++;
                    if(flag == 4)
                    {
                        printf("Time information:\n");
                        continue;
                    }
                }
                if(flag < 4)
                    continue;
                else
                    printf("%s", contents);
            }
            printf("------------------------------------------------------------\n");
        }
        //Print all file
        else if(strcmp(option, "a\n")==0)
        {
            while (getline(&contents, &len, fp) != -1)
                printf("%s", contents);
            printf("------------------------------------------------------------\n");
        }
        //exit the application
        else if(strcmp(option, "e\n")==0)
            break;
        //incorrect input
        else
        {
            printf("Wrong input type.\n");
            printf("------------------------------------------------------------\n");
        }
        fclose(fp);
    }
    return 0;
}