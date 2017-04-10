#include <iostream>
#include <vector>
#include "robot_part.h"
#include "utility.h"
using namespace std;

int main() {

  Head *head;
  Arm *arm;
  Torso *torso;
  Locomotor *locomotor;
  Battery *battery;
  Robot_model *model;
  Customer *customer;
  Sale_associate *sale_associate;
  Order *order;
 \
/*
  while(true) {
    switch (get_int(R"(
   Testing Robot Parts

(1) Create Head
(2) Create Arm
(3) Create Torso
(4) Create Locomotor
(5) Create Battery
(0) Exit

Selection? )", 0, 5)) {
*/
vector <Robot_model> models;
vector<Head> heads;
vector<Torso> torsos;
vector<Arm> arms;
vector<Battery> batteries;
vector<Locomotor> locomotors;

int option;
int part;
string model_name;
int model_number;
do
{
cout << "1) Create a Model" << endl << "2) Create parts" << endl << "3) List models" << endl << "4) Create a customer"<< endl<< "5) Create a sale associate" << endl<< "6) Create an order" <<endl<<"9) to exit" << endl;
cin >> option;
cin.ignore();

switch (option)
{
case 1:


cout << "Enter the Model's name" << endl;
getline(cin,model_name);

cout << "Enter the model's number" << endl;
cin >> model_number;
cin.ignore();

// HEADS
int head_i;
cout << "Enter number of the head to add to your model" << endl;
cout << "Heads: " << endl;

for (int i = 0; i < heads.size(); i++)
{
cout << i+1 << ")" << heads[i] << endl;

}
cin >> head_i;
cin.ignore();

//TORSOS
int torso_i;
cout << "Enter number of the torso to add to your model" << endl;
cout << "Torsos: " << endl;

for (int i = 0; i < torsos.size(); i++)
{
cout << i+1 << ")" << torsos[i] << endl;

}
cin >> torso_i;
cin.ignore();

//ARMS
int arm_i;
cout << "Enter number of the arm to add to your model" << endl;
cout << "Arms: " << endl;

for (int i = 0; i < arms.size(); i++)
{
cout << i+1 << ")" << arms[i] << endl;

}
cin >> arm_i;
cin.ignore();

//Battery
int battery_i;
cout << "Enter number of the battery to add to your model" << endl;
cout << "Batteries: " << endl;

for (int i = 0; i < batteries.size(); i++)
{
cout << i+1 << ")" << batteries[i] << endl;

}
cin >> battery_i;
cin.ignore();

//LOCOMOTORS
int locomotor_i;
cout << "Enter number of the locomotor to add to your model" << endl;
cout << "Locomotors: " << endl;

for (int i = 0; i < locomotors.size(); i++)
{
cout << i+1 << ")" << locomotors[i] << endl;

}
cin >> locomotor_i;
cin.ignore();


 model= new Robot_model(model_name, model_number,heads[head_i-1],torsos[torso_i -1],arms[arm_i -1],locomotors[locomotor_i -1],batteries[battery_i -1]);
models.push_back(*model);

break;


//

case 2:
{
int part;
cout << endl;
cout << "1) Head" << endl << "2) Arm " << endl << "3) Torso" << endl << "4) Locomotor" << endl << "5) Battery" << endl;
cout << endl;
cout << "What part do you want to create and add to the model? 0 to exit or to create another model" << endl;
cin >> part;
cin.ignore();
switch (part)
{
do{

      case 0: // Exit
        exit(0);
      case 1: // Head
        head = new Head{
          get_string("Enter this head's name: "),
          get_int("Enter this head's model number: "),
          get_double("Enter this head's cost: "),
          get_string("Enter description: "),
          get_double("Enter this head's power: ")
        };
        cout << *head << endl;
        heads.push_back(*head);
        break;
      case 2:
        arm = new Arm{
          get_string("Enter this arm's name: "),
          get_int("Enter this arm's model number: "),
          get_double("Enter this arm's cost: "),
          get_string("Enter description: "),
          get_double("Enter maximum power: ")
        };
        cout << *arm << endl;
        arms.push_back(*arm);
        break;
      case 3:
        torso = new Torso{
          get_string("Enter this torso's name: "),
          get_int("Enter this torso's model number: "),
          get_double("Enter this torso's cost: "),
          get_string("Enter description: "),
          get_int("Enter maximum # of arms (0 to 2): ", 0, 2),
          get_int("Enter maximum # of batteries (1 to 3): ", 1, 3)
        };
        cout << *torso << endl;
        torsos.push_back(*torso);
        break;
      case 4:
        locomotor = new Locomotor{
          get_string("Enter this locomotor's name: "),
          get_int("Enter this locomotor's model number: "),
          get_double("Enter this locomotor's cost: "),
          get_string("Enter description: "),
          get_double("Enter maximum power: ")
        };
        cout << *locomotor << endl;
        locomotors.push_back(*locomotor);
        break;
      case 5:
        battery = new Battery{
          get_string("Enter this battery's name: "),
          get_int("Enter this battery's model number: "),
          get_double("Enter this battery's cost: "),
          get_string("Enter description: "),
          get_double("Enter maximum energy: "),
          get_double("Enter power available: ")
        };
        cout << *battery << endl;
        batteries.push_back(*battery);
        break;
      default:
        cerr << "Impossible menu selection ===" << endl << endl;

  }while(part !=0);
  }
  break;
  }

  case 3:

  {
  cout << "List of models: " <<  endl;
  for(int i =0; i<models.size();i++)
{
cout << models[i];
cout << endl;
}
cout << endl;
break;
}

case 4:
{

string name;
int customer_number;
string phone_number;
string email_address;
cout << "What's your name?" << endl;
getline(cin,name);

cout << "Customer number?" << endl;
cin >> customer_number;
cin.ignore();
cout<< "Phone number? "<<endl;
getline(cin,phone_number);
cout << "Email? " << endl;
getline(cin,email_address);

customer = new Customer(name,customer_number,phone_number,email_address);
//customer
break;
}
case 5:
{
string name;
int employee_number;
cout << "What's your name? "<<endl;
getline(cin,name);
cout << "Employee number? " << endl;
cin >> employee_number;
cin.ignore();

sale_associate = new Sale_associate(name,employee_number);
//sale associate
break;
}

case 6:
{
int order_number;
string date;

int status;


cin.ignore();
cout << "date? "<< endl;
getline(cin,date);
cout<< "Choose customer: "<< endl;
//get customers

cout << "Choose associate" << endl;

//diplay associate

cout << "Choose robot model" << endl;
//display modes

cout << "How many of this model would you like? "<< endl;
cin>>order_number;

cout << "status? " << endl;
cin >> status;
cin.ignore();

break;

//order

}

}
  }while(option != 9);
}
