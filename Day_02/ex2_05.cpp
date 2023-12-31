#include <iostream>
#include <fstream>
#include <vector>

class Book {
public:
    std::string title;
    std::string author;
    int year;

    Book(const std::string& t, const std::string& a, int y) : title(t), author(a), year(y) {}

    void display() const {
        std::cout << "Title: " << title << "\nAuthor: " << author << "\nYear: " << year << "\n\n";
    }
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayAllBooks() const {
        std::cout << "Library Inventory:\n";
        for (const Book& book : books) {
            book.display();
        }
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream outFile(filename);
        for (const Book& book : books) {
            outFile << book.title << "," << book.author << "," << book.year << "\n";
        }
        outFile.close();
        std::cout << "Library inventory saved to file: " << filename << "\n";
    }

    void loadFromFile(const std::string& filename) {
        std::ifstream inFile(filename);
        if (!inFile.is_open()) {
            std::cerr << "Error: Could not open file " << filename << "\n";
            return;
        }

        std::string line;
        while (std::getline(inFile, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.rfind(',');

            if (pos1 != std::string::npos && pos2 != std::string::npos && pos1 != pos2) {
                std::string title = line.substr(0, pos1);
                std::string author = line.substr(pos1 + 1, pos2 - pos1 - 1);
                int year = std::stoi(line.substr(pos2 + 1));

                books.emplace_back(title, author, year);
            }
        }

        inFile.close();
        std::cout << "Library inventory loaded from file: " << filename << "\n";
    }
};

int main() {
    Library myLibrary;

    myLibrary.addBook(Book("The C++ Programming Language", "Bjarne Stroustrup", 1985));
    myLibrary.addBook(Book("Effective Modern C++", "Scott Meyers", 2014));
    myLibrary.addBook(Book("Design Patterns", "Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides", 1994));

    myLibrary.displayAllBooks();

    myLibrary.saveToFile("library_inventory.txt");

    Library newLibrary;
    newLibrary.loadFromFile("library_inventory.txt");

    newLibrary.displayAllBooks();

    return 0;
}
