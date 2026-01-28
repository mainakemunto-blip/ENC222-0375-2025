import math
#Survey Point 
class SurveyPoint3D:
    def __init__(self, x, y, elevation):
        self.x = x
        self.y = y
        self.elevation = elevation

#Grid Cell
class GridCell:
    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.elevation = 0  # default, will be overwritten by interpolation

#DEM Generator
class DEMGenerator:
    def __init__(self, points):
        self.points = points

    # IDW interpolation
    def interpolate(self, x, y):
        top = 0
        bottom = 0
        for pt in self.points:
            dx = x - pt.x
            dy = y - pt.y
            dist = math.sqrt(dx*dx + dy*dy)
            if dist == 0:
                return pt.elevation
            weight = 1 / (dist * dist)  # IDW with power = 2
            top += weight * pt.elevation
            bottom += weight
        return top / bottom

    # Generate DEM grid
    def generate_grid(self, xmin, xmax, ymin, ymax, size):
        grid = []
        x = xmin
        while x <= xmax:
            y = ymin
            while y <= ymax:
                cell = GridCell(x, y)
                cell.elevation = self.interpolate(x, y)
                grid.append(cell)
                y += size
            x += size
        return grid

#Contour Segment
class ContourSegment:
    def __init__(self, x1, y1, x2, y2, level):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2
        self.level = level

#Contour Generator
class ContourGenerator:
    def generate_contours(self, grid, interval):
        contours = []
        for i in range(len(grid)-1):
            z1 = grid[i].elevation
            z2 = grid[i+1].elevation

            low = int(min(z1, z2) // interval)
            high = int(max(z1, z2) // interval)

            for l in range(low, high+1):
                level = l * interval
                if (level >= z1 and level <= z2) or (level >= z2 and level <= z1):
                    c = ContourSegment(grid[i].x, grid[i].y,
                                       grid[i+1].x, grid[i+1].y,
                                       level)
                    contours.append(c)
        return contours

#Main
if __name__ == "__main__":

    #Survey points
    points = [
        SurveyPoint3D(36.995, -1.095, 200),
        SurveyPoint3D(37.015, -1.105, 120),
        SurveyPoint3D(37.025, -1.115, 150),
        SurveyPoint3D(37.045, -1.085, 250)
    ]

    #Generate DEM
    dem = DEMGenerator(points)
    xmin = 36.99
    xmax = 37.05
    ymin = -1.12
    ymax = -1.08
    grid_size = 0.005

    grid = dem.generate_grid(xmin, xmax, ymin, ymax, grid_size)

    #Generate contours
    cg = ContourGenerator()
    contour_interval = 10  # 10m interval
    contours = cg.generate_contours(grid, contour_interval)

    #Print first 20 contour segments
    print("First 20 contour segments:")
    for c in contours[:20]:
        print(f"Contour {c.level}m: ({c.x1},{c.y1}) to ({c.x2},{c.y2})")

    print(f"\nTotal contour segments generated: {len(contours)}")
