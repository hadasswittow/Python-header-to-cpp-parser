def buildCpp(path):
    file = open(path, encoding="utf8")
    line = file.readline().lstrip()
    # ignore all lines in the file untill the line of the class name
    while not line.startswith("class"):
        line = file.readline().lstrip()
    className = line.split()[1]
    if className.endswith("{"):
        className = className[0:len(className) - 1]
    cppFile = open(f"{className}.cpp", 'w')
    while line != "};\n":
        if line.startswith("/*"):
            while "*/" not in line:
                line = file.readline().lstrip()
        elif ')'in line:
            if '{' in line or f"{className}::" in line: #if the function is implemented in the header
                while '}' not in line:
                    line = file.readline().lstrip()
            else:  # if it is a function and not an attribute
                if "//" in line:  # ignore comments in the middle of function declaration
                    line = line[:line.find("//")]
                line = line.replace(';', '{\n}\n')
                if line.startswith(f"{className}(") or line.startswith(f"~{className}("):  # if the function is a constructor or a destructor
                    full_func_dec = f"{className}::" + line
                else:
                    full_func_dec = line.split()[0] + f" {className}::" + line[line.find(' ')+1:len(line)]
                cppFile.write(full_func_dec)

        line = file.readline().lstrip()
        print(line)
    file.close()
