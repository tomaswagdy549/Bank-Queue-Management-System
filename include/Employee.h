#ifndef EMPLOYEE_H
#define EMPLOYEE_H
using namespace std;
#include "Clients.h"
#include "ClientStatus.h"
class Employee
{
public:
    string name;
    int ID;
    int ClientsServed;
    bool available;
    std::unique_ptr<std::thread> WorkingThread;
    Employee(int ID,Clients * currentQueue,ClientStatus * happeningNow)
    {
        this->ID = ID;
        cout<<"What is the employee "<<ID<<" name ?"<<endl;
        string EmployeeName;
        cin>>EmployeeName;
        this->name = EmployeeName;
        ClientsServed = 0;
        available = true;
        WorkingThread = std::make_unique<std::thread>([this, currentQueue, happeningNow]()
        {
            Working(currentQueue, happeningNow);
        });
    }
        void stopWorking()
    {
        available = false;
        if(WorkingThread->joinable())
        {
            WorkingThread->join();
        }
    }

    private :
    void Working(Clients * queueCurrent,ClientStatus * history)
    {
        while(available)
        {
            Client * ClientIsComing = queueCurrent->RemoveClient();
            std::this_thread::sleep_for(std::chrono::seconds(1));
            while(ClientIsComing != NULL)
            {
                history->CreateEvent(this->ID,ClientIsComing->ID,false);
                std::this_thread::sleep_for(std::chrono::seconds(ClientIsComing->timeRequired));
                history->CreateEvent(this->ID,ClientIsComing->ID,true);
                ClientIsComing = queueCurrent->RemoveClient();
                ClientsServed++;
            }
        }
    }

protected:

private:
};
#endif // EMPLOYEE_H
