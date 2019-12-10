#include <bits/stdc++.h>
#include <string>
#include <fstream>
#include <ctime>
#include <windows.h>

using namespace std;

string des9;
long long int sum=0,sum2=0,pri=0,pri1=0,tempsum;      //setting compiler to c11/c14 version from setting sometimes resolves ofstream issues
long double sum1=0.00;

vector<string>reciept_product;        //Vector For storing bought product information
vector<int>reciept_price;
vector<int>reciept_q;

vector<string>deque_q_product;        //Vector for keeping track of canceled products
vector<int>deque_q_quantity;
vector<int>deque_q_base_price;
vector<int>deque_q_price;

vector<string>dairy_product;          //Vector for storing dairy dept. bought products
vector<int>dairy_price;

vector<string>frozen_product;         //Vector for storing frozen dept. bought products
vector<int>frozen_price;

vector<string>drinks_product;         //Vector for storing drinks dept. bought products
vector<int>drinks_price;

vector<string>fish_product;           //Vector for storing fish dept. bought products
vector<int>fish_price;

vector<string>cooking_product;        //Vector for storing cooking dept. bought products
vector<int>cooking_price;


int stringtoint(string price)         //Function used to convert string price to int from csv file
{
    int ans=0;

    for(int i=0; i<price.size(); i++)
    {
        ans = ans*10 + price[i]-48;
    }
    return ans;
}


void readFile(int inter)             //Function To read csv files according to department file
{

    string line,in,product,price,cur;
    int cvprice;

    ifstream dd;

    if(inter==1)
    {
        dd.open("Dairy.csv");

        while(dd.good())
        {

            getline(dd,in,',');
            getline(dd,product,',');
            getline(dd,price,',');
            getline(dd,cur,'\n');

            if(in=="EOF")
                break;

            cout<<"                                                                      ||     "<<in<<" "<<product<<" "<<price<<" "<<cur<<"     ||"<<endl;

            cvprice=stringtoint(price);

            dairy_product.push_back(product);
            dairy_price.push_back(cvprice);

        }

        dd.close();
    }

    else if(inter==2)
    {
        dd.open("Frozen.csv");

        while(dd.good())
        {
            getline(dd,in,',');
            getline(dd,product,',');
            getline(dd,price,',');
            getline(dd,cur,'\n');

            if(in=="EOF")
                break;

            cout<<"                                                                    ||       "<<in<<" "<<product<<" "<<price<<" "<<cur<<"       ||"<<endl;

            cvprice=stringtoint(price);

            frozen_product.push_back(product);
            frozen_price.push_back(cvprice);

        }

        dd.close();
    }

    else if(inter==3)
    {
        dd.open("Drinks.csv");

        while(dd.good())
        {
            getline(dd,in,',');
            getline(dd,product,',');
            getline(dd,price,',');
            getline(dd,cur,'\n');

            if(in=="EOF")
                break;

            cout<<"                                                                        ||     "<<in<<" "<<product<<" "<<price<<" "<<cur<<"     ||"<<endl;

            cvprice=stringtoint(price);

            drinks_product.push_back(product);
            drinks_price.push_back(cvprice);

        }

        dd.close();

    }

    else if(inter==4)
    {
        dd.open("Fish And Meat.csv");

        while(dd.good())
        {

            getline(dd,in,',');
            getline(dd,product,',');
            getline(dd,price,',');
            getline(dd,cur,'\n');

            if(in=="EOF")
                break;

            cout<<"                                                                    ||           "<<in<<" "<<product<<" "<<price<<" "<<cur<<"                       ||"<<endl;

            cvprice=stringtoint(price);

            fish_product.push_back(product);
            fish_price.push_back(cvprice);

        }

        dd.close();

    }

    else if(inter==5)
    {
        dd.open("Cooking.csv");

        while(dd.good())
        {
            getline(dd,in,',');
            getline(dd,product,',');
            getline(dd,price,',');
            getline(dd,cur,'\n');

            if(in=="EOF")
                break;

            cout<<"                                                                      ||     "<<in<<" "<<product<<" "<<price<<" "<<cur<<"           ||"<<endl;

            cvprice=stringtoint(price);

            cooking_product.push_back(product);
            cooking_price.push_back(cvprice);

        }

        dd.close();

    }
}


