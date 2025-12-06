#include <gtest/gtest.h>
#include <filesystem>
#include "../src/circle.h"
#include "../src/triangle.h"
#include "../src/convex_polygon.h"
#include "../src/geo_utils.h"

TEST(GeoTest, WriteAndReadShapesTest) {
    std::filesystem::path input_path = "shapes.txt";
    std::vector<Shape *> shapes;

    //測試 write_shapes_to_file
    Circle c{{0.0, 0.0}, 5.0};
    Triangle t{{0.0, 0.0}, {3.0, 0.0}, {3.0, 4.0}};
    std::vector<Point *> vertices{
        new Point{0.0, 0.0},
        new Point{3.0, 0.0},
        new Point{3.0, 4.0},
        new Point{0.0, 4.0}
    };
    ConvexPolygon cp(vertices);

    shapes.push_back(&c);
    shapes.push_back(&t);
    shapes.push_back(&cp);

    write_shapes_to_file(shapes, input_path);

    //測試 read_shapes_from_file
    std::vector<Shape *> read_shapes;

    read_shapes = read_shapes_from_file(input_path);

    EXPECT_EQ("Circle 0.00 0.00 5.00", read_shapes[0]->to_string());
    EXPECT_EQ("Triangle 0.00 0.00 3.00 0.00 3.00 4.00", read_shapes[1]->to_string());
    EXPECT_EQ("ConvexPolygon 0.00 0.00 3.00 0.00 3.00 4.00 0.00 4.00", read_shapes[2]->to_string());

    std::filesystem::remove(input_path);

    for (auto vertex: vertices) 
        delete vertex;

    cleanup_shapes(read_shapes);
}

TEST(GeoTest, SortShapesByPropertyTest) {
    std::vector<Shape *> shapes;

    Circle c{{0.0, 0.0}, 5.0};
    Triangle t{{0.0, 0.0}, {3.0, 0.0}, {3.0, 4.0}};
    std::vector<Point *> vertices{
        new Point{0.0, 0.0},
        new Point{3.0, 0.0},
        new Point{3.0, 4.0},
        new Point{0.0, 4.0}
    };
    ConvexPolygon cp(vertices);

    shapes.push_back(&c);
    shapes.push_back(&t);
    shapes.push_back(&cp);

    // by area 的 inc 排序

    sort_shapes_by_property(shapes, "area", "inc");

    EXPECT_EQ("Triangle 0.00 0.00 3.00 0.00 3.00 4.00", shapes[0]->to_string());
    EXPECT_EQ("ConvexPolygon 0.00 0.00 3.00 0.00 3.00 4.00 0.00 4.00", shapes[1]->to_string());
    EXPECT_EQ("Circle 0.00 0.00 5.00", shapes[2]->to_string());

    // by area 的 dec 排序

    sort_shapes_by_property(shapes, "area", "dec");

    EXPECT_EQ("Circle 0.00 0.00 5.00", shapes[0]->to_string());
    EXPECT_EQ("ConvexPolygon 0.00 0.00 3.00 0.00 3.00 4.00 0.00 4.00", shapes[1]->to_string());
    EXPECT_EQ("Triangle 0.00 0.00 3.00 0.00 3.00 4.00", shapes[2]->to_string());

    // by perimeter 的 inc 排序

    sort_shapes_by_property(shapes, "perimeter", "inc");

    EXPECT_EQ("Triangle 0.00 0.00 3.00 0.00 3.00 4.00", shapes[0]->to_string());
    EXPECT_EQ("ConvexPolygon 0.00 0.00 3.00 0.00 3.00 4.00 0.00 4.00", shapes[1]->to_string());
    EXPECT_EQ("Circle 0.00 0.00 5.00", shapes[2]->to_string());

    // by perimeter 的 dec 排序

    sort_shapes_by_property(shapes, "perimeter", "dec");

    EXPECT_EQ("Circle 0.00 0.00 5.00", shapes[0]->to_string());
    EXPECT_EQ("ConvexPolygon 0.00 0.00 3.00 0.00 3.00 4.00 0.00 4.00", shapes[1]->to_string());
    EXPECT_EQ("Triangle 0.00 0.00 3.00 0.00 3.00 4.00", shapes[2]->to_string());
    
    for (auto vertex: vertices) 
        delete vertex;
}