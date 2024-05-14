#ifndef BANK_H
#define BANK_H
#include "Employee.h"
#include "Clients.h"
#include "ClientStatus.h"
#include "Client.h"
class Bank
{
    Employee ** employees;
    int EmployeesNum;
    Clients clients;
    ClientStatus ClientHistory;
    int ReceivedClientNumber;
public:

    Bank()
    {
        int InitEmpsNum;
        cout<<"how many employees you have"<<endl;
        cin>>InitEmpsNum;
        employees = new Employee*[InitEmpsNum];
        EmployeesNum = InitEmpsNum;
        for (int i = 0; i < EmployeesNum ; i++)
        {
            employees[i] = new Employee(i+1,&clients,&ClientHistory);
        }
        ReceivedClientNumber = 0;
        /*thread check([this]()
        {
            checkClients();
        });
        check.detach();*/
    }

    void ReceiveClient()
    {
        cout<<"What is the client name ? "<<endl;
        string name;
        cin>>name;
        cout<<"How long The client will take in seconds ?"<<endl;
        int CostumerTime;
        cin>>CostumerTime;
        cout<<"Is it VIP client ?"<<endl;
        char confirm ;
        cin>>confirm;
        Client * newClient = new Client(name,CostumerTime,++ReceivedClientNumber);
        if(confirm == 'y')
        {
            clients.AddVipClient(newClient);
        }
        else
        {
            clients.AddClient(newClient);
        }
        ClientHistory.CreateEvent(0,ReceivedClientNumber,false);
        if(clients.NumOfClients > 2 * EmployeesNum )
        {
            addNewEmployee();
        }
    }

    void ShowTheWaitingQueue()
    {
        clients.showQueue();
    }

    void ShowTheBankStatus()
    {
        ClientHistory.ShowStatus();
    }

    void showRates()
    {
        ClientHistory.rate(EmployeesNum);
    }


protected:

private:
        void addNewEmployee()
    {
        cout<<"new employee must be added"<<endl;
        Employee ** newEmployee = new Employee*[++EmployeesNum];
        Employee * newOne = new Employee(EmployeesNum,&clients,&ClientHistory);
        for(int i = 0 ;i<EmployeesNum-1;i++)
        {
            newEmployee[i] = employees[i];
        }
        newEmployee[EmployeesNum-1] = newOne;
        delete[] employees;
        employees = newEmployee;
    }

    /*void checkClients()
    {
        while(true)
        {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            if(clients.NumOfClients <= EmployeesNum * 2 )
            {
                removeEmployee();
            }
        }
    }*/

    /*void removeEmployee()
    {
      if(EmployeesNum == 0)
        return;

      Employee ** newEmployee = new Employee*[--EmployeesNum];
      for(int i = 0 ; i<EmployeesNum ; i++)
      {
          newEmployee[i] = employees[i];
      }
      employees[EmployeesNum]->stopWorking();
      delete[] employees;
      employees = newEmployee;
    }*/

};
#endif // BANK_H
