from cs50 import get_string


def main():

     text = get_string("Text : ")
     letters = count_letters(text)
     words = count_words(text)

     sentences = count_sentences(text)

     L = float (((letters * 100) / words))
     S = float((sentences * 100) / words)

     index = (0.0588 * L) - (0.296 * S) - 15.8
     r_index = round(index)

     if r_index<1:
          print("before grade 1")
     elif r_index <16:
          print("Grade ", r_index)
     else:
          print("Grade 16+")



def count_letters(input_string):
    count = 0
    for char in input_string:
        if char.isalpha():
            count += 1
    return count


def count_words(input_string):
    words = input_string.split()
    return len(words)




def count_sentences(str1):

    count=0

    for str in str1:
        if(str=='!' or str =="?" or str =="."):
                count+=1

    return count


main()