/*
    Temperaturario                                      This code generate random temperature sensor
                                                        data and then it makes some elaboration.
    Code wrote by Mattia Marelli                        The Random data che be easily replace with
    in 2025 as an homework for school                   an array of data read by some sensors
*/

#include    <stdio.h>
#include    <windows.h>
#include    <math.h>
#include    <stdlib.h>

#define     debugGenDelay                           1
#define     debugGenDelayMs                         debugGenDelay * 1000

#define     minRandom                               -10
#define     maxRandom                               30

#define     relevationEveryMinute                   30
#define     weekLenght                              7

#define     relevationCountInDay                    (24 * 60) / relevationEveryMinute

#define     BLACK                                   "\e[0;30m"
#define     RED                                     "\e[0;31m"
#define     GREEN                                   "\e[0;32m"
#define     YELLOW                                  "\e[0;33m"
#define     BLUE                                    "\e[0;34m"
#define     MAGENTA                                 "\e[0;35m"
#define     CYAN                                    "\e[0;36m"
#define     WHITE                                   "\e[0;37m"
#define     BOLD_BLACK                              "\e[1;30m"
#define     BOLD_RED                                "\e[1;31m"
#define     BOLD_GREEN                              "\e[1;32m"
#define     BOLD_YELLOW                             "\e[1;33m"
#define     BOLD_BLUE                               "\e[1;34m"
#define     BOLD_MAGENTA                            "\e[1;35m"
#define     BOLD_CYAN                               "\e[1;36m"
#define     BOLD_WHITE                              "\e[1;37m"
#define     COLOR_RESET                             "\e[0m"

/**
 * @brief generate a random float beatween two large int grater than 1000, because the result will be something like generated / 1000
 * 
 * @param min number
 * @param max number
 * @return float the generated number converted to float
 */
float generateFloat(int min, int max)
{
    int random = rand() % (max + 1 - min) + min;
    return (float)random / 100;
}

/**
 * @brief Get the Avarege number in a specific range of a list
 * 
 * @param lista the array 
 * @param start index of where to start
 * @param end index of where to stop
 * @return float avarege number
 */
float getAvarege(float *lista, int start, int end)
{
    float sum = 0;
    for (int i = start; i < end; i++)
    {
        sum += lista[i];
    }
    return sum / (end - start);
}

/**
 * @brief Get the Max number in a specific range of a list
 * 
 * @param lista the array 
 * @param start index of where to start
 * @param end index of where to stop
 * @return float max number
 */
float getMax(float *lista, int start, int end)
{
    float max = lista[start];
    for (int i = start + 1; i < end; i++)
    {
        if (lista[i] > max)
        {
            max = lista[i];
        }
    }
    return max;
}

/**
 * @brief Get the Min number in a specific range of a list
 * 
 * @param lista the array 
 * @param start index of where to start
 * @param end index of where to stop
 * @return float min number
 */
float getMin(float *lista, int start, int end)
{
    float min = lista[start];
    for (int i = start + 1; i < end; i++)
    {
        if (lista[i] < min)
        {
            min = lista[i];
        }
    }
    return min;
}

