#include "shape.h"
#include "triangle.h"
#include "circle.h"
#include "convex_polygon.h"
#include "point.h"
#include "geo_utils.h"
#include <fstream>
#include <sstream>
#include <algorithm>

std::vector<Shape*> read_shapes_from_file(const std::filesystem::path& filename) {
    std::vector<Shape *> shapes;

    std::ifstream ifs(filename);
    std::string line;

    if (!ifs.is_open())
        throw std::runtime_error("Runtime Error");

    while (std::getline(ifs, line)) {
        if (line.empty())
            continue;

        std::istringstream iss(line);
        std::string type;

        iss >> type;

        if (type == "Triangle") {
            std::string px, py;
            Point p[3];

            for (int i=0;i<3;i++) {
                iss >> px >> py;

                p[i].x = std::stod(px);
                p[i].y = std::stod(py);
            }

            // Triangle t{p[0], p[1], p[2]};
            // shapes.push_back(&t);
            shapes.push_back(new Triangle{p[0], p[1], p[2]});
        }
        else if (type == "Circle") {
            std::string px, py, radius;
            Point p;

            iss >> px >> py >> radius;

            p.x = std::stod(px);
            p.y = std::stod(py);

            // Circle c{p, std::stod(radius)};
            // shapes.push_back(&c);
            shapes.push_back(new Circle{p, std::stod(radius)});
        }
        else {
            std::string px, py;
            std::vector<Point *> vertices;

            while (iss >> px >> py) {
                vertices.push_back(new Point{std::stod(px), std::stod(py)});
            }

            ConvexPolygon* cp = new ConvexPolygon{vertices};

            if (cp->isConvexPolygon() == false)
                throw std::runtime_error("Not a Convexpolygon");

            // ConvexPolygon cp(vertices);
            // shapes.push_back(&cp);
            shapes.push_back(cp);
        }
    }

    return shapes;
}

void write_shapes_to_file(const std::vector<Shape*>& shapes, const std::filesystem::path& filename) {
    std::ofstream ofs(filename);

    if (!ofs.is_open())
        throw std::runtime_error("Runtime Error");
    
    for (auto shape: shapes) {
        ofs << shape->to_string() << std::endl;
    }

    ofs.close();
}

void sort_shapes_by_property(std::vector<Shape*>& shapes, const std::string& property, const std::string& order) {
    if (property == "area") {
        if (order == "inc") {
            std::sort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b) {
                return a->area() < b->area();
            });
        }
        else if (order == "dec") {
            std::sort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b) {
                return a->area() > b->area();
            });
        }
    }
    else if (property == "perimeter") {
        if (order == "inc") {
            std::sort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b) {
                return a->perimeter() < b->perimeter();
            });
        }
        else if (order == "dec") {
            std::sort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b) {
                return a->perimeter() > b->perimeter();
            });
        }
    }
}

void cleanup_shapes(std::vector<Shape*>& shapes) {
    for (auto shape: shapes) {
        delete shape;
    }

    shapes.clear();
}