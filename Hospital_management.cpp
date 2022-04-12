#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Data
{
    string name,disease,gender,phone_No,Doctor;
    int Room_No,Age,Id,service_type;
};


struct Node
{
    Data value;
    Node* next;
};



Data inputdata()
{
    string Name,Disease,Gender,dr,pn;
    int Rno,age,id,sr;
    Data p;
    cout<<"Enter the Name of patient : "<<endl;
    cin.ignore();
    getline(cin,Name);
    cout<<"Enter the Disease : "<<endl;
    getline(cin,Disease);
    cout<<"Enter the geneder of patient : "<<endl;
    getline(cin,Gender);
    cout<<"Enter the Room NO of Patient :"<<endl;
    cin>>Rno;
    cout<<"Enter the Age of Patient : "<<endl;
    cin>>age;
    cout<<"Enter the Id Of Patient :"<<endl;
    cin>>id;
    cout<<"Enter the Phone Number Of Patient :"<<endl;
    cin.ignore();
    getline(cin,pn);
    cout<<"Enter the Doctor Of Patient :"<<endl;
    getline(cin,dr);
    cout<<"Enter the Service Type ( 0 for OPD / 1 For Emergency ) Of Patient :"<<endl;
    cin>>sr;


    p.name=Name;
    p.disease=Disease;
    p.gender=Gender;
    p.Room_No=Rno;
    p.Age=age;
    p.Id=id;
    p.phone_No=pn;
    p.Doctor=dr;
    p.service_type=sr;

    


    cout<<" //  Data Entered Successfully // "<<" "<<endl;
    cout<<endl;

    return p;

}

void appendBack(Node* & head,Node* & tail, Data patient)
{
    Node* n=new Node;
    n->value=patient;
    n->next=NULL;
    if(head==NULL)
    {
        head=n;
        tail=n;
        
        return;
    }
    tail->next=n;
    tail=tail->next;
    tail->next=NULL;

}


void appendFront(Node* & ehead,Data patient)
{
    Node* n=new Node;
    n->value=patient;
    n->next=ehead;
    ehead=n;
    
}

Node* searchById(Node* head,int i)
{
    Node* temp=head;
    while(temp!=NULL && temp->value.Id!=i)
    {
        temp=temp->next;
    }
    return temp;
}

Node* searchByRno(Node* head,int rn)
{
    Node* temp=head;
    while(temp!=NULL && temp->value.Room_No!=rn)
    {
        temp=temp->next;
    }
    return temp;

}

void printData(Node* temp)
{
    if(temp==NULL)
    {
        return;
    }
        if(temp->value.service_type==0)
        {
            cout<<" !! OPD !!"<<endl;
        }
        else if(temp->value.service_type==1)
        {
            cout<<" !! EMERGENCY !!"<<endl;
        }

        cout<<"The ID Of The patient is ";
        cout<<temp->value.Id<<endl;

        cout<<"The Name Of The patient is ";
        cout<<temp->value.name<<endl;

        cout<<"The Phone Number Of The patient is ";
        cout<<temp->value.phone_No<<endl;

        cout<<"The Room No Of The patient is ";
        cout<<temp->value.Room_No<<endl;

        cout<<"The Age Of The patient is ";
        cout<<temp->value.Age<<endl;

        cout<<"The Disease Of The patient is ";
        cout<<temp->value.disease<<endl;

        cout<<"The Name Of The Doctor Treating is ";
        cout<<temp->value.Doctor<<endl;

}

void byDiseaseEmergency(Node* ehead,string dis)
{
    cout<<"! EMERGENCY PATIENT !"<<endl;
    if(ehead==NULL)
    {
        cout<<"No Patients in EMERGENCY WARD of this Decease"<<endl;
        return;
    }
    Node* temp=ehead;
    while(temp!=NULL)
    {
        if(temp->value.disease==dis){
        printData(temp);
        
        }
        temp=temp->next;
    }

}



void byDisease(Node* head,string dis,Node* ehead)
{
    cout<<" ! OPD Patients !"<<endl;
    if(head==NULL)
    {
        cout<<"No Patients Found in OPD with Particular disease"<<endl;
        byDiseaseEmergency(ehead,dis);
    }
    Node* temp=head;
    while(temp!=NULL )
    {
        if(temp->value.disease==dis)
        {
            printData(temp);
        }
        temp=temp->next;
    }

    byDiseaseEmergency(ehead,dis);
}

