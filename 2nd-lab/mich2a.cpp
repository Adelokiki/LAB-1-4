#include <iostream>
#include <string>
#include <array>

using namespace std;

// publication class
class publication {
protected:
    string title;
    float price;

public:
    // default constructor
    publication() : title(""), price(0.0) {}

    // virtual method to get data from the user
    virtual void getdata() {
        cout << "enter the title of the publication: ";
        getline(cin, title);
        cout << "enter the price of the publication: ";
        cin >> price;
        cin.ignore(); // to ignore the newline character left in the buffer
    }

    // virtual method to display data
    virtual void putdata() const {
        cout << "title: " << title << endl;
        cout << "price: $" << price << endl;
    }

    // virtual destructor
    virtual ~publication() {}
};

// sales class
class sales {
protected:
    array<float, 3> sales; // array to hold sales data for last three months

public:
    // default constructor
    sales() {
        sales.fill(0.0); // initialize sales to zero
    }

    // method to get sales data from the user
    void getsalesdata() {
        for (int i = 0; i < 3; ++i) {
            cout << "enter sales for month " << (i + 1) << ": ";
            cin >> sales[i];
        }
        cin.ignore(); // to ignore the newline character
    }

    // method to display sales data
    void putsalesdata() const {
        cout << "sales data for the last three months:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "month " << (i + 1) << ": $" << sales[i] << endl;
        }
    }
};

// book class derived from publication and sales
class book : public publication, public sales {
private:
    int pages;

public:
    // default constructor
    book() : publication(), sales(), pages(0) {}

    // method to get data from the user
    void getdata() override {
        publication::getdata(); // call base class getdata
        cout << "enter the number of pages in the book: ";
        cin >> pages;
        cin.ignore(); // to ignore the newline character
        getsalesdata(); // get sales data
    }

    // method to display data
    void putdata() const override {
        publication::putdata(); // call base class putdata
        cout << "pages: " << pages << endl;
        putsalesdata(); // display sales data
    }
};

// audio class derived from publication and sales
class audio : public publication, public sales {
private:
    int duration; // duration in minutes

public:
    // default constructor
    audio() : publication(), sales(), duration(0) {}

    // method to get data from the user
    void getdata() override {
        publication::getdata(); // call base class getdata
        cout << "enter the duration of the audio book in minutes: ";
        cin >> duration;
        cin.ignore(); // to ignore the newline character
        getsalesdata(); // get sales data
    }

    // method to display data
    void putdata() const override {
        publication::putdata(); // call base class putdata
        cout << "duration: " << duration << " minutes" << endl;
        putsalesdata(); // display sales data
    }
};

int main() {
    // create a book instance
    cout << "enter details for the book:" << endl;
    book book_instance;  // Renamed variable to avoid confusion with class name
    book_instance.getdata();
    book_instance.putdata();

    cout << "\nenter details for the audio:" << endl;
    audio audio_instance;  // Renamed variable to avoid confusion with class name
    audio_instance.getdata();
    audio_instance.putdata();

    return 0; 
}
