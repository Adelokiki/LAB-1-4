#include <iostream>
#include <string>

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

// book class derived from publication
class book : public publication {
private:
    int pages;

public:
    // default constructor
    book() : publication(), pages(0) {}

    // method to get data from the user
    void getdata() override {
        publication::getdata(); // call base class getdata
        cout << "enter the number of pages in the book: ";
        cin >> pages;
        cin.ignore(); // to ignore the newline character
    }

    // method to display data
    void putdata() const override {
        publication::putdata(); // call base class putdata
        cout << "pages: " << pages << endl;
    }
};

// audio class derived from publication
class audio : public publication {
private:
    int duration; // duration in minutes

public:
    // default constructor
    audio() : publication(), duration(0) {}

    // method to get data from the user
    void getdata() override {
        publication::getdata(); // call base class getdata
        cout << "enter the duration of the audio book in minutes: ";
        cin >> duration;
        cin.ignore(); // to ignore the newline character
    }

    // method to display data
    void putdata() const override {
        publication::putdata(); // call base class putdata
        cout << "duration: " << duration << " minutes" << endl;
    }
};

int main() {
    // create a book instance
    cout << "enter details for the book:" << endl;
    book book_instance; // Renamed variable to avoid confusion with class name
    book_instance.getdata();
    book_instance.putdata();

    cout << "\nenter details for the audio:" << endl;
    audio audio_instance; // Renamed variable to avoid confusion with class name
    audio_instance.getdata();
    audio_instance.putdata();

    return 0;
}
