#include "reference_book.h"

ReferenceBook::ReferenceBook(long unique_id, std::string title, std::string author): LibraryItem(unique_id, title, author) {}

std::string ReferenceBook::get_type() {
    return "ReferenceBook";
}

std::string ReferenceBook::to_string() {
    return "ReferenceBook: " + get_title() + " by " + get_author();
}