n = int(input())

# edge cases
print(0)
if n > 1:
    print(6)

series = 0

# summation pattern
for i in range(3, n + 1):
    combinations = int((i ** 2) * (i ** 2 - 1) / 2)
    series += i - 2
    value = combinations - (8 * series)
    print(value)
