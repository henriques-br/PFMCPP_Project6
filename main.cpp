/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

Purpose:  This project will show you the difference between member functions and static class functions, as well as the difference between pointers and references and the code semantics that accompany pointers and references.

 Pointers

 Please look at the screenshot in the files to see what happens if you paste this assignment into an existing cpp file in an xcode project
 
 Task: replace all of the <#place holder#> placeholders with proper names and types that will make this program compile and run.
 
 press the Compile, link and run... button and work your way through all of the error messages.
 

 steps:
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
     Their names (line 105,106) are different than the member variables names (line 77), even tho the placeholders share the same name.
     Don't let this confuse you.
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses smaller's member variable with some safe pointer usage.
    the possible return values of the compare() function should give you a hint.
    Also: if smaller == nullptr, make the cout statement explain the reasons that `f.compare()` might return nullptr.  
    hint: There are multiple reasons
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 13) remember the rules for using pointers!  What is the one thing we always do before we use a pointer?
 Always initialize pointers to nullptr if not assigning them to an object (imediatelly) when we declare them
 Always check if they are nullptr or pointing to a valid object before use them
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
#include <string>
struct T
{
    T(int v, const char* n) : value(v), name(n) {}   //1
    int value;                                       //2
    std::string name;                                //3
};

struct Comparator                                //4
{
    T* compare(T* a, T* b) //5
    {
        if ( a == nullptr || b == nullptr )
        {
            return nullptr;
        }
        if( a->value < b->value ) return a;
        if( a->value > b->value ) return b;
        return nullptr;
    }
};

struct U
{
    float current { 0 }, target { 0 };
    float updateTarget(float* updatedValue)      //12
    {
        std::cout << "U's current value: " << current << std::endl;

        current = *updatedValue;

        std::cout << "U's current updated value: " << current << std::endl;

        while( std::abs(target - current) > 0.001f )
        {
            target += (current - target) * 0.5f;
        }

        std::cout << "U's target updated value: " << target << std::endl;

        return target * current;
    }
};

struct Utility
{
    static float update(U* that, float* updatedValue)        //10
    {
        std::cout << "U's current value: " << that->current << std::endl;
        that->current = *updatedValue;
        std::cout << "U's current updated value: " << that->current << std::endl;
        while( std::abs(that->target - that->current) > 0.001f )
        {
            /*
             write something that makes the distance between that->target and that->current get smaller
             */
            that->target += (that->current - that->target) * 0.5f;
        }
        std::cout << "U's target updated value: " << that->target << std::endl;
        return that->target * that->current;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T firstVariable(5,"First Variable" );                                                    //6
    T secondVariable(4, "Second Variable");                                                  //6
    
    Comparator f;                                                                            //7
    auto* smaller = f.compare(&firstVariable, &secondVariable);                              //8
    
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl;                 //9
    }
    else
    {
        std::cout << "compare() returned nullptr because:\n"
                  << "1. both values are equal\n"
                  << "2. no smaller object exists\n";
    }
    
    U firstU;
    float updatedValue = 5.f;
    std::cout << "[static func] firstU's multiplied values: " << Utility::update(&firstU , &updatedValue) << std::endl;                  //11
    
    U secondU;
    std::cout << "[member func] secondU's multiplied values: " << secondU.updateTarget( &updatedValue ) << std::endl;
}
