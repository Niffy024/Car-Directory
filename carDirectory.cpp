//
//  main.cpp
//  This code works for a car directory. 
//It adds car details(owner's name, surname, car id, car model,regsitration date and service date of the car). 
//It can be used to delete cars from directory. 
//It list the available cars in the directory. 
//It can be used to search for cars in the directory(search according to car id, search according to owner's name). 
///It can update the car information already saved.
//It can sort the cars in the directory (according to car id, according to owner's name)
//
//  Created by Machine on 1/9/23.
//

#include<iostream>
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include<string.h>
#include<string>
#include<cstdlib>
#define SIZE 100
using namespace std;
struct date{
    int day, month, year;
};
struct car{
    int ID;
    char owner_name[20], owner_surname[20], model[20];
    struct date reg_date, ns_date;
}car_directory[SIZE];
void add_new_car(struct car[], int *, int);
void list_cars(struct car[]);
void id_search(struct car[]);
void name_search(struct car[]);
void id_sort(struct car[]);
void name_sort(struct car[]);
void update_car(struct car[]);
void delete_car(struct car[]);

//void print_car(struct car[]);



int main(){
    //pointer for count
    int count=0;
    int options;
    char letter, letter2;
    int i=0;
    int *iptr=&i;
    menu:
        //----------MENU----------
        cout<<"1- Add a new car to directory"<<endl;
        cout<<"2- Delete a car from the directory"<<endl;
        cout<<"3- List available cars in the directory"<<endl;
        cout<<"4- Search a car:"<<endl;
        cout<<"\t A- Search according to car id"<<endl;
        cout<<"\t B- Search according to owner name"<<endl;
        cout<<"5- Update car information"<<endl;
        cout<<"6- Sort according to car id"<<endl;
        cout<<"7- sort according to owner name"<<endl;
        cout<<"8- Quit"<<endl;
        cout<<"Enter Choice: ";
        cin>>options;

    switch(options){
        
         case 1:
             for(i; i<SIZE; i++){
                 add_new_car(car_directory, &count,i);
                     cout<<"Y- ADD A NEW CAR?"<<endl;
                     cout<<"N- GO TO MENU?"<<endl;
                     cout<<"Enter choice: ";
                     cin>>letter2;
                 switch(letter2){
                     case 'Y':
                         *iptr+1;
                         break;
                     case 'N':
                         *iptr+1;
                         goto menu;
                }
                
            }
             
            //goto menu;
        case 2:
            
            delete_car(car_directory);
            goto menu;
                    
          case 3:
              if(count == 0){
                  cout<<"There are no available cars in the directory!!"<<endl;
                  goto menu;
              }

              else{
                  cout<<"Available cars in the Directory Are: "<<endl;
                  list_cars(car_directory);
                 goto menu;
            }
        case 4:
            cout<<"A- Search according to ID: "<<endl;
            cout<<"B- Search according to owner Name: "<<endl;
            cout<<"Select a letter: ";
            cin>>letter;
            switch(letter){
                case 'A':
                    id_search(car_directory);
                    goto menu;
                case 'B':
                    name_search(car_directory);
                    goto menu;
            }
            goto menu;
        case 5:
            update_car(car_directory);
            goto menu;
            
        case 6:
            id_sort(car_directory);
            goto menu;
        case 7:
            name_sort(car_directory);
            goto menu;
        case 8:
            exit(1);
                 
         default:
             cout<<"Wrong choice, select a choice between 1 and 8"<<endl;
              goto menu;
    }


    return 0;
    //system("PAUSE");
    
}

