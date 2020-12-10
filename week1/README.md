# Week 1 C

## Requirements

### [Mario](https://cs50.harvard.edu/x/2020/psets/1/mario/more/)

Let’s recreate those pyramids in C, albeit in text, using hashes (#) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramids themselves are also be taller than they are wide.

```c
   #  #
  ##  ##
 ###  ###
####  ####
```

The program we’ll write will be called mario. And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.

Here’s how the program might work if the user inputs 8 when prompted:

```c
$ ./mario
Height: 8
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########
```

If the user doesn’t, in fact, input a positive integer between 1 and 8, inclusive, when prompted, the program should re-prompt the user until they cooperate:

```c
$ ./mario
Height: -1
Height: 0
Height: 42
Height: 50
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
```

Notice that width of the “gap” between adjacent pyramids is equal to the width of two hashes, irrespective of the pyramids’ heights.

### [Credit](https://cs50.harvard.edu/x/2020/psets/1/credit/)

- American Express uses 15-digit numbers
- MasterCard uses 16-digit numbers
- Visa uses 13- and 16-digit numbers.

And those are decimal numbers (0 through 9), not binary, which means, for instance, that American Express could print as many as `10^15 = 1,000,000,000,000,000` unique cards! (That’s, um, a quadrillion.)

- All American Express numbers start with `34` or `37`
- most MasterCard numbers start with `51`, `52`, `53`, `54`, or `55` (they also have some other potential starting numbers which we won’t concern ourselves with for this problem)
- all Visa numbers start with `4`.

But credit card numbers also have a “checksum” built into them, a mathematical relationship between at least one number and others. That checksum enables computers (or humans who like math) to detect typos (e.g., transpositions), if not fraudulent numbers, without having to query a database, which can be slow.

According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

In a file called `credit.c` in a `~/pset1/credit/` directory, write a program that prompts the user for a credit card number and then reports (via `printf`) whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein. So that we can automate some tests of your code, we ask that your program’s last line of output be `AMEX\n` or `MASTERCARD\n` or `VISA\n` or `INVALID\n`, nothing more, nothing less. For simplicity, you may assume that the user’s input will be entirely numeric

(i.e., devoid of hyphens, as might be printed on an actual card).

But do not assume that the user’s input will fit in an int! Best to use `get_long` from CS50’s library to get users’ input. (Why?)

Consider the below representative of how your own program should behave when passed a valid credit card number (sans hyphens).

```c
$ ./credit
Number: 4003600000000014
VISA
```

Now, get_long itself will reject hyphens (and more) anyway:

```c
$ ./credit
Number: 4003-6000-0000-0014
Number: foo
Number: 4003600000000014
VISA
```

But it’s up to you to catch inputs that are not credit card numbers (e.g., a phone number), even if numeric:

```c
$ ./credit
Number: 6176292929
INVALID
```

Test out your program with a whole bunch of inputs, both valid and invalid. (We certainly will!) Here are [a few card numbers](https://developer.paypal.com/docs/classic/payflow/payflow-pro/payflow-pro-testing/#credit-card-numbers-for-testing) that PayPal recommends for testing.

## Reference

- More details on [Course Page](https://cs50.harvard.edu/x/2020/psets/1/)
