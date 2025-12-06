#include "library_management_system.h"

LibraryManagementSystem::LibraryManagementSystem() {}

void LibraryManagementSystem::add_item(LibraryItem* item) {
    library_item.push_back(item);
}

std::vector<LibraryItem*> LibraryManagementSystem::search_by_title(std::string title) {
    std::vector<LibraryItem*> container;

    for (int i=0;i<library_item.size();i++) {
        if (library_item[i]->get_title().find(title) != std::string::npos) {
            container.push_back(library_item[i]);
        }
    }
    
    return container;
}

std::vector<LibraryItem*> LibraryManagementSystem::search_by_author(std::string author) {
    std::vector<LibraryItem*> container;

    for (int i=0;i<library_item.size();i++) {
        if (library_item[i]->get_author().find(author) != std::string::npos) {
            container.push_back(library_item[i]);
        }
    }

    return container;
}

int LibraryManagementSystem::get_total_items() {
    return library_item.size();
}