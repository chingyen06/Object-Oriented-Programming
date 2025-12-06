#ifndef LIBRARY_MANAGEMENT_SYSTEM_H
#define LIBRARY_MANAGEMENT_SYSTEM_H

#include <vector>
#include <string>
#include <filesystem>

#include "library_item.h"

class LibraryManagementSystem {
public:
    LibraryManagementSystem();
    
    void add_item(LibraryItem* item);
    bool remove_item(long id);
    
    std::vector<LibraryItem*> search_by_title(std::string title);
    std::vector<LibraryItem*> search_by_author(std::string author);

    int get_total_items();

    void save_to_file(const std::filesystem::path& output_path);
    void load_from_file(const std::filesystem::path& input_path);
    void clear();

private:
    std::vector<LibraryItem*> library_item;
};

#endif // LIBRARY_MANAGEMENT_SYSTEM_H
