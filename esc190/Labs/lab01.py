def f():
    global a
    a = 10

a = 5
f()
print(a)

print("hello", a, "yes")