
#include <vector>
#include <string>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_JPEG_Image.H>
#include <climits>
#include <exception>
#include <FL/Fl.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Input.H>
#include <cstdlib>
#include <FL/Fl_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Robot_part {
  public:
    Robot_part(string description, double cost, int model_number, string name)
        : _description{description}, _cost{cost}, _model_number{model_number}, _name{name} { }
    string name() const {return _name;}
    int model_number() const {return _model_number;}
    double cost() const {return _cost;}
    string description() const {return _description;}
  protected:
    string _name;
    int _model_number;
    double _cost;
    string _description;
};

class Head : public Robot_part {
  public:
    Head(string name,
         int model_number,
         double cost,
         string description,
         double power)
       : Robot_part(description, cost, model_number, name),
         _power{power} { }
/*
    Head override (ifstream& ist){
    (ist.open("robot.txt"));
    ist >> _name; ist >> _model_number; ist >> _cost; ist >> _description; ist>> _power;
    Head(_name,_model_number,_cost,_description,_power);
    }*/

    double power() const {return _power;}
    void save(ofstream& ost)
    { ost.open("robot.txt",ios_base::app);
    ost << "2"<<endl; ost <<"1"<<endl; ost<<_name << endl; ost << _model_number << endl; ost << _cost << endl;ost << _description << endl; ost << _power << endl;
    ost.close();
    }

  private:
    double _power;
};

ostream& operator<< (ostream& ost, const Head& head) {
  ost << "Head " << head.name() << " (model " << head.model_number() << ") "
      << "costs $" << head.cost()
      << " and uses " << head.power() << " watts" << endl;
  ost << head.description();
  return ost;
}

class Locomotor : public Robot_part {
  public:
    Locomotor(string name,
              int model_number,
              double cost,
              string description,
              double max_power)
            : Robot_part(description, cost, model_number, name),
              _max_power{max_power} { }
    double max_power() const {return _max_power;}
   void save(ofstream& ost)
    { ost.open("robot.txt",ios_base::app);
    ost << "2"<<endl; ost <<"4"<<endl;ost << _name << endl; ost << _model_number << endl; ost << _cost << endl;ost << _description << endl; ost << _max_power << endl;
    ost.close();
    }
  private:
    double _max_power;
};

ostream& operator<< (ostream& ost, const Locomotor& locomotor) {
  ost << "Locomotor " << locomotor.name() << " (model " << locomotor.model_number() << ") "
      << "costs $" << locomotor.cost()
      << " and uses up to " << locomotor.max_power() << " watts" << endl;
  ost << locomotor.description();
  return ost;
}

class Arm : public Robot_part {
  public:
    Arm(string name,
        int model_number,
        double cost,
        string description,
        double max_power)
      : Robot_part(description, cost, model_number, name),
        _max_power{max_power} { }
    double max_power() const {return _max_power;}
   void save(ofstream& ost)
    { ost.open("robot.txt",ios_base::app);
    ost << "2"<<endl; ost <<"2"<<endl;ost << _name << endl; ost << _model_number << endl; ost << _cost << endl;ost << _description << endl; ost << _max_power << endl;
    ost.close();
    }
  private:
    double _max_power;
};

ostream& operator<< (ostream& ost, const Arm& arm) {
  ost << "Arm " << arm.name() << " (model " << arm.model_number() << ") "
      << "costs $" << arm.cost()
      << " and uses up to " << arm.max_power() << " watts" << endl;
  ost << arm.description();
  return ost;
}

class Torso : public Robot_part {
  public:
    Torso(string name,
          int model_number,
          double cost,
          string description,
          int max_arms,
          int battery_compartments)
        : Robot_part(description, cost, model_number, name),
          _max_arms{max_arms},
          _battery_compartments{battery_compartments} { }
    int max_arms() const {return _max_arms;}
    int battery_compartments() const {return _battery_compartments;}
  void save(ofstream& ost)
    { ost.open("robot.txt",ios_base::app);
    ost << "2"<<endl; ost <<"3"<<endl;ost << _name << endl; ost << _model_number << endl; ost << _cost << endl;ost << _description << endl; ost << _max_arms << endl; ost << _battery_compartments << endl;
    ost.close();
    }

