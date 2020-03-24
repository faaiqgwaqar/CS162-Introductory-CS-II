Week 4 Lab Exercise
===================

This is the repo for CS 162's Lab #4.  You will commit your source code files into this repository for the TAs to check off.  The description of the lab exercise is below and can also be found here:

https://docs.google.com/document/d/1MN-PX8HAxpi7eagDanX5TR2F1E-tyVJf7_tMpxZCQ5w/edit?usp=sharing

In this lab, you’ll start to explore using C++ classes by getting a head-start on Assignment 2.

## Step 1: Clone the git repository for this lab

We’re going to use git and GitHub Classroom again for this lab.  Just like you did for the previous lab exercises, use git clone to download your repository onto your development machine using the clone URL from your repo on GitHub:
```
git clone REPO_URL
```

## Step 2: Implement the `Card` class from Assignment 2

In [Assignment 2](https://classroom.github.com/a/phbOO7kT), you must implement several C++ classes and use them to write a Go Fish game.  In this lab, we’ll implement and test a few of those classes.  The first one you’ll implement is the `Card` class, which represents a single playing card:
```c++
class Card {
  private:
    int rank;  // Should be in the range 0-12.
    int suit;  // Should be in the range 0-3.
  public:
  // constructors, destructor, accessors, and mutators
};
```

You’ll need to implement the needed constructors, destructors, accessor functions, and mutator methods.  To do this, think carefully about what operations (if any) you’ll need to perform on an individual card and what information you’ll need to be able to get from the card.  Put the definition for this class in `card.hpp` and the implementation in `card.cpp`.  Once these files are done add and commit them to your git repo, and push them to GitHub.

## Step 3: Implement the `Deck` class from Assignment 2

Once you have a class to represent a single card, you can implement your class to represent a whole deck of 52 cards:
```c++
class Deck {
  private:
    Card cards[52];
    int n_cards;  // Number of cards remaining in the deck.
  public:
  // constructors, destructor, accessors, and mutators
};
```

Again, in addition to the attributes outlined above, you’ll need to implement any needed constructors, destructors, accessor, and mutator methods.  Again, think about what operations need to be performed on a deck of cards.  For shuffling, you’ll want to use [C++’s rand() function](http://www.cplusplus.com/reference/cstdlib/rand/).  Put the definition for this class in `deck.hpp` and the implementation in `deck.cpp`.  Once these files are done add and commit them to your git repo, and push them to GitHub.

## Step 4: Implement the `Hand` class from Assignment 2

Now that you have classes to represent cards and a deck, you should be able to implement the class to represent a player’s hand of cards:
```c++
class Hand {
  private:
    Card* cards;
    int n_cards;  // Number of cards in the hand.
  public:
  // constructors, destructor, accessors, and mutators
};
```

When writing the methods for this class, make sure you write a method to print the hand out to `std::cout`.  Put the definition for this class in `hand.hpp` and the implementation in `hand.cpp`.  Once these files are done add and commit them to your git repo, and push them to GitHub.

## Step 5: Write a small application to deal a hand of cards

In order to test your classes, write a small program that uses them to do the following things:
  * Initializes a new deck of 52 cards.
  * Shuffles that deck.
  * Deals a hand of 7 cards.
  * Prints the contents of that hand to the console.

Put this program in `deal_hand.cpp`.  Also, add a `Makefile` to compile your program.  Once these files are done add and commit them to your git repo, and push them to GitHub.

## Grading Criteria
That’s it!  After you’re done with your lab, make sure you get it checked off by your TA so that you get points for it.  If you don’t get your work checked off, you’ll receive a zero for the lab, and we won’t be able to change your grade, since we’ll have no way to know whether or not you were at the lab.

This lab is worth 10 points total.  Here’s the breakdown:
  * 1 point: your `Card` class is implemented and committed and pushed to your repository on GitHub (i.e.   everything through Step 2 is done).
  * 3 points: your `Deck` class is implemented and committed and pushed to your repository on GitHub (i.e.  everything through Step 3 is done).
  * 3 points: your `Hand` class is implemented and committed and pushed to your repository on GitHub (i.e.  everything through Step 4 is done).
  * 3 points: your `deal_hand` program works correctly and is committed and pushed to your repository on GitHub   (i.e. everything through Step 5 is done).
