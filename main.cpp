/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
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
        if (updatedValue == nullptr)
        {
            std::cout << "updatedValue is nullptr\n";
            return 0.f;
        }
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
        if (that == nullptr)
        {
            std::cout << "that is nullptr\n";
            return 0.f;
        }
        if (updatedValue == nullptr)
        {
            std::cout << "updatedValue is nullptr\n";
            return 0.f;
        }
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