void add_new_car(struct car car_directory[SIZE], int *ptr, int i){
    //for(int i=0; i<SIZE; i++){
    //int i;
        cout<<"--------------------------------------------------------------------------"<<endl;
        cout<<"Enter ID: ";
        cin>>car_directory[i].ID;
        cout<<"Enter Name: ";
        cin>>car_directory[i].owner_name;
        cout<<"Enter Surname: ";
        cin>>car_directory[i].owner_surname;
        cout<<"Enter Car Model: ";
        cin>>car_directory[i].model;
        cout<<"Enter Car Registration date: "<<endl;
        cout<<"Day: ";
        cin>>car_directory[i].reg_date.day;
        cout<<"Month: ";
        cin>>car_directory[i].reg_date.month;
        cout<<"Year: ";
        cin>>car_directory[i].reg_date.year;
        cout<<"Enter Next service date: "<<endl;
        cout<<"Day: ";
        cin>>car_directory[i].ns_date.day;
        cout<<"Month: ";
        cin>>car_directory[i].ns_date.month;
        cout<<"Year: ";
        cin>>car_directory[i].ns_date.year;
        cout<<"-------------------------------------------------------------------------"<<endl;
        i++;
        
        *ptr = 1;
    //}
    
}
void list_cars(struct car car_directory[SIZE]){
    for(int i=0; i<SIZE; i++){
//        if(car_directory[i].ID==0)
//            break;
        if(car_directory[i].ID == 0){
            
        }
        else{
                cout<<"--------------------------CAR LIST------------------------"<<endl;
                cout<<i+1<<"."<<"Car"<<endl;
                cout<<"ID: ";                                 cout<<car_directory[i].ID<<endl;
                cout<<"Name: ";                             cout<<car_directory[i].owner_name<<endl;
                cout<<"Surname: ";                             cout<<car_directory[i].owner_surname<<endl;
                cout<<"Car Model: ";                         cout<<car_directory[i].model<<endl;
                cout<<"Car Registration date: "<<endl;
                cout<<"Day: ";                                cout<<car_directory[i].reg_date.day<<"\t";
                cout<<"Month: ";                             cout<<car_directory[i].reg_date.month<<"\t";
                cout<<"Year: ";                             cout<<car_directory[i].reg_date.year<<endl;
                cout<<"Next service date: "<<endl;
                cout<<"Day: ";                                cout<<car_directory[i].ns_date.day<<"\t";
                cout<<"Month: ";                             cout<<car_directory[i].ns_date.month<<"\t";
                cout<<"Year: ";                             cout<<car_directory[i].ns_date.year<<endl;
                cout<<"-----------------------------------------------------------"<<endl;
        }

//        if(car_directory[i+1].ID == 0){
//            break;
//        }
    }
    
}
void id_search(struct car car_directory[SIZE]){
    cout<<"\n Enter id of the Car youre looking for: ";
    int ID;
    cin>>ID;
    for(int i=0; i<SIZE; i++){
        if(ID == car_directory[i].ID){
            cout<<"--------------------------CAR LIST------------------------"<<endl;
            cout<<"ID: ";                                 cout<<car_directory[i].ID<<endl;
            cout<<"Name: ";                             cout<<car_directory[i].owner_name<<endl;
            cout<<"Surname: ";                             cout<<car_directory[i].owner_surname<<endl;
            cout<<"Car Model: ";                         cout<<car_directory[i].model<<endl;
            cout<<"Car Registration date: "<<endl;
            cout<<"Day: ";                                cout<<car_directory[i].reg_date.day<<"\t";
            cout<<"Month: ";                             cout<<car_directory[i].reg_date.month<<"\t";
            cout<<"Year: ";                             cout<<car_directory[i].reg_date.year<<endl;
            cout<<"Next service date: "<<endl;
            cout<<"Day: ";                                cout<<car_directory[i].ns_date.day<<"\t";
            cout<<"Month: ";                             cout<<car_directory[i].ns_date.month<<"\t";
            cout<<"Year: ";                             cout<<car_directory[i].ns_date.year<<endl;
            cout<<"-----------------------------------------------------------"<<endl;
        }
        if(i==SIZE-1 && ID !=car_directory[i].ID){
            cout<<"YOU DO NOT HAVE A CAR WITH US!!";
        }

    }
}