void byDnameEmergency(Node* ehead,string d)
{
    if(ehead==NULL)
    {
       cout<<"No Patient is treated By the Given doctor in OPD"<<endl;
       return;
    }
    Node* temp=ehead;
    while(temp!=NULL)
    {
        if(temp->value.Doctor==d)
        {
            printData(temp);
        }
        temp=temp->next;

    }
}

void byDname(Node* head,string d,Node* ehead)
{
    if(head==NULL)
    {
        cout<<" No Patient is treated By the Given doctor in OPD"<<endl;
        byDnameEmergency(ehead,d);
        return;
    }

    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->value.Doctor==d)
        {
            printData(temp);
        }
        temp=temp->next;
    }

    byDnameEmergency(ehead,d);

}


void deleteRecord(Node* &head,Node* &tail,int i)
{
    if(head==NULL)
    {
        return;
    }
    if(head==tail && head->value.Id==i )
    {
        Node* temp=head;
        head=head->next;
        tail=NULL;
        delete(temp);
        return;
    }
    if(head->value.Id==i)
    {
        Node* temp=head;
        head=head->next;
        delete(temp);
        return;
    }

    Node* prev=head;
    Node* temp=head;

    while(temp!=NULL && temp->value.Id!=i)
    {
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL)
    {
        cout<<"! NO DATA FOUND TO DELETE !"<<endl;
        return;
    }

    Node* del=temp;
    prev->next=temp->next;
    if(tail==temp)
    {
        tail=prev;
        temp=prev;

    }

    cout<<"! THE GIVEN DATA IS SUCCESSFULLY DELETED !"<<endl;
}

Node* bynameE(Node* t,string n)
{
    if(t==NULL)
    {
        return NULL;
    }
    Node* te=t;
    while(te!=NULL)
    {
        if(te->value.name==n)
        {
            return te;
        }
        te=te->next;
    }
    return NULL;
}

Node* byname(Node* t,string n)
{
    if(t==NULL)
    {
        return NULL;
    }
    Node* te=t;
    while(te!=NULL)
    {
        if(te->value.name==n)
        {
            return te;
        }
        te=te->next;
    }
    return NULL;
}

void changeId(Node* temp,int nid)
{
    temp->value.Id=nid;
}

void changerno(Node* temp,int rno)
{
    temp->value.Room_No=rno;
}

void changedis(Node* temp,string dis)
{
    temp->value.disease=dis;
}

void changeS(Node* temp,int s)
{
    temp->value.service_type=s;
}

void changedr(Node* temp, string drn)
{
    temp->value.Doctor=drn;
}

void changepn(Node* temp,string p)
{
    temp->value.phone_No=p;
}


void printList(Node* head)
{
    Node* temp=head;
    if(temp==NULL)
    {
        cout<<"The Database Is Empty"<<" "<<endl;
        return ;
    }

    cout<<"The Infomation of the Patient is are Follows"<<endl;
    cout<<endl;
    while(temp!=NULL)
    {   
        
        cout<<"The ID Of The patient is ";
        cout<<temp->value.Id<<endl;

        cout<<"The Name Of The patient is ";
        cout<<temp->value.name<<endl;

        cout<<"The Phone Number Of The patient is ";
        cout<<temp->value.phone_No<<endl;

        cout<<"The Room No Of The patient is ";
        cout<<temp->value.Room_No<<endl;

        cout<<"The Age Of The patient is ";
        cout<<temp->value.Age<<endl;

        cout<<"The Disease Of The patient is ";
        cout<<temp->value.disease<<endl;

        cout<<"The Name Of The Doctor Treating is ";
        cout<<temp->value.Doctor<<endl;

        temp=temp->next;
        cout<<endl;
    }

    cout<<endl;
}



