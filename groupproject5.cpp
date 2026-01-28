#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Survey Point
class SurveyPoint3D {
public:
    double x;
    double y;
    double elevation;

    SurveyPoint3D(double a, double b, double c) {
        x = a;
        y = b;
        elevation = c;
    }
};

// Grid Cell
class GridCell {
public:
    double x;
    double y;
    double elevation;

    GridCell(double a, double b) {
        x = a;
        y = b;
        elevation = 0; // default, will be overwritten by interpolation
    }
};

// DEM Generator
class DEMGenerator {
private:
    vector<SurveyPoint3D> points;

public:
    DEMGenerator(vector<SurveyPoint3D> p) {
        points = p;
    }

    // IDW interpolation
    double interpolate(double x, double y) {
        double top = 0;
        double bottom = 0;

        for (int i = 0; i < points.size(); i++) {
            double dx = x - points[i].x;
            double dy = y - points[i].y;
            double dist = sqrt(dx * dx + dy * dy);

            if (dist == 0)
                return points[i].elevation;

            double weight = 1 / (dist * dist);
            top = top + weight * points[i].elevation;
            bottom = bottom + weight;
        }
        return top / bottom;
    }

    vector<GridCell> generateGrid(double xmin, double xmax,
                                  double ymin, double ymax,
                                  double size) {

        vector<GridCell> grid;

        for (double x = xmin; x <= xmax; x += size) {
            for (double y = ymin; y <= ymax; y += size) {
                GridCell cell(x, y);
                cell.elevation = interpolate(x, y);
                grid.push_back(cell);
            }
        }
        return grid;
    }
};

// Contour Segment
class ContourSegment {
public:
    double x1, y1;
    double x2, y2;
    double level;
};

// Contour Generator
class ContourGenerator {
public:
    vector<ContourSegment> generateContours(vector<GridCell> grid,
                                            double interval) {

        vector<ContourSegment> contours;

        for (int i = 0; i < grid.size() - 1; i++) {
            double z1 = grid[i].elevation;
            double z2 = grid[i + 1].elevation;

            int low = (int)(min(z1, z2) / interval);
            int high = (int)(max(z1, z2) / interval);

            for (int l = low; l <= high; l++) {
                double level = l * interval;

                if ((level >= z1 && level <= z2) ||
                    (level >= z2 && level <= z1)) {

                    ContourSegment c;
                    c.x1 = grid[i].x;
                    c.y1 = grid[i].y;
                    c.x2 = grid[i + 1].x;
                    c.y2 = grid[i + 1].y;
                    c.level = level;

                    contours.push_back(c);
                }
            }
        }
        return contours;
    }
};

// Main
int main() {

    // Survey points
    vector<SurveyPoint3D> points = {
        SurveyPoint3D(36.995, -1.095, 150),
        SurveyPoint3D(37.015, -1.105, 120),
        SurveyPoint3D(37.025, -1.115, 200),
        SurveyPoint3D(37.045, -1.085, 300)
    };

    // Generate DEM
    DEMGenerator dem(points);

    // Set grid to cover all points
    double xmin = 36.99;
    double xmax = 37.05;
    double ymin = -1.12;
    double ymax = -1.08;
    double gridSize = 0.005; // small spacing for smooth DEM

    vector<GridCell> grid = dem.generateGrid(xmin, xmax, ymin, ymax, gridSize);

    // Generate contours
    ContourGenerator cg;
    double contourInterval = 10; // 10 meters
    vector<ContourSegment> contours = cg.generateContours(grid, contourInterval);

    // Print some contour segments 
    for (int i = 0; i < contours.size() && i < 20; i++) { // print first 20 segments
        cout << "Contour " << contours[i].level << "m: ";
        cout << "(" << contours[i].x1 << "," << contours[i].y1 << ") to ";
        cout << "(" << contours[i].x2 << "," << contours[i].y2 << ")" << endl;
    }

    cout << "\nTotal contour segments generated: " << contours.size() << endl;

    return 0;
}
