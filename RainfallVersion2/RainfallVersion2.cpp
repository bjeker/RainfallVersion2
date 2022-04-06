// Ryan Bieker, CS 3060 001, Chapter 8 Programming Challenges, due 4/5/2022, 
//Calulates rainfall over 12 months, displays list of months, and sorts rainfall

#include <iostream>
#include <iomanip>

using namespace std;

void totalRain();
void sortArrays(string months[], int rain[], int monthCount);
void printArrays(string months[], int rain[], int monthCount);

int main()
{
    totalRain();
}

//calculates total rain over 12 months with input for monthly rainfall
void totalRain()
{
    double total = 0;
    int rain = 0;
    int monthCount = 12;
    string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    int rainFall[12];

    //user input rainfall per month
    for (int i = 0; i < monthCount; i++)
    {
        cout << "Enter rainfall for " << months[i] << ": ";
        cin >> rain;
        total += rain;
        rainFall[i] = rain;
    }

    //total rainfall
    cout << "Total rainfall: " << total << endl;

    //average rainfall
    double avg = 0;
    avg = total / monthCount;
    cout << "Average rainfall: " << avg << endl;

    //least rainfall
    string leastMonth = months[0];
    int least = rainFall[0];

    for (int i = 0; i < monthCount; i++)
    {
        if (rainFall[i] < least)
        {
            least = rainFall[i];
            leastMonth = months[i];
        }
    }

    cout << "Least rainfall in: " << leastMonth << endl;

    //most rainfall
    string mostMonth = months[0];
    int most = rainFall[0];

    for (int i = 0; i < monthCount; i++)
    {
        if (rainFall[i] > most)
        {
            most = rainFall[i];
            mostMonth = months[i];
        }
    }

    cout << "Most rainfall in: " << mostMonth << endl;

    sortArrays(months, rainFall, monthCount);
}

//sort rain array and set months array to be at same index
void sortArrays(string months[], int rain[], int monthCount)
{
    int minIndex = 0;
    int tempNum = 0;
    string tempString = "";

    //selection sort rainfall
    for (int i = 0; i < monthCount - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < monthCount; j++)
        {
            if (rain[j] < rain[minIndex])
            {
                minIndex = j;
            }
        }

        //swap rain array
        tempNum = rain[minIndex];
        rain[minIndex] = rain[i];
        rain[i] = tempNum;

        //swap months array
        tempString = months[minIndex];
        months[minIndex] = months[i];
        months[i] = tempString;
    }

    printArrays(months, rain, monthCount);
}

//print rainfall and months
void printArrays(string months[], int rain[], int monthCount)
{
    for (int i = 0; i < monthCount; i++)
    {
        cout << rain[i] << " inches in " << months[i] << endl;
    }
}