  private:
    int _max_arms;
    int _battery_compartments;
};

ostream& operator<< (ostream& ost, const Torso& torso) {
  ost << "Torso " << torso.name() << " (model " << torso.model_number() << ") "
      << "costs $" << torso.cost()
      << " and can hold " << torso.max_arms() << " arms and "
      << torso.battery_compartments() << " batteries" << endl;
  ost << torso.description();
  return ost;
}

class Battery : public Robot_part {
  public:
    Battery(string name,
            int model_number,
            double cost,
            string description,
            double max_energy,
            double power_available)
          : Robot_part(description, cost, model_number, name),
            _max_energy{max_energy},
            _power_available{power_available} { }
    double max_energy() const {return _max_energy;}
    double power_available() const {return _power_available;}
  void save(ofstream& ost)
    { ost.open("robot.txt",ios_base::app);
    ost << "2"<<endl; ost <<"5"<<endl;ost << _name << endl; ost << _model_number << endl; ost << _cost << endl;ost << _description << endl; ost << _max_energy << endl; ost <<_power_available <<endl;
    ost.close();
    }

  private:
    double _max_energy;
    double _power_available;
};

ostream& operator<< (ostream& ost, const Battery& battery) {
  ost << "Battery " << battery.name() << " (model " << battery.model_number() << ") "
      << "costs $" << battery.cost()
      << ", driving " << battery.power_available() << " watts "
      << "and containing " << battery.max_energy() << " kWh"  << endl;
  ost << battery.description();
  return ost;
}

class Robot_model {
  public:
    Robot_model(string name, int model_number, Head head, Torso torso, Arm arm , Locomotor locomotor, Battery battery)
        : _name{name}, _model_number{model_number}, _head{head}, _torso{torso},_arm{arm},_locomotor{locomotor},_battery{battery} { }
    string name() const {return _name;}
    int model_number() const {return _model_number;}
    void head() const{ cout << _head << endl;cout << endl;}
    void arm() const{cout << _arm << endl; cout << endl;}
    void torso() const{cout << _torso << endl; cout << endl;}
    void locomotor() const{cout << _locomotor<< endl; cout << endl;}
    void battery() const{cout << _battery << endl; cout << endl;}
    double cost() const { double total_cost = _head.cost() + _arm.cost() + _torso.cost() + _locomotor.cost() + _battery.cost(); return total_cost;
}

void save(ofstream& ost)
{
ost.open("robot.txt",ios_base::app);
ost << "1"<<endl; ost << _name << endl; ost << _model_number << endl; ost << _head <<endl; ost << _torso << endl; ost << _arm << endl; ost << _locomotor << endl; ost << _battery << endl;
}
  protected:
    string _name;
    int _model_number;
    Head _head;
    Arm _arm;
    Torso _torso;
    Locomotor _locomotor;
    Battery _battery;
};


ostream& operator<< (ostream& ost, const Robot_model& model) {
  ost << "Robot Model " << model.name() << " (model " << model.model_number() << ") "
     << "With parts: " <<  endl;
     model.head();
     model.arm();
     model.torso();
     model.locomotor();
     model.battery();

  ost << "Total cost of the model is: $"<< model.cost() << endl;


  return ost;
}

class Customer
{
private:
	string _name;
	int _customer_number;
	string _phone_number;
	string _email_address;

public:
	Customer(string name, int customer_number,string phone_number,string email_address) : _name{name},_customer_number{customer_number},_phone_number{phone_number},_email_address{email_address} {}
    string name() const { return _name;}
    int customer_number() const {return _customer_number;}
    string phone_number() const {return _phone_number;}
    string email_address() const {return _email_address;}

    void save(ofstream& ost)
    {
    ost << "4" << endl;ost << _name << endl; ost << _customer_number << endl; ost << _phone_number << endl; ost << _email_address << endl;
    }

};
ostream& operator<< (ostream& ost, const Customer& customer) {
  ost << "Customer " << customer.name() << " ( " <<customer.customer_number() << ") "
     << "Phone: " << customer.phone_number() << " Email: " << customer.email_address() << endl;

  return ost;
}

