#include <climits>  // LONG_MAX
#include <cerrno>   // errno
#include <cmath>    // HUGE_VAL 
#include <cstdlib>  // strtol strtod
#include "string_tool.h"

namespace jc {
namespace base{

    // 1.https://stackoverflow.com/questions/194465/how-to-parse-a-string-to-an-int-in-c
    // 2.https://github.com/syuu1228/openbsd-src/blob/master/lib/libc/stdlib/strtonum.c
    // 3.http://www.kumobius.com/2013/08/c-string-to-int/

	const int kInconvertible = 1;
    const int kTooSmall      = 2;
    const int kTooLarge      = 3;

    int StringTool::String2Int(char const *intStr, char const **errStr)
    {
        long l = 0;
        char* pEnd;
        int error = 0;
        struct errVal {
            const char *errStr;
            int err;
        } ev[4] = {
            { nullptr,               0 },
            { "inconvertible",  EINVAL },
            { "too small",      ERANGE },
            { "too large",      ERANGE },
        };

        ev[0].err = errno;
        //With each thread having its own local errno.
        //This is a requirement in libraries compliant with C11 and C++11 standards.
        errno = 0; 
        l = strtol(intStr, &pEnd, 10);
        if (intStr == pEnd || *pEnd != '\0') {
            error = kInconvertible;
        }
        else if ((l == LONG_MAX && errno == ERANGE) || l > INT_MAX) {
            error = kTooLarge;
        }
        else if ((l == LONG_MIN && errno == ERANGE) || l < INT_MIN) {
            error = kTooSmall;
        }
        if (errStr != nullptr) {
            *errStr = ev[error].errStr;
        }
        errno = ev[error].err;
        if (error != 0) {
            l = 0;
        }

        return (static_cast<int>(l));
    }

    double StringTool::String2Double(char const *doubleStr, const char** errStr)
    {
        double d = 0.0;
        char* pEnd;
        int error = 0;
        struct errVal {
            const char *errStr;
            int err;
        } ev[4] = {
            { nullptr,               0 },
            { "inconvertible",  EINVAL },
            { "too small",      ERANGE },
            { "too large",      ERANGE },
        };

        ev[0].err = errno;
        //With each thread having its own local errno.
        //This is a requirement in libraries compliant with C11 and C++11 standards.
        errno = 0;
        d = strtod(doubleStr, &pEnd);
        if (doubleStr == pEnd || *pEnd != '\0') {
            error = kInconvertible;
        }
        else if (d == HUGE_VAL && errno == ERANGE) {
            error = kTooLarge;
        }
        else if (d == -HUGE_VAL && errno == ERANGE) {
            error = kTooSmall;
        }
        if (errStr != nullptr) {
            *errStr = ev[error].errStr;
        }
        errno = ev[error].err;
        if (error != 0) {
            d = 0.0;
        }

        return (d);
    }
}
}
