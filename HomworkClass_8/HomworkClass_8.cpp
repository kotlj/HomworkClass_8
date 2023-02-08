
#include <iostream>



class Date
{
private:
    unsigned int year;
    int month;
    int day;

    void helper()
    {
        if (month % 2 == 0)
        {
            if (month == 2)
            {
                if (year % 4 == 0)
                {
                    if (day > 29)
                    {
                        day -= 29;
                        ++month;
                    }
                }
                else
                {
                    if (day < 28)
                    {
                        day -= 28;
                        ++month;
                    }
                }
            }
            else
            {
                if (day > 30)
                {
                    day -= 30;
                    ++month;
                }
            }
        }
        else
        {
            if (day > 31)
            {
                day -= 31;
                ++month;
            }
        }
        if (month > 12)
        {
            month -= 12;
            ++year;
        }
        if (month < 1)
        {
            --year;
            month += 12;
        }
        if (day < 1)
        {
            --month;
            if (month % 2 == 0)
            {
                if (month == 2)
                {
                    day += 27;
                }
                else
                {
                    day += 29;
                }
            }
            else
            {
                day += 30;
            }
        }
    }
    void setToOne()
    {
        if (month == 0)
        {
            month++;
        }
        if (day == 0)
        {
            day++;
        }
    }
public:
    Date()
    {
        this->year = 2022;
        this->month = 1;
        this->day = 1;
    }
    Date(int _year, int _month, int _day)
    {
        this->year = _year;
        this->month = _month;
        this->day = _day;
        helper();
        setToOne();
    }

    void increaseDay()
    {
        this->day++;
        helper();
    }

    int getYear() const
    {
        return this->year;
    }
    int getMonth() const
    {
        return this->month;
    }
    int getDay() const
    {
        return this->day;
    }

    void setYear(unsigned int _year)
    {
        this->year = _year;
    }
    void setMonth(int _month)
    {
        this->month = _month;
        helper();
        setToOne();
    }
    void setDay(int _day)
    {
        this->day = _day;
        helper();
        setToOne();
    }
    
    void operator++()
    {
        ++day;
        helper();
    }
    void operator++(int post)
    {
        day++;
        helper();
    }
    void operator--()
    {
        --day;
        helper();
    }
    void operator--(int post)
    {
        day--;
        helper();
    }
    bool operator!=(Date &obj)
    {
        if (this->year != obj.getYear() && this->month != obj.getMonth() && this->day != obj.getDay())
        {
            return true;
        }
        return false;
    }
    bool operator==(Date &obj)
    {
        if (this->year == obj.getYear() && this->month == obj.getMonth() && this->day == obj.getDay())
        {
            return true;
        }
        return false;
    }
    bool operator>(Date &obj)
    {
        if (this->year > obj.getYear())
        {
            return true;
        }
        else if (this->year == obj.getYear() && this->month > obj.getMonth())
        {
            return true;
        }
        else if (this->year == obj.getYear() && this->month == obj.getMonth() && this->day > obj.getDay())
        {
            return true;
        }
        return false;
    }
    bool operator<(Date& obj)
    {
        if (this->year < obj.getYear())
        {
            return true;
        }
        else if (this->year == obj.getYear() && this->month < obj.getMonth())
        {
            return true;
        }
        else if (this->year == obj.getYear() && this->month == obj.getMonth() && this->day < obj.getDay())
        {
            return true;
        }
        return false;
    }
    friend std::ostream& operator<<(std::ostream &out, const Date& date);
    friend std::istream& operator>>(std::istream &in, Date& date);
    Date operator=(Date& obj)
    {
        if (*this != obj)
        {
            this->year = obj.getYear();
            this->month = obj.getMonth();
            this->day = obj.getDay();
        }
        return *this;
    }
    Date operator+=(Date& obj)
    {
        this->year += obj.getYear();
        this->month += obj.getMonth();
        this->day += obj.getDay();
        helper();

        return *this;
    }
    Date operator-=(Date& obj)
    {
        this->year -= obj.getYear();
        this->month -= obj.getMonth();
        this->day -= obj.getDay();
        helper();

        return *this;
    }

    Date operator()(unsigned int _year, int _month, int _day)
    {
        this->year = _year;
        this->month = _month;
        this->day = _day;

        return *this;
    }
};

std::ostream& operator<<(std::ostream &out, const Date& date)
{
    out << "Date(" << date.year << ", " << date.month << ", " << date.day << ')';

    return out;
}

std::istream& operator>>(std::istream &in, Date& date)
{
    in >> date.year;
    in >> date.month;
    in >> date.day;

    return in;
}


int main()
{
    Date test(2022, 12, 30);
    Date copy(2010, 1, 1);
    for (int i = 0; i < 5; i++)
    {
        test++;
    }
    std::cout << test << std::endl;
    for (int i = 0; i < 30; i++)
    {
        test--;
    }
    std::cout << test << std::endl;
    test = copy;
    std::cout << test << std::endl;
    if (test == copy)
    {
        std::cout << "true\n";
    }
    test += copy;
    std::cout << test << std::endl;
    test(100, 5, 12);
    std::cout << test << std::endl;
}