class Sale_associate
{
private:
	string _name;
	int _employee_number;

public:
	Sale_associate(string name, int employee_number): _name{name},_employee_number{employee_number}{}

    void save(ofstream& ost)
    {
    ost << "5"<< endl;ost << _name << endl; ost << _employee_number << endl;
    }

    string name() const {return _name;}
    int employee_number() const {return _employee_number;}
};


ostream& operator<< (ostream& ost, const Sale_associate& sale_associate) {
  ost << "Sale associate " << sale_associate.name() << " Employee n* " << sale_associate.employee_number() << endl;

  return ost;
}


class Order
{
private:
	int _order_number;
	string _date;
	Customer _customer;
	Sale_associate _sale_associate;
	Robot_model _model;
	int _status;


public:
	Order(int order_number,string date,Customer customer,Sale_associate sale_associate,Robot_model model,int status) : _order_number{order_number},_date{date},_customer{customer},_sale_associate{sale_associate},_model{model},_status{status} {}

	double robot_cost() {return _model.cost();}
	double extended_price() {return _model.cost() * _order_number;}

    int order_number() const {return _order_number;}
    string date() const {return _date;}
    Customer customer() const {return _customer;}
    Sale_associate sale_associate() const {return _sale_associate;}
    Robot_model model() const {return _model;}
    int status() const {return _status;}

    void save(ofstream& ost)
    {
    ost <<"6"<<endl;ost << _order_number << endl; ost << _date << endl; ost << _customer << endl; ost << _sale_associate << endl; ost << _model << endl; ost << _status << endl;
    }

};

ostream& operator<< (ostream& ost, const Order& order) {
  ost << "Order placed on " << order.date() << " By " << order.customer() << endl;

  return ost;
}
//
string get_string(string prompt) {
  string result = "";
  cout << prompt;
  getline(cin, result);
  return result;
}

//
// Skip all characters in the STDIN buffer up to and including the next newline
// For use after a cin stream operation, to clear invalid text and the newline
//
void skip() {
  if (cin.fail())
    cin.clear();
  cin.ignore(INT_MAX, '\n');
}

//
// Return any valid integer from the user
//
int get_int(string prompt) {
  int result = 0;
  while (true) {
    cout << prompt;
    cin >> result;
    bool success = cin.good();
    skip();
    if (success) return result;
    cerr << "### Not an integer!" << endl;
  }
}

//
// Return any valid integer between min_int and max_int, inclusive
//
int get_int(string prompt, int min_int, int max_int) {
  int result = min_int - 1;
  while (true) {
    result = get_int(prompt);
    if (min_int <= result && result <= max_int) return result;
    cerr << "### Integer must be between " << min_int << " and " << max_int << "!\n";
  }
}

//
// Return any valid double from the user
//
double get_double(string prompt) {
  double result = 0.0;
  while (true) {
    cout << prompt;
    cin >> result;
    bool success = cin.good();
    skip();
    if (success) return result;
    cerr << "### Not a number!" << endl;
  }
}

// /////////////////////////////////////////
// F I L E   I / O
// /////////////////////////////////////////

//
// Return any string from the file, including a simple \n
//
string get_string(istream& ist) {
  string result = "";
  getline(ist, result);
  return result;
}

//
// Skip all characters in the input buffer up to and including the next newline
// For use after a input stream operation, to clear invalid text and the newline
//
void skip(istream& ist) {
  if (ist.fail())
    ist.clear();
  ist.ignore(INT_MAX, '\n');
}

//
// Return any valid integer from the file
//
int get_int(istream& ist) {
  int result = 0;
  ist >> result;
  skip(ist);
  return result;
}

//
// Return any valid double from the file
//
double get_double(istream& ist) {
  double result = 0.0;
  ist >> result;
  skip(ist);
  return result;
}

Head *head;
  Arm *arm;
  Torso *torso;
  Locomotor *locomotor;
  Battery *battery;
  Robot_model *model;
  Customer *customer;
  Sale_associate *sale_associate;
  Order *order;


