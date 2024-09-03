def ExtendedGCD(a, b):
    x0, x1 = 1, 0
    y0, y1 = 0, 1

    while b != 0:
        q = a // b
        r = a % b
        a = b
        b = r
        x = x0 - q * x1
        y = y0 - q * y1
        x0, x1 = x1, x
        y0, y1 = y1, y

    return a, x0, y0

def main():
    a = int(input("Enter First Number : "))
    b = int(input("Enter Second Number : "))
    g, x, y = ExtendedGCD(a, b)
    print(f"GCD is {g}, x is {x}, y is {y}\nSuch that ax + by = GCD(a,b)")

if __name__ == "__main__":
    main()
