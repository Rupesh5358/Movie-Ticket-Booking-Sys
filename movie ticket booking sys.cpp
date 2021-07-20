#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
#include<stdio.h>


using namespace std;

class Movie
{

public:
    char m_movie_name[20];
    int m_price;
    int m_total_ticket_count;
    char m_format[5];
    char m_release_date[20];
    char m_show_time[10];
    char m_auditorium;
    char m_movie_duration[10];
    char m_genre[10];
    char m_director_name[20];



    Movie()
    {
        m_price =0;
        m_total_ticket_count=0;

        strcpy(m_movie_name,"N/A");
        strcpy(m_release_date,"N/A");
        strcpy(m_show_time,"N/A");
        strcpy(m_movie_duration,"N/A");
        strcpy(m_genre,"N/A");
        strcpy(m_director_name,"N/A");
        m_auditorium='N';
    }


    void display()
    {

        cout<<setfill('-')<<setw(41)<<"|"<<endl;
        cout<<"DISPALYING MOVIE DETAILS:<"<<endl;
        cout<<setfill('-')<<setw(41)<<"|"<<endl;
        cout<<"Movie Name :"<<m_movie_name<<endl;
        cout<<"Price:"<<m_price<<endl;
        cout<<"Total Ticket Count :"<<m_total_ticket_count<<endl;
        cout<<"Format :"<<m_format<<endl;
        cout<<"Release Date :"<<m_release_date<<endl;
        cout<<"Show time :"<<m_show_time<<endl;
        cout<<"Auditorium :"<<m_auditorium<<endl;
        cout<<"Movie Duration :"<<m_movie_duration<<endl;
        cout<<"Genre :"<<m_genre<<endl;
        cout<<"Director Name :"<<m_director_name<<endl;

    }


    void accept()
    {

        cout<<"Enter Movie Name :";
        cin>>m_movie_name;
        cout<<"Enter Price:";
        cin>>m_price;
        cout<<"Enter Total Ticket Count :";
        cout<<"Enter Format (2D/3D):";
        cin>>m_format;
        cout<<"Enter Release Date :";
        cin>>m_release_date;
        cout<<"Enter Show Time : ";
        cin>>m_show_time;
        cout<<"Enter Auditorium :";
        cin>>m_auditorium ;
        cout<<"Enter Movie Duration :";
        cin>>m_movie_duration;
        cout<<"Enter Movie Genre :";
        cin>>m_genre;
        cout<<"Enter Director Name :";
        cin>>m_director_name;

    }




    void writeMovieData()
    {

        ofstream fout;
        fout.open("movie.dat",ios::app|ios::binary);
        fout.write((char*)this , sizeof(*this));
        fout.close();

    }



    void viewMovieData()
    {

        ifstream fin;
        fin.open("movie.dat",ios::app|ios::binary);
        if(!fin)
            {

                cout<<"NO DATA FOUND !!"<<endl;

            }
        else
        {
                fin.read((char*)this,sizeof(*this));
                while(!fin.eof()) //end of file eof()
                    {
                        display();
                        fin.read((char*)this,sizeof(*this));
                    }
                fin.close();
          }
    }




};



class TicketDetails
{

public:
    int seat_number;
    char row_number;
    char ticket_type[20];
};

class TicketDisplay:public Movie, public TicketDetails   //multiple
{
public:
    void displayticket()
    {

        cout<<setfill('-')<<setw(41)<<"|"<<endl;
        cout<<"DISPLAY TICKET DETAILS !!!"<<endl;
        cout<<setfill('-')<<setw(41)<<"|"<<endl;
        cout<<"Movie Name :"<<m_movie_name<<endl;
        cout<<"Show Time:"<<m_show_time<<endl;
        cout<<"Movie Duration :"<<m_movie_duration<<endl;
        cout<<"Ticket Type :"<<ticket_type<<endl;
        cout<<"Row Number :"<<row_number<<endl;
        cout<<"Seat Number :"<<seat_number<<endl;

    }

