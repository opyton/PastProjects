Nathaniel Lee

1.Vocab:
unit testing - testing the smallest unit of a program. Ex. testing that the method getNum() would return a number
integration testing - testing of a group of units to ensure they work together. Ex. would include
	ensuring a class that calls a method will operate as intended.
system testing - testing the entire program to ensure it operates as intended.
test driven development - the process of developing and improving a program through the use of repeated small
	case testing. 
JUnit 5 - similar to jdk, it is a combination of several softwares (platform + jupiter + vintage)
JUnit Platform - foundation for launching frameworks on the jvm.
JUnit Jupiter - used to write tests and extensions in junit
JUnit Vintage - test engine for running old junit models (3 and 4)

6.
project.build.sourceEncoding - according to the maven FAQ, this is used to 
	set encoding
java.version - sets java version
junit.jupiter.version- sets the version of junit jupiter
junit.platform.version - sets the version of junit platform

9.
Experience with JUnit testing. Initially I ran into a few errors with the tester saying my basicSalary class
was pointing too a null. This was resolved by omitting BasicSalaryCalculator from the code 
BasicSalaryCalculator basicSalaryCalculator = new BasicSalaryCalculator() as the class was already
instantiated as a private variable earlier in the code. Otherwise, the instructions were clear and made sense. There was
no cause for confusion due to vague instruction.

Further Questions:
1. @BeforeEach - annotation to ensure method happens before each test
2. @AfterEach - ensures the method happens after each test
3. @Test - method used for testing
4. Assertions.assertEquals - java method that returns a false and ends the program if the values do not equal each  other
5. Assertion.assertThrows - method that returns false and ends program if the specified exception is not thrown
