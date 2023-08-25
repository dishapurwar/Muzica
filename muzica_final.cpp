
#include<windows.h>
#include<mmsystem.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>


using namespace std;

struct node
{
    char song[100];
    struct node *next;
    struct node *prev;
}*top,*temp,*top1;

void tofile(char a[])
{
    fstream f1;
    f1.open("playlist.txt",ios::out|ios::app);
    f1<<a<<endl;
    f1.close();
}

void add_node(node *&head)
{
    system("cls");
    cout<<endl<<endl;
    char *a;
    node *first=head;
    while(first->next!=NULL)
    {
        first=first->next;
    }
    first->next=new node;
    first->prev=first;
    first=first->next;
    cout<<"\t\t\t\t\t\t                             Enter Song name -  ";
    cin>>a;
    strcpy(first->song,a);
    tofile(a);
    first->next=NULL;
    cout <<endl<<endl<< "\t\t\t\t\t\t                             Press Enter To Continue....";
    getchar();
    getchar();
}

void delete_file(char a[])
{
    fstream f1,f2;
    string line;
    int x=0;
    f1.open("playlist.txt",ios::in|ios::out);
    f2.open("temp.txt",ios::in|ios::out);
    while(!f1.eof())
    {
        getline(f1,line);
        if(strcmp(a,line.c_str())!=0)
            f2<<line<<endl;
        else if (strcmp(a,line.c_str())==0)
            x=1;
    }
    f1.close();
    f2.close();
    remove("playlist.txt");
    rename("temp.txt","playlist.txt");
    if(x==0)
    {
        cout << "There is no song with name you entered." << endl;
    }
    else
    {
        cout << "Song has been deleted." << endl;
    }
}

void printlist(node *&head)
{
    system("cls");
    node *first=head;
    cout<<endl<<"\t\t\t\t\t\t                                Playlist Name- ";
    cout<<first->song<<endl;
    node *temp1=first->next;
    while(temp1->next!=NULL)
    {
        cout<<"\t\t\t\t\t\t                                "<<temp1->song<<endl;
        temp1=temp1->next;
    }
    cout<<"\t\t\t\t\t\t                                "<<temp1->song<<endl;
    cout <<endl<<endl<< "\t\t\t\t\t\t                             Press Enter To Continue....";
    getchar();
}

void count_nodes(node *&head)
{
    system("cls");
    node *first=head;
    int i=0;
    while (first->next!=NULL)
    {
        first=first->next;
        i++;
    }
    i++;
    cout<<"\t\t\t\t\t\t                                Total songs-  "<<i-1<<endl;
    cout <<endl<<endl<< "\t\t\t\t\t\t                             Press Enter To Continue....";
    getchar();


}


void search1(node *&head)
{
    system("cls");
    char *song;
    cout<<"\t\t\t\t\t\t                        Enter song To be Searched- ";
    cin>>song;
    int flag=0;
    //int pos=0;
    while(head!=NULL)
    {
        if(strcmp(head->song,song)==0)
        {
            cout<<endl<<"\t\t\t\t\t\t                                #Song Found"<<endl;
            flag++;
            break;
        }
        else
        {
            head=head->next;
            //pos=pos+1;
        }
    }
    if(flag==0)
    {
        cout<<endl<<"\t\t\t\t\t\t                                #Song Not found"<<endl;
    }
    cout <<endl<<endl<< "\t\t\t\t\t\t                             Press Enter To Continue....";
    getchar();
    getchar();

}

void create()
{
    top = NULL;
}

void push(char data[])
{
    if (top == NULL)
    {
        top =new node;
        top->next = NULL;
        strcpy(top->song,data);
    }
    else if (strcmp(top->song,data)!=0)
    {
        temp =new node;
        temp->next = top;
        strcpy(temp->song,data);
        top = temp;
    }
}

void display()
{
    top1 = top;
    if (top1 == NULL)
    {
        cout<<endl<<"\t\t\t\t\t\t                                =>NO recently played tracks.\n";
        return;
    }
    cout<<endl<<"\t\t\t\t\t\t                                #Recently played tracks-\n";
    while (top1 != NULL)
    {
        cout<<"\t\t\t\t\t\t                                "<<top1->song;
        cout<<endl;
        top1 = top1->next;
    }
}

void play(char* songg){
    PlaySound(songg,NULL,SND_ASYNC);
    cout<<"\t\t\t\t\t\t                                Playing..."<<songg<<endl;
}
 void stop(){
    PlaySound(TEXT("STOPPED"),NULL,SND_APPLICATION);
    cout<<"\t\t\t\t\t\t                                Stopped"<<endl;
}
void player(char song[]){
    int choice;
    char songg[100];
    strcpy(songg,song);
    do{
        cout<<"\t\t\t\t\t\t                                Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1: play(strcat(song,".wav"));break;
            case 2: stop();push(songg);break;
            //push (song);
            case 3:break;
        }
    }while(choice!=3);

}
void playsong(struct node *first)
{
    char song[100];
    printlist(first);
    cout<<endl<<"\t\t\t\t\t\t                         Choose song you wish to play- ";
    scanf("%s",song);
    int flag=0;

    while(first!=NULL)
    {

        if(strcmpi(first->song,song)==0)
        {

            cout<<endl<<"\t\t\t\t\t\t                               =>......"<<song<<endl;
            cout<<endl<<"\t\t\t\t\t\t                       Enter 1 to play and 2 to pause and 3 to exit"<<endl<<endl;



            if(strcmpi(song,"besabriyaan")==0){
                player(song);
            }
            else if(strcmpi(song, "hawa_banke")==0){
                player(song);
            }
            else if(strcmpi(song, "ek_tarfa")==0){
                player(song);
            }
            else if(strcmpi(song, "bhula_dunga")==0){
               player(song);
            }
            else if(strcmpi(song,"baarish_lete_aana")==0){
                player(song);
            }
            else if(strcmpi(song, "baarishon_mein")==0){
               player(song);

            }
            else if(strcmpi(song, "bhula_diya")==0){
                player(song);

            }
            else if(strcmpi(song, "rabba_mehar_kari")==0){
                player(song);

            }
            else if(strcmpi(song, "kaash_aisa_hota")==0){
                player(song);

            }

            flag++;
        }
        else
        {
            first=first->next;
        }
    }
    if(flag==0)
    {
        cout<<endl<<"\t\t\t\t\t\t                                #Song Not found"<<endl;
    }
}