vector <Robot_model> models;
vector<Head> heads;
vector<Torso> torsos;
vector<Arm> arms;
vector<Battery> batteries;
vector<Locomotor> locomotors;
vector<Customer> customers;
vector<Sale_associate> sale_associates;
vector<Order> orders;
ofstream ost;
ifstream ist;

string model_name;
int model_number;

void HeadCB(Fl_Widget *w, void *p) {

 head = new Head{

          fl_input("Head's name: ",""),atoi(fl_input("Head's model number: ","")),atof(fl_input("Head's cost: ","")),fl_input("Head's description: ",""),atof(fl_input("Head's power: ",""))

        };
        cout << *head << endl;
        head->save(ost);
        heads.push_back(*head);


}

 void ArmCB(Fl_Widget *w, void *p) {
arm = new Arm{
              fl_input("Arm's name: ",""),atoi(fl_input("Arm's model number: ","")),atof(fl_input("Arm's cost: ","")),fl_input("Arm's description: ",""),atof(fl_input("Arm's max power: ",""))

        };
        cout << *arm << endl;
        arm->save(ost);
        arms.push_back(*arm);
 }
 void TorsoCB(Fl_Widget *w, void *p) {
   torso = new Torso{

fl_input("Torso's name: ",""),atoi(fl_input("Torso's model number: ","")),atof(fl_input("Torso's cost: ","")),fl_input("Torso's description: ",""),atoi(fl_input("maximum # of arms (0 to 2): ","")),atoi(fl_input("Enter maximum # of batteries (1 to 3): "))

        };
        cout << *torso << endl;
        torso->save(ost);
        torsos.push_back(*torso);
}
void LocomotorCB(Fl_Widget *w, void *p) {
locomotor = new Locomotor{
                 fl_input("Locomotor's name: ",""),atoi(fl_input("Locomotor's model number: ","")),atof(fl_input("Locomotor's cost: ","")),fl_input("Locomotor's description: ",""),atof(fl_input("Locomotor's max power: ",""))

        };
        cout << *locomotor << endl;
        locomotor->save(ost);
        locomotors.push_back(*locomotor);
}

void BatteryCB(Fl_Widget *w, void *p) {
battery = new Battery{
                fl_input("Battery's name: ",""),atoi(fl_input("Battery's model number: ","")),atof(fl_input("Battery's cost: ","")),fl_input("Battery's description: ",""),atof(fl_input("Battery's max energy: ","")), atof(fl_input("Battery's power available: ", ""))

        };
        cout << *battery << endl;
        battery->save(ost);
        batteries.push_back(*battery);
}

void ModelCB(Fl_Widget *w, void *p) {

model_name = fl_input("Enter the Model's name","");

model_number = atoi(fl_input("Enter the model's number",""));



// HEADS
int head_i;
string headss;


for (int i = 0; i < heads.size(); i++)
{
headss += to_string(i+1) + ") ";
  headss += heads[i].name();
  headss += "\n";

}

head_i = atoi(fl_input(headss.c_str(),""));


//TORSOS
int torso_i;
string torsoss;


for (int i = 0; i < torsos.size(); i++)
{
torsoss += to_string(i+1) + ") ";
  torsoss += torsos[i].name();
 torsoss += "\n";
}

torso_i = atoi(fl_input(torsoss.c_str(),""));


//ARMS
int arm_i;
string armss;


for (int i = 0; i < arms.size(); i++)
{
armss += to_string(i+1) + ") " ;
  armss += arms[i].name();
armss += "\n";
}

arm_i = atoi(fl_input(armss.c_str(),""));

//Battery
int battery_i;
string batteriess;


for (int i = 0; i < batteries.size(); i++)
{
batteriess += to_string(i+1) + ") ";
  batteriess += batteries[i].name();
batteriess += "\n";
}

battery_i = atoi(fl_input(batteriess.c_str(),""));

//LOCOMOTORS
int locomotor_i;
string locomotorss;


for (int i = 0; i < locomotors.size(); i++)
{
locomotorss += to_string(i+1) + ") ";
  locomotorss += locomotors[i].name();
locomotorss += "\n";
}

locomotor_i = atoi(fl_input(locomotorss.c_str(),""));


model= new Robot_model(model_name, model_number,heads[head_i-1],torsos[torso_i -1],arms[arm_i -1],locomotors[locomotor_i -1],batteries[battery_i -1]);
model->save(ost);
models.push_back(*model);

}


