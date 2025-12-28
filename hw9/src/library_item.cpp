#include "library_item.h"

// Ticket
LibraryItem::Ticket::Ticket(long token): token(token) {}

long LibraryItem::Ticket::get_token() const {
    return token;
}

// LibraryItem
LibraryItem::LibraryItem(std::string title, std::string author): title(title), author(author) {}

std::string LibraryItem::get_title() {
    return title;
}

std::string LibraryItem::get_author() {
    return author;
}