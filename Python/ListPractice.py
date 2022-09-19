# books = [1, 2, 3, 4]

# print(books)

# books.append(5)

# print(books)

# books.pop()
# print(books)

# books.insert(2, 8)
# print(books)

dict = {
    "Aditya": [92, 97, 95, 96],
    "Gourav": [70, 76, 94, 94]
}

print(dict)

for keys in dict.keys():
    print(keys)

print(dict.keys())

print(dict["Aditya"])
print(dict["Aditya"][2])
print(dict["Gourav"][2])

insert_DictData = {"Ujjwal": [90, 89, 91, 93]}

dict.update(insert_DictData)

print(dict)