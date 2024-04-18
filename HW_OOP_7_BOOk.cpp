#include <iostream>
#include <string>
using namespace std;

class Book {
    string name;
    int pages;
    double weight;

public:
    Book() {
        SetBookName("War and Peace");
        SetPages(1300);
        SetWeight(6.4);
    }

    Book(const string& name, int pages, double weight) {
        SetBookName(name);
        SetPages(pages);
        SetWeight(weight);
    }

    ~Book() {
        cout << "Book is sold out\n";
    }

    void Print() const {
        cout << "Book name: " << name << "\n";
        cout << "Total pages: " << pages << "\n";
        cout << "Takes up mb: " << weight << "\n";
    }

    string Compare(const Book& other) const {
        if (*this < other) {
            return " has fewer pages and less weight than ";
        }
        else if (*this > other) {
            return " has more pages and more weight than ";
        }
        else if (*this == other) {
            return " books have the same number of pages and weight ";
        }
        else if (*this <= other) {
            return " has fewer or equal pages and less or equal weight than ";
        }
        else if (*this >= other) {
            return " has more or equal pages and more or equal weight than ";
        }
    }

    void SetBookName(const string& name) {
        this->name = name;
    }

    string GetBookName() const {
        return name;
    }

    void SetPages(int pages) {
        if (pages < 0 || pages > 1600) throw "ERROR!";
        this->pages = pages;
    }

    int GetPages() const {
        return pages;
    }

    void SetWeight(double weight) {
        if (weight < 0 || weight > 500) throw "ERROR!";
        this->weight = weight;
    }

    double GetWeight() const {
        return weight;
    }

    bool operator<(const Book& other) const {
        if (pages != other.pages) {
            return pages < other.pages;
        }
        return weight < other.weight;
    }

    bool operator>(const Book& other) const {
        if (pages != other.pages) {
            return pages > other.pages;
        }
        return weight > other.weight;
    }

    bool operator==(const Book& other) const {
        return pages == other.pages && weight == other.weight;
    }

    bool operator<=(const Book& other) const {
        return (*this < other) || (*this == other);
    }

    bool operator>=(const Book& other) const {
        return (*this > other) || (*this == other);
    }

    istream& ReadFromConsole(istream& input) {
        cout << "Welcome!\n";
        cout << "Please, enter the name of the book: ";
        input >> name;
        cout << "Please, enter the total number of pages: ";
        input >> pages;
        cout << "Please, enter the book's weight in megabytes: ";
        input >> weight;
        return input;
    }

    ostream& WriteToConsole(ostream& output) const {
        output << "\n================================\n";
        output << "Book state:\n";
        output << "Book name: " << name << "\n";
        output << "Total pages: " << pages << "\n";
        output << "Takes up mb: " << weight << "\n";
        output << "\n================================\n\n";
        return output;
    }
};

istream& operator>>(istream& input, Book& book) {
    return book.ReadFromConsole(input);
}

ostream& operator<<(ostream& output, const Book& book) {
    return book.WriteToConsole(output);
}

int main() {
    Book book1;
    Book book2;
    cin >> book1;
    cin >> book2;
    cout << book1 << book2;

    cout << "Comparison between " << book1.GetBookName() << " and " << book2.GetBookName() << ":\n";
    cout << "Book  " << book1.GetBookName() << book1.Compare(book2) << " book " << book2.GetBookName() << "\n";

    return 0;
}
