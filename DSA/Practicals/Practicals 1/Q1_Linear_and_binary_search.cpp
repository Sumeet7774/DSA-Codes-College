// 1. Linear search for int,float and string array
//    Binary search for int and float array

#include <bits/stdc++.h>
using namespace std;
class linearSearch
{
public:
    void int_linear_search(int intArr[], int n, int element)
    {
        int elementIndex = -1; // we have to initialize the answer to -1 because otherwise it wont print else part

        for (int i = 0; i < n; i++)
        {
            if (intArr[i] == element)
            {
                elementIndex = i;
                break;
            }
        }

        if (elementIndex != -1)
        {
            cout << "The element " << element << " is found at index: " << elementIndex << endl <<endl;
        }
        else
        {
            cout << "The element " << element << " is not there in the array" << endl;
        }
    }

    void float_linear_search(float floatArr[], int n, float element)
    {
        int elementIndex = -1;

        for (int i = 0; i < n; i++)
        {
            if (floatArr[i] == element)
            {
                elementIndex = i;
                break;
            }
        }

        if (elementIndex != -1)
        {
            cout << "The element " << element << " is found at index: " << elementIndex << endl << endl;
        }
        else
        {
            cout << "The element " << element << " is not there in the array" << endl;
        }
    }

    void string_linear_search(string stringArr[], int n, string element)
    {
        int elementIndex = -1;

        for (int i = 0; i < n; i++)
        {
            if (stringArr[i] == element)
            {
                elementIndex = i;
                break;
            }
        }

        if (elementIndex != -1)
        {
            cout << "The name " << element << " is found at index: " << elementIndex << endl << endl;
        }
        else
        {
            cout << "The name " << element << " is not there in the array" << endl;
        }
    }
};

