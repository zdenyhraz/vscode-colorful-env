class Entity:
    def __init__(self, id, name):
        self.name = name
        self.id = id

    def Hello(self):
        print("Entity ", self.name, "says hello")


def CreateEntities(count):
    for i in range(count):
        if i > count / 2:
            e = Entity(id, name)
            e.Hello()


id = 1
name = "bro"
e = Entity(id, name)
e.Hello()

CreateEntities(3)

print(dir(Entity))
