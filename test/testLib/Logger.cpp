#include "Logger.h"
#include "Colors.h"

void logPassed(string message)
{
        cout << PASSED_COLOR << message << RESET;
}

void logFailed(string message)
{
        cout << ERROR_COLOR << message << RESET;
}

void logTestResults(bool passed, string message)
{
        if (passed)
        {
                logPassed(message);
        }
        else
        {
                logFailed(message);
        }
}
