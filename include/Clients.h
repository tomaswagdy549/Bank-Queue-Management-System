#ifndef CLIENTS_H
#define CLIENTS_H
#include "Client.h"
class Clients
{
    Client ** clients;
    int ClientSize;
    public:
    int NumOfClients;
    Clients()
    {
        ClientSize = 10;
        NumOfClients = 0;
        clients = new Client*[ClientSize];
    }

    void AddClient(Client* AddedClient)
    {
        if (NumOfClients < ClientSize)
        {
            clients[NumOfClients++] = AddedClient;
        }
        else
        {
            ExtendAndAddClient(AddedClient);
        }
    }

    void ExtendAndAddClient(Client* AddedClient)
    {
        ClientSize += 10;
        Client** NewClients = new Client*[ClientSize];
        for (int i = 0; i < NumOfClients; i++)
        {
            NewClients[i] = clients[i];
        }
        delete[] clients;
        clients = NewClients;
        clients[NumOfClients++] = AddedClient;
    }

    void AddVipClient(Client* AddedClient)
    {
        ClientSize += 10;
        Client** NewClients = new Client*[ClientSize];
        NewClients[0] = AddedClient;
        for (int i = 1; i <= NumOfClients; i++)
        {
            NewClients[i] = clients[i-1];
        }
        delete[] clients;
        NumOfClients++;
        clients = NewClients;
    }

    Client* RemoveClient()
    {
        if (NumOfClients <= 0)
            return nullptr;

        Client* IncomingClient = clients[0];
        Client** NewClients = new Client*[ClientSize - 1];
        for (int i = 1; i < NumOfClients; i++)
        {
            NewClients[i - 1] = clients[i];
        }
        delete[] clients;
        clients = NewClients;
        NumOfClients--;
        return IncomingClient;
    }

    void showQueue()
    {
        if(NumOfClients==0)
        {
            cout<<"no clients for now"<<endl;
        }
        for(int i = 0 ; i < NumOfClients ; i++)
        {
            clients[i]->DisplayClient();
        }
    }



protected:

private:
};

#endif // CLIENTS_H