int main()
{
    // DAY - VALORI
    float rawData[7][48];
    // DAY - PERIODO - MEDIA/MIN/MAX
    float data[7][3][3];

    // UTF8 chars in terminal
    SetConsoleOutputCP(CP_UTF8);

    // Debug Mode Message
    system("cls");
    printf(RED "[DEBUG] " CYAN "Avvio in modalità di debug con dati simulati..." COLOR_RESET);
    Sleep(2000);
    system("cls");

    // Random Number generation + data print (divided in 2 for : week - day)
    for (int i = 0; i < weekLenght; i++)
    {
        for (int j = 0; j < relevationCountInDay; j++)
        {
            // Get a random number
            rawData[i][j] = generateFloat(minRandom * 100, maxRandom * 100);

            // Find the avarage,min,max value in half day
            if ((j + 1) % 24 == 0)
            {
                // Index of the "block" = [0,1,2], based on the time of day, and subtract one because arrays are zero-indexed.
                int blockIndex = (j + 1) / 24 - 1;

                data[i][blockIndex][0] = getAvarege(rawData[i], j - 23, j + 1);
                data[i][blockIndex][1] = getMin(rawData[i], j - 23, j + 1);
                data[i][blockIndex][2] = getMax(rawData[i], j - 23, j + 1);
            }
        }

        // Save avarage,min,max value of the whole day
        data[i][2][0] = getAvarege(rawData[i], 0, relevationCountInDay);
        data[i][2][1] = getMin(rawData[i], 0, relevationCountInDay);
        data[i][2][2] = getMax(rawData[i], 0, relevationCountInDay);

        // Print all the datas
        printf(RED "Giorno: " CYAN "%d\n", i + 1);

        printf(BOLD_MAGENTA "\nPrime %d misurazioni:\n", relevationCountInDay / 2);
        printf(YELLOW "    - " CYAN "MEDIA: " WHITE "%.2f °C\n", data[i][0][0]);
        printf(YELLOW "    - " CYAN "MIN:   " WHITE "%.2f °C\n", data[i][0][1]);
        printf(YELLOW "    - " CYAN "MAX:   " WHITE "%.2f °C\n", data[i][0][2]);

        printf(BOLD_MAGENTA "\nSeconde %d misurazioni:\n", relevationCountInDay / 2);
        printf(YELLOW "    - " CYAN "MEDIA: " WHITE "%.2f °C\n", data[i][1][0]);
        printf(YELLOW "    - " CYAN "MIN:   " WHITE "%.2f °C\n", data[i][1][1]);
        printf(YELLOW "    - " CYAN "MAX:   " WHITE "%.2f °C\n", data[i][1][2]);

        printf(BOLD_MAGENTA "\nResoconto:\n");
        printf(YELLOW "    - " CYAN "MEDIA: " WHITE "%.2f °C\n", data[i][2][0]);
        printf(YELLOW "    - " CYAN "MIN:   " WHITE "%.2f °C\n", data[i][2][1]);
        printf(YELLOW "    - " CYAN "MAX:   " WHITE "%.2f °C\n", data[i][2][2]);

        Sleep(debugGenDelayMs);
        system("cls");
    }

    // Avarage,min,max value of the whole week
    float weeklyAverage = 0;
    float weeklyMin = data[0][2][1]; // Initialize with the minimum of the first day
    float weeklyMax = data[0][2][2]; // Initialize with the maximum of the first day

    for (int i = 0; i < weekLenght; i++)
    {
        // Sum for weekly avarage
        weeklyAverage += data[i][2][0];

        // Find the min one
        if (data[i][2][1] < weeklyMin)
        {
            weeklyMin = data[i][2][1];
        }

        // Find the max one
        if (data[i][2][2] > weeklyMax)
        {
            weeklyMax = data[i][2][2];
        }
    }

    // Find the avarage value of the whole week
    weeklyAverage /= weekLenght;

    // Print all the datas
    printf(RED "\n\n\nResoconto settimanale:\n");
    printf(YELLOW "    - " CYAN "MEDIA: " WHITE "%.2f °C\n", weeklyAverage);
    printf(YELLOW "    - " CYAN "MIN:   " WHITE "%.2f °C\n", weeklyMin);
    printf(YELLOW "    - " CYAN "MAX:   " WHITE "%.2f °C\n", weeklyMax);

    // Clear the screen
    Sleep(debugGenDelayMs * 2);
    system("cls");

    // Print the table
    printf("\n" YELLOW "_____________________________________________________");
    printf("\n" YELLOW "|" RED "   Giorno   " YELLOW "|" RED "   Minima   " YELLOW "|" RED "   Massima  " YELLOW "|" RED "   Media    " YELLOW "|");
    printf("\n" YELLOW "|____________|____________|____________|____________|");

    for (int i = 0; i < weekLenght; i++)
    {
        printf("\n" YELLOW "|            |            |            |            |");

        char buffer1[10], buffer2[10], buffer3[10];

        // Num lenght : 6 (+/- 00.00)
        // Using a buffer because the default print method with %f will ignore the 06.2f formatting code.
        sprintf(buffer1, "%+06.2f", data[i][2][1]);
        sprintf(buffer2, "%+06.2f", data[i][2][2]);
        sprintf(buffer3, "%+06.2f", data[i][2][0]);

        printf("\n" YELLOW "|" CYAN "  Giorno %d  " YELLOW "|" WHITE "   %s   " YELLOW "|" WHITE "   %s   " YELLOW "|" WHITE "   %s   " YELLOW "|",
               i + 1, buffer1, buffer2, buffer3);

        printf("\n" YELLOW "|____________|____________|____________|____________|");
    }

    printf("\n\n\n");
    printf(COLOR_RESET);
    system("pause");
    return 0;
}
