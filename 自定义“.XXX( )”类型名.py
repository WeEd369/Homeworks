class Person:
    # 初始化方法：定义属性 name 和 age
    def __init__(self, a, b):
        # self.属性名 = 参数 → 给对象绑定属性
        self.name = a  # name 是对象的属性
        self.age = b    # age 是对象的属性

# 创建对象时，传入属性值（无需传self）
p1 = Person("Alice", 20)
p2 = Person("Bob", 18)

# 访问对象的属性：对象.属性名
print(p1.name)  # 输出：Alice
print(p2.age)   # 输出：18