class binarySearch
{
public:
    int int_binary_search(int intArr[], int n, int element)
    {
        int low = 0;
        int high = n - 1;
        int flag = 0;

        while (low <= high)
        {
            int mid = low + (high - low ) / 2;

            if (intArr[mid] == element)
            {
                cout << "The element " << element << " was found at index: " << mid << endl<< endl;
                flag = 1;
                break;
            }

            if (intArr[mid] < element)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        if (flag == 0)
        {
            cout << "Search Unsuccessfull! Element not found" << endl<< endl;
        }
        return 0;
    }

    float float_binary_search(float floatArr[], int n, float element)
    {
        int low = 0;
        int high = n - 1;
        int flag = 0;

        while (low <= high)
        {
            int mid = low + (high - low ) / 2;

            if (floatArr[mid] == element)
            {
                cout << "The element " << element << " was found at index: " << mid <<endl << endl;
                flag = 1;
                break;
            }

            if (floatArr[mid] < element)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        if (flag == 0)
        {
            cout << "Search Unsuccessfull! Element not found" << endl;
        }
        return 0;
    }
};

int main()
{

    int count = 0;

searchChoice:

    char mainchoice;
    int subchoice;
    cout << "Enter 'l' for Linear Search or Enter 'b' for Binary Search: "; // Enter l for linear search and b for binary search
    cin >> mainchoice;

    cout << endl;

    if (mainchoice == 'l') // for linear search
    {
    datatypeChoice:
        cout << "Enter '0' for int array or Enter '1' for float array or Enter '2' for string array: "; // Enter 0 for int array. Enter 1 for float array. Enter 2 for string array
        cin >> subchoice;

        cout << endl;

        if (subchoice == 0)
        {
            int n;
            cout << "Enter your number: ";
            cin >> n;

            int intArr[n];

            for (int i = 0; i < n; i++)
            {
                cin >> intArr[i];
            }
            cout << endl;

            int element;
            cout << "Enter integer element to search: ";
            cin >> element;

            linearSearch intlinearsearch;
            intlinearsearch.int_linear_search(intArr, n, element);

        goto_Choice1:

            cout << endl;
            char gotoChoice_1;
            cout << "Enter 's' to go to searchChoice or Enter 'd' to go to datatypeChoice: ";
            cin >> gotoChoice_1;

            cout << endl;

            if (gotoChoice_1 == 's')
            {
                goto searchChoice;
            }
            else if (gotoChoice_1 == 'd')
            {
                goto datatypeChoice;
            }
            else
            {
                cout << "Invalid input enter again!!" << endl;
                count++;

                if (count == 3)
                {
                    count = 0;
                    cout << "Exiting the program due to more number of invalid input" << endl;
                    exit(0);
                }
                goto goto_Choice1;
            }
        }
        else if (subchoice == 1)
        {
            int n;
            cout << "Enter your number: ";
            cin >> n;

            float floatArr[n];

            for (int i = 0; i < n; i++)
            {
                cin >> floatArr[i];
            }
            cout << endl;

            float element;
            cout << "Enter float element to search: ";
            cin >> element;

            linearSearch floatlinearsearch;
            floatlinearsearch.float_linear_search(floatArr, n, element);

        goto_Choice2:

            cout << endl;
            char gotoChoice_2;
            cout << "Enter 's' to go to searchChoice or Enter 'd' to go to datatypeChoice: ";
            cin >> gotoChoice_2;

            cout << endl;

            if (gotoChoice_2 == 's')
            {
                goto searchChoice;
            }
            else if (gotoChoice_2 == 'd')
            {
                goto datatypeChoice;
            }
            else
            {
                cout << "Invalid input enter again!!" << endl;
                count++;

                if (count == 3)
                {
                    count = 0;
                    cout << "Exiting the program due to more number of invalid input" << endl;
                    exit(0);
                }
                goto goto_Choice2;
            }
        }
        else if (subchoice == 2)
        {
            int n;
            cout << "Enter your string size: ";
            cin >> n;

            string stringArr[n];

            for (int i = 0; i < n; i++)
            {
                cin >> stringArr[i];
            }
            cout << endl;

            string element;
            cout << "Enter string element to search: ";
            cin >> element;

            linearSearch stringlinearsearch;
            stringlinearsearch.string_linear_search(stringArr, n, element);

        goto_Choice3:

            cout << endl;
            char gotoChoice_3;
            cout << "Enter 's' to go to searchChoice or Enter 'd' to go to datatypeChoice: ";
            cin >> gotoChoice_3;

            cout << endl;

            if (gotoChoice_3 == 's')
            {
                goto searchChoice;
            }
            else if (gotoChoice_3 == 'd')
            {
                goto datatypeChoice;
            }
            else
            {
                cout << "Invalid input enter again!!" << endl;
                count++;

                if (count == 3)
                {
                    count = 0;
                    cout << "Exiting the program due to more number of invalid input" << endl;
                    exit(0);
                }

                goto goto_Choice3;
            }
        }
        else
        {
            cout << "Invalid Choice" << endl;
            count++;

            if (count == 3)
            {
                count = 0;
                cout << "Exiting the program due to more number of invalid input" << endl;
                exit(0);
            }

            goto datatypeChoice;
        }
    }
    else if (mainchoice == 'b') // for binary search
    {
    datatypeChoice_B:

        int subchoice;
        cout << "Enter '0' for int array or Enter '1' for float array: "; // Enter 0 for int array. Enter 1 for float array
        cin >> subchoice;

        cout << endl;

        if (subchoice == 0)
        {
            int n;
            cout << "Enter your number: ";
            cin >> n;

            int intArr[n];

            for (int i = 0; i < n; i++)
            {
                cin >> intArr[i];
            }
            cout << endl;

            int element;
            cout << "Enter integer element to search: ";
            cin >> element;

            binarySearch intbinarysearch;
            intbinarysearch.int_binary_search(intArr, n, element);

        goto_choice_1_B:

            char goto_choice1b;
            cout << "Enter 's' to go to searchChoice or Enter 'd' to go to datatypeChoice: ";
            cin >> goto_choice1b;

            cout << endl;

            if (goto_choice1b == 's')
            {
                goto searchChoice;
            }
            else if (goto_choice1b == 'd')
            {
                goto datatypeChoice_B;
            }
            else
            {
                cout << "Invalid input enter again!!" << endl;
                count++;

                if (count == 3)
                {
                    count = 0;
                    cout << "Exiting the program due to more number of invalid input" << endl;
                    exit(0);
                }

                goto goto_choice_1_B;
            }
        }
        else if(subchoice == 1)
        {
            int n;
            cout << "Enter your number: ";
            cin >> n;   

            float floatArr[n];

            for (int i = 0; i < n; i++)
            {
                cin >> floatArr[i];
            }
            cout << endl;

            float element;
            cout << "Enter integer element to search: ";
            cin >> element;

            binarySearch floatbinarysearch;
            floatbinarysearch.float_binary_search(floatArr, n, element);

            goto_choice_2B:

            char goto_choice2_b;
            cout << "Enter 's' to go to searchChoice or Enter 'd' to go to datatypeChoice: ";
            cin >> goto_choice2_b;

            cout << endl;

            if (goto_choice2_b == 's')
            {
                goto searchChoice;
            }
            else if (goto_choice2_b == 'd')
            {
                goto datatypeChoice_B;
            }
            else
            {
                cout << "Invalid input enter again!!" << endl;
                count++;

                if (count == 3)
                {
                    count = 0;
                    cout << "Exiting the program due to more number of invalid input" << endl;
                    exit(0);
                }

                goto datatypeChoice_B;
            }
        }
        else
        {
            cout << "Invalid Choice" << endl;
            count++;

            if (count == 3)
            {
                count = 0;
                cout << "Exiting the program due to more number of invalid input" << endl;
                exit(0);
            }

            goto datatypeChoice_B;
        }

        return 0;
    }
}
