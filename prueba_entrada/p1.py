"""def resolve_greedy(N, fractions):
    fractions.sort(key=lambda x: x[0] + x[1] + x[2])
    
    max_fractions = 0
    max_a = max_b = max_c = 0

    for i in range(N):
        a, b, c = fractions[i]
        max_a = max(max_a, a)
        max_b = max(max_b, b)
        max_c = max(max_c, c)

        if max_a + max_b + max_c <= 10000:
            max_fractions += 1
        else:
            break

    return max_fractions"""

def resolve(N, fractions):
    def n_persons(fractions, k):
        fractions.sort(key=lambda x: x[0] + x[1] + x[2])
        fractions = fractions[:k] 
        max_a = max(p[0] for p in fractions)
        max_b = max(p[1] for p in fractions)
        max_c = max(p[2] for p in fractions)

        return max_a + max_b + max_c <= 10000
    
    low = 0
    high = N
    result = 0

    while low <= high:
        mid = (low + high) // 2
        if n_persons(fractions, mid):
            result = mid
            low = mid + 1
        else:
            high = mid - 1
    return result

def main():
    input_lines = []
    with open("input_p1.txt", "r") as f:
        input_lines = f.read().splitlines()

    T = int(input_lines[0])
    counter = 1
    for t in range(1, T+1):
        N = int(input_lines[counter])
        fractions = []
        counter += 1
        for _ in range(N):
            a, b, c = map(int, input_lines[counter].split())
            fractions.append((a, b, c))
            counter += 1
        result = resolve(N, fractions)
        print(f"Caso #{t}: {result}")

if __name__ == "__main__":
    main()