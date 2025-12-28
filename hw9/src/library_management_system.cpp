#include "library_management_system.h"
#include <iostream>

LibraryManagementSystem::LibraryManagementSystem() {}

LibraryItem::Ticket LibraryManagementSystem::add_item(LibraryItem* item) {
    if (item == nullptr) {
        return LibraryItem::Ticket(-1);
    }

    items[index] = item;
    check_out[index] = false;

    return LibraryItem::Ticket(index++);
}

bool LibraryManagementSystem::remove_item(const LibraryItem::Ticket& ticket) {
    long token = ticket.get_token();

    // if (token == -1 || items.find(token) == items.end() || check_out[token]) {
    //     return false;
    // }

    // std::cout << std::endl << token << ": " << std::endl;

    if (!is_available(ticket)) {
        // std::cout << "not available " << check_out[token] << std::endl;
        return false;
    }

    delete items[token];
    items.erase(token);
    check_out.erase(token);
    return true;
}

bool LibraryManagementSystem::checkout(const LibraryItem::Ticket& ticket) {
    long token = ticket.get_token();

    // if (token == -1 || items.find(token) == items.end() || check_out[token]) {
    //     return false;
    // }

    if (!is_available(ticket)) {
        return false;
    }

    check_out[token] = true;
    return true;
}

bool LibraryManagementSystem::return_item(const LibraryItem::Ticket& ticket) {
    long token = ticket.get_token();

    if (token == -1 || items.find(token) == items.end() || !check_out[token]) {
        return false;
    }

    check_out[token] = false;
    return true;
}

bool LibraryManagementSystem::is_available(const LibraryItem::Ticket& ticket) {
    long token = ticket.get_token();

    if (token == -1 || items.find(token) == items.end() || check_out[token]) {
        return false;
    }

    return true;
}

int LibraryManagementSystem::get_total_items() {
    return items.size();
}

int LibraryManagementSystem::get_available_items() {
    int total = 0;

    for (auto item: items) {
        if (is_available(item.first)) {
            total++;
        }
    }

    return total;
}

void LibraryManagementSystem::clear() {
    for (auto &item: items) {
        delete item.second;
    }

    items.clear();
    check_out.clear();
    index = 1;
}