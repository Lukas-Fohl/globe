import re

def main():
    with open("./src.txt","r+") as file:
        data = file.read();
        ndata = data.split("\n")
        for x in ndata:
            print(len(x))
        #print(str(data).split("\n"))

if __name__ == "__main__":
    main()