void ExitCB(Fl_Widget *w, void *p) {
exit(0);
}



Fl_Menu_Item menuitems[] = {

{"&Create",0,0,0,FL_SUBMENU},
{"&Robot Model", FL_ALT + 'm',(Fl_Callback *)ModelCB},

{ "&Robot part", 0,0,0,FL_SUBMENU},
{"&Head", FL_ALT + 'h', (Fl_Callback *)HeadCB},
{"&Arm", FL_ALT + 'a', (Fl_Callback *)ArmCB},
{"&Torso", FL_ALT + 't', (Fl_Callback *)TorsoCB},
{"&Locomotor", FL_ALT + 'l', (Fl_Callback *)LocomotorCB},
{"&Battery", FL_ALT + 'b', (Fl_Callback *)BatteryCB},

{0},
{"&Exit", FL_ALT + 'e', (Fl_Callback*)ExitCB},

{0},
{0}
};



int main() {

 Fl_Window *win = new Fl_Window(600,500, "Robot Shop");
 win->color(FL_WHITE);

fl_register_images();

Fl_Menu_Bar *menubar = new Fl_Menu_Bar(0,0,600,30);
menubar->menu(menuitems);
win->show();



int part;

ist.open("robot.txt");

do{
switch(get_int(ist))
{
case 9:
{exit(0);}

case 1:
{
string name = get_string(ist);
int model_number = get_int(ist);
head = new Head{
get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist)};
torso = new Torso{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_int(ist),get_int(ist)};
arm = new Arm{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist)};
locomotor = new Locomotor{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist)};
battery = new Battery{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist),get_double(ist)};

model = new Robot_model{name,model_number,*head,*torso,*arm,*locomotor,*battery};
models.push_back(*model);
break;}
case 2:
{

switch(get_int(ist))
{
case 1:{
head = new Head{
get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist)};
heads.push_back(*head);
break;}

case 2: {
arm = new Arm{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist)};
arms.push_back(*arm); break;}

case 3:{
torso = new Torso{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_int(ist),get_int(ist)};
torsos.push_back(*torso); break;}

case 4:{
locomotor = new Locomotor{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist)};
locomotors.push_back(*locomotor);break;}

case 5: {
battery = new Battery{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist),get_double(ist)};
batteries.push_back(*battery);break;}

}
break; //break of case 2
}

case 4:{
customer = new Customer{get_string(ist),get_int(ist),get_string(ist),get_string(ist)};
customers.push_back(*customer);break;}

case 5:{
sale_associate = new Sale_associate{get_string(ist),get_int(ist)};
sale_associates.push_back(*sale_associate);break;}

case 6:{
int order_number = get_int(ist);
string date = get_string(ist);
customer = new Customer{get_string(ist),get_int(ist),get_string(ist),get_string(ist)};
sale_associate = new Sale_associate{get_string(ist),get_int(ist)};
string name = get_string(ist);
int model_number = get_int(ist);
head = new Head{
get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist)};
torso = new Torso{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_int(ist),get_int(ist)};
arm = new Arm{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist)};
locomotor = new Locomotor{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist)};
battery = new Battery{get_string(ist),get_int(ist),get_double(ist),get_string(ist),get_double(ist),get_double(ist)};

model = new Robot_model{name,model_number,*head,*torso,*arm,*locomotor,*battery};


int status = get_int(ist);
order = new Order{order_number,date, *customer,*sale_associate,*model,status};
orders.push_back(*order);
break;}

}
}while(!ist.eof());
ist.close();



win->end();
 return Fl::run();
}



// g++ -std=c++0x robot.cpp -lfltk -o robotgui
//./robotgui

