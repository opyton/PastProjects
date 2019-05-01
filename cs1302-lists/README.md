# CSCI 1302 - Lists

This document contains the description for the Lists project
assigned to the students in the Spring 2018 CSCI 1302 classes
at the University of Georgia.

**Read the entirety of this file before
beginning your project.** 

## Due Dates

This project is **DUE FRI 2018-03-09 @ 11:55 PM EST**.

## Academic Honesty

You agree to the Academic Honesty policy as outlined in the course syllabus and
course website. In accordance with this notice, I must caution you to **not** 
fork this repository on GitHub if you have an account. Doing so will more than
likely make your copy of the project publicly visible. Please follow the 
instructions contained in the Resources section below in order to do your 
development on nike.

## Updates

Updates will be posted here. You will be informed about any changes 
through **Piazza** and **eLC** so please keep a lookout for them.

## Project Description

In this project, you will be providing two different implementations of
a generic ```List``` interface, which defines different operations that one
should be able to do with a *list*. A list is simply an object that represents 
an ordered collection of elements. The list implementation can decide how the
elements are stored internally so long as users are able to interact with
those elements via the methods defined in the interface. In this way, a list
is an example of an *abstract data type* (ADT). To put it another way: while 
the implementor needs to undertand the specific details of the implementation
(in order to write the code to make it happen), the user of a list does not. 
The users simply interact with objects of the list implementation through
the methods defined in the interface. 

Each implementation will be a generic class with specific functional
and non-functional requirements. These classes need to implement ```List<T>```
and override its methods to provide their functionality. 

In addition to the Javadoc comments in 
<a href="src/main/java/cs1302/p3/List.java">```cs1302.p3.List```</a>,
the HTML documention for the ```List<T>``` interface is available 
<a href="http://cobweb.cs.uga.edu/~mec/cs1302/lists-apidocs/cs1302/p3/List.html">here</a>.
Implementors should make sure that each method functions or behaves as described
by its documentation, except in cases where a functional requirement changes
the behavior of the method. Whenever an overridden method's behavor differs from
how it's described in the ```List<T>``` interface, this new behavor should be 
documented using Javadoc. 

Implementors are always free to implement additional methods in addition
to the ones defined by the interface. However, they should not assume that
users will use them (even if declared with ```public``` visibility), since
they are not defined in the interface. These additional methods may help
avoid redundancy and promote code reuse within an implementation.

### Learning Outcomes

* Implement generic classes according to an interface (1302-LO1).
* Utilitze inheritance and polymorphism in a software project (1302-LO3-LO4).
* Test your implementation using unit tests (1302-LO9).

### Functional Requirements

* **```ArrayList<T>```:** Create the ```cs1302.p3.ArrayList``` generic class
  with type parameter ```T``` such that it properly implements the 
  ```cs1302.p3.List<T>``` interface with the requirements listed below.

  * The generic type parameter is not bounded.

  * The ```add(T)``` method adds an element to the end of the list. The Javadoc
    documentation for this methods should clearly indicate this behavior.

  * You must explicitly define a default constructor for this class. The
    initial size of an ```ArrayList<T>``` is ```0``` regardless of your
    actual internal array capacity. 

  * **Extra Credit (5 points):** Override the ```iterator()``` method for your
    ```ArrayList``` class as described in the ```List``` interface. This may 
    require you to create an additional class that implements another interface.

* **```SortedArrayList<T extends Comparable<T>>```:** Create the 
  ```cs1302.p3.SortedArrayList``` generic class with bounded type parameter 
  ```T``` such that it properly implements the ```cs1302.p3.List<T>``` 
  interface with the requirements listed below. 

  * The generic type parameter is bounded by ```java.util.Comparable<T>```
    in order to enable comparisons between existing and or prospective 
    elements of the list.

  * The ```add(T)``` and ```add(int, T)``` methods are implemented such that 
    elements are added to the list in sorted order, regardless of the index 
    position specified. The Javadoc documentation for these methods should 
    clearly indicate this behavior.

  * You must explicitly define a default constructor for this class. The
    initial size of a ```SortedArrayList<T>``` is ```0``` regardless of your
    actual internal array capacity. 

  * **Design Choice:** Whether or not this class extends your ```ArrayList```
    class is entirely up to you. The only functional requirements are that
    it implements the interface as described above. 

  * **Extra Credit (5 points):** Override the ```iterator()``` method for your
    ```SortedArrayList``` class as described in the ```List``` interface. This 
    may require you to create an additional class that implements another 
    interface.

### Non-Functional Requirements

* **Storage:** In general, when implementing an interface for a collection ADT
  (i.e., something that represents objects that contain other objects), the
  implementor gets to decide how the implementation stores the collection of
  elements. For this project, each list implementation should store its elements
  using an array of type ```Box<T>[]```. Ideally, we would want an array of type 
  ```T[]```, but Java does not allow the creation of generic arrays. The 
  ```Box<T>``` class provides a generic static method for the creation of arrays
  with type ```Box<T>[]```. The ```Box<T>``` class is  provided to you in 
  <a href="src/main/java/cs1302/p3/Box.java">```cs1302.p3.Box```</a>.
  The HTML documention for the ```Box<T>``` class is available 
  <a href="http://cobweb.cs.uga.edu/~mec/cs1302/lists-apidocs/cs1302/p3/Box.html">here</a>.
  Since users of an ADT implementation do not interact with the underlying
  storage directly (and only through the methods defined in the interface),
  this non-functional requirement is transparent to users. However, using an
  array of generic "boxes", each containing an element of type ```T```, does increase
  the level of abstraction for the implementor.  To create an array of type 
  ```Box<T>[]``` use the static 
  <a href="http://cobweb.cs.uga.edu/~mec/cs1302/lists-apidocs/cs1302/p3/Box.html#array-int-">```array```</a>
  method. Since, in this project,  a list implementation is using its internal 
  array as storage for its elements, the internal array capacity must always be at 
  least the size of the list that uses it. You should grow and shrink the array 
  as needed. It reccommended that you make support methods to help streamline this 
  process as needed. 