void purchage(int des,int index,int q)             //This Function is used save bought products in vectors
{

    if(des==1)
    {
        if((index+1)<=0 || (index+1)>=16)
        {
            cout<<"      No Valid Product Exists..."<<endl;
        }
        else
        {
            reciept_product.push_back(dairy_product.at(index));
            reciept_price.push_back(dairy_price.at(index));
            reciept_q.push_back(q);
            sum+=(dairy_price.at(index)*q);
        }
    }

    else if(des==2)
    {
        if((index+1)<=0 || (index+1)>=25)
        {
            cout<<"      No Valid Product Exists..."<<endl;
        }
        else
        {
            reciept_product.push_back(frozen_product.at(index));
            reciept_price.push_back(frozen_price.at(index));
            reciept_q.push_back(q);
            sum+=(frozen_price.at(index)*q);
        }
    }

    else if(des==3)
    {
        if((index+1)<=0 || (index+1)>=20)
        {
            cout<<"      No Valid Product Exists..."<<endl;
        }
        else
        {
            reciept_product.push_back(drinks_product.at(index));
            reciept_price.push_back(drinks_price.at(index));
            reciept_q.push_back(q);
            sum+=(drinks_price.at(index)*q);
        }
    }

    else if(des==4)
    {
        if((index+1)<=0 || (index+1)>=8)
        {
            cout<<"      No Valid Product Exists..."<<endl;
        }
        else
        {
            reciept_product.push_back(fish_product.at(index));
            reciept_price.push_back(fish_price.at(index));
            reciept_q.push_back(q);
            sum+=(fish_price.at(index)*q);
        }
    }

    else if(des==5)
    {
        if((index+1)<=0 || (index+1)>=18)
        {
            cout<<"      No Valid Product Exists..."<<endl;
        }
        else
        {
            reciept_product.push_back(cooking_product.at(index));
            reciept_price.push_back(cooking_price.at(index));
            reciept_q.push_back(q);
            sum+=(cooking_price.at(index)*q);
        }
    }

}


void category()         //This function show all department names
{

    cout<<endl<<"                                                                             ======================================================"<<endl;
    cout<<"                                                                             ||                                                  ||"<<endl;
    cout<<"                                                                             ||        1.Dairy Corner                            ||"<<endl;
    cout<<"                                                                             ||        2.Frozen Food And Snacks Corner           ||"<<endl;
    cout<<"                                                                             ||        3.Drinks Corner                           ||"<<endl;
    cout<<"                                                                             ||        4.Fish And Meat Corner                    ||"<<endl;
    cout<<"                                                                             ||        5.Cooking Corner                          ||"<<endl;
    cout<<"                                                                             ||                                                  ||"<<endl;
    cout<<"                                                                             ======================================================"<<endl<<endl;

}


void decision(int inter)       //This function is used for from which department and which products will be bought
{

    string des1,des2;
    int index,q;

    cout<<"      Do You Want To Buy Product From This Corner ?( Enter Y for Yes Or N For No): ";

    while(1)
    {

        cin>>des1;
        cout<<endl;

        if(des1=="Y" || des1=="y")
        {

            cout<<"      Enter The Product Number And Their Quantity (Enter 0,0 To End): "<<endl;

            while(1)
            {
                cout<<"      ";
                cin>>index>>q;

                if(index==0 && q==0)
                    break;

                purchage(inter,index-1,q);
            }

            cout<<"      Do You Want To Buy Product From Other Corner?(Enter Y For Yes Or N For No) : ";

            while(1)
            {

                cin>>des2;
                cout<<endl;

                if(des2=="Y" || des2=="y")
                {
                    category();
                    cout<<"      Please Enter From Which Corner You Want To Shop : ";
                    break;
                }
                else if(des2=="N" || des2=="n")
                {
                    des9="0";
                    break;
                }
                else
                {
                    cout<<"      Invalid Input! Please try again."<<endl;
                    cout<<"      Do You Want To Buy Product From Other Corner?(Enter Y For Yes Or N For No) : ";
                }

            }

            break;
        }
        else if(des1=="N" || des1=="n")
        {
            cout<<"      Do You Want To Buy Product From Other Corner?(Enter Y For Yes Or N For No): ";


            while(1)
            {

                cin>>des2;
                cout<<endl;

                if(des2=="Y" || des2=="y")
                {
                    category();
                    cout<<"      Please Enter From Which Corner You Want To Shop: ";
                    break;
                }
                else if(des2=="N" || des2=="n")
                {
                    des9="0";
                    break;
                }
                else
                {
                    cout<<"      Invalid Input! Please Try Again."<<endl;
                    cout<<"      Do You Want To Buy Product From Other Corner?(Enter Y For Yes Or N For No): ";
                }

            }

            break;
        }
        else
        {
            cout<<"      Invalid Input! Please Try Again."<<endl;
            cout<<"      Do You Want To Buy Product From This Corner ?( Enter Y for Yes Or N For No): ";
        }
    }

}



