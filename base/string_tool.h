#ifndef COMPASS_BASE_STRING_TOOL_H_
#define COMPASS_BASE_STRING_TOOL_H_

namespace compass {
namespace base {
   
class StringTool
{
    static int String2Int(char const *intStr, char const **errStr);
    static double String2Double(char const *doubleStr, char const **errStr);
};

}
}

#endif // COMPASS_BASE_STRING_TOOL_H_