* **Javadoc Documentation:** Each method and class needs to be documented
  using Javadoc comments. If a method overrides an inheritted method that is
  already documented, then that method only needs a Javadoc comment if the
  implementation differs from the existing documentation. 

* **In-line Documentation:** Code blocks should be adequately documented
  using in-line comments. This is especially necessary when a block of code
  is not immediately understood by a reader (e.g., the grader). 

### Grading

This project will be graded using unit tests that will not be made available
before the project deadline. It is paramount that you do not modify the
<code>List</code> interface provided by the project's skeleton code in any
way. It is also very important that you follow the package and naming
conventions for the <code>ArrayList</code> and <code>SortedArrayList</code>
classes described in this project description. Modifying the provided 
interface and or not following the naming conventions outlined in this
project description will cause the unit tests to automatically fail. 

TL;DR - Do not modify the provided interfaces and classes; Follow naming 
conventions. **If not, then your project will not be graded.**

## Getting/Updating Skeleton Code

On Nike, execute the following terminal command in order to download the project
files into sub-directory within your present working directory:

```
$ git clone https://github.com/cs1302uga/cs1302-lists.git
```

This should create a directory called <code>cs1302-lists</code> in
your present working directory that contains the project files.

If any updates to the project files are announced by your instructor, you can
merge those changes into your copy by changing into your project's directory
on Nike and issuing the following terminal command:

```
$ git pull
```

If you have any problems with any of these procedures, then please contact
your instructor.

## Submission Instructions

You will be submitting your project via Nike before the deadline indicated
near the top of this document. Make sure your project files
are on <code>nike.cs.uga.edu</code>. Change into the parent directory of your
project directory. If you've followed the instructions provided in this document, 
then the name of your project directory is likely <code>cs1302-lists</code>. 
While in your project's parent directory, execute the following command: 

```
$ submit cs1302-lists cs1302a
```

It is also a good idea to email a copy to yourself. To do this, simply execute 
the following command, replacing the email address with your email address:

```
$ tar zcvf cs1302-lists.tar.gz cs1302-lists
$ mutt -s "[cs1302] cs1302-lists" -a cs1302-lists.tar.gz -- your@email.com < /dev/null
```

If you have any problems submitting your project then please send a private
post to your instructor via the course Piazza as soon as possible. However, 
creating a post about something like this the day or night the project is due 
is probably not the best idea.

# Supplement

## FAQ

Below are some frequently asked questions related to this project.


1. **What's the difference between ```throw``` and ```throws```?**
   
   From a user's perspective, when a method signature indicates that it ```throws```
   an exception, this is an indication to users of that method that they should 
   use a try-catch block when invoking that method, since an exceptional (and 
   usually documented) case can occur. From an implementor's perspective, the 
   ```throws``` keyword indicates that the method *may* ```throw``` an exception
   under certain exceptional (and usually documented) cases. For example, if
   a method's documentation indicates that it ```throws NullPointerException```
   when a parameter called ```elem``` is ```null```, then the implementor might
   place the following near the top of that method's implementaiton:

   ```java
   if (elem == null) throw new NullPointerException("elem cannot be null");
   ```

2. **How do I determine the type of ```Object list``` in the ```equals(Object)``` method?**

   Ideally, you would check that ```list``` is an instance of ```List<T>```.
   However, Java does not allow this since any ```List<T>``` gets erased to
   ```List``` during type erasure due to the involvement of a generic type 
   parameter. Instead, you need to check if ```list``` is an instance of the 
   raw type ```List```. This will result in all elements being of ```list```
   being treated as type ```Object```, regardless of their actual type. This
   is perfectly okay since you will be performing equality tests between
   elements of the current list and ```list``` using the ```equals(Object)```
   method. This also means that ```list``` can be an object of any 
   implementation of the ```List<T>``` interface. It does not have to the
   same implementation as the calling object.

   If ```list instanceof List``` is ```true```, then it is safe to cast the
   reference to a ```List``` (e.g., ```List l = (List) list```). This will
   give you access to the ```get(int)``` method via the casted reference
   (e.g., ```l.get(0)```) for, potentially, the purpose of comparing it to
   an element in the current list in the same position.


3. **How do I include the interface's Javadoc for a method in addition to my own without copy/paste?**

   You can use the ```{@inheritDoc}``` tag near the end of the description
   in your method's Javadoc comment to include the original documentation.
   For example, you might do the following:

   ```java
   /**
    * Short one line description. This is the rest of the description. It may
    * involve several sentences.
    *
    * <p>
    * {@inheritDoc}
    *
    * @param p string called p (never write this)
    */
   public void foo(String p) { 
       /** ... */ 
   } // foo
   ```

   It is common practice to include the more specific documentation first, 
   followed by more general documentation, if needed.

Have a question? Please post it on the course Piazza.

<hr/>

[![License: CC BY-NC-ND 4.0](https://img.shields.io/badge/License-CC%20BY--NC--ND%204.0-lightgrey.svg)](http://creativecommons.org/licenses/by-nc-nd/4.0/)

<small>
Copyright &copy; 2018 Michael E. Cotterell and the University of Georgia.
This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/4.0/">Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License</a> to students and the public.
The content and opinions expressed on this Web page do not necessarily reflect the views of nor are they endorsed by the University of Georgia or the University System of Georgia.
</small>