    void getTicketDetails()
    {

        cout<<"Enter Movie Name :";
        cin>>m_movie_name;
        cout<<"Enter Show Time";
        cin>>m_show_time;
        cout<<"Enter Movie Duration :";
        cin>>m_movie_duration;
        cout<<"Please Enter  Ticket Type (gold ,silver , platinum ) :";
        cin>>ticket_type;
        cout<<"Enter Row Number :";
        cin>>row_number;
        cout<<"Enter Seat Number :";
        cin>>seat_number;

    }


    void writeTicketData()
    {

        ofstream fout;
        fout.open("ticket.dat",ios::app|ios::binary);
        fout.write((char*)this , sizeof(*this));
        fout.close();

    }

    void viewTicketData()
    {
        ifstream fin;
        fin.open("ticket.dat",ios::in|ios::binary);
        if(!fin)
        {

            cout<<"NO DATA FOUND !!"<<endl;

        }
        else
        {

            fin.read((char*)this , sizeof(*this));
            while(!fin.eof())
            {

                displayticket();
                fin.read((char*)this , sizeof(*this));

            }
            fin.close();

        }
    }
};

class Help
{

public:
    virtual void show()
    {

        cout<<"For any Help , Please Contact Administrator "<<endl;

    }
};
class TicketHelp :public Help
{

public:
    virtual void show()
    {

        cout<<"For Ticket Related Issue , Go to counter NO.2 "<<endl;

    }

};

class MovieHelp :public Help
{

public:
    virtual void show()
    {

        cout<<"For Movie Related Issue , Go to counter NO.1 "<<endl;

    }

};


int main()
{
    TicketDisplay ticketData;
    Movie movieData;
    cout<<"|"<<setfill('-')<<setw(41)<<"|"<<endl;
    cout<<"|"<<"----------MOVIE BOOKING SYSTEM "<<setfill('-')<<setw(11)<<"|"<<endl;
    cout<<"|"<<setfill('-')<<setw(41)<<"|"<<endl;


    while(1)
        {

            cout<<"1.Input Movie Details "<<endl
                <<"2.Display Movie Details "<<endl
                <<"3.Enter Tickets Details "<<endl
                <<"4.Display Ticket "<<endl
                <<"5.Help"<<endl
                <<"6.Exit"<<endl;


            int ch,n=0;
            cout<<"Enter Your Choice :";
            cin>>ch;

            switch(ch)
            {

                case 1:
                    {

                        cout<<setfill('=')<<setw(45)<<"|"<<endl;
                        cout<<"Enter Movie Details ....."<<endl;
                        cout<<setfill('=')<<setw(45)<<endl;
                        movieData.accept();
                        movieData.writeMovieData();

                    }
                    break;

                case 2:
                    {

                        movieData.viewMovieData();

                    }
                    break;


                case 3:
                    {
                        cout<<setfill('=')<<setw(45)<<"|"<<endl;
                        cout<<"Enter Ticket Details ...."<<endl;
                        cout<<setfill('=')<<setw(45)<<"|"<<endl;
                        ticketData.getTicketDetails();
                        ticketData.writeTicketData();


                    }
                    break;

                case 4 :
                        ticketData.viewTicketData();
                        break;

                case 5 :
                    {

                        int x;
                        cout<<"1.Ticket Issue "<<endl
                            <<"2.Movie Issue "<<endl
                            <<"3.General Issue "<<endl
                            <<"Enter Your Choice :";

                        cin>>x;

                        if(x==1)
                            {

                                cout<<"For any Help , Please Contact Administrator "<<endl;
                            }
                        else if(x==2)
                            {
                               cout<<"For Ticket Related Issue , Go to counter NO.2 "<<endl;
                            }
                        else if(x==3)
                            {

                                cout<<"For Movie Related Issue , Go to counter NO.1 "<<endl;
                            }
                        break;
                    }

                    case 6:
                        return 0;


                }
 }
 return 0;
}
