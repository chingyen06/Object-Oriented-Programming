#include "library_management_system.h"
#include "book.h"
#include "ebook.h"
#include "reference_book.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

LibraryManagementSystem::LibraryManagementSystem() {}

void LibraryManagementSystem::add_item(LibraryItem* item) {
    library_item.push_back(item);
}

bool LibraryManagementSystem::remove_item(long id) {
    bool cleared = false;

    for (int i=0;i<library_item.size();i++) {
        if (library_item[i]->get_unique_id() == id) {
            delete library_item[i];
            library_item.erase(library_item.begin() + i);
            cleared = true;
        }
    }

    return cleared;
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

void LibraryManagementSystem::save_to_file(const std::filesystem::path& output_path) {
    std::ofstream ofs(output_path);
    if (!ofs.is_open()) {
        throw std::runtime_error("Runtime Error");  // 修正 SaveToInvalidPathTest
    }

    for (int i=0;i<library_item.size();i++) {
        ofs << library_item[i]->get_unique_id() << "," << library_item[i]->get_type() << "," << 
        library_item[i]->get_title() << "," << library_item[i]->get_author() << std::endl;
    }

    ofs.close();
}

void LibraryManagementSystem::load_from_file(const std::filesystem::path& input_path) {
    std::ifstream ifs(input_path);
    std::string line;

    if (!ifs.is_open()) {
        throw std::runtime_error("Runtime Error");  // 修正 LoadFromNonExistentFileTest
    }

    clear();

    while (std::getline(ifs, line)) {
        if (line.empty())  // 修正 LoadFromFileWhitespaceHandlingTest
            continue;

        std::istringstream iss(line);
        std::string word;
        std::vector<std::string> info;

        while (std::getline(iss, word, ',')) {
            info.push_back(word);
        }

        
        long id;
        try {  //修正 LoadFromFileMalformedDataTest
            id = std::stol(info[0]);
        } catch (...) {
            continue;
        }

        std::string type = info[1];
        std::string title = info[2];
        std::string author = info[3];

        if (type == "Book") {
            LibraryItem* item = new Book(id, title, author);
            add_item(item);
        } else if (type == "EBook") {
            LibraryItem* item = new EBook(id, title, author);
            add_item(item);
        } else if (type == "ReferenceBook") {
            LibraryItem* item = new ReferenceBook(id, title, author);
            add_item(item);
        }
    }
}

void LibraryManagementSystem::clear() {
    for (auto item : library_item) {
        delete item;
    }
    library_item.clear();
}