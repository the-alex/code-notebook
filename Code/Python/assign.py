import time
import random
import sys

# These two lines open a file and load each line into a separate index.
textFile = open(sys.args[1], "r")
challenges = textFile.readlines()
# Remove the newline
for x in xrange(len(challenges)):
    challenges[x] = challenges[x][:-1]

# string : list[integer]
players = {"trevor" : [],
            "nick" : [],
            "anthony" : [],
            "alexZeit" : [],
            "alexChoj" : [],
            "spencer" : []}

# This version generates a random index to a list of challenge numbers, checks
# if it hasn't been used, and then adds that number to the list.
def oldRand():
    for player in players:
        # int : bool
        randSoFar = dict()

        for x in xrange(0, len(challenges)):
            thisRandInt = random.randint(0, len(challenges) - 1)

            # If the number has already been generated, we gen another.
            while thisRandInt in randSoFar:
                thisRandInt = random.randint(0, len(challenges) - 1)

            # Add it to the list of used indicies
            randSoFar[thisRandInt] = True

            # Otherwise we add it to the list of indices
            players[player].append(thisRandInt)

# This version only pulls challenges known to be unused
# and updates the list of valid values after each pull.
def newRand():
    for player in players:
        validChallenges = range(0, len(challenges))
        for x in xrange(0, len(challenges)):
            randIndex = random.randint(0, len(validChallenges) - 1)
            selectedChallenge = validChallenges[randIndex]
            validChallenges = validChallenges[:randIndex] + validChallenges[randIndex + 1:]
            players[player].append(selectedChallenge)


def main():
    print "Number of Challenges:", len(challenges)
    start = time.time()
    newRand()
    print time.time() - start

    # for player in players:
    #     print player + " =", players[player]
    #     print

    start = time.time()
    oldRand()
    print time.time() - start

if __name__ == "__main__":
    main()
