# This is an example of one way to continuously read user input from the
# command line.


def take_user_input():
    """
    Takes user input from the command line until an empty string is entered.
    """
    list_of_strings = list()
    while True:
        inString = raw_input('Enter Input: ')
        if len(inString) == 0:
            break
        else:
            list_of_strings.append(inString)
    return list_of_strings

if __name__ == '__main__':
    # Tests
    user_list = take_user_input()
    print "User Content: "
    print user_list