void interface_up(int inter)   //For designing upper part of products list
{
    if(inter==1)
    {
        cout<<endl<<endl<<"                                                                      ////////////////////////////////////////////////////////////////////"<<endl;
        cout<<"                                                                      ||                                                                ||"<<endl;
        cout<<"                                                                      ||            Products Available In Dairy Corner Are:             ||"<<endl;
        cout<<"                                                                      ||                                                                ||"<<endl;
    }

    else if(inter==2)
    {
        cout<<endl<<endl<<"                                                                    /////////////////////////////////////////////////////////////////////////"<<endl;
        cout<<"                                                                    ||                                                                     ||"<<endl;
        cout<<"                                                                    ||       Products Available In Frozen Food And Snacks Corner Are:      ||"<<endl;
        cout<<"                                                                    ||                                                                     ||"<<endl;

    }

    else if(inter==3)
    {
        cout<<endl<<endl<<"                                                                        //////////////////////////////////////////////////////////////////"<<endl;
        cout<<"                                                                        ||                                                              ||"<<endl;
        cout<<"                                                                        ||           Products Available In Drinks Corner Are:           ||"<<endl;
        cout<<"                                                                        ||                                                              ||"<<endl;
    }

    else if(inter==4)
    {
        cout<<endl<<endl<<"                                                                    /////////////////////////////////////////////////////////////////////////"<<endl;
        cout<<"                                                                    ||                                                                     ||"<<endl;
        cout<<"                                                                    ||          Products Available In Fish And Vegetable Corner Are:       ||"<<endl;
        cout<<"                                                                    ||                                                                     ||"<<endl;
    }

    else if(inter==5)
    {
        cout<<endl<<endl<<"                                                                      //////////////////////////////////////////////////////////////////"<<endl;
        cout<<"                                                                      ||                                                              ||"<<endl;
        cout<<"                                                                      ||            Products Available In Cooking Corner Are:         ||"<<endl;
        cout<<"                                                                      ||                                                              ||"<<endl;
    }

}


void interface_down(int inter)    //For designing lower part of products list
{

    if(inter==1)
    {
        cout<<"                                                                      ||                                                                ||"<<endl;
        cout<<"                                                                      ////////////////////////////////////////////////////////////////////"<<endl<<endl<<endl;
    }
    else if(inter==2)
    {
        cout<<"                                                                    ||                                                                     ||"<<endl;
        cout<<"                                                                    /////////////////////////////////////////////////////////////////////////"<<endl<<endl<<endl;
    }

    else if(inter==3)
    {
        cout<<"                                                                        ||                                                              ||"<<endl;
        cout<<"                                                                        //////////////////////////////////////////////////////////////////"<<endl<<endl<<endl;
    }

    else if(inter==4)
    {
        cout<<"                                                                    ||                                                                     ||"<<endl;
        cout<<"                                                                    /////////////////////////////////////////////////////////////////////////"<<endl<<endl<<endl;
    }

    else if(inter==5)
    {
        cout<<"                                                                      ||                                                              ||"<<endl;
        cout<<"                                                                      //////////////////////////////////////////////////////////////////"<<endl<<endl<<endl;
    }
}



void Dairy()              //Function for buying products from dairy dept.
{

    interface_up(1);

    readFile(1);

    interface_down(1);

    decision(1);

}



void Frozen()         //Function for buying products from frozen dept.
{
    interface_up(2);

    readFile(2);

    interface_down(2);

    decision(2);
}



void Drinks()        //Function for buying products from drinks dept.
{
    interface_up(3);

    readFile(3);

    interface_down(3);

    decision(3);
}



void Fish()        //Function for buying products from fish dept.
{
    interface_up(4);

    readFile(4);

    interface_down(4);

    decision(4);
}



