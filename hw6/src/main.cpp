#include <iostream>
#include <string>
#include <stdexcept>
#include "shape.h"
#include "geo_utils.h"

int main(int argc, char* argv[]) {
    if (argc != 5) {  //輸入的參數不符合
        std::cerr << "Use ./geo <input_file> <output_file> <property> <order>" << std::endl;
        return 1;
    }

    // argv[0] 是 "./geo"，不需要
    std::filesystem::path input_file = argv[1];
    std::filesystem::path output_file = argv[2];
    std::string property = argv[3];
    std::string order = argv[4];

    std::vector<Shape *> shapes;

    try {
        shapes = read_shapes_from_file(input_file);  //讀入資料
        sort_shapes_by_property(shapes, property, order);  //排序資料
        write_shapes_to_file(shapes, output_file);  //寫入資料
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        cleanup_shapes(shapes);
        return 1;
    }

    cleanup_shapes(shapes);  //要清除，不然會記憶體洩漏
    return 0;
}
