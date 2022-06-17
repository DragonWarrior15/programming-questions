from collections import deque


def print_stack(x):
    # for debugging
    print([k for k in x])


def decompress(s):
    """
    decompress a string of the representation number[char]
    input : 2[a]3[b], output : aabbb
    the brackets can be nested inside one another
    input : 2[a3[b]], output : abbbabbb
    """
    num_stack = deque()
    char_stack = deque()
    output = ""
    index = 0
    while index != len(s):
        # print_stack(num_stack)
        # print_stack(char_stack)
        c = s[index]
        # check if digit
        if 48 <= ord(c) and ord(c) <= 57:
            if len(num_stack) == 0:
                num_stack.append(c)
            else:
                num_stack.append(num_stack.pop() + c)
        # check if brackets
        elif c == "[":
            char_stack.append("")
            num_stack.append("")
        elif c == "]":
            try:
                x = num_stack.pop()
                if x != "":
                    num_stack.append(x)
            except e:
                pass
            if len(num_stack) == 1 and len(char_stack) == 1:
                output += int(num_stack.pop()) * char_stack.pop()
            elif len(num_stack) > 1 and len(num_stack) == len(char_stack):
                temp_output = int(num_stack.pop()) * char_stack.pop()
                char_stack.append(char_stack.pop() + temp_output)
            elif len(num_stack) < len(char_stack):
                num_stack.append("1")
                output += int(num_stack.pop()) * char_stack.pop()
            else:
                print("Not Possible")
        elif 97 <= ord(c) and ord(c) <= 122:
            if len(char_stack) == 0:
                char_stack.append(c)
            else:
                char_stack.append(char_stack.pop() + c)
        index += 1
    if len(num_stack) == 1 and len(char_stack) == 1:
        output += int(num_stack.pop()) * char_stack.pop()
    elif len(num_stack) > 1 and len(num_stack) == len(char_stack):
        temp_output = int(num_stack.pop()) * char_stack.pop()
        char_stack.append(char_stack.pop() + temp_output)
    elif len(num_stack) < len(char_stack):
        num_stack.append("1")
        output += int(num_stack.pop()) * char_stack.pop()
    else:
        print("Not Possible")
    return output


decompress("a[]b")
# 'ab'
decompress("1[1[1[1[1[1[1[1[1[1[1[1[1[1[1[1[1[1[1[1[xx]]]]]]]]]]]]]]]]]]]]")
# 'xx'
decompress("2[a]3[c]b")
"aacccb"
decompress("2[a]3[c]b")
# aacccb
decompress("2[a3[b]]")
# abbbabbb
