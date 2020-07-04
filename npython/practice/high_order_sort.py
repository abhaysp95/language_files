lst = ["Siddhi", "Tarun", "Shivam", "Subhanshu", "Smriti"]
lst.sort(reverse=True)
print(lst)
tup = tuple(lst)
print(sorted(tup))

stu = [
    ("Reetika", 18, 'Allahabad'),
    ("Abhay", 25, 'Varanasi'),
    ("Subhanshu", 21, 'Kanpur'),
    ]
print(stu.sort())

age = lambda stuage:stuage[1]
print(age)
stu.sort(key=age)
print(stu)

stu.sort(key=lambda adr:adr[2])
print(stu)
