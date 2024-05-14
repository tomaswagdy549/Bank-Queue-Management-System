#ifndef CLIENTSTATUS_H
#define CLIENTSTATUS_H
#include "Event.h"
class ClientStatus
{
    Event * first;
public:
    ClientStatus()
    {
        first = NULL;
    }

    void CreateEvent(int TellerWhoServed,int ClientWhoCame,bool served)
    {
        Event * newEvent = new Event(ClientWhoCame,TellerWhoServed,served);
        if(first == NULL)
        {
            first = newEvent;
        }
        else
        {
            Event * current = first;
            while(current->next != NULL)
            {
                current = current->next;
            }
            current->next = newEvent;
        }
    }

    void ShowStatus()
    {
        Event * current = first;
        while(current != NULL)
        {
            current->DisplayEvent();
            current = current->next;
        }
    }

    void rate(int employeesServed)
    {
        float employeesTimesServiced[employeesServed];
        for(int i = 0; i<employeesServed; i++)
        {
            employeesTimesServiced[i] = 0;
        }
        float waitingTime = 0;
        float ServiceTime = 0;
        int Clients = 0;
        Event * firstTracer = first;
        while(firstTracer != NULL)
        {
            if(firstTracer->TellerNo == 0)
            {
                Event * secondTracer = firstTracer->next;
                bool clientFound = false;
                while(secondTracer != NULL && !clientFound)
                {
                    if(firstTracer->CustomerNo == secondTracer->CustomerNo)
                    {
                        clientFound = true;
                        waitingTime += (secondTracer->seconds - firstTracer->seconds) + 60 * (secondTracer->minutes - firstTracer->minutes);
                        ServiceTime += GetServiceTime(secondTracer,employeesTimesServiced);
                        Clients++;
                    }
                    secondTracer = secondTracer->next;
                }
            }
            firstTracer = firstTracer->next;
        }
        cout<<"waiting average time is  "<<waitingTime/Clients<<" sec"<<endl;
        cout<<"Service average time is  "<<ServiceTime/Clients<<" sec"<<endl;
        for(int i = 0; i<employeesServed; i++)
        {
            cout<<"Teller No. "<<i+1<<" Utilization is %"<<employeesTimesServiced[i]*100/ServiceTime<<endl;
        }
    }



protected:

private:
    float GetServiceTime(Event * locatedEvent,float * employeesTimesServiced)
    {
        Event * thirdTracer = locatedEvent->next;
        while(thirdTracer != NULL)
        {
            if(thirdTracer->CustomerNo == locatedEvent->CustomerNo)
            {
                *(employeesTimesServiced + thirdTracer->TellerNo -1) += thirdTracer->seconds-locatedEvent->seconds
                        + 60 * (thirdTracer->minutes-locatedEvent->minutes);
                return thirdTracer->seconds-locatedEvent->seconds + 60 * (thirdTracer->minutes-locatedEvent->minutes);
            }
            thirdTracer = thirdTracer->next;
        }
        return 0;
    }

};

#endif // CLIENTSTATUS_H
