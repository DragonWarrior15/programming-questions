# Runtime Errors
While solving the problems on an online Judge, many runtime errors can be faced, which are not clear by the message which comes with them. Lets try to understand these errors.

To get clear about the definition of run time error:
A runtime error means that the program was compiled successfully, but it exited with a runtime error or crashed. You will receive an additional error message, which is most commonly one of the following:

### 1) SIGSEGV
This is the most common error, i.e., a "segmentation fault". This may be caused e.g. by an out-of-scope array index causing a buffer overflow, an incorrectly initialized pointer, etc. This signal is generated when a program tries to read or write outside the memory that is allocated for it, or to write memory that can only be read. For example, you’re accessing a[-1] in a language which does not support negative indices for an array.

### 2) SIGXFSZ
"output limit exceeded". Your program has printed too much data to output.

### 3) SIGFPE
"floating point error". This usually occurs when you’re trying to divide a number by 0, or trying to take the square root of a negative number.

### 4) SIGABRT
These are raised by the program itself. This happens when the judge aborts your program in the middle of execution. Due to insufficient memory, this can be raised.

### 5) NZEC
(non-zero exit code) - this message means that the program exited returning a value different from 0 to the shell. For languages such as C/C++, this probably means you forgot to add "return 0" at the end of the program. It could happen if your program threw an exception which was not caught. Trying to allocate too much memory during code execution may also be one of the reasons.

For interpreted languages like Python, NZEC will usually mean that your program either crashed or raised an uncaught exception. Some of the reasons being in such cases would be: the above mentioned runtime errors. Or, for instance usage of an external library which is causing some error, or not being used by the judge.

### 6) MLE (Memory Limit Exceeded)
This error means that your program tried to allocate memory beyond the memory limit indicated. This can occur if you declare a very large array, or if a data structure in your program becomes too large.

### 7) OTHER
This type of error is sometimes generated if you use too much memory. Check for arrays that are too large, or other elements that could grow to a size too large to fit in memory. It can also be sometimes be generated for similar reasons to the SIGSEGV error.

Some ways to avoid runtime errors:
1) Make sure you aren't using variables that haven't been initialized. These may be set to 0 on your computer, but aren't guaranteed to be on the judge.
2) Check every single occurrence of accessing an array element and see if it could possibly be out of bounds.
3) Make sure you aren't declaring too much memory. 64 MB is guaranteed, but having an array of size [100000] * [100000] will never work.
4) Make sure you aren't declaring too much stack memory. Any large arrays should be declared globally, outside of any functions, as putting an array of 100000 ints inside a function probably won't work.

# Acceptable Runtimes
The table below is to help understand the growth of several common time complexities, 
and thus help judge if the algorithm is fast enough to get an Accepted ( assuming the algorithm is correct ).
Length of Input (N) | Worst Accepted Algorithm
------------------- | ------------------------
<= [10..11] | O(N!), O(N<sup>6</sup>)
<= [15..18] | O(2<sup>N</sup> * N<sup>2</sup>)
<= [18..22] | O(2<sup>N</sup> * N)
<= 100 | O(N<sup>4</sup>)
<= 400 | O(N<sup>3</sup>)
<= 2k | O(N<sup>2</sup> * logN)
<= 10k | O(N<sup>2</sup>)
<= 1M | O(N * logN)
<= 100M | O(N), O(logN), O(1)

# Useful Operators
<table>
    <head>
        <tr>
        <th>Symbol</th>
        <th>Operation</th>
        <th>Usage</th>
        <th>Explanation</th>
        </tr>
    </head>
    <tr>
        <td>&amp;</td>
        <td>bitwise AND</td>
        <td>x &amp; y</td>
        <td>sets the bit if set in both operands</td>
    </tr>
    <tr>
        <td>|</td>
        <td>bitwise OR</td>
        <td>x | y</td>
        <td>sets the bit if set in either operands</td>
    </tr>
    <tr>
        <td>^</td>
        <td>bitwise XOR</td>
        <td>x ^ y</td>
        <td>sets the bit if set in one operand bubt not both</td>
    </tr>
    <tr>
        <td>~</td>
        <td>bitwise NOT</td>
        <td>~x</td>
        <td>unary operator that flips bits</td>
    </tr>
    <tr>
        <td>&lt;&lt;</td>
        <td>left shift</td>
        <td>x &lt;&lt; y</td>
        <td>shits bits of x left by y bits, equivalent to multiply by 2<sup>y</sup></td>
    </tr>
    <tr>
        <td>&gt;&gt;</td>
        <td>right shift</td>
        <td>x &gt;&gt; y</td>
        <td>shits bits of x right by y bits, equivalent to divide by 2<sup>y</sup></td>
    </tr>
</table>

