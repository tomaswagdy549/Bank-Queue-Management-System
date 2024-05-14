#ifndef CLIENT_H
#define CLIENT_H


class Client
{
    string name;
    public:
    int ID;
    int timeRequired;
        Client(string name,int timeRequired,int ID)
        {
            this->name = name;
            this->timeRequired = timeRequired;
            this->ID = ID;
        }

        void DisplayClient()
        {
            cout<<name<<" "<<ID<<" "<<timeRequired<<"sec"<<endl;
        }

    protected:

    private:
};

#endif // CLIENT_H
