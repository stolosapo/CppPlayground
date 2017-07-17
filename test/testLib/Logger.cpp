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

void logIgnored(string message)
{
        cout << IGNORED_COLOR << message << RESET;
}

void logTestResults(bool ignored, bool passed, string message)
{
        if (ignored)
        {
                logIgnored(message);
                return;
        }

        if (passed)
        {
                logPassed(message);
        }
        else
        {
                logFailed(message);
        }
}
