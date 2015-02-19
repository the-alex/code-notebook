from collections import deque



# The following function is based off of a recursive permutation algorithm
# I used on my TSP solution.

def gen_perms(inSuffix, inPrefix = [], runningStructure = []):
    prefix = list(inPrefix)
    suffix = deque(inSuffix)

    if len(suffix) == 0:
        return runningStructure.append(prefix)

    for index in range(len(suffix)):
        prefix.append(suffix[0])
        suffix.popleft()
        gen_perms(suffix, prefix, runningStructure)
        suffix.append(prefix[-1])
        prefix.pop()

    return runningStructure

def main():
    rawr = [1, 2, 3, 4]

    for p in gen_perms(rawr):
        print p


if __name__ == '__main__':
    main()

