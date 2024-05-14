#ifndef EVENT_H
#define EVENT_H
class Event
{
    int hour;
    public:
    int CustomerNo;
    int TellerNo;
    Event * next;
    bool served;
    int minutes;
    int seconds;

        Event(int CustomerNo,int TellerNo,bool served)
        {
            time_t currentTime = time(nullptr);
            tm* localTime = localtime(&currentTime);
            minutes = localTime->tm_min;
            seconds = localTime->tm_sec;
            hour = localTime->tm_hour;
            this->CustomerNo = CustomerNo;
            this->TellerNo = TellerNo;
            this->served = served;
            next = NULL;
        }

        void DisplayEvent()
        {
             cout<<"client number "<<CustomerNo;
             if(TellerNo == 0)
             {
                cout<<" entered and waiting";
             }
             else
             {
                 if(served == true)
                    cout<<" is finished with teller NO. "<<TellerNo;
                 else
                    cout<<" is being served by teller NO. "<<TellerNo;
             }
             cout<<" at "<<hour<<":"<<minutes<<":"<<seconds<<endl;
        }


    protected:

    private:
};

#endif // EVENT_H
