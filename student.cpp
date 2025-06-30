#include<bits/stdc++.h>
#include<windows.h>
/*
#include - iostream, fstream, windows.h
*/
using namespace std;

class University{
  private:
    string RollNo, Name, Subject, Address;

  public:
    University(): RollNo(""), Name(""), Subject(""), Address(""){}

    void setRollNo(string rollNo)
    {
      RollNo=rollNo;
    }

    void setName(string name)
    {
      Name=name;
    }

    void setSubject(string subject)
    {
      Subject=subject;
    }

    void setAddress(string address)
    {
      Address=address;
    }

    string getRollNo()
    {
      return RollNo;
    }

    string getName()
    {
      return Name;
    }

    string getSubject()
    {
      return Subject;
    }

    string getAddress()
    {
      return Address;
    }
};

void add(University stud)
{
  string rollno,name,sub,address;

  cout<<"\tEnter Roll Number: ";
  cin>>rollno;
  stud.setRollNo(rollno);

  cout<<"\tEnter Name: ";
  cin>>name;
  stud.setName(name);

  cout<<"\tEnter Subject: ";
  cin>>sub;
  stud.setSubject(sub);

  cout<<"\tEnter Address: ";
  cin>>address;
  stud.setAddress(address);

  ofstream out("C:/Users/Keerthi Chandrika/Desktop/C++/University Management System/university.txt", ios::app);

  if(!out)
  {
    cout<<"\tError: File can't be opened"<<endl;
  }

  else
  {
    out<<"\t"<<stud.getRollNo()<<" : "<<stud.getName()<<" : "<<stud.getSubject()<<" : "<<stud.getAddress()<<endl<<endl;
  }

  out.close();
  cout<<"\tStudent Added Successfully!!"<<endl;
}

void search()  //based on roll number
{
  string rollno;

  cout<<"\tEnter Roll Number of Student: ";
  cin>>rollno;

  ifstream in("C:/Users/Keerthi Chandrika/Desktop/C++/University Management System/university.txt");

  if(!in)
  {
    cout<<"\tError: File can't be opened"<<endl;
  }
  string line;
  bool found=false;
  while(getline(in,line))
  {
    int data=line.find(rollno);
    if(data!=string::npos)
    {
      cout<<"\t"<<line<<endl;
      found=true;
    }
  }
  if(!found)
  {
    cout<<"\tStudent Not found!!"<<endl;
  }
  in.close();
}

void update(University stud)
{
  string rollno;
  cout<<"\tEnter Roll Number of Student: ";
  cin>>rollno;

  ifstream infile("C:/Users/Keerthi Chandrika/Desktop/C++/University Management System/university.txt");
  ofstream outfile("C:/Users/Keerthi Chandrika/Desktop/C++/University Management System/university_temp.txt");

  if(!infile || !outfile)
  {
    cout<<"\tError: File can't be opened"<<endl;
  }

  string line;
  bool found=false;
  while(getline(infile,line))
  {
    int pos=line.find(rollno);
    if(pos!=string::npos)
    {
      string ad;
      cout<<"\tEnter new address: ";
      cin>>ad;

      stud.setAddress(ad);
      
      int newPos=line.find_last_of(':');
      line.replace(newPos+2, string::npos, stud.getAddress());
      found=true;
    } 
    outfile<<line<<endl;
  }
  if(!found)
  {
    cout<<"\tStudent Not Found!!"<<endl;
  }
  outfile.close();
  infile.close();
  remove("C:/Users/Keerthi Chandrika/Desktop/C++/University Management System/university.txt");
  rename("C:/Users/Keerthi Chandrika/Desktop/C++/University Management System/university_temp.txt","C:/Users/Keerthi Chandrika/Desktop/C++/University Management System/university.txt");
  cout<<"\tData Updated"<<endl;
}

int main()
{
  University stud;

  bool exit=false;
  while(!exit)
  {
    system("cls");
    int val;
    cout<<"\tWelcome To University Management System"<<endl;
    cout<<"\t***************************************"<<endl;
    cout<<"\t1.Add Student"<<endl;
    cout<<"\t2.Search Student"<<endl;
    cout<<"\t3.Update Data of Student"<<endl;
    cout<<"\t4.Exit"<<endl;
    cout<<"\tEnter Your Choice: ";
    cin>>val;

    if(val==1)
    {
      system("cls");
      add(stud);
      Sleep(6000);
    }

    else if(val==2)
    {
      system("cls");
      search();
      Sleep(6000);
    }

    else if(val==3)
    {
      system("cls");
      update(stud);
      Sleep(6000);
    }

    else if(val==4)
    {
      system("cls");
      exit=true;
      cout<<"\tGood Luck!";
      Sleep(3000);
    }
  }
  return 0;
}