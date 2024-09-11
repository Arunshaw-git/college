import csv
import sys


def main():

    database=[]
    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py (CSV) and (Text) ")


    # TODO: Read database file into a variable
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for data in reader:

                database.append(data)


    # TODO: Read DNA sequence file into a variable

    with open(sys.argv[2]) as file:
        dnasequence =file.read()

    subsequences= []
    subsequences = list (database[0].keys())[1:]

    # TODO: Find longest match of each STR in DNA sequence
    result={}

    for i in range(len(subsequences)):

      longest_run =  longest_match(dnasequence,subsequences[i])
      result[subsequences[i]]=longest_run

    # TODO: Check database for matching profiles
    for j in database:
        match =0
        for sequence in subsequences:
            if result[sequence]==int(j[sequence]):
                 match +=1

        if match == len(subsequences):
            print(j['name'])
            return


    print('no match')



def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