int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    Node* ehead=NULL;
    Data patient;

    int c=1;
    
   
    while(c)
    {
    cout<<"Enter 1 to Add Data"<<endl;
    cout<<"Enter 2 to Search data by ID"<<endl;
    cout<<"Enter 3 to Print the data of Patients By Room NO "<<endl;
    cout<<"Enter 4 to print the data of Patients By Having a Particular disease"<<endl;
    cout<<"Enter 5 to print The data Of Patients treated By same Doctor "<<endl;
    cout<<"Enter 6 to Remove Patient Details by given ID"<<endl;
    cout<<"Enter 7 to Edit Patient Details"<<endl;
    cout<<"Enter 8 To print The Entire List Of Emergency Patients"<<endl;
    cout<<"Enter 9 to print Entire List of OPD Patient"<<endl;
    

    int ch;
    cin>>ch;
    string dn,d,fname;
    Node* temp=NULL;
    Node* Rtemp=NULL;
    Node* start=NULL;
    int in,rnn,sst;
    string di,cdr,pn;
    int nch;


    switch(ch)
    {

        case 1:
        cout<<"Enter the patient data below"<<endl;
        patient=inputdata();
        if(patient.service_type==0){
        appendBack(head,tail,patient);
        }
        else if(patient.service_type==1)
        {
            appendFront(ehead,patient);
        }
        break;

        case 2:
        cout<<"Enter the Id number of the patient:"<<endl;
        int i;
        cin>>i;
        temp=searchById(head,i);
        if(temp!=NULL)
        {
             printData(temp);
        }
        
        else{
             temp=searchById(ehead,i);
             if(temp!=NULL)
             {
                  printData(temp);
             }
             else{
            cout<<"!! The ID is Not found !!"<<endl;
            }
        }

        break;

        case 3:

        cout<<"Enter the Room No of Patient"<<endl;
        int room_no;
        cin>>room_no;
        Rtemp= searchByRno(head,room_no);
        if(Rtemp!=NULL)
        {
             printData(Rtemp);
        }
        
        else{
             Rtemp=searchByRno(ehead,room_no);
             if(Rtemp!=NULL)
             {
                  printData(Rtemp);
             }
             else{
            cout<<"!! The Room is Alraedy Empty !!"<<endl;
            }
        }


        break;

        case 4:

        cout<<"Enter The Disease Name "<<endl;
        cin.ignore();
        
        getline(cin,dn);
        byDisease(head,dn,ehead);
        break;

        case 5:
        cout<<"Enter The Name Of Doctor"<<endl;
        cin.ignore();
        getline(cin,d);
        byDname(head,d,ehead);
        break;

        case 6:
        cout<<"Enter the Id number of the patient:"<<endl;
        int in;
        cin>>in;

        deleteRecord(head,tail,in);
        break;

        case 7:

        cout<<"Enter the Full name Of The pateint"<<endl;
        cin.ignore();
        getline(cin,fname);
        start=byname(head,fname);
        if(start==NULL)
        {
            start=bynameE(ehead,fname);

        }

        cout<<"Enter 1 To Edit ID_NUMBER"<<endl;
        cout<<"Enter 2 to Edit Room NO"<<endl;
        cout<<"Enter 3 To Edit disease"<<endl;
        cout<<"Enter 4 to Edit Service Type"<<endl;
        cout<<"Enter 5 to Edit Doctor"<<endl;
        cout<<"Enter 6 to Edit Phone Number"<<endl;
     //   int nch;
        cin>>nch;
       /* int in,rnn,sst;
        string di,cdr,pn;
        */

        switch(nch)
        {
            case 1:
            cout<<"Enter the New ID NUumber"<<endl;
            cin>>in;

            changeId(start,in);


            break;

            case 2:
            cout<<"Enter the New Room No NUumber"<<endl;
            cin>>rnn;
            changerno(start,rnn);

            break;

            case 3:
            cout<<"Enter the new disease"<<endl;
            cin.ignore();
            getline(cin,di);
            changedis(start,di);

            break;

            case 4:
            cout<<"Enter The new service Type (0-> OPD / 1-> Emergency)"<<endl;
            cin>>sst;
            changeS(start,sst);

            break;

            case 5:
            cout<<"Enter the new doctor name"<<endl;
            cin.ignore();
            getline(cin,cdr);
            changedr(start,cdr);


            break;

            case 6:
            cout<<"Enter New phone Number"<<endl;
            cin.ignore();
            getline(cin,pn);
            changepn(start,pn);

            break;
        }

        
        break;

        case 8:
        printList(ehead);
        break;

        case 9:
        printList(head);
        break;

        case 10:
        printData(head);
        break;
       
    }
    cout<<endl;

    cout<<"Press 0 To Exit or Press 1 To continue: "<<endl;
    cin>>c;



    }

  

    cout<<"ENDED Thanks"<<endl;

    return 0;
    
}