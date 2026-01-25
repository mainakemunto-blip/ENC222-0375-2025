# Base class
class Square:
    def __init__(self, side=0):
        self.side = side

    def getPeri(self):
        return 4 * self.side

    def getArea(self):
        return self.side * self.side
# Derived class
class Cube(Square):
    def __init__(self, side=0):
        super().__init__(side)

    def getArea(self):
        return 6 * self.side * self.side

    def getVolume(self):
        return self.side * self.side * self.side
# Main program
sq = Square(15)
print("Square Perimeter:", sq.getPeri())
print("Square Area:", sq.getArea())

cb = Cube(15)
print("Cube Surface Area:", cb.getArea())
print("Cube Volume:", cb.getVolume())