void Cooking()     //Function for buying products from cooking dept.
{
    interface_up(5);

    readFile(5);

    interface_down(5);

    decision(5);
}


void greetings()       //Opening part of the program
{
    cout<<"                                                                                        ===================================   "<<endl;
    cout<<"                                                                                       |                                   |  "<<endl;
    cout<<"                                                                                       |  Welcome To Our Store App Service |  "<<endl;
    cout<<"                                                                                       |                                   |  "<<endl;
    cout<<"                                                                                        ===================================   "<<endl;
    cout<<endl<<endl;
}


void comand()        //function for Choice list
{

    cout<<"                                                                             ======================================================"<<endl;
    cout<<"                                                                             ||        1.Buy Products.                           ||"<<endl;
    cout<<"                                                                             ||        2.Show Previous Receipt                   ||"<<endl;
    cout<<"                                                                             ||        3.Show Previous Given Feedback            ||"<<endl;
    cout<<"                                                                             ||        4.Exit Our App                            ||"<<endl;
    cout<<"                                                                             ======================================================"<<endl<<endl;
}


void delete_q()    //Function for canceling products
{

    int q,q2;

    cout<<"      Enter the products you want to cancel And its quantity( 0 to end ): ";

    cout<<endl<<"                                                                   ------------------------------------------------------------------------"<<endl;

    int j=0;

    while(1)
    {

        cout<<"      ";
        cin>>q>>q2;
        if(q==0 && q2==0)
            break;

        q--;

        if(q2>reciept_q.at(q))
        {
            cout<<"      Invalid Quantity..."<<endl;
        }
        else
        {

            cout<<endl<<"                                                                   ------------------------------------------------------------------------"<<endl;
            cout<<"                                                                           "<<j+1<<". Product: "<<reciept_product.at(q)<<endl;
            cout<<"                                                                              Quantity: X-"<<q2<<endl;
            cout<<"                                                                              Price(X-1): "<<reciept_price.at(q)<<endl;
            cout<<"                                                                              Price: "<<reciept_price.at(q)*q2<<endl;
            cout<<"                                                                   ------------------------------------------------------------------------"<<endl;

            sum2+=(reciept_price.at(q)*q2);

            deque_q_product.push_back(reciept_product.at(q));
            deque_q_quantity.push_back(q2);
            deque_q_base_price.push_back(reciept_price.at(q));
            deque_q_price.push_back(reciept_price.at(q)*q2);

            j++;
        }
    }

    sum-=sum2;

    cout<<"                                                                   ------------------------------------------------------------------------"<<endl;
    cout<<endl<<"                                                                             Reduced Price :                                   --> "<<"- "<<sum2<<endl<<endl;
    cout<<"                                                                   ------------------------------------------------------------------------"<<endl;
    cout<<endl<<"                                                                             Total Price :                                       --> "<<sum<<endl<<endl;
    cout<<"                                                                   ========================================================================"<<endl;

    pri1=1;

}