void name_search(struct car car_directory[SIZE]){
    cout<<"\n Enter the owner name of the Car youre looking for: ";
    char name[20];int count = 0;
    cin>>name;
    
    for(int i=0; i<SIZE; i++){
        
        int j=0; int valid = 0;
        if(name==car_directory[i].owner_name){
            cout<<"--------------------------CAR LIST------------------------"<<endl;
            cout<<"ID: ";                                 cout<<car_directory[i].ID<<endl;
            cout<<"Name: ";                             cout<<car_directory[i].owner_name<<endl;
            cout<<"Surname: ";                             cout<<car_directory[i].owner_surname<<endl;
            cout<<"Car Model: ";                         cout<<car_directory[i].model<<endl;
            cout<<"Car Registration date: "<<endl;
            cout<<"Day: ";                                cout<<car_directory[i].reg_date.day<<"\t";
            cout<<"Month: ";                             cout<<car_directory[i].reg_date.month<<"\t";
            cout<<"Year: ";                             cout<<car_directory[i].reg_date.year<<endl;
            cout<<"Next service date: "<<endl;
            cout<<"Day: ";                                cout<<car_directory[i].ns_date.day<<"\t";
            cout<<"Month: ";                             cout<<car_directory[i].ns_date.month<<"\t";
            cout<<"Year: ";                             cout<<car_directory[i].ns_date.year<<endl;
            cout<<"-----------------------------------------------------------"<<endl;
            count =1;
        
        }
    }
    if(count =0){
        cout<<"YOU DONT HAVE A CAR WITH US!!"<<endl;
    }
}

