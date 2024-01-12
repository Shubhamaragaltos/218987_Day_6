#include <iostream>
#include <future>
/*
option 1: one after the other. Always complete one thing before starting the
          next week.

          name: single thread technique
//////////////////////////////////////////////////////////////////////////////////
Option 2: I will complete all task in such a way that i "practically stat all
            of them at the same time" but keep juggling them based on some
            criteria

            name : multi-threaded approach
//////////////////////////////////////////////////////////
Option 3: Map number of tasks amongst number of available "workers"

            name: Parallel execution
////////////////////////////////////////////////////////
Option 4: start a task. Either delegate it to another worker OR do it yourself
          after some time.
          if someone else is doing a task, monitor it, wait for their work
          to be done, take follow-up actions accrodingly

          name : Asynchronous excecution
/////////////////////////////////////////////////
*/

int square(std::future<int> &ft)
{
    std::cout << "\nHello from square. I have started my work";
    std::this_thread::sleep_for(std::chrono::seconds(0));
    int number = ft.get();
    return number * number;
}
int factorial(int number)
{
   // std::this_thread::sleep_for(std::chrono::seconds(2));

    if (number < 0)
    {
        throw std::runtime_error("negative number error");
    }
    else if (number == 0 || number == 1)
    {
        return 1;
    }

    else
    {
        return number * factorial(number - 1);
    }
}
int main()
{
    // step 1: make a promise
    std::promise<int> pr;

    // setp 2: future linked to the promise
    std::future<int> ft = pr.get_future();

    // OS: launch Square (if possible as a new thread)
    std::future<int> result_ft = std::async(std::launch::async, &square, std::ref(ft));

    int val = 0;
    std::cin >> val;
    pr.set_value(val);

    std::cout << factorial(5);
        std::cout << " Result of Square is: " << result_ft.get()<<"\n";


    //

}

/*
future-promise model



Square Calculation

main needs to delegate the task of square calculation

-----> A new thread for square will be registered with OS




*/
