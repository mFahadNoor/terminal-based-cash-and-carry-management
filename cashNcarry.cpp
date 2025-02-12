#include <iostream>
using namespace std;

class Product{
    string name;
    float price;
    int quantity;
public:
    Product(string n = "\0", int p=0)
    {
        name = n;
        price = p;
    }
    Product(int q, string n = "\0", int p=0)
    {
        quantity = q;
        name = n;
        price = p;
    }
    void setPrice(float a)
    {
        price = a;
    }
    float getPrice()
    {
        return price;
    }
    void setQuantity(int a)
    {
        quantity = a;
    }
    int getQuantity()
    {
        return quantity;
    }
    string getName()
    {
        return name;
    }
    void setName(string s)
    {
        name = s;
    }
};
class Store{  //================ MODULE 1, 2 ================
protected:
    Product **products;
    int total_products;
public:
    Store()
    {
        total_products = 0;
    }
    Store(int n)
    {
        total_products = n;
        products = new Product*[n];
        for(int i=0; i<n; i++)
        {
            string naam;
            int p, q;
            cout << "\n\nEnter Name of product: ";
            cin >> naam;
            cout << "Enter Price: ";
            cin >> p;
            cout << "Enter the quantity: ";
            cin >> q;
            products[i] = new Product(q, naam, p);
        }
    }
    int locate(string nm) // checks the index where product of given 'name' is.
    {
        for(int i=0; i<total_products; i++)
        {
            if(nm == products[i]->getName())
            {
                return i;
            }
        }
        return total_products; // if this line is accessed, it means product doesnt exist
    }
    void add_product(string n, int p, int quant)
    {
        int i = locate(n);
        if(i > total_products)
        {
            int q = products[i]->getQuantity();
            products[i]->setQuantity(q+quant);
            products[i]->setPrice(p);
        }
        else
        {
            products[total_products] = new Product(n, p);
            total_products++;
        }
    }
    void remove_product(string n, int quant)
    {
        int i = locate(n);
        if(i == total_products)
        {
            cout << "\n**Error: This product doesnt exist.\n";
        }
        else
        {
            int q = products[i]->getQuantity();
            if(quant > q)
            {
                cout << "\n**Error: Not enough products are available.\n";
            }
            else if(quant == q)
            {
                total_products--;
                products[total_products] = nullptr;
            }
            else
            {
                products[i]->setQuantity(q-quant);
            }
        }
        //now, for placing order
        if(products[i]->getQuantity() < 100)
        {
            cout << "!! The quantity of given product is less than 100. PLACING ORDER FOR" << n << endl; // PRODUCTS ORDERING <-----
        }
    }
    void disc(int n) // for discount
    {
        for(int i=0; i<total_products; i++)
        {
            int pric = products[i]->getPrice();
            pric = pric * n / 100;
            products[i]->setPrice(pric);
        }
    }
    void Sale(char c)
    {
        switch (c)
        {
            case 'r':
                disc(50);   //50% discount for ramadan
                break;
            case 'y':
                disc(25);   //25% discount for new year
                break;
            case 'a':
                disc(33);   //33% discount for 14th aug
                break;
            case 'm':
                disc(33);   //33% discount for 23 march
                break;
            case 'c':
                disc(20);   //20% discount for christmas or winter
                break;
        }
    }
    int getTotalProducts()
    {
        return total_products;
    }
    int getQuantity(int i)
    {
        return products[i]->getQuantity();
    }
    string getName(int i)
    {
        return products[i]->getName();
    }
    float getPrice(int i)
    {
        return products[i]->getPrice();
    }
    void setQuantity(int i, int q)
    {
        products[i]->setQuantity(getQuantity(i)-q);
    }
    
};
class Manager : private Store{  //================ MODULE 3 =================

};
class Sales: private Product{
    int day;
    int month;
    Product **sold_prods; //array of all products sold that day
    int size; //shows size of array
public:
    Sales(){}
    Sales(int d, int m, Product p[], int total)
    {
        day = d;
        month = m;
        size = total;
        string n;
        int pr;
        for (int i = 0; i < total; i++)
        {
            n = p[i].getName();
            pr = p[i].getPrice();
            sold_prods[i] = new Product(n, pr);
        }
    }
    void AddDay(Product p[], int total)
    {
        //copying to a new array
        Product *new_arr[total];
        for (int i = 0; i < size; i++)
        {
            new_arr[i] = sold_prods[i];
        }
        size = total;
        new_arr[total-1] = p;
        sold_prods = new_arr;
    }
    int getDay()
    {
        return day;
    }
    int getMonth()
    {
        return month;
    }

};
int main()
{
    bool cart_flag = false;
    float gt=0;
    bool stop_flag = false;
    int total_sales_ofday=0;
    int choice;
    int index;
    int day, month, total_days=1;
    Sales *sales_perday;
    int total_incart=0;
    bool logout_flag = false;
    while(!logout_flag)
    {
        cout << "Welcome to the retail store! Please inform weather you're a Manager(press 1) or a Salesman(press 2). (press 3 to exit)\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\n<<< Logged in as MANAGER >>>\n";
            stop_flag = false;
            int choose;
            while (!stop_flag)
            {
                cout << "1) Show sale reports\n2) Log Out";
                cin >> choose;
                switch (choose)
                {
                case 1:
                    int chose;
                    cout << "1) For a Day\n2) For a Month\n3) Most Profitable Day\n";
                    cin >> chose;
                    switch (chose)
                    {
                    case 1:
                        for (int i = 0; i < total_days; i++)
                        {
                            
                        }
                        
                        break;
                    case 2:

                        break;
                    case 3:
                        
                        break;
                    default:
                        break;
                    }
                    break;
                case 2:
                    stop_flag = true;
                    break;
                default:
                    break;
                }
            }
            
            break;
        case 2:
            {
                Product *sales_ofday;
                int prods;
                cout << "\n<<< Logged in as SALESMAN >>>\n";
                cout << "~First of all, you will be required to add products, their price and their quantity.\n";
                cout << "Please enter how many products there are: ";
                cin >> prods;
                Store Cash_n_Carry(prods);
                do
                {
                    cout << "Please enter today's month (1-12): ";
                    cin >> month;
                } while (month > 12 || month < 1);
                do
                {
                    cout << "Please enter today's date (1-31): ";
                    cin >> day;
                } while (day > 31 || day < 1);
                
                cout << "\n\nYou have successfully entered the products and date information. Now which function would you like to perform? \n";
                while(!stop_flag)
                {
                    int day, date;
                    int choose;
                    cout << "\n\t<<Main Menu for SALESMAN>>\n";
                    cout << "1) Add to cart\n 2) Products Ordering\n3) Products Take\n4) Add discount\n5)Refund\n6) Close the store for the day\n7) Log OUT \n";
                    cin >> choose;
                    string s;
                    switch(choose)
                    {
                    case 1:
                        Product *items;
                        char c;
                        int q;
                        int qua;
                        do
                        {
                            cout << "Please Enter the name of Product: ";
                            cin >> s;
                            index = Cash_n_Carry.locate(s);
                            if(index == Cash_n_Carry.getTotalProducts())
                            {
                                cout << "** This Product doesn't exist!?\n\n";
                            }
                            else
                            {
                                sales_ofday[total_sales_ofday-1].setName(Cash_n_Carry.getName((index)));
                                sales_ofday[total_sales_ofday-1].setQuantity(qua);
                                cout << "Please Enter the Quantity of Product: ";
                                cin >> qua;
                                if(qua > Cash_n_Carry.getQuantity(index))
                                {
                                    cout << "** Given Quantity is too much!?\n\n";
                                }
                                else
                                {
                                    total_sales_ofday++;
                                    total_incart++;
                                    Product temp[total_incart];
                                    if(total_incart > 1)
                                    {
                                        for(int i=0; i<total_incart-2; i++) //-2 because that would indicate till the last index of items[] (we just added one so, -2)
                                        {
                                            temp[i] = items[i];
                                        }
                                    }
                                    temp[total_incart-1].setName(Cash_n_Carry.getName(index));
                                    temp[total_incart-1].setPrice(Cash_n_Carry.getPrice(index));
                                    temp[total_incart-1].setQuantity(qua);
                                    items = temp;
                                    Cash_n_Carry.setQuantity(index, qua);
                                    cout << "\nWould you like to enter another product? (y, n): ";
                                    cin >> c;
                                    switch (c)
                                    {
                                    case 'y':
                                        break;
                                    case 'n':
                                        cart_flag = true;
                                        break;
                                    default:
                                        break;
                                    }                                
                                }
                            } 
                        }while (!cart_flag);
                        cout << "\n\n\n--------RECEIPT-------\n";
                        for (int i = 0; i < total_incart; i++)
                        {
                            gt += (items[i].getPrice() * items[i].getQuantity());
                            cout << items[i].getName() << " x" << items[i].getQuantity() << " = " << items[i].getQuantity()*items[i].getPrice();
                            cout << endl;
                        }
                        cout << "------------------------------------\nGrand Total = " << gt << endl;
                        break;
                    case 2:
                        cout << "Please enter the name of product: ";
                        cin >> s;
                        index = Cash_n_Carry.locate(s);
                        if (index == Cash_n_Carry.getTotalProducts())
                            cout << "!! This product doesn't exist...\n";
                        else
                        {
                            if(Cash_n_Carry.getQuantity(index) < 100)
                            {
                                cout << "Placing order for the product " << s << " to be delivered. \n";
                            }
                            else
                            {
                                cout << "!! This product is already available in abundance...\n";
                            }
                        }
                        break;
                        
                    case 3:
                        cout << "Please enter the name of product to be taken: ";
                        cin >> s;
                        int qu;
                        cout << "Enter the quantity of product to be removed: ";
                        cin >> qu;
                        Cash_n_Carry.remove_product(s, qu);
                        break;

                    case 4:
                        char chose;
                        cout << "<Sale Menu>\nr) 50%"
                        << "discount for ramadan\ny) 25 %"
                        << "discount for new year\na) 33 %"
                        << "discount for 14th aug\nm) 33 %"
                        << "discount for 23 march\nc) 20 %"
                        << "discount for christmas or wintern \n";
                        cin >> chose;
                        switch (chose)
                        {
                        case 'r':
                            Cash_n_Carry.Sale(chose);
                            break;
                        case 'y':
                            Cash_n_Carry.Sale(chose);
                            break;
                        case 'a':
                            Cash_n_Carry.Sale(chose);
                            break;
                        case 'm':
                            Cash_n_Carry.Sale(chose);
                            break;
                        case 'c':
                            Cash_n_Carry.Sale(chose);
                            break;
                        default:
                            cout << "** INVALID INPUT\n";
                            break;
                        }
                        break;
                    case 5:
                        cout << "Please verify if the receipt shows date of 7 or less days ago. Today's date is: ";
                        cout << day << "/" << month<<endl;
                        break;
                    case 6:
                        cout << "Closing.. \n";
                        total_days++;
                        do
                        {
                            cout << "Please enter today's month (1-12): ";
                            cin >> month;
                        } while (month > 12 || month < 1);
                        do
                        {
                            cout << "Please enter today's date (1-31): ";
                            cin >> day;
                        } while (day > 31 || day < 1);
                        break;

                    case 7:
                        stop_flag = true;
                        break;
                    default:
                        cout << "** INVALID INPUT\n";
                        break;
                    }
                }
            }
            break;

        case 3:
            logout_flag = true;
            break;
        default:
            cout << "** INVALID INPUT\n";
            break;
        }
    }
}