void recent()
{
    system("cls");
    display();
    cout <<endl<<endl<< "\t\t\t\t\t\t                             Press Enter To Continue....";
    getchar();
    getchar();
}

void topelement()
{
    system("cls");
    top1=top;
    if(top1==NULL)
    {
        cout<<endl<<"\t\t\t\t\t\t                                #NO last played tracks.\n";
        return;
    }
    cout<<endl<<"\t\t\t\t\t\t                                =>Last Played Song - "<<top->song<<endl;
    cout <<endl<<endl<< "\t\t\t\t\t\t                             Press Enter To Continue....";
    getchar();
    getchar();

}

node  *del_pos(node *&head, int pos)
{
           system("cls");
           node *prev1,*temp;
           prev1= new node;
           temp= new node;
           int i=0;

           if(pos==1)
           {
                temp=head;
                delete_file(temp->song);
                head=head->next;
                head->prev = NULL;
                free(temp);
                cout<<endl<<"\t\t\t\t\t\t                                The list is updated"<<endl<<"\t\t\t\t\t\t                                Use the display function to check"<<endl;
                 return head;
           }
           while(i<pos-1)
           {
               prev1=head;
               head=head->next;
                i++;

            }
            //for last node
            if(head->next==NULL)
            {

            temp=head;
            delete_file(temp->song);

            prev1->next->prev=NULL;
            prev1->next=NULL;

            free(temp);
             cout<<endl<<"\t\t\t\t\t\t                                The list is updated"<<endl<<"\t\t\t\t\t\t                                Use the display function to check"<<endl;
          }
            //for middle nodes
            else
            {
            temp=head;
            delete_file(temp->song);
            prev1->next=temp->next;
            temp->next->prev=prev1;
            free(temp);
             cout<<endl<<"\t\t\t\t\t\t                                The list is updated"<<endl<<"\t\t\t\t\t\t                                Use the display function to check"<<endl;
            }

             cout <<endl<<endl<< "\t\t\t\t\t\t                             Press Enter To Continue....";
            getchar();
            getchar();
}

void deletemenu(struct node *start)
{
           int pos;
            cout<<"\t\t\t\t\t\t                             Enter the pos of the song : ";
            cin>>pos;
            del_pos(start,pos);


}

main()
{
    int choice,loc;
    char song[100];
    node *start,*hold;
    start=new node;
    system("Color 0A");
    //system("Color 70");
    cout << "| -----------------------------------------------------------------------------------------------------------------------------------------------------------------------|"<<endl;
    cout << "|                                                                         ***** MUZICA WELCOMES YOU *****                                                                |"<<endl;
    cout << "| -----------------------------------------------------------------------------------------------------------------------------------------------------------------------|"<<endl<<endl<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t\t   **please use '_' for space."<<endl;
    cout<<"\n\n\t\t\t\t\t\t\t\t\t  Enter your playlist name-  ";
    cin.getline(start->song,100);
    start->next=NULL;
    hold=start;
    create();

    do
    {
        cout<<endl<<endl;
        cout << "\t\t\t\t\t\t|-----------------------------------------------------------------------------|"<<endl;
        cout << "\t\t\t\t\t\t|                              <<<< FEATURES >>>>                             |"<<endl;
        cout << "\t\t\t\t\t\t|-----------------------------------------------------------------------------|"<<endl;
        cout << "\t\t\t\t\t\t|                                                                             |"<<endl;
        cout << "\t\t\t\t\t\t|                              [1] Add New Song                               |"<<endl;
        cout << "\t\t\t\t\t\t|                              [2] Delete Song                                |"<<endl;
        cout << "\t\t\t\t\t\t|                              [3] Display Entered Playlist                   |"<<endl;
        cout << "\t\t\t\t\t\t|                              [4] Total Songs                                |"<<endl;
        cout << "\t\t\t\t\t\t|                              [5] Search Song                                |"<<endl;
        cout << "\t\t\t\t\t\t|                              [6] Play Song                                  |"<<endl;
        cout << "\t\t\t\t\t\t|                              [7] Recently Played List                       |"<<endl;
        cout << "\t\t\t\t\t\t|                              [8] Last Played                                |"<<endl;
        cout << "\t\t\t\t\t\t|                              [9] Exit                                       |"<<endl;
        cout << "\t\t\t\t\t\t|-----------------------------------------------------------------------------|"<<endl<<endl;
        cout << "\t\t\t\t\t\t                                Enter your choice - ";
        cin>>choice;
        cout<<endl<<endl;
        cout << "\t\t\t\t\t\t                               Press Enter To Continue....";
        getchar();
        getchar();


        switch(choice)
        {
        case 1:
            add_node(start);
            break;
        case 2:
            deletemenu(start);
            break;
        case 3:
            printlist(start);
            break;
        case 4:
            count_nodes(hold);
            break;
        case 5:
            search1(start);
            break;
        case 6:
            playsong(start);
            break;
        case 7:
            recent();
            break;
        case 8:
            topelement();
            break;
        case 9:
            exit(0);
        }
    }
    while(choice!=9);
}
