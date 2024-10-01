limit = int(input('Enter limit = '))
count = 0
num = 2

while count < limit:
    for i in range(2, num):
        if num % i == 0:
            break
    else:
        print(num, 'is a prime number')
        count += 1
    num += 1