void save(string name,string id)                    //Function to save customer receipt
{
    string line;

    vector<string>::iterator i;
    vector<int>::iterator it,its,its2;


    line=name+id+"receipt"+".txt";

    ofstream write;
    write.open(line);

    write<<"                                                                   ========================================================================"<<endl<<endl;
    write<<"                                                                                               Customer: "<<name<<"                        "<<endl<<endl;
    write<<"                                                                                               Unique Code: "<<id<<"                        "<<endl<<endl;
    write<<"                                                                   ========================================================================"<<endl;

    i=reciept_product.begin(),its=reciept_price.begin(),it=reciept_q.begin();

    int j=0;

    while(i!=reciept_product.end())
    {

        write<<"                                                                          "<<j+1<<". Product: "<<*i<<"                                     "<<endl;
        i++;
        write<<"                                                                             Quantity: X-"<<*it<<"                                         "<<endl;
        write<<"                                                                             Price(X-1): "<<*its<<"                                        "<<endl;
        write<<"                                                                             Price: "<<((*its)*(*it))<<"                                        "<<endl;
        its++;
        it++;
        write<<"                                                                   ------------------------------------------------------------------------"<<endl;
        j++;
    }

    write<<"                                                                   ------------------------------------------------------------------------"<<endl;
    write<<endl<<"                                                                             Total Price :                                        --> "<<tempsum<<endl<<endl;
    write<<"                                                                   ========================================================================"<<endl;


    i=deque_q_product.begin(),its=deque_q_price.begin(),it=deque_q_quantity.begin(),its2=deque_q_base_price.begin();

    if(pri1==1)
    {
        int j=0;

        while(i!=deque_q_product.end())
        {

            write<<"                                                                          "<<j+1<<". Product: "<<*i<<"                                     "<<endl;
            i++;
            write<<"                                                                             Quantity: X-"<<*it<<"                                         "<<endl;
            it++;
            write<<"                                                                             Price(X-1): "<<*its2<<"                                        "<<endl;
            its2++;
            write<<"                                                                             Price: "<<*its<<"                                        "<<endl;
            its++;
            write<<"                                                                   ------------------------------------------------------------------------"<<endl;
            j++;
        }

        write<<"                                                                   ------------------------------------------------------------------------"<<endl;
        write<<endl<<"                                                                             Reduced Price :                                      --> "<<"-"<<sum2<<endl<<endl;
        write<<"                                                                   ------------------------------------------------------------------------"<<endl;
        write<<endl<<"                                                                             Total Price :                                        --> "<<sum<<endl<<endl;
        write<<"                                                                   ========================================================================"<<endl;

    }

    if(pri==1)
    {

        write<<endl<<"                                                                             Discount Price :                                     --> "<<"-"<<sum1<<endl<<endl;
        write<<"                                                                   ------------------------------------------------------------------------"<<endl;
        write<<endl<<"                                                                             Total Price :                                        --> "<<sum-sum1<<endl<<endl;
        write<<"                                                                   ========================================================================"<<endl;
    }

    time_t now = time(0);
    char* dm = ctime(&now);

    write<<"                                                                   Date & Time: "<<dm<<endl;

    write.close();

    cout<<"      Saving Informations Please Wait..."<<endl;
    cout<<"      Saved !"<<endl;

}


void payment(string name,string id)     //Function for generating receipt
{

    vector<string>::iterator i;
    vector<int>::iterator it,its;

    i=reciept_product.begin(),its=reciept_price.begin(),it=reciept_q.begin();

    cout<<endl<<"      Generating Payment Receipt For "<<name<<" ."<<endl;
    cout<<"      Please Be Patient ";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<endl<<endl;
    cout<<"                                                                   ========================================================================"<<endl<<endl;
    cout<<"                                                                                               Customer: "<<name<<"                        "<<endl<<endl;
    cout<<"                                                                                               Unique Code: "<<id<<"                        "<<endl<<endl;
    cout<<"                                                                   ========================================================================"<<endl;

    int j=0;

    while(i!=reciept_product.end())
    {

        cout<<"                                                                          "<<j+1<<". Product: "<<*i<<"                                     "<<endl;
        i++;
        cout<<"                                                                             Quantity: X-"<<*it<<"                                         "<<endl;
        cout<<"                                                                             Price(X-1): "<<*its<<"                                        "<<endl;
        cout<<"                                                                             Price: "<<((*its)*(*it))<<"                                        "<<endl;
        it++;
        its++;
        cout<<"                                                                   ------------------------------------------------------------------------"<<endl;
        j++;
    }

    cout<<endl<<"                                                                             Total Price :                                       --> "<<sum<<endl<<endl;
    cout<<"                                                                   ========================================================================"<<endl;

    tempsum=sum;

    string del;
    cout<<"      Do you want to remove anything ?: ";

    while(1)
    {

        cin>>del;

        if(del=="Y" || del =="y")
        {
            delete_q();
            break;
        }
        else if(del=="N" || del=="n")
        {
            break;
        }
        else
        {
            cout<<"      Invalid Input! Please Try Again."<<endl;
            cout<<"      Do you want to remove anything ?: ";
        }
    }

    if(pri==1)
    {
        sum1*=sum;
        cout<<endl<<"                                                                             Discount Price :                                   --> "<<"-"<<sum1<<endl<<endl;
        cout<<"                                                                   ------------------------------------------------------------------------"<<endl;
        cout<<endl<<"                                                                             Total Price :                                      --> "<<sum-sum1<<endl<<endl;
        cout<<"                                                                   ========================================================================"<<endl;
    }

    if(sum!=0)
    {
        cout<<endl<<"      Please Pay Your Bill With Cash .... "<<endl;
    }

}



