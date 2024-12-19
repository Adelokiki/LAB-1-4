#include <iostream>
#include <vector>
#include <string>

using namespace std;

// books
enum booktype { fiction, technical };

// book class definition
class book {
public:
    string author;
    string title;
    booktype type;

    // constructor with validation
    book(const string& author, const string& title, booktype type) :
        author(author), title(title), type(type) {
        if (author.empty() || title.empty()) {
            throw invalid_argument("author and title cannot be empty.");
        }
    }
};

// function to display book counts using switch
void displaybookcountsswitch(const vector<book>& library) {
    int fictioncount = 0;
    int technicalcount = 0;

    for (const book& b : library) {
        switch (b.type) {
        case fiction:
            fictioncount++;
            break;
        case technical:
            technicalcount++;
            break;
        }
    }

    cout << "book counts (using switch):" << endl;
    cout << "fiction: " << fictioncount << endl;
    cout << "technical: " << technicalcount << endl;
}

// function to display book counts without switch
void displaybookcounts(const vector<book>& library) {
    int fictioncount = 0;
    int technicalcount = 0;

    for (const book& b : library) {
        // using if-else instead of switch
        if (b.type == fiction) {
            fictioncount++;
        } else if (b.type == technical) {
            technicalcount++;
        }
    }

    cout << "\nbook counts (without switch):" << endl;
    cout << "fiction: " << fictioncount << endl;
    cout << "technical: " << technicalcount << endl;
}

int main() {
    // create a vector (dynamically sized array) to store books
    vector<book> library;

    // populate the library with some books
    try {
        library.push_back(book("jane austen", "pride and prejudice", fiction));
        library.push_back(book("stephen hawking", "a brief history of time", technical));
        library.push_back(book("george orwell", "nineteen eighty-four", fiction));
        // this will throw an exception: library.push_back(book("", "no author", technical));
    } catch (const invalid_argument& e) {
        cerr << "error: " << e.what() << endl;
        // handle the exception (e.g., ask for correct input)
    }

    // display book counts using both methods
    displaybookcountsswitch(library);
    displaybookcounts(library);

    return 0;
}
