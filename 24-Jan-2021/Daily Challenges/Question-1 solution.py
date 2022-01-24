def reverseArray(given, flag):
    if(flag):
        # USING INBUILT METHOD
        given.reverse()
    else:
        # IMPLEMENTING ON MY OWN
        for i in range((len(given)-1)/2):
            temp = given[i]
            given[i] = given[len(given)-1]
            given[len(given)-1] = temp


if __name__ == "__main__":
    given = input().split()
    reverseArray(given, True)
    print(" ".join(given))