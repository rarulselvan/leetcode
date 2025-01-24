
class MyCalendar 
{
private:
    vector<pair<int, int>> calendar;

public:
    bool book(int start, int end)
    {
        for (const auto [s, e] : calendar)
        {
            if (start < e && end > s ) 
                return false;
        }
        calendar.emplace_back(start, end);
        return true;
    }
};

/* Example
voin main()
{
    MyCalendar myCalendar = new MyCalendar();
    myCalendar.book(10, 20); // return True
    myCalendar.book(15, 25); // return False, It can not be booked because time 15 is already booked by another event.
    myCalendar.book(20, 30);
}*/
