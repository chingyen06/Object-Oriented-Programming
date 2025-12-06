#include "book.h"

Book::Book(long unique_id, std::string title, std::string author): LibraryItem(unique_id, title, author) {}

std::string Book::get_type() {
    return "Book";
}

std::string Book::to_string() {
    return "Book: " + get_title() + " by " + get_author();
}