void id_sort(struct car car_directory[SIZE]){

    for(int i=0; i<SIZE-1; i++){
        for(int j=0; j<SIZE-i-1; j++){
            int tempID, temp_reg_day, temp_reg_month, temp_reg_year, temp_ns_year, temp_ns_day, temp_ns_month;
            char temp[20];
            if(car_directory[j].ID>car_directory[j+1].ID){
                //---------------ID---------------//
                tempID=car_directory[j].ID;
                car_directory[j].ID = car_directory[j+1].ID;
                car_directory[j+1].ID = tempID;
                //------------------------------//
                //------------REGISTRATION DATES-------//
                temp_reg_day = car_directory[j].reg_date.day;
                car_directory[j].reg_date.day = car_directory[j+1].reg_date.day;
                car_directory[j+1].reg_date.day = temp_reg_day;
            
                temp_reg_month = car_directory[j].reg_date.month;
                car_directory[j].reg_date.month = car_directory[j+1].reg_date.month;
                car_directory[j+1].reg_date.month = temp_reg_month;
                
                temp_reg_year = car_directory[j].reg_date.year;
                car_directory[j].reg_date.year = car_directory[j+1].reg_date.year;
                car_directory[j+1].reg_date.year = temp_reg_year;
                //--------------------------------------//
                //------------NEXT SERVICE DATES-------//
                temp_ns_day = car_directory[j].ns_date.day;
                car_directory[j].ns_date.day = car_directory[j+1].ns_date.day;
                car_directory[j+1].ns_date.day = temp_ns_day;
            
                temp_ns_month = car_directory[j].ns_date.month;
                car_directory[j].ns_date.month = car_directory[j+1].ns_date.month;
                car_directory[j+1].ns_date.month = temp_ns_month;
                
                temp_ns_year = car_directory[j].ns_date.year;
                car_directory[j].ns_date.year = car_directory[j+1].ns_date.year;
                car_directory[j+1].ns_date.year = temp_ns_year;
                //--------------------------------------//
                //--------------------OWNER NAME-------------------//
                strcpy(temp, car_directory[j].owner_name);
                strcpy(car_directory[j].owner_name, car_directory[j+1].owner_name);
                strcpy(car_directory[j+1].owner_name, temp);
                //---------------------------------------------------//
                //-----------------OWNER SURNAME-----------------//
                strcpy(temp, car_directory[j].owner_surname);
                strcpy(car_directory[j].owner_surname,car_directory[j+1].owner_surname);
                strcpy(car_directory[j+1].owner_surname, temp);
                //-----------------------------------------------//
                //---------------------MODEL---------------------//
                strcpy(temp, car_directory[j].model);
                strcpy(car_directory[j].model,car_directory[j+1].model);
                strcpy(car_directory[j+1].model, temp);
                //-----------------------------------------------//

            }
            
        }
    }

    cout<<"--------------SORTED CAR INFORMATION(ID)--------------------"<<endl;
    for(int i=0; i<SIZE; i++){
        if(car_directory[i].ID == 0){
            
        }
        else{
            cout<<i+1<<"."<<"Car"<<endl;
            cout<<"ID: ";                                 cout<<car_directory[i].ID<<endl;
            cout<<"Name: ";                             cout<<car_directory[i].owner_name<<endl;
            cout<<"Surname: ";                             cout<<car_directory[i].owner_surname<<endl;
            cout<<"Car Model: ";                         cout<<car_directory[i].model<<endl;
            cout<<"Car Registration date: "<<endl;
            cout<<"Day: ";                                cout<<car_directory[i].reg_date.day<<"\t";
            cout<<"Month: ";                             cout<<car_directory[i].reg_date.month<<"\t";
            cout<<"Year: ";                             cout<<car_directory[i].reg_date.year<<endl;
            cout<<"Next service date: "<<endl;
            cout<<"Day: ";                                cout<<car_directory[i].ns_date.day<<"\t";
            cout<<"Month: ";                             cout<<car_directory[i].ns_date.month<<"\t";
            cout<<"Year: ";                             cout<<car_directory[i].ns_date.year<<endl;
            cout<<"------------------END OF LIST-----------------------------"<<endl;
        }

//        if(car_directory[i+1].ID == 0){
//            break;
//        }
    }
    
    
}
void name_sort(struct car car_directory[SIZE]){

    for(int i=0; i<SIZE-1; i++){
        for(int j=0; j<SIZE-i-1; j++){
            int tempID, temp_reg_day, temp_reg_month, temp_reg_year, temp_ns_year, temp_ns_day, temp_ns_month;
            char temp[20];
            if(strcmp(car_directory[j].owner_name,car_directory[j+1].owner_name)>0){
                //---------------ID---------------//
                tempID=car_directory[j].ID;
                car_directory[j].ID = car_directory[j+1].ID;
                car_directory[j+1].ID = tempID;
                //------------------------------//
                //------------REGISTRATION DATES-------//
                temp_reg_day = car_directory[j].reg_date.day;
                car_directory[j].reg_date.day = car_directory[j+1].reg_date.day;
                car_directory[j+1].reg_date.day = temp_reg_day;
            
                temp_reg_month = car_directory[j].reg_date.month;
                car_directory[j].reg_date.month = car_directory[j+1].reg_date.month;
                car_directory[j+1].reg_date.month = temp_reg_month;
                
                temp_reg_year = car_directory[j].reg_date.year;
                car_directory[j].reg_date.year = car_directory[j+1].reg_date.year;
                car_directory[j+1].reg_date.year = temp_reg_year;
                //--------------------------------------//
                //------------NEXT SERVICE DATES-------//
                temp_ns_day = car_directory[j].ns_date.day;
                car_directory[j].ns_date.day = car_directory[j+1].ns_date.day;
                car_directory[j+1].ns_date.day = temp_ns_day;
            
                temp_ns_month = car_directory[j].ns_date.month;
                car_directory[j].ns_date.month = car_directory[j+1].ns_date.month;
                car_directory[j+1].ns_date.month = temp_ns_month;
                
                temp_ns_year = car_directory[j].ns_date.year;
                car_directory[j].ns_date.year = car_directory[j+1].ns_date.year;
                car_directory[j+1].ns_date.year = temp_ns_year;
                //--------------------------------------//
                //--------------------OWNER NAME-------------------//
                strcpy(temp, car_directory[j].owner_name);
                strcpy(car_directory[j].owner_name, car_directory[j+1].owner_name);
                strcpy(car_directory[j+1].owner_name, temp);
                //---------------------------------------------------//
                //-----------------OWNER SURNAME-----------------//
                strcpy(temp, car_directory[j].owner_surname);
                strcpy(car_directory[j].owner_surname,car_directory[j+1].owner_surname);
                strcpy(car_directory[j+1].owner_surname, temp);
                //-----------------------------------------------//
                //---------------------MODEL---------------------//
                strcpy(temp, car_directory[j].model);
                strcpy(car_directory[j].model,car_directory[j+1].model);
                strcpy(car_directory[j+1].model, temp);
                //-----------------------------------------------//

            }
            
        }
    }

    cout<<"--------------SORTED CAR INFORMATION(NAME)--------------------"<<endl;
    for(int i=0; i<SIZE; i++){
        if(strlen(car_directory[i].owner_name)==0){
            
        }
        else{
            cout<<i+1<<"."<<"Car"<<endl;
            cout<<"ID: ";                                 cout<<car_directory[i].ID<<endl;
            cout<<"Name: ";                             cout<<car_directory[i].owner_name<<endl;
            cout<<"Surname: ";                             cout<<car_directory[i].owner_surname<<endl;
            cout<<"Car Model: ";                         cout<<car_directory[i].model<<endl;
            cout<<"Car Registration date: "<<endl;
            cout<<"Day: ";                                cout<<car_directory[i].reg_date.day<<"\t";
            cout<<"Month: ";                             cout<<car_directory[i].reg_date.month<<"\t";
            cout<<"Year: ";                             cout<<car_directory[i].reg_date.year<<endl;
            cout<<"Next service date: "<<endl;
            cout<<"Day: ";                                cout<<car_directory[i].ns_date.day<<"\t";
            cout<<"Month: ";                             cout<<car_directory[i].ns_date.month<<"\t";
            cout<<"Year: ";                             cout<<car_directory[i].ns_date.year<<endl;
            cout<<"------------------END OF LIST-----------------------------"<<endl;
        }
        
//        if(car_directory[i+1].ID == 0){
//            break;
//        }
        
    }
    
    
}
void update_car(struct car car_directory[SIZE]){
    int ID;int count=0;
    cout<<"Enter ID of the car to be updated: ";
    cin>>ID;
    for(int i=0; i<SIZE; i++){
        int tempID;
        if(ID == car_directory[i].ID)
        {
            cout<<"--------------------------CAR DETAILS TO BE UPDATED------------------------"<<endl;
            cout<<"ID: ";                                 cout<<car_directory[i].ID<<endl;
            cout<<"Name: ";                             cout<<car_directory[i].owner_name<<endl;
            cout<<"Surname: ";                             cout<<car_directory[i].owner_surname<<endl;
            cout<<"Car Model: ";                         cout<<car_directory[i].model<<endl;
            cout<<"Car Registration date: "<<endl;
            cout<<"Day: ";                                cout<<car_directory[i].reg_date.day<<"\t";
            cout<<"Month: ";                             cout<<car_directory[i].reg_date.month<<"\t";
            cout<<"Year: ";                             cout<<car_directory[i].reg_date.year<<endl;
            cout<<"Next service date: "<<endl;
            cout<<"Day: ";                                cout<<car_directory[i].ns_date.day<<"\t";
            cout<<"Month: ";                             cout<<car_directory[i].ns_date.month<<"\t";
            cout<<"Year: ";                             cout<<car_directory[i].ns_date.year<<endl;
            count=1;
            cout<<"--------------------------------------------------------------------------"<<endl;
            
            cout<<"Enter ID: ";
            cin>>car_directory[i].ID;
            cout<<"Enter Name: ";
            cin>>car_directory[i].owner_name;
            cout<<"Enter Surname: ";
            cin>>car_directory[i].owner_surname;
            cout<<"Enter Car Model: ";
            cin>>car_directory[i].model;
            cout<<"Enter Car Registration date: "<<endl;
            cout<<"Day: ";
            cin>>car_directory[i].reg_date.day;
            cout<<"Month: ";
            cin>>car_directory[i].reg_date.month;
            cout<<" Year: ";
            cin>>car_directory[i].reg_date.year;
            cout<<"Enter Next service date: "<<endl;
            cout<<"Day: ";
            cin>>car_directory[i].ns_date.day;
            cout<<"Month: ";
            cin>>car_directory[i].ns_date.month;
            cout<<"Year: ";
            cin>>car_directory[i].ns_date.year;
            
            cout<<"CAR DETAILS HAS BEEN UPDATED!!"<<endl;
            //cout<<"----------------------------------------------------------------------"<<endl;
        }
//        if(i == SIZE-1 && ID != car_directory[i].ID)
//            cout<<"CAR COULD NOT BE FOUND!!"<<endl;
//            cout<<"-----------------------------------------------------------------------"<<endl;
        
    }
    if(count==0){
        cout<<"CAR COULD NOT BE FOUND!!";
        cout<<"------------------------------------------------------------------------"<<endl;
    }
        
}

