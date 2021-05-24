Create a factory that creates an instance of some type T,
 initializes it with arguments and returns it.

Here are some usage examples of the factory.

int *p1 = CreateObject<int>(5) ;
 
std::string *s = CreateObject<std::string>() ;//Default construction
 
Employee * emp = CreateObject<Employee>(
"Bob",    //Name
101,      //Id
1000) ;   //Salary
 
Contact *p = CreateObject<Contact>(
"Joey",                //Name
987654321,             //Phone number
"Boulevard Road, Sgr", //Address
"joey@poash.com") ;    //Email