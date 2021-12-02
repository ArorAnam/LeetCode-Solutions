int DaysInMonth(int month, int year);
// Do not edit above this line. It is only shown so you can see the function signature.
/*
 * Complete the function below.
 */
int distanceFromNY1900(int year, int month, int day);

//by Ben Cimperman

int DaysBetween(int year1, int month1, int day1, int year2, int month2, int day2) {
    //Since the number of days in a given month is variable, as is the number of years, my solution is goning to find how many days it takes to get to each date and then take the difference, starting from  1/1/1900.
    return abs(distanceFromNY1900(year1, month1, day1)-distanceFromNY1900(year2, month2, day2));
}

int distanceFromNY1900(int year, int month, int day){
    int total = 0;
    for (unsigned int x = 1900; x < year; x ++){
        //These lines check if the year in question is a leap year, which is every year divisible by four except those divisible by 100 but including those divisible by 400
        if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0) total += 366;
        else total += 365;
    }
    for (unsigned int y = 1; y < month; y ++){
        total += DaysInMonth(y, year);
    }
    total += day;
    return total;
}