void delete_car(struct car car_directory[SIZE]){
    int ID;
    cout<<"Enter ID of the car to be deleted: ";
    cin>>ID;
    for(int i=0; i<SIZE; i++){
        int tempID;
        char null[20]="";
        if(ID == car_directory[i].ID)
        {
            cout<<"--------------------------CAR DETAILS TO BE DELETED------------------------"<<endl;
            cout<<"ID: ";                                 cout<<car_directory[i].ID<<endl;
            cout<<"Name: ";                             cout<<car_directory[i].owner_name<<endl;
            cout<<"Surname: ";                             cout<<car_directory[i].owner_surname<<endl;
            cout<<"Car Model: ";                         cout<<car_directory[i].model<<endl;
            cout<<"Car Registration date: "<<endl;
            cout<<"Day: ";                                cout<<car_directory[i].reg_date.day<<"\t";
            cout<<"Month: ";                             cout<<car_directory[i].reg_date.month<<"\t";
            cout<<"Year: ";                             cout<<car_directory[i].reg_date.year<<endl;
            cout<<"Next service date: "<<endl;
            cout<<"Day: ";                                cout<<car_directory[i].ns_date.day<<"\t";
            cout<<"Month: ";                             cout<<car_directory[i].ns_date.month<<"\t";
            cout<<"Year: ";                             cout<<car_directory[i].ns_date.year<<endl;
            cout<<"--------------------------------------------------------------------------"<<endl;
            
//            car_directory[i].ID = NULL;
//            car_directory[i].reg_date.day= NULL;
//            car_directory[i].reg_date.month= NULL;
//            car_directory[i].reg_date.year= NULL;
            strcpy(car_directory[i].owner_name, null);
            strcpy(car_directory[i].owner_surname, null);
            strcpy(car_directory[i].model, null);
            strcpy(car_directory[i].owner_name, null);
            strcpy(car_directory[i].owner_name, null);

            
            cout<<"CAR DETAILS HAS BEEN DELETED!!"<<endl;
            cout<<"----------------------------------------------------------------------"<<endl;
        }
        if(i == SIZE-1 && ID != car_directory[i].ID)
            cout<<"CAR COULD NOT BE FOUND!!"<<endl;
            //cout<<"-----------------------------------------------------------------------"<<endl;
        
    }
    
}

            
