#include "ebook.h"

EBook::EBook(long unique_id, std::string title, std::string author): LibraryItem(unique_id, title, author) {}

std::string EBook::get_type() {
    return "EBook";
}

std::string EBook::to_string() {
    return "EBook: " + get_title() + " by " + get_author();
}