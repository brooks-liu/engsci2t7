# functions are global variables with attributes (so you can say f.mem = None and basically have a global variable)
        

class AcornEntry:
    def __init__(self, course: str, mark: int):
        self.course = course
        self.mark = mark
    
    def __repr__(self) -> str:   # this is what prints first if you run print(acorn_artsie)
        return f"The mark in {self.course} is {self.mark}"
    
    def __lt__(self, other):   # less than
        if self.course < other.course:
            return True
        elif self.course == self.course:
            return self.mark < other.mark
        else:
            return False
        # or return (self.course, self.mark) < (other.course, other.mark) since python compares tuples in this way
        # if you use .sort() on a list with acornentrys, itll now use this definition to sort them
    

acorn_artsie = AcornEntry("CSC108", 100)
acorn_engsci = AcornEntry("ESC180", 90)

#see queue.py