void exprivileged(string name)              //Function for old users
{
    string pin,priv;

    while(1)
    {
        cout<<"Do You Have Any Privileged Pin?(Enter Y or N) : ";
        cin>>priv;

        if(priv=="Y" || priv=="y")
        {

            cout<<"      Enter Your Privileged Pin (3 Digit): ";
            cin>>pin;

            cout<<"      Checking If You Are A Privileged Customer Or Not..."<<endl;
            cout<<"      Please Be Patient ";
            Sleep(400);
            cout<<".";
            Sleep(400);
            cout<<".";
            Sleep(400);
            cout<<".";
            Sleep(400);
            cout<<endl<<endl;

            ifstream dd;
            dd.open("Privilaged.csv");

            string line,line2;

            line2=name+pin;

            while(dd>>line)
            {

                int x=line.compare(line2);

                if(x==0)
                {
                    pri=1;
                    cout<<endl<<endl;
                    cout<<"      Congratulations, You are our valuable privileged customer....."<<endl;
                    cout<<"      You will be awarded a 10% discount according to our current campaign.....";
                    Sleep(400);
                    cout<<endl<<endl;

                    sum1+=0.10;
                }
            }

            dd.close();

            if(pri==0)
            {
                cout<<"      Sorry, you not a privileged customer....."<<endl<<endl;
            }

            break;
        }
        else if(priv=="N" || priv=="n")
        {
            break;
        }
        else
        {
            cout<<"      Invalid Input...Please Try Again..."<<endl;
        }
    }

}



void newprivileged(string name)         //Function for new user
{

    int i,j;
    string line,line2;
    string arr[1000];
    string pin;

    cout<<"      Enter Your Privileged Pin (3 Digit): ";
    cin>>pin;

    ifstream ds;
    ds.open("Privilaged.csv");

    i=0;
    while(ds>>line)
    {

        arr[i]=line;

        i++;
    }
    ds.close();

    line2=name+pin;

    arr[i]=line2;
    i++;

    ofstream dd;
    dd.open("Privilaged.csv");

    for(j=0; j<i; j++)
    {
        dd<<arr[j]<<endl;
    }
    dd.close();

}

