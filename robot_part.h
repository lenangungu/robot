#ifndef _ROBOT_PART
#define _ROBOT_PART 2017
#include <string>
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

#endif