void feedback(string name,string id)                 //Function for saving feedback
{
    string des10,line,star,detail;

    cout<<"      Would you like to give feedback?(Enter Y to give or N to skip): ";

    while(1)
    {
        cin>>des10;

        line=name+id+"feed"+".txt";

        if(des10=="Y" || des10=="y")
        {

            time_t now = time(0);
            char* dm = ctime(&now);

            ofstream ds;
            ds.open(line);

            cout<<"      Please Give Star (From 1-5 ): ";
            cin>>star;
            cout<<endl;

            cout<<"      Details: ";
            cin>>detail;
            cout<<endl;

            ds<<"Name: "<<name<<endl;
            ds<<"Unique Code: "<<id<<endl;
            ds<<"Stars: "<<star<<endl;
            ds<<"Detail: "<<detail<<endl;
            ds<<"Time: "<<dm<<endl;


            cout<<"      Thank You For Your Feedback ...."<<endl<<endl;
            break;

        }
        else if(des10=="N" || des10=="n")
        {
            cout<<"      Thank you...."<<endl<<endl;
            break;
        }
        else
        {
            cout<<"      Invalid Input! Please try again."<<endl;
            cout<<"      Would you like to give feedback?(Enter Y to give or N to skip): ";
        }
    }
}
void buy()                   //Function for buying
{
    string a;

    cout<<"      To See Our Different Product Corners Press Y Or N To Exit: ";

    while(1)
    {

        cin>>a;
        cout<<endl;

        if(a=="Y" || a=="y")
        {
            category();
            cout<<"      Please Enter From Which Corner You Want To Shop : ";

            while(des9!="0")
            {
                cin>>des9;
                cout<<endl;

                if(des9=="0")
                    break;
                else if(des9=="1")
                    Dairy();
                else if(des9=="2")
                    Frozen();
                else if(des9=="3")
                    Drinks();
                else if(des9=="4")
                    Fish();
                else if(des9=="5")
                    Cooking();
                else
                {
                    cout<<"      Invalid Choice, Try Again!"<<endl<<endl;
                    cout<<"      Please Enter From Which Corner You Want To Shop : ";
                }

            }

            if(sum==0)
            {
                cout<<"      Sir, You Haven't Purchased Anything, Thank You For Your Time...."<<endl;
            }
            else
            {
                string name,id;

                cout<<"      Please Enter Your Name: ";
                cin>>name;
                cout<<endl;
                cout<<"      Please Enter Your Unique Code (3 Digit): ";
                cin>>id;
                cout<<endl<<endl;

                exprivileged(name);
                payment(name,id);

                cout<<endl;

                if(pri==0)
                {
                    if(sum>=1500)
                    {
                        string prid;

                        cout<<"      As You Bought Product Of 1500 or More ....You Can Be An Privileged Customer..."<<endl<<endl;

                        while(1)
                        {

                            cout<<"      Do You Want To Be A Privileged Customer? (Enter Y for Yes or N for No) : ";
                            cin>>prid;
                            cout<<endl;
                            if(prid=="Y" || prid=="y")
                            {
                                newprivileged(name);
                                cout<<"      Congratulation You Are An Privileged Customer From Now......"<<endl;
                                cout<<"      You Can Avail Exiting Promotional Offers From Next Shopping......"<<endl<<endl;
                                break;
                            }
                            else if(prid=="N" || prid=="n")
                            {
                                break;
                            }
                            else
                            {
                                cout<<"      Invalid Input...Please Try Again."<<endl;
                            }
                        }
                    }
                }

                cout<<endl<<"      Sir, Thank You For Shopping With Us ....."<<endl<<endl;

                feedback(name,id);

                if(sum!=0)
                {
                    save(name,id);
                }
            }
            break;
        }

        else if(a=="N" || a=="n")
        {
            cout<<"      We are sorry sir, hope that next time we will be able to serve you ....."<<endl<<endl;
            break;
        }
        else
        {
            cout<<"      Invalid Choice, Try again !"<<endl<<endl;
            cout<<"      To See Our Different Product Corners Press Y Or N To Exit: ";
        }
    }

    des9="100";
    sum=0,sum2=0,pri=0,pri1=0,tempsum;
    sum1=0.00;

    reciept_product.clear();
    reciept_price.clear();
    reciept_q.clear();

    deque_q_product.clear();
    deque_q_base_price.clear();
    deque_q_price.clear();
    deque_q_quantity.clear();

    dairy_product.clear();
    dairy_price.clear();

    frozen_product.clear();
    frozen_price.clear();

    drinks_product.clear();
    drinks_price.clear();

    fish_product.clear();
    fish_price.clear();

    cooking_product.clear();
    cooking_price.clear();

}

void receipt()        //Function for showing receipt
{
    string line,line2,name,id;

    cout<<"      Please Enter Your Name: ";
    cin>>name;
    cout<<"      Please Enter Your Unique Code: ";
    cin>>id;

    line=name+id+"receipt"+".txt";

    ifstream dd;
    dd.open(line);

    if(dd.good()==false)
    {
        cout<<"      No such user receipt exits."<<endl;
    }
    else
    {
        while(dd.good())
        {
            getline(dd,line2,'\n');
            cout<<line2<<endl;
        }
        dd.close();
    }
}


void showfeedback()   //Function for showing feedback
{
    string line,line2,name,id;

    cout<<"      Please Enter Your Name: ";
    cin>>name;
    cout<<"      Please Enter Your Unique Code: ";
    cin>>id;

    line=name+id+"feed"+".txt";

    ifstream dd;
    dd.open(line);

    if(dd.good()==false)
    {
        cout<<"      No such user feedback exits."<<endl;
    }
    else
    {
        cout<<"                                                                             ======================================================"<<endl<<endl;
        while(dd.good())
        {
            getline(dd,line2,'\n');
            cout<<"                                                                               "<<line2<<endl;
        }
        cout<<"                                                                             ======================================================"<<endl<<endl;
        dd.close();
    }
}

int main()
{


    system("color 0B");

    greetings();
    comand();

    string com;

    while(1)
    {
        cout<<"      Enter Your Choice: ";
        cin>>com;
        cout<<endl<<endl;

        if(com=="1")
        {
            buy();
            comand();
        }
        else if(com=="2")
        {
            receipt();
            comand();
        }
        else if(com=="3")
        {
            showfeedback();
            comand();
        }
        else if(com=="4")
        {
            cout<<"      Thank You For Using Our App..."<<endl;
            break;
        }
        else
        {
            cout<<"      Invalid Input...Please Try Again..."<<endl;
        }
    }
}



